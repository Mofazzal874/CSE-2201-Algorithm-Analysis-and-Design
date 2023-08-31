#include<bits/stdc++.h>
using namespace std;
#define int long long
template<typename T>
using min_heap = priority_queue<T , vector<T> , greater<T>> ; //to make minHeap. min_heap<type> name
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);



void print(int numNodes, vector<vector<int>> &adjL){
    for(int i = 1 ; i <= numNodes; i++){
        for(int j = 1 ; j <= numNodes ; j++ ){
            if(adjL[i][j] == 1e8) cout<<"INF"<<" " ;
            else cout<<adjL[i][j]<<" " ;
        }
        cout<<endl;
    }
}


void fWarshall(int n ,vector<vector<int>> &cost ){

    for(int k = 1 ; k <= n ;k++){
        for(int i = 1; i <= n ; i++){
            for(int j = 1; j <= n ; j++){
                if((cost[i][k] + cost[k][j] < cost[i][j] )&& (cost[i][k] != 1e8 && cost[k][j]!= 1e8)){
                    cost[i][j] = min(cost[i][j] ,cost[i][k] + cost[k][j]) ;
                }
            }
        }
    }
    print(n, cost) ;

}


int32_t main(){

    int numNodes,numEdges ;
    cin>>numNodes>>numEdges; 
    vector<vector<int>> cost(numNodes+1 , vector<int> (numNodes+1 , 1e8)) ;
   
    for(int i = 1 ; i <= numNodes; i++){
        for(int j = 1 ; j <= numNodes ; j++ ){
            if(i == j) cost[i][j] = 0 ; 
        }
    }
    while(numEdges--){
        int u , v, wt ;
        cin>>u>>v>>wt ;   
        cost[u][v] = wt ; 
    }
    
    //print(numNodes , cost);
    fWarshall(numNodes, cost) ;
    


    
}
