#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

const auto INF = INT_MAX;

/**
 * @Param graph the graph matrix 
 * @Param source start node 
 * @Param target end node 
 * node 0 ... n 
 * step 
 * 
 */
int dijkstra(vector<vector<int> >& graph,int target){
    int size = graph.size() > graph[0].size() ? graph.size() : graph[0].size();
    vector<int> dist; //distence  
    queue<int> waited; //should handle at the next round 

    dist.push_back(0); // from zreo node to zero node is zero 
    
    for(int i = 1;i < size;i++){
      dist.push_back(INF); // unreachable from zero node
      if(graph[0][i] >=0) dist[i] =  graph[0][i]; // if have weight then use this to init 
      waited.push(i);
    }

    while(!waited.empty()){
      auto node = waited.front;

      // check if there is a path from j to node graph[j][node]
      for(int j = 1;j < size;j++){

      }
    }

    return dist[target];
}


int main(){
  return 0;
}

