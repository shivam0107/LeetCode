class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        
        vector<string> ans;

        unordered_map<char , int> mp1;


            for(auto c : words[0]){
                mp1[c]++;
               
            }
      

        for(int i = 1; i<words.size(); i++){
            unordered_map<char , int> mp2;

            string s = words[i];

            for(auto c : s){
                mp2[c]++;
            }

            for (auto& pair : mp1) {
                char c = pair.first;
                pair.second = min(pair.second, mp2[c]);
            }
        }

         for (auto& pair : mp1) {
            if (pair.second > 0) {
                for (int j = 0; j < pair.second; j++) {
                    ans.push_back(string(1, pair.first));
                }
            }
         }

        return ans;


    }
};