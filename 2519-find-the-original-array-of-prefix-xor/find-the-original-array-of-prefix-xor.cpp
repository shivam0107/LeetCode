class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = 0;
        for(int i = 0; i<pref.size(); i++){
            int x = pref[i];
             pref[i] = n ^ pref[i];
             n = x;
            
        }

        return pref;
    }
};