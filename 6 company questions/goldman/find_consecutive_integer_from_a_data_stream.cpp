// https://leetcode.com/problems/find-consecutive-integers-from-a-data-stream/

class DataStream {
public:
   int val , k , cnt ;
    DataStream(int value, int k) {
        this->k = k;
        val = value;
        cnt = 0;
    }
    
    bool consec(int num) {
        if(num==val) cnt++;
        else cnt = 0;
        return cnt>=k;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */