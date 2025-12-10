#include<bits/stdc++.h>
using namespace std;

bool canPlace(int** board, int n, int row, int col){

/// Check in column
for(int i=row-1;i>=0;i--){
    if(board[i][col] == 1){
        return false;
    }
}

/// Check in row
for(int i=col+1;i<n;i++){
    if(board[row][i] == 1){
        return false;
    }
}

/// Left Diagonal

for(int i=row-1, j = col-1;i>=0 && j >=0;i--, j--){
    if(board[i][j] == 1){
        return false;
    }
}

/// Right Diagonal
for(int i=row-1, j = col+1;i>=0 && j < n;i--, j++){
    if(board[i][j] == 1){
        return false;
    }
}

return true;
}

void nQueen(int** board, int n, int row){

 if(row ==n){
    /// Print Board

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"*******"<<endl;
    return;
 }

 for(int i=0;i<n;i++){
    if(canPlace(board, n, row, i) == true){
        board[row][i] = 1;
        nQueen(board, n, row + 1);
        board[row][i] = 0;
    }
 }
return;
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

    nQueen(board, n, 0);

return 0;
}
