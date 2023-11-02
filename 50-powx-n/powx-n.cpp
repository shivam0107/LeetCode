class Solution {
public:
    double myPow(double x, int n) {
        double ans;
        long long nn  = abs(n);
        // using recursion 
        if(n == 0){
            return 1;
        }
        if(n == 1) return x;

       

        if(nn%2 == 0)  {
            ans = myPow(x , nn/2);
            ans =  ans*ans;
            return n < 0 ?  1/ans : ans;
         }
        else { 
            ans = myPow(x , nn/2);
            ans =  x*ans*ans;
            return n < 0 ?  1/ans : ans;
        };
        
       
        
        
        
        
        // if(x == 1.00000) return x;

        // double ans = 1;
        // long negative = n;
        // n = abs(n);

        // for(long i = 1;i<=n; i++){
        //     ans  *= x;
        // }

        // if(negative < 0){
        //     ans = 1/ans;
        // }

        // return ans;
        
    }
};