class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        map<int , set<int>> mp;

        mp[stones[0]+1] = {1};

       
        for(int i = 0; i<n; i++){
            int stone = stones[i];

            set<int> st = mp[stone];

            for(auto val : st){
                        mp[val+stone-1].insert(val-1);
                        mp[val+stone].insert(val);
                        mp[val+stone+1].insert(val+1);
                  
                }
            }          
   

          return mp[stones[n-1]].size() != 0;

    }
};