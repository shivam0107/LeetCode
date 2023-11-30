class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> ans;

        map<int , int> mp;
        for(int i = 0; i<nums2.size(); i++){
            for(int j = i+1; j<nums2.size(); j++){
                if(nums2[i] < nums2[j]){
                    mp[nums2[i]] = nums2[j];
                    break;
                }
            }
        }

        for(int i = 0; i<nums1.size(); i++){
            int x = mp[nums1[i]];
            if(x != 0){
                ans.push_back(x);
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};