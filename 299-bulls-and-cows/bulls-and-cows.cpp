class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> freq(10 , 0);
        int n = guess.length();
        
     
        int bulls = 0;
        int cows = 0;
        
        for(int i = 0; i<n; i++){
            if(secret[i] == guess[i]){
                bulls++;   
            }
            else{
               if(freq[secret[i]-'0']++ < 0) cows++;
                if(freq[guess[i]-'0']-- > 0) cows++;

            }

        }

       
        string ans = "";
        ans += to_string(bulls);
        ans += "A";
        ans += to_string(cows);
        ans+= "B";

        return ans;
    }
};