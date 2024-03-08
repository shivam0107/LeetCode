class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int , int> mp;
            for(auto i : nums){
                    mp[i]++;
                    
            }
            
            
          vector<int> temp;
            
            for(auto i : mp){
                    temp.push_back(i.second);
            }
            
            sort(temp.begin() , temp.end() , greater<int>());
            
            int cnt = temp[0];
            for(int i = 1; i<temp.size(); i++){
                    if(temp[i] == temp[i-1]){
                            cnt += temp[i];
                    }
                    else{
                            break;
                    }
                   
            }
            
            return cnt;
    }
};