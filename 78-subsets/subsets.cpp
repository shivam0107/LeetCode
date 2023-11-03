class Solution {
public:

    void subset(int i , vector<int>& nums , vector<vector<int>> &ans ,  vector<int>& temp ){
        if( i == nums.size()){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        subset(i+1 , nums , ans , temp);

        temp.pop_back();
        subset(i+1 , nums , ans , temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> ans;
       vector<int> temp;

       subset(0 , nums , ans , temp);

       return ans;
    }
};