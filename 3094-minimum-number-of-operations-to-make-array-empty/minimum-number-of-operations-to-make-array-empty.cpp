class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        map<int , int> map;
        
        int op = 0;
        
        for(int i =0; i< nums.size(); i++){
            map[nums[i]]++;
        }
        
        for(auto it: map){
            int val = it.second;
            if(val == 1) return -1;
            
            op += val/3;
            
            
            if(val%3) op++;
            
            
            
        }
        
        return op;
    }
};