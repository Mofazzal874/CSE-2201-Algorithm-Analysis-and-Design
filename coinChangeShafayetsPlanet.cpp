#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define pii pair<int,int>
template<typename T>
using min_heap = priority_queue<T , vector<T> , greater<T>> ; //to make minHeap. min_heap<type> name
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);


int n ; 

int f(int i, int W,vector<int> &coins , vector<vector<int>> &dp) {
    if (W < 0) return 1e9;
    if (i == n) {
        if (W == 0) return 0;
        return 1e9;
    }
    
    
    if (dp[i][W] != -1) return dp[i][W];
    
    int res_1 = 1 + f(i +1, W - coins[i] , coins , dp); //if the coin number is unlimited , then change i+1 to i 
    int res_2 = f(i + 1, W , coins , dp);
    
     return dp[i][W] = min(res_1, res_2);
}

int main(){

    cin>>n ;
    vector<int> coins(n); 
    for(int i = 0 ; i < n ; i++) cin>>coins[i] ; 
    int w ; cin>>w ;
    vector<vector<int>> dp(n , vector<int>(w+1 , -1)) ;  
    int ans = f(0 , w , coins , dp) ;
    if(ans ==1e9) cout<<"Not possible\n" ;
    else cout<<ans<<endl;

    
 
}