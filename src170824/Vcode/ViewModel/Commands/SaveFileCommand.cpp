#include<ViewModel/Commands/SaveFileCommand.h>
#include<ViewModel/ViewModel.h>
SaveFileCommand::SaveFileCommand(ViewModel* p) :pvm(p) {}
void SaveFileCommand::exec() {
	shared_ptr<StringParam> sp = static_pointer_cast<StringParam, Param>(params);
	pvm->saveFile(sp->getPath());
}
void SaveFileCommand::setParams(const shared_ptr<Param>& p) {
	params = p;
}