#define mod  1000000007

class Solution {
public:
    long long power(long long a , long long b){
       
        //base case--
        if(b == 0) return 1;
        if(b == 1) return a;

        long long ans = power(a , b/2);
       if(b % 2 == 0){
           ans *= ans;
           ans %= mod;
           return ans;
       }
       else{
           ans = a * ans * ans;
           ans %= mod;
           return ans;
       }

        
    } 
    int countGoodNumbers(long long n) {

        //better approach -- count even places and odd places
        long long even = (n/2)+(n%2);
        long long odd = n/2;

       return (power(5 , even) * power(4 , odd)) % mod;


        

        //brute force approach -- TLE
        // long long ans  = 1;
        // long long mod = 10e9 + 7;

        // for(int i = 0; i<n; i++){
        //     if(i%2 == 0){
        //         ans *= 5;
        //     }
        //     else{
        //         ans *= 4;
        //     }

        //     ans = ans % mod;
        // }

        // ans = ans % mod;

        
    }
};