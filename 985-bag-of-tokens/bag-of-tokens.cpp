class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        int score = 0;

        
        sort(begin(tokens) , end(tokens));

        int  n = tokens.size();


        int l = 0;
        int h = n-1;


        while(l <= h) {

            if(tokens[l] <= power){
                power -= tokens[l];
                score++;
                l++;
            }
            else if(h-l-1 >= 1 && score > 0 ){
                power += tokens[h];
                score--;
                h--;
            }
            else{
               return score;
            }
               
            
         



        }

        return score;


    }
};