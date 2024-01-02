class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;


        for(int i = 0; i < queries.size(); i++){
            vector<pair<string , int>> temp;

            int pos = queries[i][1];
          
            int k = queries[i][0];

            for(int j = 0; j<nums.size(); j++){  
                    int n1 = nums[j].size();
                    string s = nums[j].substr(n1 - pos);
  
                    temp.push_back({s , j});
            }
  
            sort(temp.begin() , temp.end());
           

            ans.push_back(temp[k-1].second);

        }

        return ans;
    }
};