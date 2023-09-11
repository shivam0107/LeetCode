class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

       unordered_map<char ,int> map1;
       unordered_map<char ,int> map2;


       for(int i =0; i<s.length(); i++){
           map1[s[i]]++;
           map2[t[i]]++;
       }

       for(int i = 0; i<s.length(); i++){
           if(map1.find(s[i]) != map1.end() && map2.find(s[i]) != map2.end()){
               int check1 = map1[s[i]];
               int check2 = map2[s[i]];

               if(check1 != check2){
                   return false;
               }

           }
           else{
               return false;
           }
       }

        return true;      
        
    }
};