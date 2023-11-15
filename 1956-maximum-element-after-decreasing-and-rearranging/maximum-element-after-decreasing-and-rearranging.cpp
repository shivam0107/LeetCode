class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        
        sort(arr.begin() , arr.end());
        int prev = 0;

        for(int i = 0; i<arr.size(); i++){
            arr[i] = min(arr[i] , prev+1);
            prev = arr[i];
        }

        return arr[arr.size()-1];
    }
};