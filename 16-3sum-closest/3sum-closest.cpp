class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin() , nums.end());
        int res = 0;
        int minDiff = INT_MAX;


        for(int i = 0; i<nums.size(); i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            int j = i+1;
            int k = nums.size()-1;

            while(j < k){

                    int sum = nums[i] +nums[j] + nums[k];
                    if(sum == target){
                        return sum;
                    }
                    else if(sum < target){
                        j++;
                    }
                    else if(sum > target){
                        k--;
                    }
                    else{
                        j++;
                        k--;

                        while( j < k && nums[j] == nums[j-1]) j++;
                        while( j < k && nums[k] == nums[k+1]) k--;
                    }

                    int diffToTarget = abs(sum - target);
                    if(diffToTarget < minDiff){
                        res = sum;
                        minDiff = diffToTarget;
                    }
            }
        }

        return res;
    }
};