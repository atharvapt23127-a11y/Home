#include<iostream>
using namespace std;


int main(){

int n , capacity;
cout<<"Enter Total Item : ";
cin>>n;

 int weight[n], val[n];
 double ratio[n];

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


 for (int i = 0; i < n; i++) {
        ratio[i] = (double)val[i] / weight[i];
    }

 cout<<"\nThe ratio of each Item is : \n";
for(int i=0; i<n; i++){
 cout<<ratio[i]<<"  ";
}


for(int i=0; i<n-1; i++){
  for(int j=0; j<n-1-i; j++){
    if(ratio[j] < ratio[j+1]){
    
     // swap ratio.
     
     int tempRatio = ratio[j];
     ratio[j] = ratio[j+1];
     ratio[j+1] = tempRatio;
     
     // swap weight 
     
     int tempWeight = weight[j];
     weight[j] = weight[j+1];
     weight[j+1] = tempWeight;
     
     // swap value
     
     int tempVal = val[j];
     val[j] = val[j+1];
     val[j+1] = tempVal;
    
    }
  }
}

double totalVal = 0.0;
int currentWeight = 0;

for(int i=0; i<n; i++){
  if(currentWeight + weight[i] <= capacity){
    currentWeight += weight[i];
    totalVal += val[i];
  }else{
    int remain = capacity - currentWeight; 
    totalVal += val[i] * ((double)remain / weight[i]);
    break;
  }
}

cout<<"\nMax Value in Knapsack : "<<totalVal<<"\n";


return 0;
}
