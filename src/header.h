#ifndef LMS
#define LMS

#include <mysql.h>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <ctime>
#include <limits>


using namespace std;

struct connection_details
{
    string server= "sql11.freesqldatabase.com";
    string user = "sql11647459";
    string password = "ZLGYw14be4";
    string database = "sql11647459";
};

struct libraryMember
{
    string id;
    string first_name;
    string last_name;
};


struct result
{
    vector<vector<string>>row;
    vector<string> column;
    vector<int> columntype;
    int num_row=0;
    int num_colum=0;

    bool dispaly_all()
    {
        int choice;
        if(num_colum>0 && num_row>0)
        {
            for (size_t i = 0; i < num_row; i++)
            {
                for (size_t j = 0; j < num_colum; j++)
                {
                    cout << column[j] << " \t:\t " << row[i][j] << endl;
                }
            }
            cout << "0.back" << endl;
            if (!(cin>>choice))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            return true;
        }
        else
        {
            cout << "NOT FOUND!!" << endl;
            if (!(cin>>choice))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            return false;
        }

    }
    bool dispaly_all_row()
    {
        int choice;
        if(num_colum>0 && num_row>0)
        {
            for (size_t i = 0; i < num_row; i++)
            {
                cout << i+1 << ".";
                for (size_t j = 0; j < num_colum; j++)
                {
                    cout << row[i][j] << " ";
                }
                cout << endl;
            }
            cout << "0.back" << endl;
            return true;
        }
        else
        {
            cout << "NOT FOUND!!" << endl;
            if (!(cin>>choice))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            return false;
        }
    }
    bool dispaly_one(int index)
    {
        int choice;
        if(num_colum>0 && num_row>0)
        {
            for (size_t j = 1; j < num_colum; j++)
            {
                cout << column[j] << " \t:\t " << row[index][j] << endl;
            }
            cout << "0.back" << endl;
            if (!(cin>>choice))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            return true;
        }
        else
        {
            cout << "NOT FOUND!!" << endl;
            if (!(cin>>choice))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            return false;
        }

    }

};

result perform_query(string sql_query);
string get_id(string mysql_function);

void library_member();
void recommendation();
void browse(libraryMember libmem);
void search();
void browse_gener();
void browse_auther();
void search_by_id();
void search_by_title();
void search_by_isbn();
void search_by_author();


#endif
