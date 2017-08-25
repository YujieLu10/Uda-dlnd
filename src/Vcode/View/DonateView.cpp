#include "DonateView.h"



DonateWindow::DonateWindow(QWidget *parent) :QDialog(parent) {
	ui.setupUi(this);
	donatePixmap = new QPixmap("img\\about.jpg");
	ui.label->setPixmap(*donatePixmap);
	ui.verticalLayout->addWidget(ui.label);
	setLayout(ui.verticalLayout);
	setFixedSize(500, 300);
	setWindowModality(Qt::ApplicationModal);
	Qt::WindowFlags flags = Qt::Dialog;
	flags |= Qt::WindowCloseButtonHint;
	setWindowFlags(flags);
}
