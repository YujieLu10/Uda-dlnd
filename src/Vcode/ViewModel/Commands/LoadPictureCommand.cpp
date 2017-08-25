#include<ViewModel/Commands/LoadPictureCommand.h>
#include<ViewModel/ViewModel.h>
LoadPictureCommand::LoadPictureCommand(ViewModel* p):pvm(p){}
void LoadPictureCommand::exec() {
	shared_ptr<StringParam> sp= static_pointer_cast<StringParam, Param>(params);
	pvm->loadPicture(sp->getPath());
}
void LoadPictureCommand::setParams(const shared_ptr<Param>& p) {
	params = p;
}