class Solution {
public:

    string minRemoveToMakeValid(string s) {
        
        stack<int> st;
        unordered_map<int , int> mp;

        for(int i = 0; i<s.length(); i++){
            
            if(s[i] == '('){
                st.push(i);
            }
            else if(s[i] == ')'){
                if(st.empty()){
                    mp[i]++;

                }else{
                    st.pop();
                }
            }
        }

        while(!st.empty()){
            mp[st.top()]++;
            st.pop();
        }

        string str;

        for(int i = 0; i<s.length(); i++){
            
            if(mp.find(i) == mp.end()){
                str += s[i];
            }
        }



        return str;
    }
};