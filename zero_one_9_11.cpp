#include<iostream>
using namespace std;

int max(int a , int b){
 if(a>b){
  return a;
 }else{
  return b;
 }
}

int knapsack(int n , int capacity , int val[] , int weight[]){
  int dp[n+1][capacity+1];
  
  for(int i=0; i<=n; i++){
     for(int j=0; j<=capacity; j++){
       
       if(i == 0 || j == 0){
        dp[i][j] = 0;
       }else if(weight[i-1] <= j){
         dp[i][j] = max(val[i-1]+dp[i-1][j - weight[i-1]] , dp[i-1][j]);
       }else{
        dp[i][j] = dp[i-1][j];
       }
     
     }
  }
  
  
  cout<<"Max Profit : "<<dp[n][capacity]<<"\n";
  
  for(int i=n; i>0; i--){
   if(dp[i][capacity] != dp[i-1][capacity]){
     cout<<"Item : "<<i<<" of weight : "<<weight[i-1]<<" and  value : "<<val[i-1]<< " is Included \n";
     capacity -= weight[i-1];
   }
  }
  
  return dp[n][capacity];
}

int main(){

int n , capacity;
cout<<"Enter Total Item : ";
cin>>n;

int weight[n], val[n];
 
cout<<"Enter Weight ff each Item : ";
for(int i=0; i<n; i++){
 cin>>weight[i];
}

cout<<"Enter value of each Item : ";
for(int i=0; i<n; i++){
 cin>>val[i];
}
cout << "Enter knapsack capacity: ";
cin >> capacity;

knapsack(n,capacity,val,weight);
return 0;
}
