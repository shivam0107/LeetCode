class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> ans;
        unordered_map<int , int> mp;
        stack<int> st;
        int n = nums2.size();

       for(int i = n-1; i>=0; i--){
           while(!st.empty() && st.top() < nums2[i]){
               st.pop();
           }

           if(st.empty() == false){
               mp[nums2[i]] = st.top();
           }
           else{
               mp[nums2[i]] = -1;
           }


           st.push(nums2[i]);
        }


        for(int i = 0; i<nums1.size(); i++){
                ans.push_back(mp[nums1[i]]);
        }




        //using hashmap -- TC -- O(n^2)
        // map<int , int> mp;
        // for(int i = 0; i<nums2.size(); i++){
        //     for(int j = i+1; j<nums2.size(); j++){
        //         if(nums2[i] < nums2[j]){
        //             mp[nums2[i]] = nums2[j];
        //             break;
        //         }
        //     }
        // }

        // for(int i = 0; i<nums1.size(); i++){
        //     int x = mp[nums1[i]];
        //     if(x != 0){
        //         ans.push_back(x);
        //     }
        //     else{
        //         ans.push_back(-1);
        //     }
        // }
        return ans;
    }
};