#include <View/View.h>
#include <QFileDialog>
#include <QMessageBox>
#include <qlayout.h>

View::View(QWidget *parent)
	: QMainWindow(parent) {
	ui.setupUi(this);
	ui.importPicAction->setShortcuts(QKeySequence::Open);
	ui.importPicAction->setStatusTip(tr("Import a picture of verification code"));
	ui.exitAction->setShortcuts(QKeySequence::Close);
	ui.exitAction->setStatusTip(tr("Quit"));
	ui.saveAction->setShortcut(QKeySequence::Save);
	ui.saveAction->setStatusTip(tr("Save the recognizing result of the verification code"));
	ui.donateAction->setShortcut(Qt::CTRL | Qt::Key_D);
	ui.donateAction->setStatusTip(tr("Donate to developers"));
	ui.guideAction->setShortcut(QKeySequence::HelpContents);
	ui.guideAction->setStatusTip(tr("Guide for basic operations"));
	ui.aboutAction->setShortcut(Qt::CTRL | Qt::Key_A);
	ui.aboutAction->setStatusTip(tr("About authors and versions"));

	originScene = new QGraphicsScene();
	grayScene = new QGraphicsScene();
	denoiseScene = new QGraphicsScene();
	removeBGScene = new QGraphicsScene();
	binaryScene = new QGraphicsScene();

	errorMessage = new QString;

	//guide window
	guideWindow = new QWidget;
	guideLayout = new QVBoxLayout;
	guideLabel = new QLabel;
	guidePixmap = new QPixmap("img\\guide.jpg");
	guideLabel->setPixmap(*guidePixmap);
	guideLayout->addWidget(guideLabel);
	guideWindow->setLayout(guideLayout);

	guideWindow->setWindowTitle(QString("Guide Information"));
	guideWindow->setFixedSize(500, 330);

	//donate window
	donateWindow = new QWidget;
	donateLayout = new QVBoxLayout;
	donateLabel = new QLabel;
	donateLabel->setText(tr("Scan the following QR code to donate to developers!"));
	donatePixmap = new QPixmap("img\\donate.jpg");
	donateLabel->setPixmap(*donatePixmap);
	donateLayout->addWidget(donateLabel);
	donateWindow->setLayout(donateLayout);

	donateWindow->setWindowTitle(QString("How to donate"));
	donateWindow->setFixedSize(500, 300);

	//about window
	aboutWindow = new QWidget;
	aboutLayout = new QVBoxLayout;
	aboutLabel = new QLabel;
	aboutPixmap = new QPixmap("img\\about.jpg");
	aboutLabel->setPixmap(*aboutPixmap);
	aboutLayout->addWidget(aboutLabel);
	aboutWindow->setLayout(aboutLayout);

	aboutWindow->setWindowTitle(QString("Developer Information"));
	aboutWindow->setFixedSize(500, 300);

	//禁止最大化窗口
	setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);

	ui.leftOriginView->setScene(originScene);
	ui.binaryzationView->setScene(binaryScene);
	ui.denoiseView->setScene(denoiseScene);
	ui.removeBgView->setScene(removeBGScene);
	ui.grayView->setScene(grayScene);

	connect(ui.importPicAction, &QAction::triggered, this, &View::importPicture);
	connect(ui.saveAction, &QAction::triggered, this, &View::saveFile);
	connect(ui.confirmButton, &QPushButton::clicked, this, &View::processPicture);
	connect(ui.recognizeButton, &QPushButton::clicked, this, &View::solvePicture);
	connect(ui.exitAction, &QAction::triggered, this, &View::close);
	connect(ui.donateAction, &QAction::triggered, this, &View::donateText);
	connect(ui.guideAction, &QAction::triggered, this, &View::guideText);
	connect(ui.aboutAction, &QAction::triggered, this, &View::aboutText);

	connect(ui.rBGSlider, SIGNAL(valueChanged(int)), ui.rBGSpinBox, SLOT(setValue(int)));
	connect(ui.rBGSpinBox, SIGNAL(valueChanged(int)), ui.rBGSlider, SLOT(setValue(int)));
	connect(ui.binarySlider, SIGNAL(valueChanged(int)), ui.binarySpinBox, SLOT(setValue(int)));
	connect(ui.binarySpinBox, SIGNAL(valueChanged(int)), ui.binarySlider, SLOT(setValue(int)));
	connect(ui.denoiseSlider, SIGNAL(valueChanged(int)), ui.denoiseSpinBox, SLOT(setValue(int)));
	connect(ui.denoiseSpinBox, SIGNAL(valueChanged(int)), ui.denoiseSlider, SLOT(setValue(int)));
}

