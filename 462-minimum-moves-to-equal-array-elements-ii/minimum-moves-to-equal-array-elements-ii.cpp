class Solution {
public:

    long long  findMin(vector<int> nums , long long n){
        long long  cnt = 0;
        for(int i = 0;i<nums.size(); i++){
            cnt = cnt + abs(nums[i] - n);
        }

        return cnt;
    }

    int minMoves2(vector<int>& nums) {
        
        long long ans = INT_MAX;
        for(int i = 0; i<nums.size(); i++){
            ans = min(ans , findMin(nums , nums[i]));
        }

        return (int)ans;

    }
};