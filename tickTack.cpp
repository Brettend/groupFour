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