class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int row = matrix.size();
       int col = matrix[0].size();

       int low =0;
       int high = (row * col) -1;

       while(low <= high){
           int mid = (low + high)/2;
           int i = mid/col;
           int j = mid%col;
           if(matrix[i][j] == target){
               return true;
           }
           else if(matrix[i][j] < target){
               low = mid+1;
           }
           else{
               high = mid-1;
           }
       }


        //bruteforce O(n*m)
        // for(int i = 0; i<row;i++){
        //     for(int j =0; j<col; j++){
        //         if(matrix[i][j] == target){
        //             return true;
        //         }
        //     }
        // }
        
        
        return 0;
    }
};