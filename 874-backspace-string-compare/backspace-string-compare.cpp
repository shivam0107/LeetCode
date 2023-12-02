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

    string getString(string s){
        int cnt = 0;
         string str;
        for(int i = s.length()-1; i>=0; i--){
            if(s[i] == '#'){
                cnt++;
            }

           

            if(s[i] != '#'){
                if(cnt > 0){
                    cnt--;
                }
                else{
                    str += s[i];
                }
            }
           
        }

        return str;
    }

    bool backspaceCompare(string s, string t) {

        // string s1 = backspace(s);
        // string s2 = backspace(t);

        if(getString(s) == getString(t)){
            return true;
        }
        
        return false;
        
    }
};