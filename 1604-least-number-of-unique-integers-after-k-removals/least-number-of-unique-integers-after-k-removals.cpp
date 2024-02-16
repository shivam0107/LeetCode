class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int , int> mp;
        for(auto i : arr){
            mp[i]++;
        }

        int cnt = 0;
        vector<int> temp;

        for(auto i : mp){
            temp.push_back(i.second);

        }

        sort(temp.begin() , temp.end());

        for(int i = 0; i<temp.size(); i++){
             cout<<temp[i];
        }
        for(int i = 0; i< temp.size(); i++){
            if(k == 0) break;
            if(temp[i] <= k){
                
                k = k- temp[i];
                temp[i] = 0;
            }
            else if(temp[i] > k){
               temp[i] -= k;
                
                k = 0;
            }

           
        }

        for(int i = 0; i<temp.size(); i++){
             if(temp[i] != 0) cnt++;
        }
        cout<<endl;
        for(int i = 0; i<temp.size(); i++){
             cout<<temp[i];
        }

        return cnt;

        

       
    }
};