class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        string ans;
        if(paths.size() == 1){
            return paths[0][1];
        }
        for(int i = 0; i<paths.size(); i++){
            bool good = true;
            for(int j = 0; j<paths.size(); j++){
                if(paths[i][1] == paths[j][0]){
                    good = false;
                    break;
                }
            }

            if(good){
                return paths[i][1];
            }
        }

      return ans;
    }
};