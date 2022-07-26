#include <bits/stdc++.h>

#include <iomanip>
using namespace std;

int main()
{

    // clrscr();
    float balance1;
    int i, pin, new_pin, option;
    double balance = 20000;
    double withdraw, deposit;
    char input;

    // clrscr();
    cout << "\t\t\t **************  **************  **************  " << endl;
    cout << "\t\t\t **************  **************  **************  " << endl;
    cout << "\t\t\t       **              **              **        " << endl;
    cout << "\t\t\t       **              **              **        " << endl;
    cout << "\t\t\t       **              **              **        " << endl;
    cout << "\t\t\t       **              **              **        " << endl;
    cout << "\t\t\t       **              **              **        " << endl;
    cout << "\t\t\t       **              **              **        " << endl;
    cout << "\t\t\t **************  **************        **        " << endl;
    cout << "\t\t\t **************  **************        **        " << endl;
    cout << "\t\t=======================================================" << endl;
    cout << "\t\t\t  Welcome To [ IIT ROPAR SBI ATM ] Service        " << endl;
    cout << "\t\t\t\t    Designed By:" << endl;
    cout << "\t\t\t\t    **** AKASH **** " << endl;
    cout << "\t\t=======================================================" << endl;

    ifstream hin("atm.txt");
    hin>>new_pin;


    cout << "\t\t\t\t***** PIN FOR USER IS "<<new_pin<<"  ****" << endl;

    cout << "\n\t\t\t\t\t  ## WELCOME USER ##" << endl;

    for (int i = 0; i <= 2; i++)
    {
        cout << "\t\t\t\t\t  Enter Your Pin:";
        cin >> pin;

        balance1 = balance;
        if (pin == new_pin)
        {

            goto repeat;

        statement:
            cout <<"\t--->>Press 'Y' if you wish to proceed further  or 'N' to exit the process<<---" << endl;
            cin >> input;
            if (input == 'Y' || input == 'y')
            {
                goto repeat;
            }
            else if (input == 'N' || input == 'n')
            {
                exit(0);
            }
            else
            {
                cout << "Wrong input given" << endl;
                goto statement;
            }

        repeat:

            for (i = 0; i <= 2; i++)
            {
                cout << "\n\n";
                cout << "\t\t\t\t***************************************" << endl;
                cout << "\t\t\t\t  *** Automated Teller Machine ***" << endl;
                cout << "\t\t\t\t***************************************" << endl;
                cout << "\t\t\t\t*            Main Menu           *" << endl;
                cout << "\t\t\t\t***************************************" << endl;
                cout << "\t\t\t\t*       1 - View My Balance           *" << endl;
                cout << "\t\t\t\t*       2 - Withdraw Cash             *" << endl;
                cout << "\t\t\t\t*       3 - Deposit Funds             *" << endl;
                cout << "\t\t\t\t*       4 - Change Pin                *" << endl;
                cout << "\t\t\t\t*       5 - Exit                      *" << endl;
                cout << "\t\t\t\t***************************************" << endl;

                cout << "\t\t\t\t***************************************" << endl;
                cout << "\n";

                cout << "\t\t\t\t        Enter Option: ";

                cin >> option;
                switch (option)
                {
                case 1:

                    cout << "\n\t\t\t\t [[[% BALANCE INQUIRY %]]]\n\n";

                    cout << "\t\t\t\t***********************************" << endl;

                    cout << "\t\t\t\t  Your Balance Is: rs " << balance1 << endl;

                    cout << "\t\t\t\t***********************************" << endl;

                    goto statement;
                    break;

                case 2:

                    cout << "\n\t\t\t   [[[% WITHDRAW %]]]";
                    cout << "\n\t\t\t Enter amount in Rupees: ";
                    cin >> withdraw;
                    if (withdraw <= balance1)
                    {
                        balance1 = balance1 - withdraw;
                        cout << "\t\t\t You withdrew RS: " << withdraw << endl;
                        cout << "\t\t\t Your remaining balance is RS: " << balance1 << endl;
                    }
                    else
                    {
                        cout << "\t\t!! Sorry !! You have only Rs" << balance1 << " balance in your account. !!" << endl;
                    }

                    goto statement;
                    break;

                case 3:
                    cout << "\n\t\t\t  [[[% DEPOSIT %]]]\n";
                    cout << "\n\t\t\t Enter amount in RS: ";
                    cin >> deposit;
                    balance1 = balance1 + deposit;
                    cout << "\n\t\t\t You deposited RS: " << deposit << endl;
                    cout << "\n\t\t\t Your new balance is RS: " << balance1 << endl;

                    goto statement;
                    break;

                case 4:
                pinchange:
                    cout << "\n\t\t\t Enter Your Old Pin: ";
                    cin >> pin;
                    if (pin == new_pin)
                    {
                        ofstream hout("atm.txt");
                        cout << "\t\t\t Enter New Pin: ";
                        cin>>new_pin;
                        hout << new_pin;
                        hout.close();
                        cout << "\n\t\t\t Pin Changed Sucessfully." << endl;
                    }
                    else
                    {
                        cout << "\n\t\t\t Wrong Pin !! Enter Pin Again.\n";
                        goto pinchange;
                    }

                    goto statement;
                    break;

                case 5:
                    exit(0);
                    break;

                default:
                    cout << "\n\t\t That is an invalid option Plz enter correct option. \n";

                    break;
                }
            }
        }

        else

            cout << "\t\t\tPls try again!!! Wrong pin entered.\n\n";
    }
    return 0;
}
