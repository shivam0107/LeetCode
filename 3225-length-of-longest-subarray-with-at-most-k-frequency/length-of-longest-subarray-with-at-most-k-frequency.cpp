class Solution {
public:
        int length = 0;
         void subset(int i , vector<int>& nums  ,  vector<int>& temp , int k ){
                if( i == nums.size()){
                    map<int , int> mp;
                        for(auto i : temp){
                                mp[i]++;
                        }
                        int f = 0;
                       for(int i = 0; i<temp.size(); i++){
                               if(mp[temp[i]] > k){
                                       f = 1;
                                       break;
                               }
                              
                       }
                       
                        if(f == 0){
                               if(length < temp.size()){
                                       length = temp.size();
                               }
                        }
                    return;
                }

                temp.push_back(nums[i]);
                subset(i+1 , nums , temp , k);

                temp.pop_back();
                subset(i+1 , nums  , temp , k);
    }
        
    int maxSubarrayLength(vector<int>& nums, int k) {
     
       int n = nums.size(), l = 0, r = 0, ans = 0;
        unordered_map<int, int> freq;
        while (r < n){
            freq[nums[r]]++;
            while (l <= r && freq[nums[r]] > k)
                freq[nums[l++]]--;
            ans = max(ans, r++ - l + 1);
        }
        return ans;
    }
};