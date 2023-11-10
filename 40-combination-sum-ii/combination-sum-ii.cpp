class Solution {
public:

    void combination(int ind , vector<int> &candidates , vector<int> &ds ,  vector<vector<int>> &ans , int target){

        //base case
       
            if(target == 0){ 
                ans.push_back(ds);

                return;
            }
        

        //take  // when we use set datastructure
        // if(candidates[i] <= target){
        //     ds.push_back(candidates[i]);
        //     combination( i+1 , candidates , ds , st , target-candidates[i] );
        //     ds.pop_back();


        // }

        for(int i = ind; i<candidates.size(); i++){
            if(i > ind && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;

            ds.push_back(candidates[i]);
            combination( i+1 , candidates , ds , ans , target-candidates[i] );
            ds.pop_back();


        }





        //not take
    }

    void Print_Vector(vector<int> Vec) 
    { 
        for (int i = 0; i < Vec.size(); i++) { 
            cout << Vec[i] << " "; 
        } 
        cout << endl; 
        return; 
    } 

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        set<vector<int>> st; // brute force -- O(2^n * k logn)
        vector<int> ds;
        sort(candidates.begin() , candidates.end());


        combination( 0 , candidates , ds , ans , target);

        // for(auto it: st){
        //     ans.push_back(it);
        // }

        return ans;
       
    }
};