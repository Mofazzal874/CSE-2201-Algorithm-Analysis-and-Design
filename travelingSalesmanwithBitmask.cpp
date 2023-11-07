#include<bits/stdc++.h>
using namespace std;
#define int long long
template<typename T>
using min_heap = priority_queue<T , vector<T> , greater<T>> ; //to make minHeap. min_heap<type> name
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL);





//video link -https://youtu.be/JE0JE8ce1V0?si=JcuAhaZsuucJWc7m
int n = 4 ; 
int dist[10][10] = {
    {0,20,42,25}, 
    {20,0,30,34},
    {42,30,0.10},
    {25,34,10,0}

} ;

int dp[16][4] ; 

int visited_all = (1<<n)-1 ; //1111 to indicate all cities visited

int tsp(int mask , int pos){
//mask-denotes set of cities visited so far
//pos-position of current city

    //base case
    if(mask == visited_all){
        return dist[pos][0] ;
        //current city theke starting city te zawar distance 
    }

    //lookup 
    if(dp[mask][pos]!=-1) return dp[mask][pos] ; 

    int ans = INT_MAX ; //as we need minimum , so it is safe to assume ans as maximum for safety 
    //try to goto an unvisited city
    for(int city = 0 ; city<n ; city++) {
        if((mask&(1<<city))==0){

            //if the current bit is not visited, 
            //then try to guess what is the answer from that city to the new unvisited city
            int newAns = dist[pos][city] + tsp((mask|(1<<city)) , city) ; 
                        //distance of going from current city to new city + remainging distance(change the mask, new city)
            ans = min(ans , newAns)  ; 
        }
    }
    return dp[mask][pos] =  ans ; 
}

int32_t main(){


    for(int i = 0 ; i <(1<<n) ; i++){
        for(int j =0 ; j <n ; j++){
            dp[i][j] = - 1; 
        }
    }
    cout<<tsp(1,0)<<endl;
    return 0 ; 

    
}