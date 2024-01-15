class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int ,int> mp1 , mp2;
        vector<vector<int>> ans;

        int n = matches.size();

        for(int i = 0; i<n; i++){
            mp1[matches[i][0]]++;
            mp2[matches[i][1]]++;
        }

        vector<int> temp;

        for(auto i : mp1){
            if(mp2.find(i.first) == mp2.end()){
                temp.push_back(i.first);
            }
        }

        ans.push_back(temp);
        temp.clear();

        for(auto i : mp2){
            if(i.second == 1){
                temp.push_back(i.first);
            }
        }

        ans.push_back(temp);

        return ans;



    }
};