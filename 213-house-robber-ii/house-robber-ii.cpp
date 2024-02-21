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
        if(n == 1) return nums[0];
        

       vector<int> temp1 , temp2;

       for(int i = 0; i<n; i++){
           if(i != 0) temp1.push_back(nums[i]);
           if(i != n-1) temp2.push_back(nums[i]);

       }

       vector<int> dp(temp1.size()+1 , -1);
        int ans1 = rec(temp1 , temp1.size()-1 , dp) ;


       vector<int> dp1(temp2.size()+1 , -1);


        int ans2 = rec(temp2 , temp2.size()-1 , dp1) ;

      return max(ans1 , ans2);

       
    }
};