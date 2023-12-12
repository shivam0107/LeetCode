class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<pair<int , int>>  s1 , s2;
        vector<int> left(n) , right(n);

        for(int i = 0; i<n; i++){
            int j = i;
            while(!s1.empty() && s1.top().first >= heights[i]){
                j = s1.top().second;
                s1.pop();
            }

            s1.push({heights[i] , j});
            left[i] = j;
        }

        for(int i = n-1; i >= 0; i--){
            int j = i;
            while(!s2.empty() && s2.top().first >= heights[i]){
                j = s2.top().second;
                s2.pop();
            }

            s2.push({heights[i] , j});
            right[i] = j;
        }

        for(int i = 0; i<n; i++){
            cout<<left[i]<<" ";
        }
        cout<<endl;
        for(int i = 0; i<n; i++){
            cout<<right[i]<<" ";
        }


        int area = 0;


        for(int i = 0; i<n; i++){
            area = max(area , (right[i] - left[i] + 1)*heights[i]);
        }

        return area;
    }
};