class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> ans;
        int n = nums.size();

        vector<int> left(n);
        vector<int> right(n);
        left[0] = 1;
        right[n-1] = 1;
      
        for(int i = 1; i < n; i++){

           left[i] = left[i-1]*nums[i-1];
        }

        for(int i = n-2; i >=0; i--){
            right[i] = right[i+1]*nums[i+1];
        }

        for(int i = 0; i<n;i++){
            cout<<left[i]<<" ";
        }
        cout<<endl;
         for(int i = 0; i<n;i++){
            cout<<right[i]<<" ";
        }


        for(int i = 0; i<n; i++){
            int l = left[i];
            int r = right[i];
            left[i] = (l * r);
        }
        

        //brute force approach
        // for(int i =0; i<nums.size(); i++){
        //     int prod = 1;
        //    for(int j = 0; j<nums.size(); j++){
        //         if(j != i){
        //             prod *= nums[j];
        //         }
        //    }
        //    ans.push_back(prod);

        // }

        return left;

    }
};