#pragma once
#include "Library.h"
#include "Database_manager.h"

class Application
{
private:
	Database_manager manager;
	std::function <bool(Database_manager::database_entry, Database_manager::database_entry)> sorting;
	std::function <bool(Database_manager::database_entry)> filtering;

public:
	Application() {
		sorting = [](const Database_manager::database_entry& a, const Database_manager::database_entry& b)
		{
			return false;
		};

		filtering = [](const Database_manager::database_entry& a)
		{
			return true;
		};
	};
	int run();
	void modifyDataBase();
	void printDataBase();
	void sortingOrder();
	void filter();
	void loadDataBase();
	void storeDataBase();

};

