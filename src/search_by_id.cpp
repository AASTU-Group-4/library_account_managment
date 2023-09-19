#include "header.h"

void search_by_id()
{
    int choice;
    do
    {
        cout << "Enter Book_id:" << endl;
        cout << "0.back" << endl;

        if(cin >> choice)
        {
            system("cls");
            if (choice > 0)
            {
                result res2= perform_query("CALL get_book_by_id(" + to_string(choice) + ")");
                res2.dispaly_all();
                break;
            }
            else if(choice==0)
            {
                break;
            }
            else
            {
                system("cls");
                cout << "Invalid Choice" << endl;
            }

        }
        else
        {
            system("cls");
            cout << "Invalid Input" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (true);
}
