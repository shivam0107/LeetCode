class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        
        int l = s.length()-1;
        int m  = 0;
       int cnt = 1;

        for(int i = 0; i<s.length(); i++){
            if(s[i] == '1' && cnt == 1){
                swap(s[i] ,s[l] );
               cnt = 0;
            }

           if(i != s.length()-1){
                if(s[i] == '1'){
                swap(s[i] , s[m]);
                m++;
            }
           }
        }

        // for(int i = 0; i<s.length(); i++){
        //     if(i+1 < s.length() && s[i+1] == '0' ){
        //         swap(s[i] , s[s.length()-1]);
        //         break;
        //     }
        // }


        return s;
    }
};