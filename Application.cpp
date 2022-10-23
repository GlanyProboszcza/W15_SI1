#include "Application.h"

int Application::run()
{
    int input;
    int select = 0;
    do {
        std::cout << "\x1B[2J\x1B[H";
        std::cout << "\n------ MAIN MENU ------\n"
            <<(select == 0 ? '>' : ' ') << "modify database\n"
            <<(select == 1 ? '>' : ' ') << "load/store database\n"
            <<(select == 2 ? '>' : ' ') << "filter database\n"
            <<(select == 3 ? '>' : ' ') << "set sorting order\n"
            <<(select == 4 ? '>' : ' ') << "visualize database\n"
            <<(select == 5 ? '>' : ' ') << "back/exit\n";

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
                //loadDataBase();
                break;
            case 2:
                //filterOrder();
                break;
            case 3:
                //sortingOrder();
                break;
            case 4:
                printDataBase();
                break;
            case 5:
                return 0;
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
    return 0;
}

void Application::modifyDataBase()
{
    int input;
    int select = 0;
    do {
        std::cout << "\x1B[2J\x1B[H";
        std::cout << "\n------ MODIFY DATABASE ------\n"
            << (select == 0 ? '>' : ' ') << "add entry\n"
            << (select == 1 ? '>' : ' ') << "remove entry\n"
            << (select == 2 ? '>' : ' ') << "modify entry\n"
            << (select == 3 ? '>' : ' ') << "<- back\n";

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
                int grade;
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
            select = ((select <= 0) ? select + 5 : --select);
            break;
        case 80: // strzalka w dol
            select = (++select) % 6;
            break;
        }
    } while (true);
}

void Application::printDataBase()
{

}

