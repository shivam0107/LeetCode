class Solution {
public:

    bool isUnique(string s){
        unordered_map<char , int> mp;
        for(int i = 0; i<s.length(); i++){
            if(mp[s[i]] > 0){
                return false;
            }

            mp[s[i]]++;
            
        }

        return true;
    }

    int maxLen(int n , vector<string> &ans , vector<string> &arr , unordered_map<string,int> &dp){
        if(n < 0 ){
            return 0;
        }
        string curr="";
        for(auto &val:ans) curr+=val;

        if(dp.find(curr)!=dp.end()) return dp[curr];

        ans.push_back(arr[n]);
        unordered_map<char , int> mp;
         for(int i=0;i<ans.size();i++)
        {
            for(int j=0;j<ans[i].size();j++) mp[ans[i][j]]++;
        }

        int f = 1;
        for(auto i : mp){
            if(i.second > 1){
                f = 0;
                break;
            }
        }


       

        int left = 0, right = 0;
        if(f) left = arr[n].length() + maxLen(n-1 , ans , arr , dp);
        ans.pop_back();
        right = maxLen(n-1 , ans , arr , dp);
       return dp[curr]=max(left,right);
    }


    int maxLength(vector<string>& arr) {

        //very bad solution bro 
        //accha lo abhi optimized karta hu
        int n = arr.size()-1;

        vector<string> ans;
       unordered_map<string,int> dp;
        return maxLen(n , ans, arr , dp);



        // int length = 0;
        // if(arr.size() == 1){
        //     if(isUnique(arr[0])){
        //         return arr[0].length();
        //     }
        // }

        // for(int i = 0; i<arr.size(); i++){
        //      string s = arr[i];

        //      if(isUnique(arr[i])){
        //         if(arr[i].length() > length){
        //             length = arr[i].length();
        //         }
        //      }

        //     for(int j = 0; j<arr.size(); j++){
        //         s  +=  arr[j];
        //         if(isUnique(s)){
        //            if(s.length() > length){
        //                length = s.length();
        //            }
        //         }else{
        //             int n = arr[j].length();
        //             int m = s.length();
        //             s.erase(m-n  , m );
        //             cout<<s<<endl;

        //         }
        //     }
        // }

        // return length;
    }
};