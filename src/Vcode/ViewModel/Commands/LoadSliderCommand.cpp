#include<ViewModel/Commands/LoadSliderCommand.h>
#include<ViewModel/ViewModel.h>
LoadSliderCommand::LoadSliderCommand(ViewModel* p) :pvm(p) {}
void LoadSliderCommand::exec() {
	shared_ptr<StringParam> sp = static_pointer_cast<StringParam, Param>(params);
	pvm->loadSlider(sp->getPath());
}
void LoadSliderCommand::setParams(const shared_ptr<Param>& p) {
	params = p;
}