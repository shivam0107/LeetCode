class Solution {
public:

    
int distinctWays(int n , vector<int> &dp){

     if (n <= 1)
        return dp[n] = 1;
 
    if (dp[n] != -1) {
        return dp[n];
    }
    dp[n] = distinctWays(n - 1, dp) + distinctWays(n - 2, dp);
    return dp[n];


    // int ans;

    // while((n-2) < 0){

    //     int r = n%2;
    //     int d = n/2;

    //     if(d+r == n){
    //         ans = ans +1;
    //     }

    // }

    // ans = ans +1;

    // return ans;



}  


    int climbStairs(int n) {

        vector<int> dp(n+1 , -1);
        int ans = distinctWays(n , dp);

        return ans;
    }
};