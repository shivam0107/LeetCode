class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        int missing , repeating;
        int n = nums.size();

        unordered_map<int , int> mp;
        for(auto i : nums){
            mp[i]++;
        }

        for(int i = 1; i<=n; i++){

            if(mp.find(i) == mp.end()){
                missing = i;
            }
            else{
                if(mp[i] == 2){
                    repeating = i;
                }
            }

        }


        return {repeating , missing};
      
    }
};