class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        
        int ans = 0;
        int left = 0;
        int curCost = 0;
        for(int right = 0; right<s.length(); right++){
        
            if(s[right] != t[right]){
                curCost += abs(s[right] - t[right]);
            }

            while(curCost > maxCost){
                curCost -= abs(s[left] - t[left]);
                left++;
            }

            ans = max(ans , right-left+1);
        }

        return ans;
    }
};