class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        //use greedy approach

        unordered_map<int , int> mp;
        for(auto i : tasks){
            mp[i]++;
        }

        //create a max heap PQ
        priority_queue<pair<int , int>> pq;
        queue<pair<int , int>> q;

        for(auto i : mp){
            pq.push({i.second ,0});
        }

        int time = 0;

        while(!q.empty() || !pq.empty()){
            time++;
            //check if there is task in pq to process it
            if(!pq.empty()){
                auto t = pq.top();
                pq.pop();
                t.first--;
                if(t.first > 0){
                    t.second = time + n;
                    q.push(t);
                }
            }

            if(!q.empty() && q.front().second == time){
                pq.push(q.front());
                q.pop();
            }
        }



        return time;
    }
};