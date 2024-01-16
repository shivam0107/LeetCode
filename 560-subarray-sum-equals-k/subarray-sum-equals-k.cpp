class Solution {
public:

    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        long long sum =0;
        map<long long, int> preSum;
        int n = nums.size();

        preSum[0] = 1;

        for (int i = 0; i < n;i++)
        {   //calculating prefix sum
            sum += nums[i];

            // if(sum == k){
            //    count++;
               
            // }
            long long rem = sum - k;
            // check for rem previously in hashmap
            if(preSum.find(rem) != preSum.end()){
                count += preSum[rem];
               
            }
            /*
                keep the prefix sum as left as you can
                {2,0,0,3}
                longest subarray should be {0,0,3}
                do not update the prefix sum if it stored once
            */

               preSum[sum]++;
            

            
        }
        return count;
    }
};