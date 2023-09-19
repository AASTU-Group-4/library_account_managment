#include "header.h"


void browse(libraryMember libmem)
{
    int choice;
    do
    {
        system("cls");
        cout << "Browse by:" <<endl;
        cout << "1. History" << endl;
        cout << "2. Genre" << endl;
        cout << "3. Author" << endl;
        cout << "4. all" << endl;
        cout << "0. Back" << endl;
        if(cin >> choice)
        {
            system("cls");
            if (choice==1)
            {
                result res= perform_query("CALL get_history(" + libmem.id + ")" );
                res.dispaly_all();
            }
            else if(choice ==2)
            {
               browse_gener();
            }
            else if(choice ==3)
            {
                browse_auther();
            }
            else if(choice ==4)
            {
                result res=perform_query("CALL all_book()");
                res.dispaly_all();
                break;
            }
            else if(choice ==0)
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
