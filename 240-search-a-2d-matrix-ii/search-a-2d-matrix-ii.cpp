class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int row = matrix.size();
       int col = matrix[0].size();

       //optimal solution -- O(n+m) , TC - O(1)

       int i = 0;
        int j = col-1;
        while(i < row && j >= 0){
            if(matrix[i][j] == target){
                return true;
            }
            else if(matrix[i][j] > target){
                j--;
            }
            else{
                i++;
            }
        }

       
       //better approach  - O(n * log(m)) write it by your own
        
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