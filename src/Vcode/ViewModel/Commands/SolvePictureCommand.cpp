#include <ViewModel/Commands/SolvePictureCommand.h>
#include<ViewModel/ViewModel.h>
SolvePictureCommand::SolvePictureCommand(ViewModel * p) :pvm(p) {}
void SolvePictureCommand::exec(){
	shared_ptr<SolveParam> sp = static_pointer_cast<SolveParam, Param>(params);
	pvm->solvePicture(sp->getVerifyType());
}

void SolvePictureCommand::setParams(const shared_ptr<Param>& p){
	params = p;
}
