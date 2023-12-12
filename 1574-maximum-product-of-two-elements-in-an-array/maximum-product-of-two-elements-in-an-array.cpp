class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int i = 0; 
        int j = 0;
        sort(nums.begin() , nums.end());
        int n = nums.size();

        int product = (nums[n-1] - 1) * (nums[n-2]-1);

        return product;
    }
};