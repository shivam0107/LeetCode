class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
         n = n/4;
        int ans = 0;
        int cnt = 1;
        map<int , int> mp;
        for(auto i : arr){
           mp[i]++;
        }

        for(auto it : mp){
            if(it.second > n){
                ans = it.first;
                break;
            }
        }


        // for(int i = 0; i<arr.size(); i++){
        //     if(arr[i] == arr[i+1] && i+1 < arr.size()){
        //         cnt++;
        //     }
        //     else{
        //         if(cnt > n){
        //             ans = arr[i];
        //             break;
        //         }
        //         else{
        //             cnt = 1;
        //         }
        //     }
        // }

        return ans;
    }
};