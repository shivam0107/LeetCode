class Solution {
public:
    bool compute(long long mid , long long d1 , long long d2 , long long uc1 , long long uc2){
       
       long long count1 = mid - mid / d1;
       long long count2 = mid - mid/d2;
       long long lcm = (long long)(d1*d2) / __gcd(d1 , d2);
       long long cBoth = mid - mid/lcm;

       return cBoth >= uc1+uc2 && count1 >= uc1 && count2 >= uc2;


    }

    int minimizeSet(int d1, int d2, int uCnt1, int uCnt2) {
    
       //find count of numbers which are not divisible by  divisors
       int l = 1;
       int h = INT_MAX;
        int ans = -1;
       while(l <= h){
           long long  mid = l + (h - l)/2;
           if(compute(mid , d1 , d2 , uCnt1 , uCnt2)){
               ans = mid;
               h = mid-1;
           }
           else{
               l = mid+1;
           }
       }

        return ans;
    }
};