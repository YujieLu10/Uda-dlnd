#pragma once
#include<Common/Common.h>
class ViewModel;
class ProcessPictureCommand :public BaseCommand{
private:
	ViewModel* pvm;
	shared_ptr<Param> params;
public:

	ProcessPictureCommand(ViewModel* p);
	virtual void exec();
	virtual void setParams(const shared_ptr<Param>& p);
};

