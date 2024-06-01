class Solution {
public:
    int scoreOfString(string s) {
        
            int n = s.length();
            int sum = 0;
            for(int i = 0; i< n; i++){
                    if(i+1 <  n){
                            sum += abs(s[i] - s[i+1]);
                    }
            }
            
            return sum;
    }
};