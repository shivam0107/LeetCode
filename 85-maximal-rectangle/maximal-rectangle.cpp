class Solution {
public:

    int maxHistogram(vector<int>& heights){
         int n = heights.size();
        stack<pair<int , int>>  s1 , s2;
        vector<int> left(n) , right(n);

        //O(n) -- TC 
        //SC -- O(2n)
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

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n == 0) return 0;
        int m = matrix[0].size();
        
        vector<int> histogram(m , 0);
        int result = 0;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(matrix[i][j] == '1'){
                    histogram[j] += 1;
                }
                else{
                    histogram[j] = 0;
                }
            }

            result = max(result , maxHistogram(histogram));
            cout<<result<<" ";
        }

        return result;

       
    }
};