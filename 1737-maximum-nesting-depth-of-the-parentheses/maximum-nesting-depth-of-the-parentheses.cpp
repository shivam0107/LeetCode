class Solution {
public:
    int maxDepth(string s) {
        if(s.length() == 0) return 0;

         int maxDep = 0;
         stack<int> st;

        int count = 0;
        for(int i =0; i<s.length(); i++){

            if(s[i] == '('){
                st.push(s[i]);
                count++;
                maxDep = max(count , maxDep);
            }
            else{
                
                if(s[i] == ')'){
                    st.pop();
                    count--;
                }               
            }

        }
        

        return maxDep;

      

    }
};