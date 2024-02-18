class Solution {
public:

    int solve(vector<int>& coins, int amount , vector<int> &dp){
        //base case
        if(amount == 0) return 0;
        if(amount < 0) return INT_MAX;

        if(dp[amount] != -1){
            return dp[amount];
        }

        //make choices
        int mini = INT_MAX;
        for(int i = 0; i<coins.size(); i++){
            int ans = solve(coins , amount-coins[i] , dp);
       
            if(ans != INT_MAX){
                mini = min(mini , 1+ans);
            }
        }
        dp[amount] = mini;

        return mini;

    }

      int solveTab(vector<int>& coins, int amount ){
        //base case
        vector<int> dp(amount+1 , INT_MAX);
        dp[0] = 0;
        
        for(int i = 1; i<=amount; i++){
                for(int j = 0; j<coins.size() ; j++){
                    if(i-coins[j] >= 0 && dp[i-coins[j]] != INT_MAX )
                    dp[i] = min(dp[i] , 1+dp[i-coins[j]]);
                }
        }

        if(dp[amount] == INT_MAX) return -1;
        return dp[amount];

      }
    

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

    //     vector<int> dp(amount+1 , -1);

    //    int ans =  solve(coins , amount , dp);
    //    if(ans == INT_MAX){
    //        return -1;
    //    }

        return solveTab(coins , amount);

    }
};