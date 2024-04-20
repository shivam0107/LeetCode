class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        
        vector<vector<int>> nums;
        int n = land.size();
        int m = land[0].size();

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(land[i][j] == 1){
                    vector<int> temp(4);
                    temp[0] = i;
                    temp[1] = j;
                    int r = i;
                    int c = j;
                    //mark this group as visited
                    for( r = i; r < n && land[r][j] == 1; r++){
                        for( c = j; c < m && land[r][c] == 1; c++){
                            land[r][c] = 2;

                        }
                    }

                    temp[2] = r-1;
                    temp[3] = c-1;

                    nums.push_back(temp);


                }
            }
        }

        return nums;
    }
};