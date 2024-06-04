class Solution {
public:
    int longestPalindrome(string s) {

        int n = s.length();
        unordered_map<char , int> mp;

        for(int i = 0; i<n; i++){
            mp[s[i]] += 1;
        }

        int longest = 0;

        

            int f = 1;
            for(auto i : mp){


                if(mp.size() == 1) return i.second;
                if(i.second %2 == 0){
                    longest += i.second;
                }
                else if(i.second % 2 == 1){
                    if(f == 1){
                        longest += i.second;
                        f = 0;
                    }
                    else{
                          longest += i.second - 1;

                    }
                }


                if(i.second == 1 && f == 1){
                    longest += 1;
                    f = 0;
                }
            }
        
        // else{

        //     int f = 1;

        //     for(int i =0; i<n; i++){
        //         if(mp[s[i]] % 2 == 0){
        //             longest += mp[s[i]];
        //         }

        //         if(mp[s[i]] == 1 && f == 1){
        //             longest += 1;
        //             f = 0;
        //         }
        //     }

        // }

        return longest;
        
    }
};