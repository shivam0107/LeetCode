class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<int> st;

        for(auto elm : asteroids){
            if(elm > 0){
                st.push(elm);

            }
            else{
                while(!st.empty() && st.top() > 0 && st.top() < abs(elm)){
                    st.pop();
                }

                if(!st.empty() && st.top() == abs(elm)){
                    st.pop();
                }
                else if(st.empty() || st.top() < 0){
                    st.push(elm);
                }


            }
        }

        vector<int> ans(st.size() , 0);

        for(int i = st.size()-1; i>=0; i--){
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};