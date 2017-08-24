#pragma once
#include<Common/Common.h>
#include<qdebug.h>
class ViewModel;
class DeletePictureCommand :public BaseCommand {
private:
	ViewModel* pvm;
	shared_ptr<Param> params;
public:
	DeletePictureCommand(ViewModel* p);
	virtual void exec();
	virtual void setParams(const shared_ptr<Param>& p);
};

