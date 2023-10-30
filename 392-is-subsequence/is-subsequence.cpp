class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int m = t.length() , n = s.length();
        int j =0;
        for(int i = 0; i < m && j < n  ; i++){
           
            if(s[j] == t[i]) j++;
        }

        return (j == n);
    }
};