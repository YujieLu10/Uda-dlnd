#pragma once
#include<Common/Common.h>
#include<Model/model.h>
#include<ViewModel/Commands/LoadPictureCommand.h>
#include<ViewModel/Commands/ProcessPictureCommand.h>
#include<ViewModel/Commands/SolvePictureCommand.h>
#include<ViewModel/Commands/SaveFileCommand.h>
#include<ViewModel/Commands/DeletePictureCommand.h>
#include<QImage>
#include<QTextCodec>
#include<fstream>
class ViewModel :public Observable, public Observer {
private:
	shared_ptr<QImage> pImg;
	shared_ptr<QImage> pGrayImg;
	shared_ptr<QImage> pRemoveBGImg;
	shared_ptr<QImage> pDenoiseImg;
	shared_ptr<QImage> pBinaryImg;
	QString* res;
	QString* errorMessage;

	shared_ptr<BaseCommand> loadPictureCommand;
	shared_ptr<BaseCommand> processPictureCommand;
	shared_ptr<BaseCommand> solvePictureCommand;
	shared_ptr<BaseCommand> saveFileCommand;
	shared_ptr<BaseCommand> deletePictureCommand;

	shared_ptr<Model> model;
public:

	shared_ptr<BaseCommand> getLoadPictureCommand() {
		return loadPictureCommand;
	}
	shared_ptr<BaseCommand> getProcessPictureCommand() {
		return processPictureCommand;
	}
	shared_ptr<BaseCommand> getSolvePictureCommand() {
		return solvePictureCommand;
	}
	shared_ptr<BaseCommand> getSaveFileCommand() {
		return saveFileCommand;
	}
	shared_ptr<BaseCommand> getDeletePictureCommand() {
		return deletePictureCommand;
	}
	ViewModel() {
		loadPictureCommand = static_pointer_cast<BaseCommand, LoadPictureCommand>(shared_ptr<LoadPictureCommand>(new LoadPictureCommand(this)));
		processPictureCommand = static_pointer_cast<BaseCommand, ProcessPictureCommand>(shared_ptr<ProcessPictureCommand>(new ProcessPictureCommand(this)));
		solvePictureCommand = static_pointer_cast<BaseCommand, SolvePictureCommand>(shared_ptr<SolvePictureCommand>(new SolvePictureCommand(this)));
		saveFileCommand = static_pointer_cast<BaseCommand, SaveFileCommand>(shared_ptr<SaveFileCommand>(new SaveFileCommand(this)));
		deletePictureCommand=static_pointer_cast<BaseCommand, DeletePictureCommand>(shared_ptr<DeletePictureCommand>(new DeletePictureCommand(this)));

		pImg = shared_ptr<QImage>(new QImage());
		pGrayImg = shared_ptr<QImage>(new QImage());
		pRemoveBGImg = shared_ptr<QImage>(new QImage());
		pDenoiseImg = shared_ptr<QImage>(new QImage());
		pBinaryImg = shared_ptr<QImage>(new QImage());
		res = new QString();
		errorMessage = new QString();
	}
	~ViewModel() {

	}
	void setModel(shared_ptr<Model>& m) {
		model = m;
	}
	void loadPicture(const string& path) {
		model->loadPicture(path);
	}
	void processPicture(int grayType, int removet, int binaryt, int denoiser) {
		model->processPicture(grayType, removet, binaryt, denoiser);
	}
	void solvePicture() {
		model->solvePicture();
	}
	void saveFile(string savePath) {
		model->saveResult(savePath);
	}
	void deletePicture() {
		model->deletePicture();
	}
	shared_ptr<QImage> getpImg() {
		return pImg;
	}
	shared_ptr<QImage> getpGrayImg() {
		return pGrayImg;
	}
	shared_ptr<QImage> getpRemoveBGImg() {
		return pRemoveBGImg;
	}
	shared_ptr<QImage> getpDenoiseImg() {
		return pDenoiseImg;
	}
	shared_ptr<QImage> getpBinaryImg() {
		return pBinaryImg;
	}
	QString* getRes() {
		return res;
	}
	QString* getErrorMessage() {
		return errorMessage;
	}
	QImage cvMatToQImage(const cv::Mat &inMat) {
		switch (inMat.type()) {
			// 8-bit, 4 channel
			case CV_8UC4: {
				QImage image(inMat.data, inMat.cols, inMat.rows, inMat.step, QImage::Format_RGB32);
				return image;
			}
						  // 8-bit, 3 channel
			case CV_8UC3: {
				QImage image(inMat.data, inMat.cols, inMat.rows, inMat.step, QImage::Format_RGB888);
				return image.rgbSwapped();
			}
						  // 8-bit, 1 channel
			case CV_8UC1: {
				static QVector<QRgb>  sColorTable;
				// only create our color table once
				if (sColorTable.isEmpty())
				{
					for (int i = 0; i < 256; ++i)
						sColorTable.push_back(qRgb(i, i, i));
				}
				QImage image(inMat.data, inMat.cols, inMat.rows, inMat.step, QImage::Format_Indexed8);
				image.setColorTable(sColorTable);
				return image;
			}
			default:
				break;
		}
		return QImage();

	}
	void update(const string& attribute) {
		QTextCodec *codec = QTextCodec::codecForName("GB2312");
		*errorMessage = (codec->toUnicode(model->getException().getErrorMes().c_str()));
		if (attribute == "image") {
			*pImg = cvMatToQImage(model->getMat());
			if (pImg->isNull()) {
				*errorMessage = codec->toUnicode("转换Mat类型到QImage类型失败！");
				notify(false);
			}
			else {
				string s = "image";
				notify(s);
			}
		}
		else if (attribute == "process") {
			*pGrayImg = cvMatToQImage(model->getGrayMat());
			*pRemoveBGImg = cvMatToQImage(model->getRemoveBGMat());
			*pDenoiseImg = cvMatToQImage(model->getDenoiseMat());
			*pBinaryImg = cvMatToQImage(model->getBinaryMat());
			if (pGrayImg->isNull()) {
				*errorMessage = codec->toUnicode("灰度图不存在！");
				notify(false);
			}
			else {
				string s = "process";
				notify(s);
			}
		}
		else if (attribute == "result") {
			*res = codec->toUnicode(model->getRes().c_str());
			//中文还是不行
			if (res->isEmpty()) {
				*errorMessage = codec->toUnicode("结果不存在！");
				notify(false);
			}
			else {
				string s = "result";
				notify(s);
			}
		}
	}
	virtual void commandSucceed(bool flag) {
		if (!flag) {
			QTextCodec *codec = QTextCodec::codecForName("GB2312");
			*errorMessage=(codec->toUnicode(model->getException().getErrorMes().c_str()));
			
		}
		notify(flag);
	}
};