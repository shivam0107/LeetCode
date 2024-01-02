class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int >freq(nums.size() + 1);
        vector<vector<int>> ans;

        for(int i = 0; i<nums.size(); i++){
            
            //if freq of element if >= ans size create a new row
            if(freq[nums[i]] >= ans.size()){
                ans.push_back({});
            }

            // store the element according to its current row
            ans[freq[nums[i]]].push_back(nums[i]);
            freq[nums[i]]++;


        }
         

        

         
        return ans;
         
     
    }
};