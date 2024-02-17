class Solution {
public:
    int furthestBuilding(vector<int>& h, int b, int l) {
        int ans = 0;
        int n = h.size();
        int i = 0; int diff = 0;
        priority_queue<int> p;

          for(i = 0; i<n-1; i++){

              diff = h[i+1] - h[i];
              if(diff <= 0){
                  continue;
              }

              b -= diff;
              p.push(diff);

              if(b < 0)
              {
                  b  += p.top();
                  p.pop();
                  l--;
              }

              if(l < 0) break;


            }




















        // for(int i = 0; i<n; i++){
        //     if(i+1 == n){
        //         return i;
        //     }

        //     ans = i;
        //     int diff = (heights[i+1] - heights[i]) ;
        //     if(heights[i] >= heights[i+1]){ 
        //         continue;
        //     }
        //     else if(heights[i] < heights[i+1] && diff <= bricks){
        //         bricks = bricks - diff;
        //     }
        //     else if( heights[i] < heights[i+1] && ladders != 0){
        //         ladders--;
        //     }
        //     else{
        //         break;
        //     }
        // }

        return i;
    }
};