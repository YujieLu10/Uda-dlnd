#include <View/MainView.h>
#include <ViewModel/ViewModel.h>
#include <QtWidgets/QApplication>
#include <Model/Model.h>
#include <QtGui/qbitmap.h>
#include <qsplashscreen.h>
#include <qelapsedtimer.h>

const int SPLASHTIME = 1500;

int main(int argc, char *argv[]) {

	putenv("TESSDATA_PREFIX=Tesseract-OCR");
	QApplication a(argc, argv);
	shared_ptr<View> pv(new View);

	//initial
	QPixmap initialPixmap("img\\initial.jpg");
	QSplashScreen splash(initialPixmap);
	splash.show();
	QElapsedTimer timer;
	timer.start();
	while (timer.elapsed() < SPLASHTIME)
		a.processEvents();
	splash.close();

	shared_ptr<Model> pm(new Model);
	shared_ptr<ViewModel> pvm(new ViewModel());
	pvm->setModel(pm);

	//bind command
	pv->setLoadPictureCommand(pvm->getLoadPictureCommand());
	pv->setProcessPictureCommand(pvm->getProcessPictureCommand());
	pv->setSolvePictureCommand(pvm->getSolvePictureCommand());
	pv->setSaveFileCommand(pvm->getSaveFileCommand());
	pv->setDeletePictureCommand(pvm->getDeletePictureCommand());
	//bind data
	pv->setImg(pvm->getpImg());
	pv->setGrayImg(pvm->getpGrayImg());
	pv->setDenoiseImg(pvm->getpDenoiseImg());
	pv->setBinaryImg(pvm->getpBinaryImg());
	pv->setRemoveBGImg(pvm->getpRemoveBGImg());
	pv->setRes(pvm->getRes());
	pv->setErrorMessage(pvm->getErrorMessage());

	//observer
	pm->addObserver(static_pointer_cast<Observer, ViewModel>(pvm));
	pvm->addObserver(static_pointer_cast<Observer, View>(pv));

	//modify background
	QPixmap backgroundPixmap("img\\background.jpg");
	QPalette qp;
	qp.setBrush(pv->backgroundRole(), QBrush(backgroundPixmap));
	pv->setPalette(qp);
	pv->setMask(backgroundPixmap.mask());
	pv->setAutoFillBackground(true);

	pv->show();
	return a.exec();
}

