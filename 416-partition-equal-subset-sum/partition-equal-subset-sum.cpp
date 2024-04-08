class Solution {
public:

    bool f(int  ind   , int target, vector<int>& arr , vector<vector<int>> &dp ){

        if(target == 0) return true;
        if(ind == 0) return (arr[0] == target);

        if(dp[ind][target] != -1){
            return dp[ind][target];
        }

        bool notTake = f(ind-1 , target , arr, dp );
        bool take = false;
        if(target >= arr[ind]){
            take = f(ind-1 , target-arr[ind] , arr , dp );
        }

        return dp[ind][target] =   take || notTake;

    }

    bool canPartition(vector<int>& nums) {
        
        int result_sum = 0;

        for(auto i : nums){
            result_sum += i;
        }

        if(result_sum % 2)  return false;

        int k = result_sum / 2;
        int n = nums.size();
        vector<vector<int>>dp (n , vector<int>(k+1 , -1));

        return f( n-1 , k , nums , dp);

    }
};