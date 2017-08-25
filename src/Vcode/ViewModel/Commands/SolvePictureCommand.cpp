#include <ViewModel/Commands/SolvePictureCommand.h>
#include<ViewModel/ViewModel.h>
SolvePictureCommand::SolvePictureCommand(ViewModel * p) :pvm(p) {}
void SolvePictureCommand::exec(){
	pvm->solvePicture();
}

void SolvePictureCommand::setParams(const shared_ptr<Param>& p){
	params = p;
}
