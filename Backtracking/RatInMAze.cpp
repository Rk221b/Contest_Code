#include<bits/stdc++.h>
using namespace std;

void allPossiblePath(int** maze, int n, int** solution, int x, int y){

  /// Base Case

  if(x == n-1 && y == n-1){
    ///print solution

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<solution[i][j]<<" ";
        }
        cout<<endl;
    }
    return;
  }

  /// Boundary Condition
  if(x < 0 || y < 0 || x >= n || y >= n || maze[x][y] == 0 || solution[x][y] == 1){
    return;
  }

  if(maze[x][y] == 1){
    solution[x][y] = 1;

    allPossiblePath(maze, n, solution, x - 1, y);
    allPossiblePath(maze, n, solution, x + 1 , y);
    allPossiblePath(maze, n, solution, x , y - 1);
    allPossiblePath(maze, n, solution, x , y + 1);

    solution[x][y] = 0;
  }

}

int main(){

int n;  cin>>n;
int tmp;

int** maze = new int*[n];
for(int i=0;i<n;i++){
    maze[i] = new int[n];
    for(int j=0;j<n;j++){
        cin>>tmp;
        maze[i][j] = tmp;
    }
}

int** solution = new int*[n];
for(int i=0;i<n;i++){
    solution[i] = new int[n];
    for(int j=0;j<n;j++){
        solution[i][j] = 0;
    }
}

allPossiblePath(maze, n, solution, 0 ,0);

return 0;
}
