// TicTacToe.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
using namespace std;
void printGame(char grid[3][3]) {
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++)
            cout << char(grid[i][j])<<" ";
        cout << endl;
    }
};
bool isSameRow(char grid[3][3], int row, int col) {
    if (row == 1) {

        if (grid[row][col] != '_'&&grid[row][col] == grid[row + 1][col] && grid[row][col] == grid[row - 1][col]) {
            return true;
        }
    }
    else if(row==0) {

        if (grid[row][col] != '_' && grid[row][col] == grid[row + 1][col] && grid[row][col] == grid[row + 2][col]) {
            return true;
        }
    }
    else {

        if (grid[row][col] != '_' && grid[row][col] == grid[row - 1][col] && grid[row][col] == grid[row - 2][col]) {
            return true;
        }
    }

    return false;
}
bool isSameCol(char grid[3][3], int row, int col) {
    
    if (col == 1) {

        if (grid[row][col] != '_' && grid[row][col] == grid[row][col + 1] && grid[row][col] == grid[row][col - 1]) {
            return true;
        }
    }
    else if (col == 0) {

        if (grid[row][col] != '_' && grid[row][col] == grid[row ][col + 1] && grid[row][col] == grid[row][col + 2]) {
            return true;
        }
    }
    else {

        if (grid[row][col] != '_' && grid[row][col] == grid[row][col - 1] && grid[row][col] == grid[row ][col - 2]) {
            return true;
        }
    }

    return false;
}

bool isSameDiag(char grid[3][3], int row, int col) {
    if (row == col) {
        if (col == 1) {

            if (grid[row][col] != '_' && grid[row][col] == grid[row+1][col + 1] && grid[row][col] == grid[row-1][col - 1]) {
                return true;
            }
        }
        else if (col == 0) {

            if (grid[row][col] != '_' && grid[row][col] == grid[row+1][col + 1] && grid[row][col] == grid[row+2][col + 2]) {
                return true;
            }
        }
        else {

            if (grid[row][col] != '_' && grid[row][col] == grid[row-1][col - 1] && grid[row][col] == grid[row-2][col - 2]) {
                return true;
            }
        }
    }
    

    return false;
}


bool isGameEnded(char grid[3][3]) {

    bool isDraw = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (isSameRow(grid, i, j) || isSameCol(grid, i, j) || isSameDiag(grid, i, j)) {
                if (grid[i][j] == 'X') cout << "X is winner" << endl;
                else if (grid[i][j] == 'O') cout << "O is winner" << endl;
                return true;
            }
            else if (grid[i][j] == '_') isDraw = false;

        }
            
    }
    if (isDraw) {
        cout<< "The game is ended in a draw!" << endl;
        return true;
    }
    return false;
}
bool isCharSuitable(char ch) {
    if (!(ch == 'O' || ch == 'X')) {
        cout << "Please enter only O or X" << endl;

        return false;
    }
    return true;
}
void printTurn(bool& isX) {
    if (isX) {
        cout << "Turn for X";
        
    }
    else {
        cout << "Turn for O";
        
    }
}
void changeGrid(char grid[3][3], bool &isX, int x, int y) {
    if(grid[y - 1][x - 1] == '_'){
        if (isX) grid[y - 1][x - 1] = 'X';
        else grid[y - 1][x - 1] = 'O';
        isX = !isX;
    }
    else {
        cout << "The gap is already filled" << endl;
    }
}
int main()
{
    char grid[3][3] = { {'_','_','_'},{'_','_','_' },{'_','_','_' } };
    //printGame(grid);
    char ch; 
    bool isX = true;
    int x, y;
    bool isDraw  = false;
    while (!isGameEnded(grid)) {
        cout << "--------------------" << endl;
        printGame(grid);
        cout << endl;
        printTurn(isX);
        
        cout << endl <<"X-Y ->";
        cin >> x >> y;
        if (x > 3 || y > 3) continue;
        changeGrid(grid, isX, x, y);
        if (isDraw) break;
        cout << "--------------------" << endl <<endl;
    
    }
    printGame(grid);



    return 0;
}

