//this is an implementation on 0_1_knapsack problem
#include<bits/stdc++.h>
using namespace std;
#define int long long
template<typename T>
using min_heap = priority_queue<T , vector<T> , greater<T>> ; //to make minHeap. min_heap<type> name
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);


int knapSack(int ind , int w , vector<int>& weights , vector<int>&values , vector<vector<int>>& dp){
    
    if(ind==0){
        if(weights[0]<=w) return values[0] ; 
        else return 0 ; 
    }
    if(dp[ind][w]!=-1) return dp[ind][w] ; 
    int notTake = 0 + knapSack(ind -1 , w , weights , values , dp ) ; 
    int take = INT_MIN ; 
    if(weights[ind]<=w) take = values[ind]+knapSack(ind-1 , w-weights[ind] , weights , values , dp) ;  
    return dp[ind][w] = max(take  , notTake) ;    

}

int32_t main(){
    int t; cin>>t ;
    while(t--){
        int n ;cin>>n ; 
        vector<int> weights(n) , values(n)  ;
        for(auto &it:weights) cin>>it ; 
        for(auto &it:values) cin>>it;
        int w ; cin>>w ; 
        vector<vector<int>> dp(n+1 , vector<int>(w+1 , -1))  ;
        cout<<knapSack(n-1, w , weights , values, dp)<<endl; 

    }
    
}
/*
input:

1 
4
1 2 4 5
5 4 8 6
5
output:
13
*/