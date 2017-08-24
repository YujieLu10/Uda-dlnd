#pragma once
#include"ui_GuideView.h"
class GuideWindow :public QDialog {
	Q_OBJECT
public:
	GuideWindow(QWidget *parent = Q_NULLPTR);
private:
	Ui::GuideDialog ui;
	QPixmap* guidePixmap;
};

