class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long mod = 1000000007;
        int n = arr.size();

        long res = 0;
        vector<int> left(n) , right(n);
        stack<pair<int, int>> s1,s2;

        for(int i = 0; i<n ; i++){
            int count = 1;
            while(!s1.empty() && s1.top().first > arr[i]){
                count += s1.top().second;
                s1.pop();
            }

            s1.push({arr[i] , count});
            left[i] = count;
        }

        for(int i = n-1; i>=0 ; i--){
            int count = 1;
            while(!s2.empty() && s2.top().first >= arr[i]){
                count += s2.top().second;
                s2.pop();
            }

            s2.push({arr[i] , count});
            right[i] = count;
        }

        for(int i = 0 ; i<n; i++){
            cout<<left[i]<<" ";
        }
        cout<<endl;

        for(int i = 0 ; i<n; i++){
            cout<<right[i]<<" ";
        }


        for(int i = 0; i<n; i++){
            res =  (res + (long)arr[i]*left[i]*right[i])% mod ;
          
        }















        //brute force -- O(n2)
        // for(int i = 0; i<arr.size(); i++){
        //         int min = arr[i];
        //     for(int j =i; j<arr.size(); j++){
                
        //        if(min > arr[j]){
        //            min = arr[j];
        //        }

        //        res += min;
        //        res = res % mod;
        //     }

           
        // }


        return res;
    }
};