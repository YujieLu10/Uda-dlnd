#include "AboutView.h"



AboutWindow::AboutWindow(QWidget *parent) :QDialog(parent) {
	ui.setupUi(this);
	aboutPixmap = new QPixmap("img\\donate.jpg");
	ui.label->setPixmap(*aboutPixmap);
	ui.verticalLayout->addWidget(ui.label);
	setLayout(ui.verticalLayout);
	setFixedSize(500, 300);
	setWindowModality(Qt::ApplicationModal);
	Qt::WindowFlags flags = Qt::Dialog;
	flags |= Qt::WindowCloseButtonHint;
	setWindowFlags(flags);
}

