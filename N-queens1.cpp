
#include<bits/stdc++.h>
using namespace std;
#define int long long
template<typename T>
using min_heap = priority_queue<T , vector<T> , greater<T>> ; //to make minHeap. min_heap<type> name
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL);


//8-queens problem
const int N = 8 ; 
bool board[N][N] ;




bool isSafe(int row , int col ){

    int r = row ; 
    int c = col ; 
    //as we are going only in the right of the board every time in recursion , so we need to check only three cases


    //case-01:check  all left(previous left sided rows) rows

    while(col>=0){
        if(board[row][col]) return false  ; //that means thers is a queen in the rows
        col-- ; 
    }
    col = c ; //restoring col value 

    //case-02:check all upper left diagonal
    while(row>=0 && col>=0){
        if(board[row][col]) return false ; 
        row-- ; col--; 
    }
    row = r; //restoring row value  
    col = c ; //restoring col value

    //case-03:check all lower left diagonal

    while(row<N && col>=0){
        if(board[row][col]) return false ; 
        row++ ; col--; 
    } 

    //all condition satisfied. so queen is safe to be places at board[row][col] position 
    return true;  
}



bool placeQueens(int col){


    if(col == N) return true; //we are outside of last column .That means our calculation should
                            //not go any further. So return true

    for(int row = 0 ; row < N ; row++){
        if(isSafe(row,col)){
            board[row][col] = true ; 
            if(placeQueens(col+1)) return true;   //if placeQueens for any column is returned false , that means for that column , we checked
                                                //all the rows in that column but do not find a suitable place for the queen in that column.
                                                //So we do not to proceed in this branch any further.for understanding , 
                                                //see-https://youtu.be/i05Ju7AftcM?list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&t=633 for explanation
                                                //else return true(means go further in that branch)
            board[row][col]= false ;//Backtracking part

        }
    }

    return false ; 
}


void printQueens(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(board[i][j]==0) cout<<".";
            else cout<<"Q";
        }
        cout<<endl;
    }
}

int32_t main(){

    placeQueens(0);
    printQueens() ; 
    
}