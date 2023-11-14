class Solution {
public:

    void solve(int ind , string &digits , string &str , vector<string> &ans, string mapping[]){
        //base case
        if(ind >= digits.length()){
            ans.push_back(str);
            return;
        }

        int number = digits[ind] -'0';
        string value = mapping[number];

        for(int i = 0; i< value.length() ; i++){
            str.push_back(value[i]);
            solve(ind+1 , digits , str , ans , mapping);

            str.pop_back();
            
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() == 0) return ans;

        string str;

        string mapping[10] = {"" , "" ,"abc" ,"def" , "ghi" , "jkl" , "mno" , "pqrs" , "tuv" , "wxyz"};

        solve(0 ,digits , str , ans , mapping);

        return ans;
    }
};