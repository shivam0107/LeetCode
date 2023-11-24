class Solution {
public:
    int ways = 0;
     int solve2(int col , vector<int> &leftrow , vector<int> &upperDiagonal , vector<int> &lowerDiagonal  , vector<string> &board , int n){
        //base case
        if(col == n){
            
            return ways+1;
        }

        for(int row = 0; row<n; row++){
            if(leftrow[row] == 0 && upperDiagonal[row+col] == 0 && lowerDiagonal[n-1 + col - row] == 0){
                board[row][col] = 'Q';
                leftrow[row] = 1;
                upperDiagonal[row+col] = 1;
                lowerDiagonal[n-1 + col - row] = 1;
                ways = solve2(col+1 , leftrow , upperDiagonal , lowerDiagonal , board  , n);
                board[row][col] = '.';
                leftrow[row] = 0;
                upperDiagonal[row+col] = 0;
                lowerDiagonal[n-1 + col - row] = 0;

            }
        }
    return ways;
      
    }


    int totalNQueens(int n) {
        
       
        vector<string> board(n);

        string s(n , '.');
        for(int i = 0; i<n; i++){
            board[i] = s;

        }

        vector<int> leftrow(n , 0) , upperDiagonal(2*n-1 , 0), lowerDiagonal(2*n-1 , 0);
        

        // solve(0 , board, ans , n);//take more complexity
        //by hashing better complexity
       return solve2(0 , leftrow , upperDiagonal , lowerDiagonal , board  , n);
       
    }
};