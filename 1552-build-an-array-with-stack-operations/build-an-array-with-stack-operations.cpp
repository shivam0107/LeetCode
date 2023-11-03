class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        
         int size = target.size();
         int ct = 0;
         vector<string> ans;

         for(int i = 1; i<= n; i++){
             if(ct < size){
                 if(target[ct] == i){
                     ans.push_back("Push");
                     ct++;
                 }
                 else{
                     ans.push_back("Push");
                     ans.push_back("Pop");
                 }
             }
             

         }

         return ans;
    }
};