class Solution {
public:

void generate(vector<string> &ans , string str, int op , int cl){
    
    if(op == 0 && cl == 0){
         ans.push_back(str);
    
        return;
    }
    
    if(op != 0){
        string temp = str;
        temp.push_back('(');
        generate(ans , temp , op-1 , cl);
    }
    
    if(cl > op){
        string temp = str;
        
        temp.push_back(')');
        generate(ans , temp , op , cl-1);
    }
    
      return;
}
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int op = n;
        int cl = n;
        string str;

        generate(ans ,str , op , cl);

        return ans;
    }
};