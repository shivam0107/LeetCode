#define mod 1000000007
class Solution {
public:

    int rev(int n){
        int val =0;
        while(n){
            int last = n%10;
            val = val*10+last;
            n = n/10;
        }

        return val;
    }

    int countNicePairs(vector<int>& nums) {
        unordered_map<int , int> freq;
        int ans = 0;

        for(auto el : nums){
            int val = el - rev(el);
            ans = (ans + freq[val])%mod;
            freq[val]++;

        }

        return ans%mod;
    }
};