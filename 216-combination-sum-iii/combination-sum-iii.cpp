class Solution {
public:

    void combination(int nums ,  int k , int n , int sum ,vector<int> &ds ,  vector<vector<int>> &ans){
        //base case
        if(sum > n)return;
        if(k == 0){
            if(sum == n) ans.push_back(ds);
            return;
        }

        if(nums == 10) return;
        //take
      
            ds.push_back(nums);
            sum += nums;
            combination(nums+1 ,  k-1 , n, sum , ds , ans);

            sum -= nums;
            ds.pop_back();
            combination(nums+1 ,  k , n, sum , ds , ans);
      
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        int sum = 0;
        combination(1 ,  k , n, sum , ds , ans);
        return ans;
    }
};