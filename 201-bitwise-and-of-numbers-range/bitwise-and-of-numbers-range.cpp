class Solution {
public:

    int findMsb(int n){
        int msb = -1;
        while(n){
            n = n >> 1;
            msb++;

        }

        return msb;
    }

    int rangeBitwiseAnd(int x, int y) {
      
        int res = 0;

        while(x && y){
            int xMsb = findMsb(x);
            int yMsb = findMsb(y);

            if(xMsb != yMsb){
                break;
            }

            int msbVal = 1 << xMsb;
            res = res + msbVal;

            x = x - msbVal;
            y = y - msbVal;
        }


        return res;

    }
};