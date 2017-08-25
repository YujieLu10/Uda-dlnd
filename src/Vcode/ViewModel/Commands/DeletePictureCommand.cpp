#include "DeletePictureCommand.h"
#include<ViewModel/ViewModel.h>
DeletePictureCommand::DeletePictureCommand(ViewModel* p):pvm(p) {

}
void DeletePictureCommand::exec() {
	pvm->deletePicture();
}
void DeletePictureCommand::setParams(const shared_ptr<Param>& p) {
	params = p;
}
