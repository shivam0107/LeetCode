class Solution {
public:
    bool checkValidString(string s) {
        int open = 0 , close = 0;

        for(auto i : s){
            if(i == ')'){
                open--;
            }
            else{
                open++;
            }

            cout<<open<<endl;
            if(open < 0) return false;
        }

        for(int i = s.length()-1; i>=0; i--){
            if(s[i] == '('){
                close--;
            }
            else{
                close++;
            }

            if(close < 0) return false;
        }

        return true;
    }
};