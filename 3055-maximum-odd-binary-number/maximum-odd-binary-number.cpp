class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        
        int j = 0;
       

        for(int i = 0; i<s.length(); i++){
            if(s[i] == '1'){
                swap(s[i] ,s[j] );
                j++;
            }
        }

        for(int i = 0; i<s.length(); i++){
            if(i+1 < s.length() && s[i+1] == '0' ){
                swap(s[i] , s[s.length()-1]);
                break;
            }
        }


        return s;
    }
};