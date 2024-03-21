class Solution {
public:

    int f(int i , int j , int n , int m, vector<vector<int>>& matrix , vector<vector<int>> &dp){
        
        if(j < 0 || j >= m) return 1e9;

        if(i == n-1) return matrix[i][j];

        if(dp[i][j] != -1){
            return dp[i][j];
        }

      
         
         int x = matrix[i][j] + f(i+1 , j-1 , n , m , matrix , dp);

        int y = matrix[i][j] + f(i+1 , j , n , m , matrix , dp);

        int  z = matrix[i][j] + f(i+1 , j+1 , n , m , matrix , dp);


        return dp[i][j] = min(x , min(y , z));
    }


    int ftab( int n , int m , vector<vector<int>>& matrix  ){
      vector<vector<int>> dp(n , vector<int>(m , -1));


        for(int j = 0 ; j<m; j++){
            dp[n-1][j] = matrix[n-1][j];

        }

        for(int i = n-2; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                int x = INT_MAX;
                if(j-1 >= 0)
                x = matrix[i][j] + dp[i+1][j-1];

                int y = matrix[i][j] + dp[i+1][j];

                int  z = INT_MAX;
                if(j+1 < m)
                z = matrix[i][j] + dp[i+1][j+1];


                dp[i][j] = min(x , min(y , z));

            }
        }

        int mini = dp[0][0];
        for(int j = 1; j < m; j++){
            mini = min(mini , dp[0][j]);
        }

        return mini;
    }



    
    int fspace( int n , int m , vector<vector<int>>& matrix  ){
      vector<int> prev (m , -1);


        for(int j = 0 ; j<m; j++){
            prev[j] = matrix[n-1][j];

        }

        for(int i = n-2; i >= 0; i--){

            vector<int> curr(m , -1);
            
            for(int j = m-1; j >= 0; j--){
                int x = INT_MAX;
                if(j-1 >= 0)
                x = matrix[i][j] + prev[j-1];

                int y = matrix[i][j] + prev[j];

                int  z = INT_MAX;
                if(j+1 < m)
                z = matrix[i][j] + prev[j+1];


                curr[j] = min(x , min(y , z));

            }

            prev = curr;
        }

        int mini = prev[0];
        for(int j = 1; j < m; j++){
            mini = min(mini ,prev[j]);
        }

        return mini;
    }


    int minFallingPathSum(vector<vector<int>>& matrix) {

        
      int n = matrix.size();
      int m = matrix[0].size();
      
      vector<vector<int>> dp(n , vector<int>(m , -1));


    //   int ans = INT_MAX;
    //   for(int i = 0; i<m; i++){
    //      ans = min( ans ,  f(0 , i , n , m , matrix , dp));
    //   }

    //  return ans;

    // return ftab(n , m , matrix );
    return fspace(n , m , matrix );

    }
};