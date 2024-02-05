//https://leetcode.com/problems/kth-largest-element-in-a-stream/

class KthLargest {
public:
    int temp;
    priority_queue<int, vector<int>, greater<int>> pq;
public:

    KthLargest(int k, vector<int>& nums) {
        for (auto x : nums) pq.push(x);

        while (pq.size() > k) pq.pop();
        temp = k;
    }
    
    int add(int val) {
        pq.push(val);

        while (pq.size() > temp) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */