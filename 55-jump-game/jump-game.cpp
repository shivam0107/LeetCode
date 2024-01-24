class Solution {
public:
    bool canJump(vector<int>& nums) {

        
        int n = nums.size();
        if(n == 1) return true;
        int idx = 0;

        for(int i = 0; i <= idx; i++){
            idx = max(idx , i+nums[i]);
               if(idx >= n-1) return true;
        }

     

        return false;
    }
};