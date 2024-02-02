class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        
        vector<int> ans;
        //better solution
        for(int i = 1; i<=9; i++){
            int  num = i;
            int nextDigit = i + 1;

            while(num <= high && nextDigit <= 9){
                num = num * 10 + nextDigit;
                if(num >= low && num <= high){
                    ans.push_back(num);

                }

                nextDigit++;
            }
        }




        sort(ans.begin() , ans.end());

        //brute force to solve check all the digits between low and high
        // for(int i = low; i<= high; i++){
        //     string s = to_string(i);
    
        //     int f = 1;

        //     for(int i = 0; i<s.length()-1; i++){
        //         if(s[i]-'0'+1 != s[i+1]-'0'){
        //             f = 0;
        //         }
        //     }

        //     if(f){

        //         ans.push_back(i);

        //     }
        // }

        return ans;

    }
};