#pragma once
#include "ui_MainView.h"
#include"View/DonateView.h"
#include"View/AboutView.h"
#include"View/GuideView.h"
#include <Common/Common.h>
#include <QtWidgets/QMainWindow>
#include <QBoxLayout>
#include<QCloseEvent>
class View : public QMainWindow, public Observer
{
	Q_OBJECT

public:
	View(QWidget *parent = Q_NULLPTR);

	void setLoadPictureCommand(shared_ptr<BaseCommand> p) {
		loadPictureCommand = p;
	}

	void setProcessPictureCommand(shared_ptr<BaseCommand> p) {
		processPictureCommand = p;
	}

	void setSolvePictureCommand(shared_ptr<BaseCommand>p) {
		solvePictureCommand = p;
	}

	void setSaveFileCommand(shared_ptr<BaseCommand> p) {
		saveFileCommand = p;
	}
	void setDeletePictureCommand(shared_ptr<BaseCommand> p) {
		deletePictureCommand = p;
	}
	void setImg(shared_ptr<QImage> p) {
		pImg = p;
	}

	void setGrayImg(shared_ptr<QImage> p) {
		pGrayImg = p;
	}

	void setDenoiseImg(shared_ptr<QImage> p) {
		pDenoiseImg = p;
	}

	void setRemoveBGImg(shared_ptr<QImage> p) {
		pRemoveBGImg = p;
	}

	void setBinaryImg(shared_ptr<QImage> p) {
		pBinaryImg = p;
	}

	void setRes(QString* s) {
		res = s;
	}

	void setErrorMessage(QString* p) {
		errorMessage = p;
	}
	void closeEvent(QCloseEvent *event);

private:
	Ui::ViewClass ui;
	QString filename;
	int grayType;
	QGraphicsScene* originScene;
	QGraphicsScene* grayScene;
	QGraphicsScene* denoiseScene;
	QGraphicsScene* removeBGScene;
	QGraphicsScene* binaryScene;
	QString* res;

	
	DonateWindow* donateWindow;	
	AboutWindow* aboutWindow;
	GuideWindow* guideWindow;

	QString* errorMessage;
	shared_ptr<BaseCommand> loadPictureCommand;
	shared_ptr<BaseCommand> processPictureCommand;
	shared_ptr<BaseCommand> solvePictureCommand;
	shared_ptr<BaseCommand> saveFileCommand;
	shared_ptr<BaseCommand> deletePictureCommand;

	shared_ptr<QImage> pImg;
	shared_ptr<QImage> pGrayImg;
	shared_ptr<QImage> pDenoiseImg;
	shared_ptr<QImage> pRemoveBGImg;
	shared_ptr<QImage> pBinaryImg;

	void update(const string& atrribute);

	virtual void commandSucceed(bool flag);


private slots:
	void processPicture();

	void importPicture();

	void solvePicture();

	void saveFile();

	void guideText();

	void aboutText();

	void donateText();

	
};
