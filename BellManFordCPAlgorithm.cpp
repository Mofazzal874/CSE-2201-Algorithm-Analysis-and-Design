#include<bits/stdc++.h>
using namespace std;
#define int long long
template<typename T>
using min_heap = priority_queue<T , vector<T> , greater<T>> ; //to make minHeap. min_heap<type> name
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);


void BellmanFord(int n ,vector<vector<int>> &adjL, int source){

    vector<int> dist(n, 1e8) ; //put n+1 if the graph starts from 1(not 0)
     
    vector<int> parent(n,-1) ;// put n+1 if the graph starts from 1(not 0)
    dist[source] = 0 ;
    int x ;  
    while(n--){
        x=-1 ; 
        for(auto it: adjL){
            int u = it[0]  ; 
            int v = it[1]  ; 
            int wt = it[2] ;
            if(dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
                parent[v] = u ; 
                x = v ;     
            }

        }
    }
    if(x==-1) {
        cout<<"No negative cycle from "<<source<<endl;
        cout<<"distance array:"<< endl;
        for(auto it:dist)cout<<it<<" " ;

    }
    else {
    int y = x ; 
    for(int i = 0 ; i < n ;i++){
        y = parent[y] ; 
    }
    
    vector<int> nCycle ;
    int cur = y ;
    nCycle.push_back(cur) ; 
    cur = parent[cur] ;  
    while(cur != y){
        nCycle.push_back(cur) ; 
        cur = parent[cur] ;   
    } 
    reverse(nCycle.begin(),nCycle.end()) ; 
    cout<<"Negative cycle: " ; 
    for(auto it:nCycle) cout<<it<<" " ;
    cout<<endl;
    cout<<"distance array:"<< endl;
    for(auto it:dist)cout<<it<<" " ; 

    }
              
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