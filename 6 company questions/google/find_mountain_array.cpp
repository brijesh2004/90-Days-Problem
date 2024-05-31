class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int len = mountainArr.length();

        // 1 Find the index of peak element
        int s = 1;
        int e = len-2;

        while(s!=e){
            int mid = (s+e)>>1;
            int curr = mountainArr.get(mid);
            int next = mountainArr.get(mid+1);

            if(curr<next){
                if(curr==target) return mid;
                if(next==target) return mid+1;
                s = mid+1;
              
            }else e = mid;
        }
        int peakIndex = s;

        // search in the stricktly increasing part of the array

        s = 0;
        e = peakIndex;
        while(s<=e){
            int mid = (s+e)>>1;
            int curr = mountainArr.get(mid);

            if(curr==target)
             return mid;
            else if(curr<target) s = mid+1;
            else e = mid-1;
        }

        // search in decreasing part
        s = peakIndex+1;
        e = len-1;
        while(s<=e){
            int mid = (s+e)>>1;
            int curr = mountainArr.get(mid);
            if(curr==target) return mid;
            else if(curr>target) s =mid+1;
            else e = mid-1;
        } 
    return -1;
    }
};