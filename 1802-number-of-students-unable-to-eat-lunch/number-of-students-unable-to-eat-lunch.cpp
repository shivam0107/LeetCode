class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        
        queue<int> q1;
        queue<int> q2;

        int count = 0;

        for(auto i : students){
            q1.push(i);
        }

        for(auto i : sandwiches){
            q2.push(i);
        }

        while(!q1.empty() && !q2.empty()){

            if(count > q1.size()) return q1.size();

            if(q1.front() != q2.front()){
                int n = q1.front();
                q1.pop();
            
                q1.push(n);
                count++;
                cout<<count;
            }
            else{
                q1.pop();
                q2.pop();
                count = 0;
            }


        }


        return 0;
    }
};