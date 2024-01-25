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
        if(n < 0 || m < 0){
            return 0;
        }

        if(dp[n][m] != -1){
            return dp[n][m];
        }

        if(t1[n] == t2[m]){
           return dp[n][m] =  1+fMem(n-1 , m-1 , t1 , t2 , dp);
        }

       return dp[n][m] =  max(fMem(n , m-1 , t1 , t2 , dp) , fMem(n-1 , m , t1 , t2 , dp));

    }


    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();


        // return f(n-1 , m-1 , text1 , text2);
        vector<vector<int>> dp(n , vector<int>(m , -1));
         return fMem(n-1 , m-1 , text1 , text2 , dp);
    }
};