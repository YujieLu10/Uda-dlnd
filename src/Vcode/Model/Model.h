#pragma once
#include<Common/Common.h>
#include<opencv2/opencv.hpp>
#include<fstream>
#include<exception>
#include<string>
class QException :public exception {
private:
	string errorMessage;
public:
	QException(string s = "");

	void setErrorMes(string s);

	string getErrorMes();
};
using namespace std;
class Model :public Observable {
protected:
	cv::Mat m;
	cv::Mat graym;
	cv::Mat denoisem;
	cv::Mat removeBGm;
	cv::Mat binarym;
	string res;
	QException e;
public:
	Model() {}
	~Model() {}

	cv::Mat& getMat();

	cv::Mat& getGrayMat();

	cv::Mat& getDenoiseMat();

	cv::Mat& getRemoveBGMat();

	cv::Mat& getBinaryMat();

	QException& getException();

	string getRes() { return res; }

	wstring UTF8ToUnicode(const string& str);

	void loadPicture(const string& path);

	void processPicture(int grayType, int removet, int binaryt, int denoiser);

	void solvePicture();

	void saveResult(string savePath);
};