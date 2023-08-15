// source:Shafayetsplanet
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);




#define infinity 1<<30  //taking 2^30 as infinity value

template<typename T>
using min_heap = priority_queue<T , vector<T> , greater<T>> ;//make it a min-heap.Means minimum element will be at the top.
    //Here, vector<pair<int,int>> This part specifies the underlying container that the priority queue uses to store elements. 
    //Here, a vector of pairs of integers is used as the container

vector<int> dijktra(int n , vector<pair<int,int>> adjL[] , int source, int dest){

    vector<int>dist(n+1, infinity);
    vector<int> parent(n+1) ;  
    min_heap<pair<int,int>>pq; 
    dist[source] = 0 ;
    pq.push({dist[source], source}) ;  
    while(!pq.empty()){
        int dis = pq.top().first; 
        int node = pq.top().second;  
        pq.pop() ; 
        for(auto it: adjL[node]){
            int adjNode = it.first ; 
            int adjWeight = it.second ; 
            //Relaxation
            if((dis + adjWeight) < dist[adjNode]){
                dist[adjNode] = (dis+adjWeight); 
                pq.push({dist[adjNode] , adjNode}) ;
                parent[adjNode] = node ;     
            }
        }
        
    }
    int temp = dest;
    cout<<dest<<" " ; 
    while(temp != parent[temp]){
        cout<<parent[temp]<<" ";
        temp = parent[temp] ; 
    }
    cout<<"\n" ; 
    return dist; 

}

int32_t main(){

    vector<pair<int,int>> adjL[10000] ; 
    cout<<"Enter the number of nodes and edges.\n" ;
    int numNodes , numEdges; 
    cin>> numNodes>>numEdges;
    cout<<"\nEnter nodes connections and their weights/costs:\n" ;  
    for(int i = 0 ;i <numEdges ; i++){
        int u , v, wt; 
        cin>>u>>v>>wt ;
        adjL[u].push_back({v,wt}) ; 
    }
    cout<<"Enter source Node from where you want to start: " ; 
    int source ; cin>>source ; 
    cout<<"to see the pathway from source to desired destination, enter your destination node:\n" ;
    int des ; cin>>des; 
    vector<int> v = dijktra(numNodes, adjL , source, des) ; 
    cout<<"The shortest path array is : " ; 
    for(auto it: v){
        cout<<it<<" " ; 
    }    
}

//input: 
// 5 16
// 0 1 4
// 0 2 4
// 1 0 4
// 1 2 2
// 2 0 4
// 2 1 2
// 2 3 3
// 2 4 1
// 2 5 6
// 3 2 3
// 3 5 2
// 4 2 1
// 4 5 3
// 5 2 6
// 5 3 2
// 5 4 3
// 0
// shortest path array is : 
// 0 4 4 7 5 8


/*footNote::


if you ever need to use min-heap , you doesn't need to write it in a tedious way like this_

                priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;

You can make a template and add it to the top of your code:

                template<typename T>
                using min_heap = priority_queue<T, vector<T>, greater<T>>;

Now you can declare a min heap of pairs of ints by writing:

                min_heap<pair<int, int>> q;

*/