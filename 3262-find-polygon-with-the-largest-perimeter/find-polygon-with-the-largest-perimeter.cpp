class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long sum = 0;
        long long ans = -1;

        int n = nums.size();
        sort(nums.begin() , nums.end());
        
        for(int i  = 0; i<n; i++){
            
            if(nums[i] < sum ) ans = sum + nums[i];
            sum += nums[i];

        }
     

        return ans;
    }
};