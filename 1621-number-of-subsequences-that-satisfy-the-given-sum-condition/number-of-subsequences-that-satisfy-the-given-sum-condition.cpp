class Solution {
public:
    
int findSubarrays(int i , vector<int> &nums,  vector<int> &ds ,int k  ){
    //base case
    if(i == nums.size()){
       
       int ans = ds[0]+ds[ds.size()-1];
       ans = ans % 1000000007;
       if(ans <= k) return 1;

       return 0;
    }

    //take
    ds.push_back(nums[i]);
   
   int l =  findSubarrays(i+1, nums, ds,   k);
 
    ds.pop_back();
    
   int r =  findSubarrays(i+1, nums, ds,  k);

   return (l + r) % 1000000007;
}


    long  long power(long long x , long long  n , long long mod){
        int res = 1;

        while(n){
            if(n%2 == 1){
                res = (res*x)%mod;
                n = n-1;
            }
            else{
                x = (x*x)%mod;
                n = n/2;
            }
        }

        return res;
    }

    int numSubseq(vector<int>& nums, int target) {

        int res = 0 , mod = 1000000007;

        sort(nums.begin() , nums.end());

        for(int i = 0 , j = nums.size()-1 ; i<= j ; i++){

            while(i <= j && nums[i] + nums[j] > target){
                j--;
            }

            if(j >= i){
                int pw =(int) power(2 , j-i , mod);
                res = (res + pw)%mod;
            }
        }


            return res;

   
    }
};