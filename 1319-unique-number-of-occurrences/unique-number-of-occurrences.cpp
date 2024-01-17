class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int , int> mp;

        for(auto i : arr){
            mp[i]++;
        }

        vector<int> v;

        for(auto i : mp){
            cout<<i.second<<" ";
            v.push_back(i.second);
        }
        sort(v.begin() , v.end());

        for(int i = 1; i<v.size(); i++){
            if(v[i] == v[i-1]){
                return false;
            }
        }

        return true;

        
    }
};