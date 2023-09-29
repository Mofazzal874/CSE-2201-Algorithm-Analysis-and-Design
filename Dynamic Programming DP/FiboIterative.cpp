#include<bits/stdc++.h>
using namespace std;
#define int long long
template<typename T>
using min_heap = priority_queue<T , vector<T> , greater<T>> ; //to make minHeap. min_heap<type> name
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);


int fibo(int n ){

    vector<int> dp(n+1 , -1) ; 
    dp[0]= 0 ; 
    dp[1] = 1 ; 
    for(int i = 2 ; i <= n ; i++){
        dp[i] = dp[i-1]+dp[i-2] ; 
    }

    return dp[n] ; 
}

int32_t main(){
    cout<<fibo(5)<<endl ;
}