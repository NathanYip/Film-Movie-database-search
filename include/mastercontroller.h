#pragma once

#include "logger.h"
#include "store.h"

class MasterController
{
	private:
		static MasterController *instance;

	public:
		MasterController();
		~MasterController();
		static MasterController * getInstance();
		Store *movieStore;
		Store *appStore;
		Logger *logger;
		bool addFilm(Film*);
		bool removeFilm(int);
};
