#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
template<typename T>
using min_heap = priority_queue<T , vector<T> , greater<T>> ; //to make minHeap, min_heap<type> name
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);




int prims(vector<vector<pii>> &adjL , int s , int n ){

    vector<bool>vis(n+1);
    min_heap<pii> pq ; 
    pq.push({0,s}) ;
    int counter = 0 ; 
    int cost = 0 ;   
    while(counter!=n){
        pii p = pq.top() ; 
        pq.pop();
        int u =p.second ; 
        int wt = p .first ; 
        if(!vis[u]){
            vis[u] = true ;
            counter++ ;
            cost+=wt ; 
            for(auto edges:adjL[u]){
                pq.push(edges) ; 
            }  

        }

    }
    return cost; 
}

int32_t main(){


    int n , e ; cin>>n>>e;
    vector<vector<pii>> adjL(1000) ;//with maximum 1000 nodes  
    for(int i = 0 ; i < e ; i++){
        int u , v  , wt ; cin>>u>>v>>wt ;
        adjL[u].push_back({wt,v}) ; 
        adjL[v].push_back({wt,u}) ; 
    }
    int source ; cin>>source ; 
    cout<<prims(adjL , source, n) ; 

    
 
}
/*
input:
8 11
1 5 2
1 4 10
1 2 4
2 4 8
2 3 18
3 4 11
4 5 5
4 7 11
4 8 9
6 7 1
6 8 2
5
output:
34*/


