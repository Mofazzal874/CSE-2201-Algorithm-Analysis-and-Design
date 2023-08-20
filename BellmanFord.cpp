#include<bits/stdc++.h>
using namespace std;
#define int long long
template<typename T>
using min_heap = priority_queue<T , vector<T> , greater<T>> ; //to make minHeap. min_heap<type> name
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);



vector<int> BellmanFord(int n ,vector<vector<int>> &adjL, int source){


    vector<int> dist(n , 1e8) ;
    dist[source] = 0 ; 
    n-- ; 
    while(n--){
        for(auto it: adjL){
            int u = it[0]  ; 
            int v = it[1]  ; 
            int wt = it[2] ;
            if(dist[u]!=1e8 &&  dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt; 
            }

        }
    }
    //running iteration for Nth time to check if any negative cycle is there
    for(auto it: adjL){
            int u = it[0]  ; 
            int v = it[1]  ; 
            int wt = it[2] ;
            if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                return {-1} ; //return an array/vector which contains only -1   
            }

    } 
    return dist ; 
}

int32_t main(){


    vector<vector<int>> adjL ; 
    int numNodes , numEdges ; 
    cin>>numNodes>>numEdges ;
    for(int i = 0 ; i < numEdges ; i++){
        int u , v , wt ; cin>>u>>v>>wt; 
        vector<int> temp ;
        temp.push_back(u) ;
        temp.push_back(v) ;
        temp.push_back(wt) ;
        adjL.push_back(temp) ; 
    }
    int s ; cin>>s; 
    vector<int> v = BellmanFord(numNodes, adjL, s) ; 
    for(auto it:v) cout<<it<<" " ;
}