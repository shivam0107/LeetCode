class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int ans  = 0;
        int r = grid.size();
        int c = grid[0].size();

        for(int i = 0; i<r; i++){
            for(int j = 0; j<c;j++){
                int cnt = 0;
                if(grid[i][j] == 1){
                    if((i-1) >= 0 && grid[i-1][j] == 1){
                        cnt++;
                    }
                    if((i+1 )< r && grid[i+1][j] == 1){
                        cnt++;
                    }
                    if((j-1) >= 0 && grid[i][j-1] == 1){
                        cnt++;
                    }
                    if((j+1 )< c && grid[i][j+1] == 1){
                        cnt++;
                    }

                    ans += 4 - cnt;
                }

                
             
            }
        }

        return ans;
    }
};