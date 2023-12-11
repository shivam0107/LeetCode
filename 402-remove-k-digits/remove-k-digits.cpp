class Solution {
public:
    string removeKdigits(string num, int k) {
        
        int n = num.size();
        stack<char> st;

        //store the final string into the stack
        for(char c : num){
            while(!st.empty() && k > 0 && st.top() > c){
                st.pop();
                k--;
            }
            if(!st.empty() || c != '0'){
                st.push(c);
            }
        }
        
        //now remove the largest value from the stack
        //suppose string is like 1 2 3

        while(!st.empty() && k--){
            st.pop();
        }

        if(st.empty()){
            return "0";
        }

        while(!st.empty()){
            num[n-1] = st.top();
            st.pop();
            n -= 1;
        }

        num = num.substr(n);

        return num;
    }
};