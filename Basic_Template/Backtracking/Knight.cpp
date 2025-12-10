#include<bits/stdc++.h>
using namespace std;

bool canPlace(int** board, int n, int row, int col){

 return (row >= 0 && col >= 0 && row < n && col < n && board[row][col] == 0);

}

bool solve(int** board, int n, int move_no, int curRow, int curCol){

if(move_no == n*n){
    return true;
}

int dirX[] = {+2, +1, -1, -2, -2, -1, +1, +2};
int dirY[] = {+1, +2, +2, +1, -1, -2, -2, -1};

for(int i=0;i<8;i++){
    int nextRow = curRow + dirX[i];
    int nextCol = curCol + dirY[i];

    if(canPlace(board, n, nextRow, nextCol) == true){
        board[nextRow][nextCol] = move_no + 1;
        /// Call for rest of board
        bool smallAns = solve(board, n, move_no + 1, nextRow, nextCol);

        if(smallAns == true){
            return true;
        }
        else{
            board[nextRow][nextCol] = 0;
        }
    }
}
return false;
}

void printBoard(int** board, int n){

for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cout<<board[i][j]<<" ";
    }
    cout<<endl;
}
}

int main(){

int n;  cin>>n;

int** board = new int*[n];

for(int i=0;i<n;i++){
    board[i] = new int[n];
    for(int j=0;j<n;j++){
        board[i][j] = 0;
    }
}

board[0][0] = 1;  /// starting from (0,0)

bool ans = solve(board, n, 1, 0 ,0);

if(ans == true){
    printBoard(board, n);
}
else{
    cout<<"Sorry Can not visit all cells"<<endl;
}

}
