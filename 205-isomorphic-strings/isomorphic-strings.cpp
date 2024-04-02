class Solution {
public:
    bool isIsomorphic(string s, string t) {
            if(s.length() != t.length()){
                return false;
            }
            //map string s to string t
            unordered_map<char , char> map1;

            // map target string t to bool weather it is used or not
            unordered_map<char , bool> map2;

            for(int i = 0; i<s.length() ; i++){

                char ch1  = s[i];
                char ch2 =  t[i];
                
                //check for ch1 is used or not
                if(map1.find(ch1) != map1.end()){
                    //if ch1 is used check for mapping to ch2
                    if(map1.at(ch1) != ch2){
                        return false;
                    }
                }
                else{
                    // if not mapped thep map ch1 with ch2
                    if(map2.find(ch2) != map2.end()){
                        return false;
                    }
                    else{
                       map1[ch1] = ch2;
                       map2[ch2] = true;
                    }
                }

            }

            return true;

        


    }
};