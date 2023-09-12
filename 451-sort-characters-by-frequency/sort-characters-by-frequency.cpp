class Solution {
public:

    static bool cmp(pair<char,int> a, pair<char, int> b)
    {
        return a.second > b.second;
    }

    string frequencySort(string s) 
    {
        vector<pair<char , int>> v;
        map<char, int> map;

        for(int i = 0; i<s.length(); i++){
            map[s[i]]++;
        }

        for(auto it: map){
            v.push_back(it);
        }

        sort(v.begin() , v.end() , cmp);

        string ans = "";

        for(int i =0; i<v.size(); i++){
            int t = v[i].second;

            while(t--) 
            ans += v[i].first;
        }



     return ans;

     
        

        
        

        

        
    }
};