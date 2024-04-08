class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        
        queue<int> q1;

        int count = 0 , i = 0;

        for(auto i : students){
            q1.push(i);
        }
        while(!q1.empty()){

            if(count > q1.size()) return q1.size();

            if(q1.front() != sandwiches[i]){
                int n = q1.front();
                q1.pop();
            
                q1.push(n);
                count++;
            
            }
            else{
                q1.pop();
                i++;   
                count = 0;
            }


        }


        return 0;
    }
};