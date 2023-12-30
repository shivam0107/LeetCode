class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        unordered_map<char , int> counts;

        for(string word : words){
            for(char c : word){
                counts[c]++;
            }
        }

        for(auto it : counts){
            if(it.second%n != 0){
                return false;
            }
        }
       
        return true;
    }
};