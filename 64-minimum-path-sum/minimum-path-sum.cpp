class Solution {
public:

    int mini = INT_MAX;

    int f(int i , int j ,vector<vector<int>>& grid  , vector<vector<int>> &dp){
        if(i == 0 && j == 0) return grid[i][j];

        if(i < 0 || j < 0) return 1e9;

        if(dp[i][j] != -1) return dp[i][j];

        int r = grid[i][j]+f(i-1 , j , grid , dp);
        int b = grid[i][j]+f(i , j-1 , grid , dp);

        return dp[i][j] =  min(b , r); 

    }

     int fTab(int m , int n ,vector<vector<int>>& grid){
         vector<vector<int>> dp(m+1 , vector<int>(n+1 , INT_MAX));
        
          for(int i = 0; i<=m; i++){
            for(int j = 0; j<= n; j++){

                if(i == 0 && j == 0){
                      dp[0][0] = grid[0][0];
                }
                else{
                      int up = INT_MAX;
                      int left = INT_MAX;
                      if(i > 0){
                          up = grid[i][j] + dp[i-1][j] ;
                         
                      }
                      if(j > 0){
                          left = grid[i][j] + dp[i][j-1];
                      }


                      dp[i][j] = min(up , left);
                }
            }
        }
        return dp[m][n];


    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m , vector<int>(n , -1));



        // return f(m-1 , n-1 , grid , dp);
        return fTab(m-1 , n-1 , grid);
    }
};