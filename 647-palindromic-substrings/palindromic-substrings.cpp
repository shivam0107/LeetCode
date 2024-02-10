class Solution {
public:

    int countSubstrings(string s) {
        
        //make enter of even and odd string 

        int cnt = 0;
        int n = s.length();

        if(n == 0 || n == 1) return n;

        for(int i = 0; i< n; i++){
            int j = i;
            int k = i;
            while(j>=0 && k < n && s[j] == s[k]){
                cnt++;
               j--;
               k++;
            }

            j = i;
            k = i+1;
            while(j>=0 && k < n && s[j] == s[k]){
               j--;
               k++;
                cnt++;
            }
        }

        return cnt;
    }
};