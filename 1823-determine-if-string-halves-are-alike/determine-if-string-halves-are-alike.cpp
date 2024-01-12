class Solution {
public:

    int findVovels(string s){
         int cnt = 0;
        for(int  i = 0; i<s.length(); i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || 
            s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || 
            s[i] == 'O' || s[i] == 'U' ){
                cnt++;
            }
        }
       return cnt;

    }

    bool halvesAreAlike(string s) {
        int n = s.length();
        int m = n/2;
        
       if(findVovels(s.substr(0 , m)) == findVovels(s.substr(m , n))) return true;

       return false;
       
    }
};