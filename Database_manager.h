#pragma once
#include "Library.h"


class Database_manager
{
private:
	std::unordered_map<std::string, unsigned int> data;

public:
    Database_manager() {
        //data = {
        //{"Agata Porzadek",        4 },
        //{"Marcin Elblag",        2 },
        //{"Dominik Stokrotka",    3 },
        //{"Sylwester Wilusz",    4 },
        //{"Krystyn Dobies",        2 },
        //{"Ferdynand Zebro",        6 },
        //{"Dominik Pacha",        1 },
        //{"Witold Nowak",        4 },
        //{"Chrystian Porada",    2 },
        //{"Sebastian Dombrowski",5 },
        //{"Albert Komarek",        3 },
        //{"Igor Soboleski",        6 },
        //{"Korneli Lysek",        3 },
        //{"Hubert Kopecki",        1 },
        //{"Bartlomiej Gal",        2 },
        //{"Ludomil Kaniuk",        4 },
        //{"Radoslaw Wegrzyn",    6 },
        //{"Jakub Gazdik",        5 },
        //{"Justyn Strozewski",    3 },
        //{"Lubomir Merta",        2 },
        //{"Wladyslaw Gogol",        1 }
        //};

    }
    ~Database_manager() = default;

    struct database_entry 
        {
        std::string name;
        int grade;
        database_entry()=default;
        database_entry(std::string name, int grade): name{name}, grade {grade}{};
        ~database_entry() = default;
        };

	void add_entry(std::string name, int grade);
	void remove_entry(std::string name);
	void modify_entry(std::string name);
	std::vector<database_entry> get_entries();

    friend std::ostream& operator<< (std::ostream& out, const database_entry& v)
    {
        out << "Student's name: " << v.name << "\tGrade: " << v.grade << "\n";
        return out;
    }
    friend std::istream& operator>> (std::istream& in, database_entry& v)
    {
        std::cout << "Enter Student's name: ";
        in >> v.name;
        std::cout << "Enter Student's grade: ";
        in >> v.grade;
        return in;
    }
    friend void operator>> (database_entry& in, database_entry& v)
    {
        v.name = in.name;
        v.grade = in.grade;
    }
};

