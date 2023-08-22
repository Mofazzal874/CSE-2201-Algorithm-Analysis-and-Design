#include<bits/stdc++.h>
using namespace std;
#define int long long
template<typename T>
using min_heap = priority_queue<T , vector<T> , greater<T>> ; //to make minHeap. min_heap<type> name
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);


void BellmanFord(int n ,vector<vector<int>> &adjL, int source){


    vector<int> dist(n , 1e8) ;
    vector<int> nCycle ; 
    vector<int> parent(n,-1) ; 
    dist[source] = 0 ; 
    while(n--){
        for(auto it: adjL){
            int u = it[0]  ; 
            int v = it[1]  ; 
            int wt = it[2] ;
            if(dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
                parent[v] = u ;  
            }

        }
    }
    int temp ; 
    for(auto it:parent){
        if(it!=-1) {temp = it;break;} 
    }
    int cur = temp; 
    nCycle.push_back(cur) ; 
    
    while(parent[cur]!= temp ){
        nCycle.push_back(parent[cur]) ;
        cur = parent[cur] ;  
    } 
    reverse(nCycle.begin(),nCycle.end()) ; 
    for(auto it:nCycle) cout<<it<<" " ;     
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
    BellmanFord(numNodes, adjL, s) ; 
    
}