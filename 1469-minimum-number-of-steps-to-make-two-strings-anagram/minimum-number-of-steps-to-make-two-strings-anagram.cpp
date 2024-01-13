class Solution {
public:
    int minSteps(string s, string t) {

    
    // optimized solution
    vector<int> v(26 , 0);


    int i = 0;
    while(i < s.size()){
        v[s[i] - 'a']++;
        v[t[i] - 'a']--;

        i++;
    }

    int ans = 0;
    i = 0;
    while(i < 26){
        ans  += max(0 , v[i]);
        i++;
    }

    return ans;



        //brute force with extra space
    //     map<char , int> mp1, mp2;
    //     for(auto i : s){
    //         mp1[i]++;
    //     }
    //     for(auto i : t){
    //         mp2[i]++;
    //     }

    //     int cnt = 0;

    //    for(auto i : mp1){
    //        if(mp2.find(i.first) != mp2.end()){
              
    //                cnt += min(mp1[i.first] , mp2[i.first]);
           
    //        }
           
    //    }

       
        // return s.size() - cnt;
        
    }
};