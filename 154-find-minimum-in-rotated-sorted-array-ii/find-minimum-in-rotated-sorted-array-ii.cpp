class Solution {
public:
    int findMin(vector<int>& nums) {
        //optimal approach binary search -- O(n)
        int n = nums.size();
        if(n == 1) return nums[0];
        int low = 0;
        int high = n-1;
        int ans = INT_MAX;

     
        while(low <= high){
            int mid = (low + high) /2;
            
             if(nums[low] < nums[mid]){
                ans = min(ans , nums[low]);
                low = mid+1;
            }
            else if(nums[low] == nums[mid]){
                ans = min(ans , nums[low]);
                low++;
            }
            else if(nums[mid] < nums[high]){

                ans = min(ans , nums[mid]);
                high  = mid-1;
            }
            else{
                ans = min(ans , nums[mid]);
                high--;
            }
        }



        //brute Force approach -- O(N)
        // int mini = INT_MAX;
        // for(int i = 0; i<nums.size(); i++){
        //    if(nums[i] < mini){
        //        mini = nums[i];
        //    }
        // }

        return ans;
    }
};