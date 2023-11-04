class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        
        int maxL = -1;
        int minR = INT_MAX;

        for(int i = 0; i<left.size(); i++){
            maxL = max(maxL , left[i]);
        }
        for(int i = 0; i<right.size(); i++){
            minR = min(minR , right[i]);
        }

        int maxR = n - minR;

        maxL = max(maxL , maxR);

        return maxL;
    }
};