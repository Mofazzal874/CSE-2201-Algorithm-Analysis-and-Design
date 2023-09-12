#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int , string>
template<typename T>
using min_heap = priority_queue<T , vector<T> , greater<T>> ; //to make minHeap->min_heap<typename> anyname
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);



int maximum(vector<vector<string>> &adjL , int n , string s , string d ){

        unordered_map<string , bool> visited; 
        priority_queue<pii> pq ; 
        pq.push({0,s}) ; 
        vector<int> cost ;  
        while(pq.top().second!=d){
            pii p = pq.top() ; 
            int wt = p.first;
            string u  = p.second ;
            pq.pop() ; 
            if(!visited[u]){
                visited[u] = true; 
                cost.push_back(wt);
                for(auto it:adjL){
                    if(it[0] == u) pq.push({stoi(it[2]) , it[1]}) ;
                }
            }     
        }
    cost.push_back(pq.top().first) ; 
    // for(auto it: cost) cout<<it<<" " ; 
    // cout<<endl;
    return *min_element(cost.begin()+1, cost.end()) ;

}

int32_t main(){

    int t; 
    for(t=1 ;;t++){
        int n , m ; 
        cin>>n>>m ; 
        if(n == 0 && m == 0) break;  
        vector<vector<string>> adjL ; 
        for(int i = 0 ; i < m ; i++){
        string u , v , wt ;
        cin>>u>>v>>wt ; 
        adjL.push_back({u,v,wt}) ; 
        adjL.push_back({v,u,wt}) ; 
        }
        string source ,des ;cin>>source>>des ; 
        cout<<"Scenario #"<<t<<"\n"<<maximum(adjL , n , source , des )<<" tons\n\n";
    }
    return 0 ; 
 
}




/*input:
4 3
Karlsruhe Stuttgart 100
Stuttgart Ulm 80
Ulm Muenchen 120
Karlsruhe Muenchen
5 5
Karlsruhe Stuttgart 100
Stuttgart Ulm 80
Ulm Muenchen 120
Karlsruhe Hamburg 220
Hamburg Muenchen 170
Muenchen Karlsruhe
0 0
output:
Scenario #1
80 tons
Scenario #2
170 tons
*/