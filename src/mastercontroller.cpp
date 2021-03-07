#include "mastercontroller.h"


MasterController * MasterController::instance = new MasterController();

MasterController::MasterController()
{

	// create or load file into store
	MasterController::movieStore = new Store("movies");
	MasterController::appStore = new Store("app");
	MasterController::logger = new Logger();
}

MasterController::~MasterController()
{
	//write any unwritten changes to the file
	MasterController::movieStore->flush();
	MasterController::appStore->flush();
}

// returns false if project with same id exists, true if not;
bool MasterController::addFilm(Film * newfilm) //Film newfilm
{
	bool exists = false;
	for (int i = 0; i < movieStore->length(); i++) {
		Film *f = static_cast<Film *>(movieStore->getAt(i));
		if (f->filmID == newfilm->filmID) {
			exists = true;
			return false;
		}
	}
	if (exists == false) {
		movieStore->add(newfilm);
		exists = true;
	}
	return true;
}

// returns false if item fails to remove (if it doesnt even exist)
bool MasterController::removeFilm(int filmId)
{
	for (int i = 0; i < movieStore->length(); i++) {
		Film *f = static_cast<Film *>(movieStore->getAt(i));
		if (f->filmID == filmId) {
			movieStore->removeAt(i);
			return true;
		}
	}
	return false;
}

// returns a static global instance of the MasterController
MasterController * MasterController::getInstance()
{
	if (MasterController::instance == NULL) MasterController::instance = new MasterController(); //shouldnt be called but in case
	return MasterController::instance;
}


