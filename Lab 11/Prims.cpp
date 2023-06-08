#include <iostream>
using namespace std;


void addEdge(vector<vector<int> >& adjMatrix,int u, int v,int w){
    adjMatrix[u][v]=w;
    adjMatrix[v][u]=w;
}

int findMinNode(vector<int> weights,vector<bool> visited,int V){
    int min=INT_MAX;
    int minIndex;
    for(int i=0;i<V;i++){
        if(visited[i]==false && weights[i]<min){
            min=weights[i];
            minIndex=i;

        }
    }
    return minIndex;

}

void Prims(vector<vector<int> >& adjMatrix,int V,int startNode){
    vector<bool> visited(V,false); // keep track the visited nodes
    vector<int> weights(V,INT_MAX);//weights of different nodes 
    weights[startNode]= 0; 
    vector<int> MST(V); // created MST use parent relationship. MST[i]=j j is the parent of i
    MST[startNode]=-1;

    //iterate for V-1 times since there are V-1 edges in MST
    for(int i=0;i<V-1;i++){
        int currentMin = findMinNode(weights,visited,V); //find minimum weight node
        visited[currentMin]= true ; 

        for(int j=0;j<V;j++){
            if(visited[j]==false && adjMatrix[currentMin][j]!=0 && adjMatrix[currentMin][j]<weights[j]){
                weights[j]=adjMatrix[currentMin][j];
                MST[j]=currentMin;
            }

        }


    } 
    //print MST
    cout<< "Edge        Weight"<<endl;
    for(int i=0;i<V;i++){
        if(i!=startNode){
            cout<<MST[i]<<" - "<<i<<"         "<<adjMatrix[i][MST[i]]<<endl;
        }       
    }    
}


int main(){
    int V=6; // number of vertices
    int startNode=0;
    vector<vector<int> > adjMatrix(V,vector<int> (V,0));
    addEdge(adjMatrix,0,5,1);
    addEdge(adjMatrix,0,1,3);
    addEdge(adjMatrix,1,2,2);
    addEdge(adjMatrix,2,3,3);
    addEdge(adjMatrix,3,4,5);
    addEdge(adjMatrix,4,5,4);
    addEdge(adjMatrix,1,4,10);
    addEdge(adjMatrix,2,5,5);
    addEdge(adjMatrix,1,3,1);

    Prims(adjMatrix,V,startNode);

}
