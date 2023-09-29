#include<bits/stdc++.h>
using namespace std;
#define int long long
template<typename T>
using min_heap = priority_queue<T , vector<T> , greater<T>> ; //to make minHeap. min_heap<type> name
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);


#define N 100 

vector<int> dp(N+1 , -1) ; 

int fibo(int n ){
    if(n==0|| n==1) return n ; 
    if(dp[n]!=-1) return dp[n] ; 
    return dp[n] = fibo(n-1)+fibo(n-2) ; 
}

int32_t main(){


    cout<<fibo(5)<<endl;
    
}