//Source :shafayetsplanet
//this is the simplest approach if you know BFS . But this is not an effective one.

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);



void BFSmodified(int g[][6] , int source){

        vector<int> dist(6,INT_MAX) ;
        dist[source] = 0 ; 
        queue<int> q ; 
        q.push(source) ; 
        while(!q.empty()){
            int u = q.front() ; 
            q.pop() ; 
            for(int v = 1 ; v <= 5 ; v++){
                if(g[u][v]!= 0 && dist[u] + g[u][v] < dist[v]) {
                    dist[v] = dist[u] + g[u][v] ; 
                    q.push(v) ; 
                }
            }
        }
    for(auto it: dist) cout<<it<<" " ; 

}

int32_t main(){

    int g[6][6] ;
    cout<<"Enter costs from one vertex to another(enter 0 if there is no connection) : " ; 
    for(int i = 0 ; i <=5 ;i++ ){
        for(int j = 0 ;j<= 5 ; j++){
            printf("From %lld to %lld :", i , j) ; 
            cin>>g[i][j] ; 
        }
    }
    int source ; 
    cout<<"Enter source node: " ; 
    cin>>source ; 
    BFSmodified(g,source) ;
    //for(auto it: v) cout<<it<<" " ;  
    


}





//output:
// Enter costs from one vertex to another(enter -1 if there is no connection) : From 0 to 0 :-1
// From 0 to 1 :-1
// From 0 to 2 :-1
// From 0 to 3 :-1
// From 0 to 4 :-1
// From 0 to 5 :-1
// From 1 to 0 :-1
// From 1 to 1 :-1
// From 1 to 2 :2
// From 1 to 3 :5
// From 1 to 4 :-1
// From 1 to 5 :-1
// From 2 to 0 :-1
// From 2 to 1 :-1
// From 2 to 2 :-1
// From 2 to 3 :1
// From 2 to 4 :-1
// From 2 to 5 :-1
// From 3 to 0 :-1
// From 3 to 1 :-1
// From 3 to 2 :-1
// From 3 to 3 :-1
// From 3 to 4 :3
// From 3 to 5 :-1
// From 4 to 0 :-1
// From 4 to 1 :-1
// From 4 to 2 :-1
// From 4 to 3 :-1
// From 4 to 4 :-1
// From 4 to 5 :-1
// From 5 to 0 :-1
// From 5 to 1 :-1
// From 5 to 2 :-1
// From 5 to 3 :-1
// From 5 to 4 :-1
// From 5 to 5 :-1
// Enter source node: 1

// 2147483647 0 2 3 6 2147483647