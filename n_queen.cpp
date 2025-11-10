#include<iostream>
using namespace std;

const int MAX = 20;
int board[MAX][MAX];
int n;
int ns = 0;

void printBoard(){
 cout<<"Solution : "<<ns<<"\n";
 
 for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(board[i][j] == 1){
        cout<<" Q ";
      }else{
        cout<<" . ";
      }
    }
    cout<<endl;
  }
 cout<<endl;
}

bool isSafe(int r , int c , int n){

// horizontally

for(int j=0; j<n; j++){
   if(board[r][j] == 1){
     return false;
   }
}

// vertically

for(int i=0; i<n; i++){
   if(board[i][c] == 1){
     return false;
   }
}

// upper left diagonal

for(int i=r-1 , j=c-1 ; i>=0 &&  j>=0  ; i--, j--){
  if(board[i][j] == 1){
    return false;
  }
}

// upper right diagonal

for(int i=r-1 , j=c+1 ; i>=0 &&  j<n  ; i--, j++){
  if(board[i][j] == 1){
    return false;
  }
}

return true;
}

void placeQueen(int r , int n){
  
  if(r==n){
    ns++;
    printBoard();
    return;
  }
  
  for(int c=0; c<n; c++){
    if(isSafe(r,c,n)){
      board[r][c] = 1;
      placeQueen(r+1,n);
      board[r][c] = 0;
    }
  }
}


int main(){

cout<<"Enter Size of Board : ";
cin>>n;
cout<<endl;

if(n > MAX){
cout<<"Enter Value of n <= MAX \n";
cout<<"Enter Size of Board : ";
cin>>n;
cout<<endl;
}

for(int i=0; i<n; i++){
  for(int j=0; j<n; j++){
    board[i][j] = 0;
  }
}


cout<<endl;
placeQueen(0,n);

cout<<"Total Solution are : "<<ns<<"\n";
return 0;
}
