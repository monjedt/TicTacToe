// tictactoecpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//MADE BY monjed
#include <iostream>
#include<string>
using namespace std; 

bool isWin(string (&arr)[3][3], string symbol) {
    string Wx = "xxx"; 
    string Wo = "ooo"; 
    string win; 
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++) {
            win += arr[i][j];
            if (win == Wx || win == Wo)
            {
                return true; 
            }
        }
        win.clear();

    }
    return false;
}

bool isWin_Diagonal(string (&arr)[3][3], string symbol) {
    string Wx = "xxx";
    string Wo = "ooo";
    string win;
    for (int i = 0; i < 3; i++)
    {
        win += arr[i][i];
        if (win == Wx || win == Wo)
        {
            return true;
        }
    }
    return false;
}
void printGrid(string (&arr)[3][3]) {
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << " | " << arr[i][j];
        }
        cout << endl << "_______________" << endl;

    }
}
bool isEmptyANDupdateGrid(string position, string (&arr)[3][3], string symbol) {
for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++)
    {
        if (position == arr[i][j])
        {
            arr[i][j] = symbol;
            return true;
        }


    }

}
}


int main()
{
    char players[9] = { 'x','o','x','o','x','o','x','o','x' };
    string symbol;
    string position;
    string arr[3][3] = { {"A1","A2","A3"},
                         {"B1","B2","B3"},
                         {"C1","C2","C3"} };

    cout << "Tic Tac Toe game for 2 players, get ready! " << endl;
    cout << "for playing use (x) and (o) " << endl;
    cout << "the grid is constructed like this :" << endl;
    cout << "| A1 | A2 | A3 |" << endl << "_______________" << endl
        << "| B1 | B2 | B3 |" << endl << "_______________" << endl
        << "| C1 | C2 | C3 |" << endl;
    cout << "the game has started !!!!!!!!!!!" << endl;
    cout << "________________________________________________________" << endl;

    bool gameEnded = false;
    for (int i = 0; i < 9; i++)
    {
        bool flag = false;
        while (!flag)
        {
            printGrid(arr);
            cout << "player " << players[i] << " choose a position to play" << endl;
            symbol = players[i];
            cout << "Enter position : " << endl;
            cin >> position;
            flag = isEmptyANDupdateGrid(position, arr, symbol);
            // Check if position is already filled
            if (!flag) {
                cout << "Position is already filled! Please choose another position." << endl;
                continue; // Go back to the start of the loop to allow the player to choose again
            }
        }

        //check for winning
        bool winflag_x_y_axis = isWin(arr, symbol);
        bool winflag_diagonal = isWin_Diagonal(arr, symbol);

        if (winflag_x_y_axis || winflag_diagonal) {
            cout << "player " << players[i] << " won the game!" << endl;
            gameEnded = true;
            break;
        }
    }

    if (!gameEnded) {
        cout << "It's a draw!" << endl;
    }

    cout << "game has ended" << endl;

    return 0;
}
 