void View::saveFile() {
	QString filename = QFileDialog::getSaveFileName(this, tr("Save Result"), "", tr("*.txt")); //选择路径  
	if (!filename.isEmpty()) {
		shared_ptr<StringParam> sp = make_shared<StringParam>();
		sp->setPath(filename.toStdString());
		saveFileCommand->setParams(static_pointer_cast<Param, StringParam>(sp));
		saveFileCommand->exec();
	}
}

void View::guideText() {
	guideWindow->setWindowModality(Qt::ApplicationModal);
	guideWindow->show();
}

void View::aboutText() {
	aboutWindow->setWindowModality(Qt::ApplicationModal);
	aboutWindow->show();
}

void View::donateText() {
	donateWindow->setWindowModality(Qt::ApplicationModal);
	donateWindow->show();
}

void View::processPicture() {
	if (ui.aveButton->isChecked()) {
		grayType = GrayType::GRAY_AVERAGE;
	}
	else if (ui.maxbutton->isChecked()) {
		grayType = GrayType::GRAY_MAX;
	}
	else if (ui.weightAveButton->isChecked()) {
		grayType = GrayType::GRAY_WEIGHTAVE;
	}
	else {
		grayType = -1;
	}
	shared_ptr<ProcessParam> sp = make_shared<ProcessParam>();
	sp->setType(grayType);
	sp->setRemoveThreshold(ui.rBGSlider->value());
	sp->setBinaryThreshold(ui.binarySlider->value());
	sp->setDenoiseHalfRadius(ui.denoiseSlider->value());
	processPictureCommand->setParams(static_pointer_cast<Param, ProcessParam>(sp));

	processPictureCommand->exec();
}
void View::importPicture() {
	filename = QFileDialog::getOpenFileName(this, "Select Picture", ".", tr("Images (*.png *.bmp *.jpg *.tif *.GIF )"));
	if (!filename.isEmpty()) {
		shared_ptr<StringParam> sp = make_shared<StringParam>();
		sp->setPath(filename.toStdString());
		loadPictureCommand->setParams(static_pointer_cast<Param, StringParam>(sp));
		loadPictureCommand->exec();
	}
}
void View::solvePicture() {
	solvePictureCommand->exec();
}
void View::update(const string& attribute) {
	if (attribute == "image") {
		originScene->clear();
		originScene->addPixmap(QPixmap::fromImage(pImg->scaled(ui.leftOriginView->width(), ui.leftOriginView->height(), Qt::KeepAspectRatio)));
	}
	else if (attribute == "process") {
		grayScene->clear();
		grayScene->addPixmap(QPixmap::fromImage(pGrayImg->scaled(ui.grayView->width(), ui.grayView->height(), Qt::KeepAspectRatio)));
		denoiseScene->clear();
		denoiseScene->addPixmap(QPixmap::fromImage(pDenoiseImg->scaled(ui.denoiseView->width(), ui.denoiseView->height(), Qt::KeepAspectRatio)));
		removeBGScene->clear();
		removeBGScene->addPixmap(QPixmap::fromImage(pRemoveBGImg->scaled(ui.removeBgView->width(), ui.removeBgView->height(), Qt::KeepAspectRatio)));
		binaryScene->clear();
		binaryScene->addPixmap(QPixmap::fromImage(pBinaryImg->scaled(ui.binaryzationView->width(), ui.binaryzationView->height(), Qt::KeepAspectRatio)));
	}
	else if (attribute == "result") {
		ui.resultText->setText(*res);
	}
}
void View::commandSucceed(bool flag) {
	if (!flag) {
		QMessageBox::critical(this, "Error", *errorMessage);
	}
}