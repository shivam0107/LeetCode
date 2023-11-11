class Solution {
public:

    
    void combination(int ind , vector<int> &nums , vector<int> &ds ,  vector<vector<int>> &ans){

        //base case
       
        ans.push_back(ds);
        

        //take  // when we use set datastructure //TLE ati hai
        // if(candidates[i] <= target){
        //     ds.push_back(candidates[i]);
        //     combination( i+1 , candidates , ds , st , target-candidates[i] );
        //     ds.pop_back();


        // }

        for(int i = ind; i<nums.size(); i++){
            if(i > ind && nums[i] == nums[i-1]) continue;
        
            ds.push_back(nums[i]);
            combination( i+1 , nums , ds , ans);
           
            ds.pop_back();
     
            

        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         vector<vector<int>> ans;
        set<vector<int>> st; // brute force -- O(2^n * k logn)
        vector<int> ds;
       
        sort(nums.begin() , nums.end());

        combination( 0 , nums , ds , ans);  
        //optimal 2^n * k -- TC
        //k * x -- SC

        // for(auto it: st){
        //     ans.push_back(it);
        // }

        return ans;
    }
};