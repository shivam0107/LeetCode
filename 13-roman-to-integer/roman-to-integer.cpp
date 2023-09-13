class Solution {
public:
    int romanToInt(string s) {
        
        int ans = 0;

       
            
            map<char , int> map;

            map.insert({'I',1});
            map.insert({'V',5});
            map.insert({'X',10});
            map.insert({'L',50});
            map.insert({'C',100});
            map.insert({'D',500});
            map.insert({'M',1000});
           
            for(int i =0; i<s.length(); i++){

                int first = map.at(s[i]);

                if(i+1 < s.length()){
                    int second = map.at(s[i+1]);
                    if(first < second){
                        ans += (second - first);
                        i++;
                    }
                    else{
                        ans += first;
                    }

                }
                else{
                    ans += first;
                }

            
            }

            // return ans;
            
            
            
            
        // brute force -- mane khud se kiya hai mazak thodi hai
        //   for(int i =0; i<s.length(); i++){
                
        //     if(s[i] == 'I' && s[i+1] != 'V' && s[i+1] != 'X'){
        //         ans += 1;
        //     }
        //     else if(s[i] == 'V'){
        //         ans += 5;
        //     }
        //     else if(s[i] == 'X' && s[i+1] != 'L' && s[i+1] != 'C'){
        //         ans += 10;
        //     }
        //     else if(s[i] == 'L'){
        //         ans += 50;
        //     }
        //     else if(s[i] == 'C' && s[i+1] != 'D' && s[i+1] != 'M'){
        //         ans += 100;
        //     }
        //     else if(s[i] == 'D'){
        //         ans += 500;
        //     }
        //     else if(s[i] == 'M'){
        //         ans += 1000;
        //     }


        //     if(s[i] == 'I' && s[i+1] == 'V'){
        //         ans += 4;
        //         i += 1;
        //     }
        //     else if(s[i] == 'I' && s[i+1] == 'X'){
        //         ans += 9;
        //         i += 1;
        //     }
        //     else if(s[i] == 'X' && s[i+1] == 'L'){
        //         ans += 40;
        //         i += 1;
        //     }
        //     else if(s[i] == 'X' && s[i+1] == 'C'){
        //         ans += 90;
        //         i += 1;
        //     }
        //     else if(s[i] == 'C' && s[i+1] == 'D'){
        //         ans  += 400;
        //         i += 1;
        //     }
        //     else if(s[i] == 'C' && s[i+1] == 'M'){
        //         ans += 900;
        //         i += 1;
        //     }
           
        //   }




        return ans;


      

    }
};