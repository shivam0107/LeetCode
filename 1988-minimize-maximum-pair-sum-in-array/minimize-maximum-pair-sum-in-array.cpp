class Solution {
public:

    bool check(vector<int> &nums , int mid){
        int n = nums.size()-1;
        int num = nums[n] + nums[0];
        cout<<"check"<<num<<endl;

        if(num == mid){
            return true;
        }

        return false;
    }

    int minPairSum(vector<int>& nums) {

        sort(nums.begin() , nums.end());
        int j = nums.size()-1;
        int i = 0;
        int ans = 0;

        while(i < j){
            ans = max(ans , nums[i] + nums[j]);
            i++;
            j--;

        }


        // int low = nums[0] + nums[1];
        // int high = nums[n-1] + nums[n-2];
        // cout<<low<<" "<<high<<endl;

        // while(low <= high){
        //     int mid = (low+high) /2 ;
        //     cout<<mid<<endl;

        //     if(check(nums , mid)){
        //         high = mid-1;
        //     }
        //     else
        //     {
        //         low = mid+1;
        //     }
        // }
        

        return ans;
    }
};