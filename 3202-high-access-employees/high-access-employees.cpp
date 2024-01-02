class Solution {
public:

    bool isValid(vector<int> time){
        for(int i = 0; i<time.size()-2; i++){
            if(time[i+2] - time[i] < 60){
                return true;
            }
        }

        return false;
    }

    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {

        unordered_map<string , vector<int>> mp;

        for(auto it : access_times ){
            string hours = it[1].substr(0 , 2);
            string min = it[1].substr(2 , 2);
            int time = stoi(hours)*60 + stoi(min); // converting access time into integers
            mp[it[0]].push_back(time); // hashing time corrospond to its key 
            //why not this mp[it[0]] = time
        }

       
        vector<string> ans;

        for(auto it : mp){
            if(it.second.size() < 3){
                continue;
            }

            sort(it.second.begin() , it.second.end()); // sort access time
           
           if(isValid(it.second)){
               ans.push_back(it.first);
           }
        }

        return ans;

        
    }
};