#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <locale>
#include<Model/Model.h>
#include<Python.h>
#include<qdebug.h>
#include<cstdio>
#pragma comment(lib,"libtesseract304d.lib")
#pragma comment(lib,"liblept171d.lib")

void Model::processPicture(int grayType, int removet, int binaryt, int denoiser) {
	try {
		if (grayType < 0) {
			throw QException("请选择一种灰度方式!");
		}
		if (m.empty()) {
			throw QException("请先打开一张图片!");
		}
		//begin graym
		m.copyTo(graym);
		int nr = m.rows; // number of rows
		int nc = m.cols * m.channels(); // total number of elements per line
		switch (grayType) {
			case GrayType::GRAY_AVERAGE: {
				for (int j = 0; j < nr; j++) {
					uchar* data = m.ptr<uchar>(j);
					uchar* data1 = graym.ptr<uchar>(j);
					for (int i = 0; i < nc; i += 3) {
						data1[i] = data1[i + 1] = data1[i + 2] = (data[i] + data[i + 1] + data[i + 2]) / 3;
					}
				}
				break;
			}
			case GrayType::GRAY_MAX: {
				for (int j = 0; j < nr; j++) {
					uchar* data = m.ptr<uchar>(j);
					uchar* data1 = graym.ptr<uchar>(j);
					for (int i = 0; i < nc; i += 3) {
						uchar maxc = max(max(data[i], data[i + 1]), data[i + 2]);
						data1[i] = data1[i + 1] = data1[i + 2] = maxc;
					}
				}
				break;
			}
			case GrayType::GRAY_WEIGHTAVE: {
				for (int j = 0; j < nr; j++) {
					uchar* data = m.ptr<uchar>(j);
					uchar* data1 = graym.ptr<uchar>(j);
					for (int i = 0; i < nc; i += 3) {
						data1[i] = data1[i + 1] = data1[i + 2] = 0.3*data[i + 2] + 0.59*data[i + 1] + 0.11*data[i];
						//i Blue; i+1 Green; i+2 Red
					}
				}
				break;
			}
		}
		//end graym
		if (graym.empty()) {
			throw QException("图片灰度化失败!");
		}
		//begin remove background
		graym.copyTo(removeBGm);
		for (int j = 0; j < nr; j++) {
			uchar* data = removeBGm.ptr<uchar>(j);

			for (int i = 0; i < nc; i++) {
				data[i] = (data[i] > removet) ? 255 : data[i];
			}
		}
		if (removeBGm.empty()) {
			throw QException("图片去背景失败!");
		}
		//end remove bg
		//begin binary
		removeBGm.copyTo(binarym);
		for (int j = 0; j < nr; j++) {
			uchar* data = binarym.ptr<uchar>(j);

			for (int i = 0; i < nc; i++) {
				data[i] = (data[i] > binaryt) ? 255 : 0;
				//0 black, 255 white
			}
		}
		if (binarym.empty()) {
			throw QException("图片二值化失败!");
		}
		//end binary
		//begin denoise
		binarym.copyTo(denoisem);
		cv::Mat tmp;
		denoisem.copyTo(tmp);
		int r = denoiser;
		uchar** datas = new uchar*[nr];
		//erosion
		for (int i = 0; i < nr; i++) {
			datas[i] = binarym.ptr<uchar>(i);
		}

		for (int j = r; j < nr - r; j++) {
			uchar* desData = tmp.ptr<uchar>(j);

			for (int i = r; i < nc - r; i++) {
				//0 black, 255 white, all 0, then 0
				bool flag = true;
				for (int m = -r; m <= r; m++) {
					for (int n = -r; n <= r; n++) {
						if (datas[j + m][i + n]) {
							flag = false;
							break;
						}
					}
					if (!flag) break;
				}
				if (flag) {
					desData[i] = 0;
				}
				else {
					desData[i] = 255;
				}
			}
		}
		tmp.copyTo(denoisem);
		//dalition
		for (int i = 0; i < nr; i++) {
			datas[i] = denoisem.ptr<uchar>(i);
		}

		for (int j = r; j < nr - r; j++) {
			uchar* desData = tmp.ptr<uchar>(j);

			for (int i = r; i < nc - r; i++) {
				//0 black, 255 white, all 255, then 255
				bool flag = false;
				for (int m = -r; m <= r; m++) {
					for (int n = -r; n <= r; n++) {
						if (!datas[j + m][i + n]) {
							flag = true;
							break;
						}
					}
					if (flag) break;
				}
				if (flag) {
					desData[i] = 0;
				}
				else {
					desData[i] = 255;
				}
			}
		}
		tmp.copyTo(denoisem);
		if (denoisem.empty()) {
			throw QException("图片去噪声失败!");
		}
		cv::imwrite("denoise.jpg", denoisem);
		//end denoise
		string s = "process";
		this->notify(s);
	}
	catch (QException& E) {
		e = E;
		this->notify(false);
	}
}
wstring Model::UTF8ToUnicode(const string& str) {
	int  len = 0;
	len = str.length();
	int  unicodeLen = ::MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);
	wchar_t* pUnicode;
	pUnicode = new wchar_t[unicodeLen + 1];
	memset(pUnicode, 0, (unicodeLen + 1) * sizeof(wchar_t));
	::MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, (LPWSTR)pUnicode, unicodeLen);
	wstring rt;
	rt = (wchar_t*)pUnicode;
	delete pUnicode;
	return rt;
}
void Model::solvePicture(int verifyType) {
	if (verifyType == VerifyType::TEXT) {
		try {
			if (m.empty()) {
				throw QException("请先打开一张图片！");
			}
			if (denoisem.empty()) {
				throw QException("请先将图片去噪声!");
			}
			tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
			// Initialize tesseract-ocr with English, without specifying tessdata path
			if (api->Init(NULL, "eng+chi_sim+normal")) {
				throw QException("初始化tesseract失败!");
				exit(1);
			}

			// Open input image with leptonica library
			Pix *image = pixRead("denoise.jpg");
			if (image == nullptr) {
				throw QException("去噪声图片丢失!");
			}
			api->SetImage(image);
			// Get OCR result

			res = api->GetUTF8Text();

			api->End();
			pixDestroy(&image);
			string s = "result";
			this->notify(s);
		}
		catch (QException& E) {
			e = E;
			this->notify(false);
		}
	} else if (verifyType == VerifyType::SLIDER) {
		try {
			
			if (originPicturePath.empty() || slidePicturePath.empty()) {
				throw QException("请先打开图片！");
			}
			Py_SetPythonHome("Python27");
			PyObject *pModule, *pFunc, *pValue;			
			Py_Initialize();			
			pModule = PyImport_ImportModule("numpytest1");			
			if (pModule == NULL) {
				throw QException("pModule is NULL");
			}			
			pValue = PyObject_CallMethod(pModule, "predict", "ss", originPicturePath.c_str(), slidePicturePath.c_str());
			if (pValue == NULL) {
				throw QException("pValue is NULL");
			}						
			ostringstream os;			
			os << PyLong_AsLong(pValue);			
			res = os.str();
			Py_Finalize();
			string s = "result";
			this->notify(s);
		}
		catch (QException& E) {
			e = E;
			this->notify(false);
		}
		catch (...) {
			e = QException("unknown error!");
			this->notify(false);
		}
	}
}
void Model::loadPicture(const string& path) {
	originPicturePath = path;
	m = cv::imread(path, 1);
	if (m.empty()) {
		e.setErrorMes("加载图片失败!");
		this->notify(false);
	}
	else {
		string s = "image";
		this->notify(s);
	}
}
void Model::loadSlider(const string& path) {
	sliderm = cv::imread(path, 1);
	if (sliderm.empty()) {
		e.setErrorMes("加载图片失败!");
		this->notify(false);
	} else {
		slidePicturePath = path;
		string s = "slideImage";
		this->notify(s);
	}
}
void Model::saveResult(string savePath) {
	try {
		if (savePath.empty()) {
			throw QException("路径为空!");
		}
		if (res.empty()) {
			throw QException("结果不存在!");
		}
		ofstream fout(savePath);

		if (fout.bad()) {
			throw QException("写入文件失败!");
		}
		fout << res;
	}
	catch (QException& E) {
		e = E;
		notify(false);
	}
}
void Model::deletePicture() {
	remove("denoise.jpg");
}
cv::Mat& Model::getMat() {
	return m;
}
cv::Mat& Model::getSliderMat() {
	return sliderm;
}
cv::Mat& Model::getGrayMat() {
	return graym;
}
cv::Mat& Model::getDenoiseMat() {
	return denoisem;
}
cv::Mat& Model::getRemoveBGMat() {
	return removeBGm;
}
cv::Mat& Model::getBinaryMat() {
	return binarym;
}
QException& Model::getException() {
	return e;
}

QException::QException(string s) :errorMessage(s) {}
void QException::setErrorMes(string s) {
	errorMessage = s;
}
string QException::getErrorMes() {
	return errorMessage;
}