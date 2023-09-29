//this problem calculate the minimum coin required to make a target T

//condition_ there is infinite supply of coins

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
template<typename T>
using min_heap = priority_queue<T , vector<T> , greater<T>> ; //to make minHeap. min_heap<type> name
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
 

int coinchange(int i , int w , vector<int>&coins , vector<vector<int>> &dp){

    if(i==0){  //base case
        if(w%coins[0] ==0) return w/coins[0] ;  //we reached the first coin and if
                                                //we can divide w by it , then we need only w/coin[0] 
                                                //number of coins
        return 1e9 ; //we reached the first coins , yet the value of w is not zero , so it is not possible
                    //to find minimum coins to make w
    }
    if(dp[i][w]!=-1) return dp[i][w] ; 
    int notTake = 0 + coinchange(i-1, w , coins , dp) ; 
    int take = INT_MAX ; 
    if(coins[i]<=w) take = 1+coinchange(i, w-coins[i],coins , dp) ; //as we have unlimited coins , we will remain in the same position
    //if the coins number is limited , then change -
    //if(coins[i]<=w) take = 1+coinchange(i-1, w-coins[i],coins , dp) ;
    //all you need to change is the i part 

    return dp[i][w] = min(take, notTake) ; //return minimum number of coins in both of the cases

}

int32_t main(){
    int n ; cin>>n ; 
    vector<int> coins(n) ;  
    for(int i = 0 ; i < n ; i++)cin>>coins[i] ; 
    int w ; cin>>w ;
    vector<vector<int>> dp(n , vector<int>(w+1 , -1)) ;

    int ans = coinchange(n-1,w, coins , dp ) ;//we should from the last of the coins array
    if(ans >=1e9) cout<<"Not possible\n";
    else{
        cout<<ans<<endl;
    }

    
 
}