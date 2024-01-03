class Solution {
public:

    int countActive(string s){
        int cnt = 0;
        for(int i = 0;i < s.length(); i++){
            if(s[i] == '1'){
                cnt++;
            }
        }

        return cnt;
    }

    int numberOfBeams(vector<string>& bank) {
        int res = 0;
        vector<int> v;
        for(int i = 0; i<bank.size(); i++){
            int n = countActive(bank[i]);
            if( n != 0){
                v.push_back(n);
            }

        }

        for(int i = 0; i<v.size(); i++){
            if(i+1 < v.size()){
                int n = v[i] * v[i+1];
                res = res + n;

            }
        }

        return res;
    }
};