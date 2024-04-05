class Solution {
public:
    string makeGood(string s) {
        int n = s.length();
        for(int i = n-1; i >= 0; i--){

            if( i-1 >= 0 &&  s[i] == s[i-1]) continue;
            if( i-1 >= 0 &&  tolower(s[i]) == tolower(s[i-1]) && s[i] != s[i-1]){
                s = s.erase(i-1 , 2);
            }

            if( i+1 < n &&  tolower(s[i]) == tolower(s[i+1])  && s[i] != s[i+1] ){
                s = s.erase(i , 2);
            }
        }

        return s;
    }
};