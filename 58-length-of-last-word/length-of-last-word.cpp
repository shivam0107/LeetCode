class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        //remove trailing spaces
        int i = s.length()-1;
        
        while(  i >= 0  && s[i] == ' ' ){
            i--;
        }

        int len = 0;
        while( i >= 0  && s[i] != ' '   ){
            len++;
            i--;
        }

        return len;

    }
};