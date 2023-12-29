class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        //most optimal solution
        
        
        vector<int> ans;
        deque<int> dq;

        for(int i =0; i<nums.size(); i++){
            if(!dq.empty() && dq.front() == i-k) dq.pop_front();

            while(!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();


            dq.push_back(i);
            if(i >= k-1) ans.push_back(nums[dq.front()]);
        }
        
        return ans;


        //brute force approach
        //o(n*k)

        // for(int i = 0; i<=n; i++){
        //      int maxi = INT_MIN;

        //     for(int j = i; j<= i+k-1; j++){
        //         maxi = max(nums[j] , maxi);
        //     }

        //     ans.push_back(maxi);
        // }

        // return ans;
    }
};