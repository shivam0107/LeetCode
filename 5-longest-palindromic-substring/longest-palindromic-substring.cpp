class Solution {
public:

    // bool isPlaindrome(string s){

    //         //   cout<<s<<endl;

    //        int j = s.length()-1;
    //        int i =0;

    //        while(i<j){
    //            if(s[i] != s[j]){
    //                return false;
    //            }

    //            i++;
    //            j--;
    //        }

    //         // cout<<s<<endl;
    //        return true;
           
    // }

    string longestPalindrome(string s) {
        if(s.length() <= 1) return s;

                string ans = "";

                // better approach 

                for(int i =1; i<s.length(); i++){
                    
                    //for odd length
                    int l = i;
                    int h = i;

                    while(s[l] == s[h]){
                        l--;
                        h++;

                        if(l == -1 || h == s.length()){
                            break;
                        }
                    }


                    string str = s.substr(l+1 , h-l-1);
                    // cout<< str<<endl;

                    if(ans.length() < str.length()){
                        ans = str;
                    }



                    //for even length
                   l = i-1;
                    h = i;

                    while(s[l] == s[h]){
                        l--;
                        h++;

                        if(l == -1 || h == s.length()){
                            break;
                        }
                    }


                     str = s.substr(l+1 , h-l-1);

                    if(ans.length() < str.length()){
                        ans = str;
                    }

                }

                
                //brute force approach generate all substring
                // for(int i = 0; i<s.length(); i++){
                //     int k = 1;
                //     for(int  j = i; j<s.length();j++){

                //         string str = s.substr(i ,k++);
                //         if(isPlaindrome(str)){
                //            if(ans.length() < str.length()){
                //                 ans = str;
                //            }
                //         }
                //     }
                // }

                return ans;
         
    }
};