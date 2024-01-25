class Solution {
public:

    int f(int n , int m , string &t1 , string &t2){
        //base case
        if(n < 0 || m < 0){
            return 0;
        }

        if(t1[n] == t2[m]){
            return 1+f(n-1 , m-1 , t1 , t2);
        }

        return max(f(n , m-1 , t1 , t2) , f(n-1 , m , t1 , t2));

    }

    int fMem(int n , int m , string &t1 , string &t2 ,  vector<vector<int>> &dp){
        //base case
        if(n  ==  0 || m  ==  0){
            return 0;
        }

        if(dp[n][m] != -1){
            return dp[n][m];
        }

        if(t1[n-1] == t2[m-1]){
           return dp[n][m] =  1+fMem(n-1 , m-1 , t1 , t2 , dp);
        }

       return dp[n][m] =  max(fMem(n , m-1 , t1 , t2 , dp) , fMem(n-1 , m , t1 , t2 , dp));

    }

    int fTab(int n , int m , string &t1 , string &t2 ,  vector<vector<int>> &dp){
        //base case

        for(int i = 0; i<=n; i++) dp[i][0] = 0;
        for(int j = 0; j<=m; j++) dp[0][j] = 0;

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                     if(t1[i-1] == t2[j-1]){
                         dp[i][j] =  1+dp[i-1][j-1];
                     }
                     else{
                         dp[i][j] =  max(dp[i][j-1] , dp[i-1][j]);
                     }

                
            }
        }

        return dp[n][m];

       

    }


    
    int fSpaceOp(int n , int m , string &t1 , string &t2){
        //base case
        vector<int> prev(m+1 , 0) , curr(m+1 , 0);

        for(int j = 0; j<=m; j++) prev[j] = 0;

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                     if(t1[i-1] == t2[j-1]){
                         curr[j] =  1+prev[j-1];
                     }
                     else{
                         curr[j] =  max(curr[j-1] , prev[j]);
                     }

               
                
            }
             prev = curr;
        }

        return prev[m];

       

    }




    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();


        // return f(n-1 , m-1 , text1 , text2);
        vector<vector<int>> dp(n+1 , vector<int>(m+1 , -1));
        //  return fMem(n , m , text1 , text2 , dp);
         return fSpaceOp(n , m , text1 , text2);
    }
};