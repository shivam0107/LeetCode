class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans = 0;
        long long sum = 0;

        map<long long , int> preSum;
        preSum[0] = 1;


        for(int i = 0; i < nums.size(); i++){
           sum += nums[i];

           long long rem = sum - goal;
           if(preSum.find(rem) != preSum.end()){
                ans += preSum[rem];
           }


           preSum[sum]++;

        }

        return ans;
    }
};