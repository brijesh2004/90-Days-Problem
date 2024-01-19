
// https://leetcode.com/problems/wiggle-sort-ii/

class Solution {
public:
    void wiggleSort(vector<int>& nums) {

        // first method using extra space
        //  int n = nums.size();
        
        // // Sort the array
        // sort(nums.begin(), nums.end());

        // // Create a temporary array of the same size
        // vector<int> tempArray(n, 0);

        // // Divide the sorted array into two halves
        // int left = (n - 1) / 2;
        // int right = n - 1;

        // // Interleave the smaller and larger elements
        // for (int i = 0; i < n; ++i) {
        //     tempArray[i] = (i % 2 == 0) ? nums[left--] : nums[right--];
        // }

        // // Copy the contents of the temporary array back to the original array
        // nums = tempArray;


   // using priority queue 

    //   int n = nums.size();
    //     priority_queue<int> q(nums.begin(), nums.end());
    //     for(int i=1; i<n; i+=2) {
    //         nums[i] = q.top();
    //         q.pop();
    //     }
    //     for(int i=0; i<n; i+=2) {
    //         nums[i] = q.top();
    //         q.pop();
    //     }


    }
};