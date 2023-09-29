/*
Find the minimum number of coins required to make a value 'val'
->Given that you have a limited number of each types of coin
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
template<typename T>
using min_heap = priority_queue<T , vector<T> , greater<T>> ; //to make minHeap. min_heap<type> name
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);



vector<int> coins(1000); //coins array
vector<vector<int>> dp(1000 , vector<int>(1000, -1)) ; //memoization table
vector<int> cCount(1000) ; //count of each coins
vector<int> cVal(1005) ; //to keep track of each type used
int n ;  

int CoinChange(int i , int w  ){

    if(i == n ){ //base case
        if(w==0) return 0 ;
        return 1e9 ;  
    }
    
    if(dp[i][w]!=-1) return dp[i][w] ; 
    int notTake = CoinChange(i+1 , w) ; 
    int take = 1e9 ; 

    if(cVal[i+1] < cCount[i+1] && w >= coins[i+1]){
        take = 1+ CoinChange(i , w- coins[i+1]) ; 
    }
    return dp[i][w] = min(take, notTake) ; 

}

int32_t main(){


    cin>>n ;
    vector<int> coins(n); 
    for(int i = 0 ; i < n ; i++) cin>>coins[i] ;
    for(int i = 0 ; i < n ; i++) cin>>cCount[i] ;
    int w ; cin>>w ;
    vector<vector<int>> dp(n , vector<int>(w+1 , -1)) ;  
    int ans = CoinChange(0 , w ) ;
    if(ans ==1e9) cout<<"Not possible\n" ;
    else cout<<ans<<endl;


}