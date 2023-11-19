class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        
        sort(nums.rbegin() , nums.rend());

        int ans = 0; int cnt = 1;
        int n = nums.size();

        for(int i =1; i<n; i++){
            if(nums[i] != nums[i-1]){
                ans += cnt;
            }

            cnt++;
        }

        return ans;
    }
};