class Solution {
public:
    int col(vector<vector<int>>& mat , int i , int col){
        int cnt = 0;
        for(int j = 0; j<col; j++){
            if(mat[i][j] == 1){
                cnt++;
            }
        }

        return cnt;
    }

    int row(vector<vector<int>>& mat , int j , int row){
        int cnt = 0;
        for(int i = 0; i<row; i++){
            if(mat[i][j] == 1){
                cnt++;
            }
        }

        return cnt;
    }


    int numSpecial(vector<vector<int>>& mat) {
         int ans = 0;
        int m = mat.size();
        int n = mat[0].size();
        
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (mat[row][col] == 0) {
                    continue;
                }
                
                bool good = true;
                for (int r = 0; r < m; r++) {
                    if (r != row && mat[r][col] == 1) {
                        good = false;
                        break;
                    }
                }
                
                for (int c = 0; c < n; c++) {
                    if (c != col && mat[row][c] == 1) {
                        good = false;
                        break;
                    }
                }
                
                if (good) {
                    ans++;
                }
            }
        }

        return ans;
    }
};