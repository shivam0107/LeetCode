class Solution {
public:
    string solve( set<string> &st , string str , int n){
        //base case
        if(str.size() == n){
            if(st.find(str) == st.end()){
                return str;
            }
            return "";
        }

        string addZero = solve(st , str+'0' , n);

        if(addZero != ""){
            return addZero;
        }

        return solve(st , str+'1' , n);



        
    }
    string findDifferentBinaryString(vector<string>& nums) {
        string str;

        set<string> st;

        for(auto it : nums){
            st.insert(it);
        }
        int n = nums.size();


        return solve( st , str , n);


        
    }
};