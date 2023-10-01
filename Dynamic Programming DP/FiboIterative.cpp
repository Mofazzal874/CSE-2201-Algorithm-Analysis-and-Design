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
//Above approch is time optimized but not space optimized.
//Below approach is both time and space optimized.In this approach , we are
//keeping track of the previous 2 fibonacci numbers

int fibo1(int n){
    int prev2 = 0 ; //the base condition
    int prev1 = 1 ; //the base condition
    for(int i = 2 ; i<=n ; i++){
        int curi=prev2+prev1 ; //to keep track of current fibo number 
        prev2 = prev1 ; 
        prev1 = curi ; 
    }

    return prev1 ; 

}

int32_t main(){
    cout<<fibo1(5)<<endl ;
}