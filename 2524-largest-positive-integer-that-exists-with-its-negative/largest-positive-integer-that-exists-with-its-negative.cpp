class Solution {
public:
    int findMaxK(vector<int>& nums) {
        
        int i = 0;
        sort(nums.begin() , nums.end());


        int n = nums.size();

        int el = -1;
        

        unordered_map<int , int> mp;
        for(auto i : nums){
            mp[i]++;
        }

        int n_el = -el;

        
        for(auto i : nums){
            if(i >= 0){
                if(mp[-i]){
                    el = max(el , i);
                }
            }
        }

        return el;


        
    }
};