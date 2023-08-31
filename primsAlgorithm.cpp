#include<bits/stdc++.h>
using namespace std; 
#define pii pair<int,int> 
int prims(vector<vector<pii>> &adjL , int src,int n ){

    int cost  = 0 ;
    bool vis[n+1] = {0} ; 
    priority_queue<pii,vector<pii>,greater<pii>>pq ; 
    pq.push({0,src}) ;
    int counter = 0 ; 
    while(counter!=n){
        pii p = pq.top() ;
        pq.pop() ; 
        int u = p.second ; 
        int wt = p.first ; 
        if(!vis[u]){
            vis[u] = 1 ; 
            cost+=wt ; 
            counter++ ; 
            for(pii v : adjL[u]){
                pq.push(v) ;
            }
        } 
    }
    return cost ; 
}

int main(){

    int n , m ; cin>>n>>m ; 
    vector<vector<pii>> adjL(100) ; 
    for(int i = 0 ; i < m ; i++){
        int u , v, wt ; 
        cin>>u>>v>>wt ; 
        adjL[u].push_back({wt,v}) ;
        adjL[v].push_back({wt,u}) ;
    }
    //setting source from node 5
    cout<<prims(adjL , 5 , n) ;

    
}