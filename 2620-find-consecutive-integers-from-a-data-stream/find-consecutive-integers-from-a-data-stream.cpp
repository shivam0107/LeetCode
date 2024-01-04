class DataStream {
public:
    int value;
    int  k;
    unordered_map<int , int> mp;
    DataStream(int value, int k) {
        this->value = value;
        this->k = k;
    }
    
    bool consec(int num) {
       
       if(num == value) mp[num]++;
       else mp[value] = 0;

       if(mp[value] >= k) return true;

        

        return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */