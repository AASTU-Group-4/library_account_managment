#include "header.h"


void browse_auther()
{
    result res = perform_query("CALL get_author()");
    int choice;
    do
    {
        res.dispaly_all_row();

        if(cin >> choice)
        {
            system("cls");
            if (choice <= res.num_row && choice >0)
            {
                result res2= perform_query("CALL get_book_by_author(\"" + res.row[choice-1][0] + "\",\"" + res.row[choice-1][1] + "\")");
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
