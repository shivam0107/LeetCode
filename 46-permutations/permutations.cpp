class Solution {
public:
    void perm(int ind , vector<int> &nums , vector<vector<int>> &ans){

        if(ind == nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i = ind ;i < nums.size() ; i++){
            swap(nums[ind] , nums[i]);
            perm(ind+1 , nums,ans);
            swap(nums[ind] , nums[i]);
        }

    }

    void recurPerm(vector<int> &ds , vector<vector<int>> &ans , vector<int> &freq , vector<int> &nums ){

        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }

        for(int i = 0; i<nums.size() ; i++){
            if(!freq[i]){
                ds.push_back(nums[i]);
                freq[i] = 1;
                recurPerm(ds , ans , freq , nums);
                freq[i] = 0;
                ds.pop_back();

            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        // using freq array -- 
        //TC - n! * n , SC - O(n) + O(n)
        // vector<int> freq = {0};
        // vector<int> ds;
        // recurPerm(ds , ans , freq , nums);
        perm(0 , nums ,ans);
        return ans;
    }
};