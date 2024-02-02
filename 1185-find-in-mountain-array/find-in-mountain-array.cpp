/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &a) {
        int n = a.length();
        int peek = 0;
        int l = 0;
        int h = n-1;
        int ans = INT_MAX;

        //find peek element
        while(l <= h){
            int mid = (l+h)/2;

            if(a.get(mid) < a.get(mid+1)){
                l = peek = mid+1;

            }
            else{
                h = mid -1;
            }
        }

        //find target in left part
        l = 0;
         h = peek;

        while(l <= h){
            int m = (l + h)/2;

            if(a.get(m) == target){
                return m;
            }
            else if(a.get(m) > target){
                h = m-1;
            }
            else{
                l = m+1;
            }
        }

 //find target in right part
         l = peek;
         h = n-1;

        while(l <= h){
            int m = (l + h)/2;

            if(a.get(m) == target){
                return m;
            }
            else if(a.get(m) > target){
               
                 l = m+1;
            }
            else{
                h = m-1;
            }
        }


       

        //brute force // wrong ans -- 100 calls only 
        // for(int i = 0; i<n; i++){
        //     if(mountainArr.get(i) == target){
        //         return i;
        //     }
        // }

        return -1;
    }
};