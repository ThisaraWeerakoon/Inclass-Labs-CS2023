#include<iostream>
#include <queue>
using namespace std;


void dijkstraShortestPathFinder(int adjMatrix[6][6],int startNode,int V){
    //keep track the nodes that have been already preprocessed
    //each element in priority queue is as (distance from startNode to currentNode , currentNode)
    //This is a min priority queue
    priority_queue < pair < int, int >, vector < pair < int, int > > , greater< pair < int, int > > > preprocessedNodes ; 

    //start with pushing startNode 
    preprocessedNodes.push(make_pair(0,startNode));

    //keep track distances to each node from starting node.
    //Initialize all to Infinity
    vector<int> distances(V,INT_MAX);

    //Make startNode distance as 0
    distances[startNode]=0;
    

    //Until there are no more vertices to complete
    while(!preprocessedNodes.empty()){

        //Take minimum distance node
        int u=preprocessedNodes.top().second;
        preprocessedNodes.pop();

        for(int i=0;i<V;i++){
            //adjacent vertices
            if(adjMatrix[u][i]!=0){

                //relaxation
                if(distances[u]+adjMatrix[u][i]<distances[i]){
                    distances[i]=distances[u]+adjMatrix[u][i];
                    //insert relaxed node 
                    preprocessedNodes.push(make_pair(distances[i],i));
                }

            }
        }
    }

    //print shortest distance from startNode to eachNode
    cout<<"Starting from city "<<startNode<<endl;
    cout<<"Start City    To City        Time"<<endl;
    for(int i=0;i<V;i++){        
        cout<<startNode<<"             "<<i<<"               "<<distances[i]<<endl;
    }
}




int main(){
    int V = 6 ; //number of vertices
    //Adjacency matrix
    int adjMatrix[6][6]={{0,10,0,0,15,5},
                        {10,0,10,30,0,0},
                        {0,10,0,12,5,0},
                        {0,30,12,0,0,20},
                        {15,0,5,0,0,0},
                        {5,0,0,20,0,0}};
    
    //dijkstraShortestPathFinder(adjMatrix,0,6);
    //dijkstraShortestPathFinder(adjMatrix,1,6);
    //dijkstraShortestPathFinder(adjMatrix,2,6);
    //dijkstraShortestPathFinder(adjMatrix,3,6);
    //dijkstraShortestPathFinder(adjMatrix,4,6);
    dijkstraShortestPathFinder(adjMatrix,5,6);

}
