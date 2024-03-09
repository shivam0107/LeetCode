class Solution {
public:
    int getCommon(vector<int>& num1, vector<int>& num2) {
        int n = num1.size();
        int m = num2.size();
        
        //brute force
        // unordered_map<int , int> mp;
        // for(auto i : num2){
        //     mp[i ]++;
        // }

        // for(int i = 0; i<n; i++){
        //     if(mp.find(num1[i]) != mp.end() ){
        //         return num1[i];
        //     }
        // }

        int i = 0;
        int j = 0;
        while(i < n && j < m){
            if(num1[i] == num2[j]){
                return num1[i];
            }
            else if(num1[i] < num2[j]){
                i++;
            }
            else{
                j++;
            }
        }


        return -1;
    }
};