class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        //using two pointer -- 
        //TC - O(n)
        //SC - O(1)
        int l = 0 , r = n-1 ;
        int leftMax = 0;
        int rightMax = 0;

        for(int i = 0; i<n; i++){
            //this condition will make sure that there will be
            // minimum of height or right of height[i], >= height[l]
            if(height[l] <= height[r]){ 
                if(height[l] >= leftMax) 
                {
                    leftMax = height[l];
                }
                else
                {
                    ans += leftMax-height[l];
                }
                
                l++;

                
            }
            else{

                if(height[r] >= rightMax) rightMax = height[r];
                else{
                    ans += rightMax-height[r];
                }

                r--;


            }
        }

        //solution using prefix array and suffix array
        // TC - O(n) + O(n) + O(n)
        // SC - O(2n)

        // vector<int> pre(n , 0);
        // vector<int> suf(n , 0);

        // pre[0] = height[0];
        // for(int i = 1; i<height.size(); i++){

        //     if(pre[i-1] < height[i]){
        //         pre[i] = height[i];
        //     }
        //     else{
        //         pre[i] = pre[i-1];
        //     }
        // }

        // suf[n-1] = height[n-1];
        // for(int i = n-2; i >= 0; i--){

        //     if(suf[i+1] > height[i]){
        //         suf[i] = suf[i+1];
        //     }
        //     else{
        //         suf[i] = height[i];
        //     }
        // }

        // for(int i = 0; i<n ; i++){
           
        //    ans += min(pre[i] , suf[i]) - height[i];

        // }


       

        return ans;
    }
};