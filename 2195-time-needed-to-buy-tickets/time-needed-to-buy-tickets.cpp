class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time  = 0;
        int n = tickets.size();
        
        queue<pair<int , int>> q;

        for(int i = 0; i<n; i++){
            q.push({i , tickets[i]});
        }

        while(!q.empty()){

            if(q.size() == 1){
                int n = q.front().second;
                time += n;
                break;
            }

            auto i = q.front();
            q.pop();

            int n = i.second - 1;
            time++;
            
            if(i.first == k && n == 0) break;

            if(n == 0) continue;

            q.push({i.first , n});
                        
        }

        return time;

    }
};