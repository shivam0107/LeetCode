class Solution {
public:
    int getCommon(vector<int>& num1, vector<int>& num2) {
        int n = num1.size();
        int m = num2.size();

        unordered_map<int , int> mp;
        for(auto i : num2){
            mp[i]++;
        }

        for(int i = 0; i<n; i++){
            if(mp.find(num1[i]) != mp.end() ){
                return num1[i];
            }
        }


        return -1;
    }
};