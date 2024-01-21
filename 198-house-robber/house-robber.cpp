class Solution {
public:
    //memoization 

    // int rec(vector<int> &nums , int n , vector<int> &dp){
    //     if(n < 0){
    //         return 0;
    //     }

    //     if(dp[n] != -1){
    //         return dp[n];
    //     }

    //     int x = nums[n] + rec(nums , n-2 , dp);
    //     int y =  rec(nums , n-1 , dp);

    //     return dp[n] = max(x , y);
    // }


//tabulation
int rec(vector<int> &nums , int n , vector<int> &dp){
    
        if(n == 1) return nums[0];

        dp[0] = nums[0];
        dp[1] = max(nums[0] , nums[1]);

        for(int i = 2; i<n; i++){
            dp[i] = max(dp[i-1] , dp[i-2] + nums[i]);

        }

        return dp[n-1];
    }



    //space optimization
    // int rec(vector<int> &nums , int n , vector<int> &dp){

    //     if(n == 1) return nums[0];

    //    int prev2 = nums[0] ;
    //    int prev = max(nums[0] , nums[1]);
    //    int  curr = prev;

    //    for(int i =2; i<n; i++){
    //       curr = max(prev , prev2+nums[i]);
    //        prev2 = prev;
    //        prev = curr;
    //    }

    //    return curr;
       
    // }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1 , -1);

       return rec(nums , n , dp);
    }
};