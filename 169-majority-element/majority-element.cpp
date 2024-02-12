class Solution {
public:
    int majorityElement(vector<int>& nums) {

        // optimal solution 
        //Moore's voting algorithm
        // O(n) + O(n) = O(2N)
        int ct = 0;
        int el;
        for(int i =0; i< nums.size(); i++){

            if(ct == 0){
                el = nums[i];
                ct++;
            }
            else if(nums[i] == el){
                ct++;
            }
            else{
                ct--;
            }
        }

        int ct1 = 0;
        for(int i =0 ;i<nums.size(); i++){
            if(nums[i] == el){
                ct1++;
            }
        }

        if(ct1 > nums.size()/2){
            return el;
        }


        return 0;





        // unordered_map<int,int> hash;  // better solution O(N) - TC , O(N) -      SC

        // for(int i=0;i<nums.size();i++){
        //     hash[nums[i]]++;
        // }

        // for(auto i:hash){
        //     if(i.second > (nums.size()/2)){
        //         return i.first;
        //     }
        // }
        // return 0;
    }
};