#include "Application.h"

int Application::run()
{
    int input;
    int select = 0;
    do {
       system("cls");
        std::cout << "\n\t------ MAIN MENU ------\n"
           << "\t" <<(select == 0 ? '>' : ' ') << " modify database\n"
           << "\t" <<(select == 1 ? '>' : ' ') << " load database\n"
           << "\t" <<(select == 2 ? '>' : ' ') << " store database\n"
           << "\t" <<(select == 3 ? '>' : ' ') << " filter database\n"
           << "\t" <<(select == 4 ? '>' : ' ') << " set sorting order\n"
           << "\t" <<(select == 5 ? '>' : ' ') << " visualize database\n"
           << "\t" <<(select == 6 ? '>' : ' ') << " back/exit\n";

        input = _getch();

        switch (input) {
        case 27: // esc na klawce
            return 0;
            break;
        case 13: // enter
            switch (select) {
            case 0:
                modifyDataBase();
                break;
            case 1:
                loadDataBase();
                break;
            case 2:
                storeDataBase();
                break;
            case 3:
                filter();
                break;
            case 4:
                sortingOrder();
                break;
            case 5:
                printDataBase();
                break;
            case 6:
                return 0;
                break;
            }
            break;
        case 72: // strzalka w gore
            select = ((select <= 0) ? select + 6 : --select);
            break;
        case 80: // strzalka w dol
            select = (++select) % 7;
            break;
        }

    } while (true);
    return 0;
}
void Application::storeDataBase() {
    std::ofstream file("students_data_base.txt");
    if (!file.is_open()) {
        std::cout << "File error\n";
        _getch();
    }
    else {
        std::vector<Database_manager::database_entry> temp = manager.get_entries();
        for (auto a : temp) {
            file << a.name << "\n";
            file << a.grade << "\n";
        }
        file.flush();
        file.close();
    }

}
void Application::loadDataBase() {
    std::fstream file("students_data_base.txt");
    if (!file.is_open()) {
        std::cout << "The data base file could not be found.\n";
        _getch();
        }
    else {
        int grade;
        std::string name;
        int num=0;
        std::string line;
        while (std::getline(file, line)) {
            if (num++ % 2 == 0) {
                name = line;
            }
            else {
                grade = stoi(line);
                manager.add_entry(name, grade);
            }
        }
        file.close();
        std::cout << "The data base file loades succesfully.\n";
        _getch();
    }
}
void Application::filter() {
    int input;
    int select = 0;
    do {
       system("cls");
        std::cout << "\n\t------ SORTING ------\n"
            << "\t" << (select == 0 ? '>' : ' ') << " only passing grades\n"
            << "\t" << (select == 1 ? '>' : ' ') << " only non-passing grades\n"
            << "\t" << (select == 2 ? '>' : ' ') << " all grades\n"
            << "\t" << (select == 3 ? '>' : ' ') << " <- back\n";

        input = _getch();

        switch (input) {
        case 27: // esc na klawce
            return;
            break;
        case 13: // enter
            switch (select) {
            case 0:
            {
                this->filtering = [](const Database_manager::database_entry& a)
                {
                    return a.grade >=3;
                };
                std::cout << "Filter has been set to passing grades" << std::endl;
                _getch();
                return;
            }
            break;
            case 1:
            {
                this->filtering = [](const Database_manager::database_entry& a)
                {
                    return a.grade<3;
                };
                std::cout << "Filter has been set to non-passing grades" << std::endl;
                _getch();
                return;
            }
            break;
            case 2:
            {
                this->filtering = [](const Database_manager::database_entry& a)
                {
                    return true;
                };
                std::cout << "without filtering, all grades." << std::endl;
                _getch();
                return;
            }
            break;
            case 3:
                return;
                break;
            }
            break;
        case 72: // strzalka w gore
            select = ((select <= 0) ? select + 3 : --select);
            break;
        case 80: // strzalka w dol
            select = (++select) % 4;
            break;
        }
    } while (true);
}
void Application::sortingOrder() {
    int input;
    int select = 0;
    do {
       system("cls");
        std::cout << "\n\t------ SORTING ------\n"
            << "\t" << (select == 0 ? '>' : ' ') << " increasing by name\n"
            << "\t" << (select == 1 ? '>' : ' ') << " decreasing by name\n"
            << "\t" << (select == 2 ? '>' : ' ') << " increasing by grade\n"
            << "\t" << (select == 3 ? '>' : ' ') << " decreasing by grade\n"
            << "\t" << (select == 4 ? '>' : ' ') << " without sorting\n"
            << "\t" << (select == 5 ? '>' : ' ') << " <- back\n";

        input = _getch();

        switch (input) {
        case 27: // esc na klawce
            return;
            break;
        case 13: // enter
            switch (select) {
            case 0:
            {
                this->sorting = [](const Database_manager::database_entry& a, const Database_manager::database_entry& b)
                {
                    return a.name < b.name;
                };
                std::cout << "Sorting order has been set to increasing by name" << std::endl;
                _getch();
                return;
            }
            break;
            case 1:
            {
                this->sorting = [](const Database_manager::database_entry& a, const Database_manager::database_entry& b)
                {
                    return a.name > b.name;
                };
                std::cout << "Sorting order has been set to decreasing by name" << std::endl;
                _getch();
                return;
            }
            break;
            case 2:
            {
                this->sorting = [](const Database_manager::database_entry& a, const Database_manager::database_entry& b)
                {
                    return a.grade < b.grade;
                };
                std::cout << "Sorting order has been set to increasing by grade" << std::endl;
                _getch();
                return;
            }
            break;
            case 3:
            {
                this->sorting = [](const Database_manager::database_entry& a, const Database_manager::database_entry& b)
                {
                    return a.grade > b.grade;
                };
                std::cout << "Sorting order has been set to decreasing by grade" << std::endl;
                _getch();
                return;
            }
            break;
            case 4:
            {
                this->sorting = [](const Database_manager::database_entry& a, const Database_manager::database_entry& b)
                {
                    return false;
                };
                std::cout << "Sorting order has been set to default" << std::endl;
                _getch();
                return;
            }
            break;
            case 5:
                return;
                break;
            }
            break;
        case 72: // strzalka w gore
            select = ((select <= 0) ? select + 5 : --select);
            break;
        case 80: // strzalka w dol
            select = (++select) % 6;
            break;
        }
    } while (true);
}
void Application::modifyDataBase()
{
    int input;
    int select = 0;
    do {
       system("cls");
        std::cout << "\n\t------ MODIFY DATABASE ------\n"
            << "\t" << (select == 0 ? '>' : ' ') << " add entry\n"
            << "\t" << (select == 1 ? '>' : ' ') << " remove entry\n"
            << "\t" << (select == 2 ? '>' : ' ') << " modify entry\n"
            << "\t" << (select == 3 ? '>' : ' ') << " <- back\n";

        input = _getch();

        switch (input) {
        case 27: // esc na klawce
            return ;
            break;
        case 13: // enter
            switch (select) {
            case 0:
            {
                std::string name;
                int grade;
                std::cout << "\nAdding new Student";
                std::cout << "\nEnter name: ";
                std::cin >> name;
                std::cout << "Enter grade: ";
                std::cin >> grade;
                manager.add_entry(name, grade);
            }
                break;
            case 1:
            {
                std::string name;
                std::cout << "\nRemove Student: ";
                std::cout << "\nEnter name: ";
                std::cin >> name;
                manager.remove_entry(name);
            }
                break;
            case 2:
            {
                std::string name;
                std::cout << "\nModify Student: ";
                std::cout << "\nEnter name: ";
                std::cin >> name;
                manager.modify_entry(name);
            }
                break;
            case 3:
                return ;
                break;
            }
            break;
        case 72: // strzalka w gore
            select = ((select <= 0) ? select + 3 : --select);
            break;
        case 80: // strzalka w dol
            select = (++select) % 4;
            break;
        }
    } while (true);
}
void Application::printDataBase()
{
    std::vector<Database_manager::database_entry> temp2;
    {
    std::vector<Database_manager::database_entry> temp = manager.get_entries();
    std::copy_if(temp.begin(), temp.end(), std::back_inserter(temp2), filtering);
    }
    std::sort(temp2.begin(), temp2.end(), sorting);

    std::cout <<
        "+----------------------+---+\n" <<
        "|       Name           |   |\n" <<
        "+----------------------+---+\n";
    for (auto e : temp2)
    {
        std::cout << "| " << std::setw(20) << std::left << e.name << " | " << std::setw(1) << e.grade << " |\n" <<
            "+----------------------+---+\n";
    }
    std::cout << "\nPress any key to continue...";
    _getch();
}

