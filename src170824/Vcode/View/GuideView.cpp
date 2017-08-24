#include "GuideView.h"



GuideWindow::GuideWindow(QWidget *parent) :QDialog(parent) {
	ui.setupUi(this);
	guidePixmap = new QPixmap("img\\guide.jpg");
	ui.label->setPixmap(*guidePixmap);
	ui.verticalLayout->addWidget(ui.label);
	setLayout(ui.verticalLayout);
	setFixedSize(500, 330);
	setWindowModality(Qt::ApplicationModal);
	Qt::WindowFlags flags = Qt::Dialog;
	flags |= Qt::WindowCloseButtonHint;
	setWindowFlags(flags);
}
