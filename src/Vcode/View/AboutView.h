#pragma once
#include"ui_AboutView.h"
class AboutWindow :public QDialog {
	Q_OBJECT
public:
	AboutWindow(QWidget *parent = Q_NULLPTR);
private:
	Ui::AboutDialog ui;
	QPixmap* aboutPixmap;
};


