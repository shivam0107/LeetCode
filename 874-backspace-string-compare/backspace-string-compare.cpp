class Solution {
public:
    string backspace(string s){

        stack<char> st;
        for(int i = 0; i < s.length(); i++){

            if(s[i] != '#'){
                st.push(s[i]);
            }
            else if(s[i] == '#' && !st.empty()){
                st.pop();
            }
        }
      string str;


        while(!st.empty()){
            str += st.top();
            st.pop();
        }

        return str;
    }

    bool backspaceCompare(string s, string t) {

        string s1 = backspace(s);
        string s2 = backspace(t);

        if(s1 == s2){
            return true;
        }
        
        return false;
        
    }
};