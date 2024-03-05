class Solution {
public:
    int minimumLength(string s) {
        

        int i = 0;
        int j = s.length()-1;
        int n  = s.length()-1;


        while(i < j){
            if(s[i] == s[j]){

                i++; 
                j--;

                 while(i > 0 &&  s[i-1] == s[i] && i <= j ){
                     i++;
                 }
                
                while(j < n && s[j] == s[j+1] && i <= j){
                    j--;
                }

               

            }
            else{
                return j-i+1;
            }
        
        }

        n = j-i+1;
        if(n < 0) return 0;

        return n;
    }
};