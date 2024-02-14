class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans(n,0);
        int positive = 0,negetive = 1;

        for(int i =0; i<n ;i++){
            if(nums[i] < 0){
                ans[negetive] = nums[i];
                negetive += 2;
            }
            else{
                ans[positive] = nums[i];
                positive += 2;
            }
        }

        return ans;
        
        // vector<int> pos;
        // vector<int> neg;

        // for (int i = 0; i < nums.size(); i++)
        // {
        //     if(nums[i] > 0){
        //         pos.push_back(nums[i]);

        //     }
        //     else{
        //         neg.push_back(nums[i]);
        //     }
        // }

        // for (int i = 0; i < pos.size(); i++)
        // {
        //     nums[2 * i] = pos[i];
        //     nums[2 * i + 1] = neg[i];
        // }



  
    }
};