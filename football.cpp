#include <iostream>
#include <conio.h>
#include<windows.h>
using namespace std;
//---------------Data Structures-----------//
struct football
{
    string name;
    string position;
    int touchdowns;
    int catches;
    int passingYard;
    int receivingYard;
    int rushingYard;
};
int count = 0;
const int size = 10;
//-----------------Function Prototypes--------------//
void header();
int menu();
football addPlayer();
void show(football player);
void viewPlayer(football player[size]);
void search(football player[size]);
int finding(football player[size], string search);
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
main()
{
    system("cls");
    cout << endl;
    header();
    football player[size];
    int op;
    op = menu();
    system("cls");
    while (op<4)
    {
        header();
        if (op == 1)
        {
            player[count] = addPlayer();
            count++;
        }
        else if (op == 2)
        {
            viewPlayer(player);
        }
        else if (op == 3)
        {
            search(player);
        }
        system("cls");
        header();
        op = menu();
        system("cls");
    }
}
//----------------Function Definitions-----------//
void header()
{
    cout << endl;
    SetConsoleTextAttribute(hConsole, 3);
    cout << "\t\t----------------------------------------------------" << endl;
    cout << "\t\t|         Football Players Entering System         |" << endl;
    cout << "\t\t----------------------------------------------------" << endl;
    SetConsoleTextAttribute(hConsole, 15);
    cout << endl;
}
int menu()
{
    int a;
    cout << endl;
    SetConsoleTextAttribute(hConsole, 6);
    cout << "\t\t\t    ---------------------" << endl;
    cout << "\t\t\t    |     Main Menu     |" << endl;
    cout << "\t\t\t    ---------------------" << endl;
    cout << endl;
    SetConsoleTextAttribute(hConsole, 14);
    cout << "\t1. Add Player " << endl;
    cout << "\t2. View Player " << endl;
    cout << "\t3. Search Player" << endl;
    cout << "\t4. Exit" << endl;
    cout << endl;
    SetConsoleTextAttribute(hConsole, 15);
    cout << "  Select one option from menu_";
    cin >> a;
    cout << endl;
    cout << "\n   Press any Key to continue_";
    getch();
    return a;
}

football addPlayer()
{
    football player;
    cout << endl;
    cout << endl;
    SetConsoleTextAttribute(hConsole, 11);
    cout << "  Add Player  " << endl;
    cout << "---------------" << endl;
    cout << endl;
    cout << endl;
    SetConsoleTextAttribute(hConsole, 12);
    cout << "   Player Name : ";
    SetConsoleTextAttribute(hConsole, 15);
    cin.ignore();
    getline(cin, player.name);
    cout << endl;
    SetConsoleTextAttribute(hConsole, 12);
    cout << "   Position : ";
    SetConsoleTextAttribute(hConsole, 15);
    cin >> player.position;
    cout << endl;
    SetConsoleTextAttribute(hConsole, 12);
    cout << "   Number of Touchdowns : ";
    SetConsoleTextAttribute(hConsole, 15);
    cin >> player.touchdowns;
    cout << endl;
    SetConsoleTextAttribute(hConsole, 12);
    cout << "   Number of Catches : ";
    SetConsoleTextAttribute(hConsole, 15);
    cin >> player.catches;
    cout << endl;
    SetConsoleTextAttribute(hConsole, 12);
    cout << "   Number of Passing Yards  : ";
    SetConsoleTextAttribute(hConsole, 15);
    cin >> player.passingYard;
    cout << endl;
    SetConsoleTextAttribute(hConsole, 12);
    cout << "   Number of Receving Yards : ";
    SetConsoleTextAttribute(hConsole, 15);
    cin >> player.receivingYard;
    cout << endl;
    SetConsoleTextAttribute(hConsole, 12);
    cout << "   Number of Rushing Yards : ";
    SetConsoleTextAttribute(hConsole, 15);
    cin >> player.rushingYard;
    cout << endl;
    SetConsoleTextAttribute(hConsole, 2);
    cout << "\n    Player Added Succesfully" << endl;
    cout << endl;
    SetConsoleTextAttribute(hConsole, 15);
    cout << "\n  Press any Key to continue_";
    getch();
    return player;
}
void viewPlayer(football player[size])
{
    cout << endl;
    cout << endl;
    SetConsoleTextAttribute(hConsole, 11);
    cout << "  View Players " << endl;
    cout << "---------------" << endl;
    cout << endl;
    cout << endl;
    SetConsoleTextAttribute(hConsole, 2);
    cout << "  Name\t\tPosition\t\tTouchdowns\t\tCatches\t\tPassing Yard\t\tReceiving Yard\t\tRushing Yard" << endl;
    cout << endl;
    cout << endl;
    SetConsoleTextAttribute(hConsole, 15);
    for (int idx = 0; idx < count; idx++)
    {
        show(player[idx]);
    }
    cout << endl;
    cout << "\n   Press any Key to continue_";
    getch();
}
void show(football player)
{
    cout << " " << player.name << "   \t\t" << player.position << "      \t\t" << player.touchdowns << "       \t\t" << player.catches << "       \t\t" << player.passingYard << "         \t\t" << player.receivingYard << "         \t\t" << player.rushingYard << endl;
}
void search(football player[size])
{
    string search;
    cout << endl;
    cout << endl;
    SetConsoleTextAttribute(hConsole, 11);
    cout << "  Search Player" << endl;
    cout << "---------------" << endl;
    cout << endl;
    SetConsoleTextAttribute(hConsole, 12);
    cout << " Enter Player Name : ";
    SetConsoleTextAttribute(hConsole, 15);
    cin.ignore();
    getline(cin, search);
    int idx = 0;
    idx = finding(player, search);
    if (idx == 999)
    {
        cout << endl;
        cout << endl;
        cout << " Nothing Found" << endl;
        cout << endl; 
    }
    else
    {
        cout << endl;
        SetConsoleTextAttribute(hConsole, 2);
        cout << "  Name\t\tPosition\t\tTouchdowns\t\tCatches\t\tPassing Yard\t\tReceiving Yard\t\tRushing Yard" << endl;
        SetConsoleTextAttribute(hConsole, 15);
        cout << "\n";
        show(player[idx]);
    }
    SetConsoleTextAttribute(hConsole, 15);
    cout << "\n   Press any Key to continue_";
    getch();
}
int finding(football player[size], string search)
{
    int idx = 999;
    for (int i = 0; i < count; i++)
    {
        if (search == player[i].name)
        {
            idx = i;
            return idx;
        }
    }
}