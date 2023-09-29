#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define pii pair<int,int>
#define pdd pair<double, double>
#define pdi pair<double, int>
template<typename T>
using min_heap = priority_queue<T , vector<T> , greater<T>> ; //to make minHeap. min_heap<type> name
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);


double length(pdd p1 , pdd p2){
    return sqrt((p2.first-p1.first)*(p2.first-p1.first) + (p2.second-p1.second)*(p2.second-p1.second)) ;   
}


double prims(vector<vector<pdi>> &adjL , int s , int n){

    vector<bool> visited(n,0) ; 
    double cost = 0.0 ;
    min_heap<pdi>pq ; 
    pq.push({0.0,s}) ; 
    int counter = 0 ; 
    while(counter!=n){
        pdi p = pq.top() ; 
        pq.pop() ; 
        double wt = p.first ; 
        int u = p.second ; 
        if(!visited[u]){
            visited[u] = 1 ; 
            counter++ ; 
            cost+=wt ; 
            for(auto v:adjL[u]) pq.push(v) ; 
        }

    }

    return cost ; 


}
int main(){

    fastio
    int t ; cin>>t ; 
    while(t--){ 
        int n ; cin>>n ;
        vector<pdd> points ; 
        for(int i = 0 ; i < n ;i++){
            double x , y ; cin>>x>>y ; 
            points.push_back({x,y}); 
        }
        vector<vector<pdi>> adjL(n*n+10);

        for(int i = 0 ; i < n ;i++){
            for(int j = i+1 ; j < n ; j++){
                double l = length(points[i] , points[j])  ; 
                // cout<<l<<endl;
                // cout<<endl;
                adjL[i].push_back({l , j}) ; 
                adjL[j].push_back({l , i}) ; 
            }
        }
        // for(auto it1:adjL){
        //     for(auto it:it1) cout<<it.first<<" "<<it.second<<endl;
        //     cout<<endl;
        // }
        cout<<setprecision(2)<<fixed<<prims(adjL, 1 ,n)<<"\n" ;
        if(t>0) cout<<"\n" ; 
    }
 
}
/*
input:
1

3
1.0 1.0
2.0 2.0
2.0 4.0
output:
3.41
*/