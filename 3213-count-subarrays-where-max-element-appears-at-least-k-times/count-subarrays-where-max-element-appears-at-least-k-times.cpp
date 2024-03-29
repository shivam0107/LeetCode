class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
       int n = nums.size();
       int l = 0;
       long long ans = 0;
       int maxi = 0;

       for(auto i : nums){
          maxi =   max(maxi , i);
       }


       int freq = 0;

       for(int r = 0; r < n; r++){

            if(nums[r] == maxi) freq++;
            while(freq >= k){
                ans += (n-r);
                if(nums[l] == maxi) freq--;

                l++;
            }

       }

       return ans;

    }
};