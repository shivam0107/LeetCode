class Solution {
public:
    string largestOddNumber(string num) {

        
        string ans = "";
        for(int i = num.length()-1; i >= 0; i--){
            int temp = int(num[i]);
            if(temp % 2 == 0)
            {
                continue;
            }
            else{
                ans = num.substr(0 , i+1);
                break;
            }
           
           
        }
       
        return ans;
        
    }
};