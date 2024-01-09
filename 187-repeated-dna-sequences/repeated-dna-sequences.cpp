class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {

        vector<string> ans;
        unordered_map<string , int> mp;
        int n = s.length();

        if(n < 10){
            return ans;
        }
        
        int  i = 0;
        int j = 9;
        while(j < n){
            string temp = s.substr(i , 10);
            mp[temp]++;

            i++;
            j++;

        }

        for(auto it : mp){
            if(it.second > 1) ans.push_back(it.first);
        }


        return ans;

    }
};