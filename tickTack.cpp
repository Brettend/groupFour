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

#include <iostream>
#include<string>
using std::string;
using namespace std;

char square[10] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};

int checkwin();
void board();

int main()
{
	int i,row,col;
    int player = 1;
    char pl='X';

    char mark;
    do
    {
        board();
        player=(player%2)?1:2;
        pl=(player==1)?'X':'O';
     
        cout << "Player "<< pl << ", please enter a row (0, 1 or 2):  ";
        cin >> row;
        cout << "Player "<< pl << ", please enter a column (0, 1 or 2):  ";
        cin >> col;

        mark=(player == 1) ? 'X' : 'O';

        if (row == 0 && col == 0){square[1] = mark;}
        else if (row == 0 && col == 1){square[2] = mark;}
        else if (row == 0 && col ==2){square[3] = mark;}

        else if (row == 1 && col == 0){square[4] = mark;}
        else if (row == 1 && col== 1){square[5] = mark;}
        else if (row == 1 && col == 2){square[6] = mark;}

        else if (row == 2 && col==0){square[7] = mark;}
        else if (row == 2 && col==1){square[8] = mark;}
        else if (row == 2 && col==2){square[9] = mark;}
        else
        {
            cout<<"Invalid move ";
            player--;
            cin.ignore();
            cin.get();
        }
        i=checkwin();
        player++;
    }while(i==-1);

    board();
    if(i==1)
        cout<<"==>\aPlayer "<<--player<<" win ";
    else
        cout<<"==>\aGame draw";

    cin.ignore();
    cin.get();
    return 0;
}

<<<<<<< HEAD
/*********************************************
    FUNCTION TO RETURN GAME STATUS
    1 FOR GAME IS OVER WITH RESULT
    -1 FOR GAME IS IN PROGRESS
    O GAME IS OVER AND NO RESULT
**********************************************/

int checkwin()
{
    //Horizontal testing below
    if ( (square[1] == square[2] && square[2] == square[3]) && (square[1]!=' ' && square[2]!=' ' && square[3]!=' ' ) ) return 1;
    else if ( (square[4] == square[5] && square[5] == square[6]) && (square[4]!=' ' && square[5]!=' ' && square[6]!=' ' )) return 1;
    else if ( (square[7] == square[8] && square[8] == square[9]) && (square[7]!=' ' && square[8]!=' ' && square[9]!=' ' ))return 1;

    //vertical testing below
    else if ( (square[1] == square[4] && square[4] == square[7]) && (square[1]!=' ' && square[4]!=' ' && square[7]!=' ' ))return 1;
    else if ( (square[2] == square[5] && square[5] == square[8]) && (square[2]!=' ' && square[5]!=' ' && square[8]!=' ' ))return 1;
    else if ( (square[3] == square[6] && square[6] == square[9]) && (square[3]!=' ' && square[6]!=' ' && square[9]!=' ' ))return 1;

    //Diagonal testing below 
    else if ( (square[1] == square[5] && square[5] == square[9]) && (square[1]!=' ' && square[5]!=' ' && square[9]!=' ' ))return 1;
    else if ( (square[3] == square[5] && square[5] == square[7]) && (square[3]!=' ' && square[5]!=' ' && square[7]!=' ' ))return 1;

    else if (square[1] != ' ' && square[2] != ' ' && square[3] != ' ' 
                    && square[4] != ' ' && square[5] != ' ' && square[6] != ' ' 
                    && square[7] != ' ' && square[8] != ' ' && square[9] != ' ')
        return 0;
    else
        return -1;
}
=======

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
    cout << "|  " << square[1] <<"  |  "<< square[2] << "  |  "<< square[3] <<"  |"<< endl;

    cout << "|_____|_____|_____|" << endl;
    cout << "|     |     |     |" << endl;

    cout << "|  " << square[4] <<"  |  " << square[5] << "  |  " << square[6] <<"  |"<< endl;

    cout << "|_____|_____|_____|" << endl;
    cout << "|     |     |     |" << endl;

    cout << "|  " << square[7] << "  |  " << square[8] << "  |  " << square[9] <<"  |"<< endl;

    cout << "|     |     |     |" << endl << endl;
}
//end of project
>>>>>>> board
