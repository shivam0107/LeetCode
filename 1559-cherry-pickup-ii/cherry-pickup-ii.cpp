class Solution {
public:
    int dy[3] = {-1 , 0 , 1};
    int memo[71][71][71];

    int dfs(int r , int c1 , int c2 ,vector<vector<int>>& grid  , int n , int m){
        //base case
        if(r == n) return 0;
        if(c1 < 0 || c2 < 0 || c1 >= m || c2 >= m) return INT_MIN;
        if(memo[r][c1][c2] != -1) return memo[r][c1][c2];

        int maxAns = 0;
        for(int i = 0; i<3; i++){
            for(int j = 0; j < 3; j++){
                maxAns = max(maxAns , dfs(r+1 , c1+dy[i] , c2+dy[j] , grid , n , m));
            }
        }

         maxAns += (c1 == c2) ? grid[r][c1] : grid[r][c2] + grid[r][c1];
        return memo[r][c1][c2] = maxAns;
    }

    int cherryPickup(vector<vector<int>>& grid) {
       
       int n = grid.size();
       if(!n) return 0;
       int m = grid[0].size();
       memset(memo , -1 , sizeof(memo));

       return dfs(0 , 0 , m-1 , grid , n , m);

    }
};