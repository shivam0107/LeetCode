class Solution {
public:
    int findMaxLength(vector<int>& nums) {
       int ans = 0;
       unordered_map<int , int> mp;

      mp[0] = -1;

       int count = 0;

       for(int i = 0; i<nums.size(); i++){
            
            count = count + (nums[i] == 1 ? 1 : -1);

            if(mp.find(count) != mp.end()){
                ans = max(ans , i - mp[count]);
            }
            else{
                mp[count] = i;

            }
       }

        return ans;
    }
};