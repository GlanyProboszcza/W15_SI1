#pragma once
#include "Library.h"
#include "Database_manager.h"
#include "ui_db_context.h"

class Application
	: public ui_db_context
{
private:
	Database_manager manager;

public:

	int run();
	void modifyDataBase();
	void printDataBase();
};

