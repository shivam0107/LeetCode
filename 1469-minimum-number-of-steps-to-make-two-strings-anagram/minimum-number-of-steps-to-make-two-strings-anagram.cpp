class Solution {
public:
    int minSteps(string s, string t) {

        map<char , int> mp1, mp2;

        for(auto i : s){
            mp1[i]++;
        }
        for(auto i : t){
            mp2[i]++;
        }

        int cnt = 0;

       for(auto i : mp1){
           if(mp2.find(i.first) != mp2.end()){
              
                   cnt += min(mp1[i.first] , mp2[i.first]);
           
           }
           
       }

       
        return s.size() - cnt;
        
    }
};