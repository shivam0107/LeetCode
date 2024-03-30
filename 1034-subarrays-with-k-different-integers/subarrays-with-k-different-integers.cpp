class Solution {
public:

    int f(int k ,vector<int>& nums ){
        int n = nums.size();
        int cnt = 0;

        unordered_map<int , int> mp;

        int l = 0;

        for(int r = 0; r < n; r++){
            mp[nums[r]]++;

            while(mp.size() > k){
                mp[nums[l]]--;
                if(mp[nums[l]] == 0){
                    mp.erase(nums[l]);
                   
                }
                 l = l+1;
            }

            cnt += (r-l+1);
        }

        return cnt;

    }



    int subarraysWithKDistinct(vector<int>& nums, int k) {
       
       int exact = f(k , nums);
       int lessThan = f(k-1 , nums);


        return (exact - lessThan);

        //naive solution -- generate all the subarrays
        //O(n2) //O(n)

        // for(int i = 0; i<n; i++){
        //     unordered_map<int , int> mp;
        //     for(int j = i; j<n; j++){
        //         mp[nums[j]]++;
        //         if(mp.size() == k) cnt++;
        //         else if(mp.size() > k) break;
        //     }

        // }


        
    }
};