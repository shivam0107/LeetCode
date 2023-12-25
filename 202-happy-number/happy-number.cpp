class Solution {
public:
    int sumOfSquare(int n){
         int sum = 0;
        while(n != 0){
            int x = n%10;
            sum +=  x*x;
            n = n/10;


        }

        return sum;

    }

    bool isHappy(int n) {
       
       if(n <= 0) return false;

       unordered_set<int> st;

       while(st.find(n) == st.end()){
           st.insert(n);
           n = sumOfSquare(n);
           if(n == 1) return true;
       }

       return false;

    }
};