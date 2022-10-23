#include "Database_manager.h"

void Database_manager::add_entry(std::string name, int grade)
{
	data.insert({ name, grade });
}

void Database_manager::remove_entry(std::string name)
{
	data.erase(name);
}

void Database_manager::modify_entry(std::string name)
{
	if (data.count(name)) {
		std::cout << "Enter what you want to modify:\n1 - NAME\n2 - GRADE\nother - EXIT\n";
		char c;
		std::cin >> c;
		
		switch (c) {
		case 1:	{
			std::string helper;
			std::cout << "Enter replace name: ";
			std::cin >> helper;
			this->add_entry(helper, data[name]);
			this->remove_entry(name); 
			}
			break;
		case 2:
			std::cout << "Enter correct grade: ";
			std::cin >> data[name];
			break;
		default:
			break;
		}
	}
	else
		std::cout << "\nError!\n";
}

std::vector<Database_manager::database_entry> Database_manager::get_entries()
{
	std::vector<database_entry> temp;
	std::transform(data.begin(), data.end(), std::back_inserter(temp), [](char c) {return c; });

	return temp;
}
