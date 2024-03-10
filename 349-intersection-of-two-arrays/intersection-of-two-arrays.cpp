class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int ,int> map1;
        unordered_map<int ,int> map2;

        for(auto i : nums1){
            map1[i]++;
        }

         for(auto i : nums2){
            map2[i]++;
        }

        vector<int> ans;



        for(auto i : map1){
            if(map2.find(i.first) != map2.end()){
                ans.push_back(i.first);
            }
        }

        return ans;


        

        
    }
};