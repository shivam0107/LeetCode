class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) 
    {
        int n = dist.size();
        int m = speed.size();

    

        for(int i = 0; i < n; i++ ){
            dist[i] = ((dist[i]-1) /speed[i]);
        }
        
        sort(dist.begin() , dist.end());
        int cnt = 0;

        for(int i = 0; i < dist.size(); i++){
            if(dist[i] < i){
                break;
            }
            
                cnt++;
            
        }

        return cnt;
        
    }
};