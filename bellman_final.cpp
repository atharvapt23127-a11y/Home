#include<iostream>
#include<limits.h>
using namespace std;

int main(){

int vertices ,edges;
cout<<"Enter Number of vertices : ";
cin>>vertices;

cout<<"Enter Number of edges : ";
cin>>edges;

int u[edges];
int v[edges];
int w[edges];

cout<<"each edge (u,v,w) \n";
for(int i=0; i<edges; i++){
 cin>>u[i]>>v[i]>>w[i];
}
int source;
cout<<"Enter Source : ";
cin>>source;

int dist[vertices];

for(int i=0; i<vertices; i++){
 dist[i] = INT_MAX;
}
dist[source] = 0;

// relax all edges 

for(int i=1; i<= vertices - 1; i++){
   for(int j=0; j< edges; j++){
     if(dist[u[j]] != INT_MAX && dist[u[j]] + w[j] < dist[v[j]]){
       dist[v[j]] = dist[u[j]] + w[j];
     }
   }
}

for(int j=0; j<edges; j++){
 if(dist[u[j]] != INT_MAX && dist[u[j]] + w[j] < dist[v[j]]){
      cout<<"\nGraph Contain negative weight Cycle\n";
      return 0;
     }
}

cout << "\nVertex\tDistance from Source\n";
    for (int i = 0; i < vertices; i++) {
        if (dist[i] == INT_MAX){
            cout << i << "\tINF\n";
        }else{
            cout << i << "\t" << dist[i] << "\n";
    }
}
return 0;
}


