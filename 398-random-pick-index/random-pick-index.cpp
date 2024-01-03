class Solution {
public:
    vector<int> v;
    Solution(vector<int>& nums) {
        v = nums;
    }
    
    int pick(int target) {
        int n = v.size();
        int i = rand()%n;

        while(v[i] != target){
            i = rand()%n;
        }

        return i;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */