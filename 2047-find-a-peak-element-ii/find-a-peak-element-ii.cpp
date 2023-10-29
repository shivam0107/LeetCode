class Solution {
public:
    int maxElement(vector<vector<int>>& mat , int rows , int cols , int mid){
        int max = INT_MIN;
        int ind = 0;
        for(int i =0; i<rows; i++)    {
            if(mat[i][mid] > max){
                ind = i;
                max = mat[i][mid];
            }
        }

        return ind;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
         int rows = mat.size();
        int cols = mat[0].size();
        
        

        int low = 0;
        int high = cols;

        while(low <= high){
            int mid = (low+high)/2;
            int row = maxElement(mat , rows , cols , mid);

            int left = mid-1 >= 0 ? mat[row][mid-1] : -1;
            int right = mid+1 < cols ? mat[row][mid+1] : -1;

            if(mat[row][mid] > left && mat[row][mid] > right){
                return {row , mid};
            }
            else if(mat[row][mid] < left){
                high = mid-1;
            }
            else{
                low = mid+1;
            }

        }


      
        return {-1 , -1};
    }
};