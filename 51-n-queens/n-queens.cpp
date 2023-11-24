class Solution {
public:
    bool isSafe(int row , int col , vector<string> board, int n){
            //check upper diagonal
            int duprow = row;
            int dupcol = col;

            while(row>=0 && col >=0){
                if(board[row][col] == 'Q') return false;
                row--;
                col--;
            }

            col = dupcol;
            row = duprow;

            while(col >=0 ){
                if(board[row][col] == 'Q') return false;
                col--;

            }

            col = dupcol;
            row = duprow;

            while( row < n &&  col >=0 ){
                if(board[row][col] == 'Q') return false;
                col--;
                row++;

            }

            return true;
    }

    void solve(int col , vector<string> &board , vector<vector<string>> &ans , int n){
        //base case
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int row = 0; row<n; row++){
            if(isSafe(row , col , board , n)){
                board[row][col] = 'Q';
                solve(col+1 , board , ans , n);
                board[row][col] = '.';

            }
        }
    }

    void solve2(int col , vector<int> &leftrow , vector<int> &upperDiagonal , vector<int> &lowerDiagonal  , vector<string> &board , vector<vector<string>> &ans , int n){
        //base case
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int row = 0; row<n; row++){
            if(leftrow[row] == 0 && upperDiagonal[row+col] == 0 && lowerDiagonal[n-1 + col - row] == 0){
                board[row][col] = 'Q';
                leftrow[row] = 1;
                upperDiagonal[row+col] = 1;
                lowerDiagonal[n-1 + col - row] = 1;
    solve2(col+1 , leftrow , upperDiagonal , lowerDiagonal , board , ans , n);
                board[row][col] = '.';
                leftrow[row] = 0;
                upperDiagonal[row+col] = 0;
                lowerDiagonal[n-1 + col - row] = 0;

            }
        }
    }




    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);

        string s(n , '.');
        for(int i = 0; i<n; i++){
            board[i] = s;

        }

        vector<int> leftrow(n , 0) , upperDiagonal(2*n-1 , 0), lowerDiagonal(2*n-1 , 0);
        

        // solve(0 , board, ans , n);//take more complexity
        //by hashing 
        solve2(0 , leftrow , upperDiagonal , lowerDiagonal , board , ans , n);
        return ans;
    }
};