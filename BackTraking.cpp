/*
Backtraking is useful when you have to find the all possible solution set
it is a brute force approach 
first imaging a state space tree or solution tree. Then create the function

*/



//video link:

// C++ program to print all 
// permutations with duplicates allowed 
#include <bits/stdc++.h> 
using namespace std; 

/* Function to swap values at two pointers */
void swap(char *x, char *y) 
{ 
	char temp; 
	temp = *x; 
	*x = *y; 
	*y = temp; 
} 

/* Function to print permutations of string 
This function takes three parameters: 
1. String 
2. Starting index of the string 
3. Ending index of the string. */
void permute(char *str , int l  , int r){


    if(l==r){
        cout<<str<<endl;
    }
    else {
        for(int i = l ; i <=r ; i++){
            swap((str+l) , (str+i)) ;
            permute(str , l+1,r) ; 
            swap((str+l) , (str+i) ) ;//Backtracking part
              //swaping a two times in the same index will give us the original string. This line is for backtrack

        }
    }
}

/* Driver program to test above functions */
int main() 
{ 
	char str[] = "ABC"; 
	int n = strlen(str); 
	permute(str, 0, n-1); 
	return 0; 
} 