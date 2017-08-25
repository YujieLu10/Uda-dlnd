#include<ViewModel/Commands/ProcessPictureCommand.h>
#include<ViewModel/ViewModel.h>
ProcessPictureCommand::ProcessPictureCommand(ViewModel* p) :pvm(p){}
void ProcessPictureCommand::exec() {
	shared_ptr<ProcessParam> sp = static_pointer_cast<ProcessParam, Param>(params);
	pvm->processPicture(sp->getType(),sp->getRemoveBGThreshold(),sp->getBinaryThreshold(),sp->getDenoiseHalfRadius());
}
void ProcessPictureCommand::setParams(const shared_ptr<Param>& p) {
	params = p;
}