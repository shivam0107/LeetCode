class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int N = nums.size();
        int sum1 = N*(N+1)/2;
    
    int sum2  = 0;
    
    // int size = sizeof(A)/sizeof(A[0]);
    
    for(int i = 0; i<N; i++){
        sum2 = sum2 + nums[i];
    }
    
    sum1 = sum1 - sum2;
    
    return sum1;
    }
};