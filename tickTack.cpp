// Selemela K.G
// 216807944

// Marakalla E.T
// 218125514

//Rakgoale BM 
//219677120

//Maphutha L 
//219666519

//Ramothwala L
// 214632225

//Kgole B
//218567177


//Game Rules
//Player 1 is represented by 'X' symbol on the board
//Player 2 is represented by 'O' symbol on the board

#include "pch.h"
#include <iostream>
#include<string>
using std::string;
using namespace std;
char square[10] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' };
int checkwin();
void board();

string winPlayer = "Draw";
char symbol;

//Testing for when a player wins
//Note the function 'checkwin()' returns a 1 to indicate that a player won the game
//We testing to enforce that there can only be one winner at a time per game ran. 
TEST(GameTest, SomePlayerWon) {
    cout << endl << endl;
    if (winPlayer != "Draw") {
        cout << "SOME PLAYER WON" << endl;
        ASSERT_EQ(checkwin(), 1);
    }
}

// We testing to enforce that player symbols are not swapped per game ran.
//Making sure that player 1 is always represented by the 'X' symbol on the board
//Testing if player 1 uses the symbol 'X' and if not the test fail
TEST(GameTest, WinTest_2) {
    if (winPlayer == "Player1") {
        ASSERT_EQ('X', symbol);
    }
}

// We testing to enforce that player symbols are not swapped per game ran.
//Making sure that player 2 is always represented by the 'O' symbol on the board
//Testing if player 2 uses the symbol 'O' and if not the test fails 
TEST(GameTest, WinTest_3) {
    if (winPlayer == "Player2") {
        ASSERT_EQ('O', symbol);
    }
}

//We testing to enforce that if neither player1 nor player2 won then the result will default to a draw. 
TEST(GameTest, DrawTest_1) {
    cout << "The winPlayer global variable must contain the value '-' when a draw has been reached";
    if (winPlayer != "Player1" && winPlayer != "Player2") {
        ASSERT_EQ(winPlayer, "Draw");
    }
    else {
        cout << "THE WINNER IS :" << winPlayer << endl;
    }
}
/////////////////////END OF UNIT TEST SECTION////////////////////



/////////This is the TIC TAC Game  section//////////////////////
int main(int argc, char** argv)
{

    int i, row, col;
    int player = 1;
    char pl = 'X';

    char mark;
    do
    {
        board();
        player = (player % 2) ? 1 : 2;
        pl = (player == 1) ? 'X' : 'O';

        cout << "Player " << pl << ", please enter a row (0, 1 or 2):  ";
        cin >> row;
        cout << "Player " << pl << ", please enter a column (0, 1 or 2):  ";
        cin >> col;

        mark = (player == 1) ? 'X' : 'O';

        if (row == 0 && col == 0) { square[1] = mark; }
        else if (row == 0 && col == 1) { square[2] = mark; }
        else if (row == 0 && col == 2) { square[3] = mark; }

        else if (row == 1 && col == 0) { square[4] = mark; }
        else if (row == 1 && col == 1) { square[5] = mark; }
        else if (row == 1 && col == 2) { square[6] = mark; }

        else if (row == 2 && col == 0) { square[7] = mark; }
        else if (row == 2 && col == 1) { square[8] = mark; }
        else if (row == 2 && col == 2) { square[9] = mark; }
        else
        {
            cout << "Invalid move ";
            player--;
            cin.ignore();
            cin.get();
        }
        i = checkwin();
        player++;
    } while (i == -1);

    board();
    if (i == 1) {
        cout << "==>\aPlayer " << --player << " win ";
        string str = to_string(player);
        winPlayer = "Player" + str;
        if (winPlayer == "Player1") { symbol = 'X'; }
        else if (winPlayer == "Player2") { symbol = 'O'; }
    }
    else {
        cout << "==>\aGame draw";
    }

    cin.ignore();
    cin.get();

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

/*********************************************
    FUNCTION TO RETURN GAME STATUS
    1 FOR GAME IS OVER WITH RESULT
    -1 FOR GAME IS IN PROGRESS
    O GAME IS OVER AND NO RESULT
**********************************************/

int checkwin()
{
    //Horizontal testing below
    if ((square[1] == square[2] && square[2] == square[3]) && (square[1] != ' ' && square[2] != ' ' && square[3] != ' ')) return 1;
    else if ((square[4] == square[5] && square[5] == square[6]) && (square[4] != ' ' && square[5] != ' ' && square[6] != ' ')) return 1;
    else if ((square[7] == square[8] && square[8] == square[9]) && (square[7] != ' ' && square[8] != ' ' && square[9] != ' '))return 1;

    //vertical testing below
    else if ((square[1] == square[4] && square[4] == square[7]) && (square[1] != ' ' && square[4] != ' ' && square[7] != ' '))return 1;
    else if ((square[2] == square[5] && square[5] == square[8]) && (square[2] != ' ' && square[5] != ' ' && square[8] != ' '))return 1;
    else if ((square[3] == square[6] && square[6] == square[9]) && (square[3] != ' ' && square[6] != ' ' && square[9] != ' '))return 1;

    //Diagonal testing below 
    else if ((square[1] == square[5] && square[5] == square[9]) && (square[1] != ' ' && square[5] != ' ' && square[9] != ' '))return 1;
    else if ((square[3] == square[5] && square[5] == square[7]) && (square[3] != ' ' && square[5] != ' ' && square[7] != ' '))return 1;

    else if (square[1] != ' ' && square[2] != ' ' && square[3] != ' '
        && square[4] != ' ' && square[5] != ' ' && square[6] != ' '
        && square[7] != ' ' && square[8] != ' ' && square[9] != ' ')
        return 0;
    else
        return -1;
}

/*******************************************************************
     FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
********************************************************************/

void board()
{
    system("cls");
    cout << "\n\n\tTic Tac Toe\n\n";

    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
    cout << endl;

    cout << "|     |     |     |" << endl;
    cout << "|  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << "  |" << endl;

    cout << "|_____|_____|_____|" << endl;
    cout << "|     |     |     |" << endl;

    cout << "|  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << "  |" << endl;

    cout << "|_____|_____|_____|" << endl;
    cout << "|     |     |     |" << endl;

    cout << "|  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << "  |" << endl;

    cout << "|     |     |     |" << endl << endl;
}
//end of project
