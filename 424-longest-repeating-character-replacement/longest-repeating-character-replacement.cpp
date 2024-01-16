class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        int left = 0;
        map<char , int> mp;
        int maxC = 0;
        for(int right = 0; right<s.length(); right++){
            mp[s[right]]++;
           
            maxC = max(maxC , mp[s[right]]);
            int currlen = right- left + 1;

            if(currlen - maxC > k){
                mp[s[left]]--;
                left++;
            }
           

            ans = max(ans , right-left+1);
        }

        return ans;
    }
};