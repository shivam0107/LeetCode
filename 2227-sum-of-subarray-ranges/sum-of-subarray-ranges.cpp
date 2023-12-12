class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long sum = 0;

        //TC -- O(n2)
        for(int i = 0; i<nums.size(); i++){
            long long mx = nums[i];
            long long mn = nums[i];
            for(int j = i+1; j < nums.size(); j++){
                if(nums[j] > mx){
                    mx = nums[j];
                }
                if(nums[j] < mn){
                    mn = nums[j];
                }

                sum += mx - mn;
            }
        }

        return sum;
    }
};