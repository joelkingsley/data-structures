#include <iostream>
#include <vector>

#define INT_MAX 99999

using namespace std;

int minimumVertex(vector<int> dist,vector<bool> visited){
    int minDistance = INT_MAX;
    int minIndex = 0;
    
    for(int i=0;i<dist.size();i++){
        if(!visited[i] && dist[i] <= minDistance){
            minDistance = dist[i];
            minIndex = i;
        }
    }
    
    
    return minIndex;
}

void printSolution(vector<int> dist){
    for(int i=0;i<dist.size();i++){
        cout<<dist[i]<<endl;
    }
}

void dijsktra(vector< vector<int> > graph,int src){
    vector<int> dist;
    vector<bool> visited;
    
    for(int i=0;i<graph[0].size();i++){
        dist.push_back(INT_MAX);
        visited.push_back(false);
    }
    
    dist[src] = 0;
    
    
    for(int i=0;i<graph[0].size()-1;i++){
        
        int u = minimumVertex(dist,visited);
        
        visited[u] = true;
        
        for(int j=0;j<graph[0].size();j++){
            if(!visited[j] && graph[u][j] && dist[u]!=INT_MAX && dist[u]+graph[u][j]<dist[j]){
                dist[j] = dist[u] + graph[u][j];
            }
        }
        
    }
    
    printSolution(dist);
}

int main() {

	vector< vector<int> > graph = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
    dijsktra(graph,0);
	return 0;
}
