class Solution {
public:

    int solve(vector<int> &arr , int k  , int ind ,  vector<int> &dp){
        int n = arr.size();
        //base case
        if( ind >= arr.size()){
            return 0;
        }

        if(dp[ind] != -1){
            return dp[ind];
        }

        int mx = 0 , ans = 0;
        for(int i=ind; i<min(ind+k, n); i++){
            mx = max(mx , arr[i]);
            //recursive function
            ans = max(ans ,(i-ind+1) * mx  + solve(arr , k , i+1 , dp));
        }

        dp[ind] =   ans;
        return ans;
    }
    

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n  , -1);
        return solve(arr , k  , 0 , dp);
    }
};