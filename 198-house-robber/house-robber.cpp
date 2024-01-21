class Solution {
public:

    int rec(vector<int> &nums , int n , vector<int> &dp){
        if(n < 0){
            return 0;
        }

        if(dp[n] != -1){
            return dp[n];
        }

        int x = nums[n] + rec(nums , n-2 , dp);
        int y =  rec(nums , n-1 , dp);

        return dp[n] = max(x , y);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1 , -1);

       return rec(nums , n-1 , dp);
    }
};