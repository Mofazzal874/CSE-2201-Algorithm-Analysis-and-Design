#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
template<typename T>
using min_heap = priority_queue<T , vector<T> , greater<T>> ; //to make minHeap. min_heap<type> name
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);




//if you want to exclude some edges from the MST , and also calculate MST , this program can do that 
int prims(vector<vector<pii>> &adjL , int s ,vector<pii> &ex, int exNodes,    int n ){

    vector<bool> visited(n+1,0) ;
    int cost = 0 ; 
    min_heap<pii> pq ; 
    pq.push({0,s}) ;
    int counter = 0 ;  
    while(counter!=n){
        pii p = pq.top() ; 
        pq.pop() ; 
        int wt = p.first ; 
        int u = p.second ; 
        if(!visited[u]){
            visited[u] = 1; 
            counter++ ; 
            cost+=wt ; 
            for(pii v:adjL[u]) 
            {   pii q = {u,v.second} ; 
                if(find(ex.begin() , ex.end() , q)!=ex.end()) continue ; 
                else pq.push(v) ;
            }
        }
    }
    return cost ; 
}

int32_t main(){

    int n , m ; cin>>n>>m ;
    vector<vector<pii>> adjL(100) ;  
    for(int i = 0 ; i < m ; i++){
        int u , v, wt ; cin>>u>>v>>wt ; 
        adjL[u].push_back({wt,v}) ;
        adjL[v].push_back({wt,u}) ;
    }
    //Enter the number of edges that you want to avoid 
    int exEdges; cin>>exEdges ;
    //Enter Edges that you want to avoid while making the MST

    vector<pii> ex ;
    for(int i =0 ; i < exEdges ; i++) {
        int u  , v ;
        cin>>u>>v ; 
        ex.push_back({u,v}) ; ex.push_back({v,u}) ; 
    } 
    
    int s ; cin>>s; 
    cout<<prims(adjL ,s, ex ,exEdges , n ) ;
 
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
2
4 8
1 2
1
output:
40
*/