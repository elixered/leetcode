/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int tar;
    int searchL(int low, int high,  MountainArray &nums)
    {
        int ans = -1;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            int x = nums.get(mid);
            if(x==tar)
            return mid;
            else if(x>tar)
                high = mid-1;
            else low = mid+1;
        }
        return -1;
    }
    int searchR(int low, int high,  MountainArray &nums)
    {
        int ans = -1;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            int x = nums.get(mid);
            if(x==tar)
            return mid;
            else if(x<tar)
                high = mid-1;
            else low = mid+1;
        }
        return -1;
    }
    
    int findInMountainArray(int target, MountainArray &nums) {
        int low = 0;
        int n = nums.length();
        int high = n-1;
        int peakIdx;
        tar = target;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            int x = nums.get(mid);
            if(mid>0 && nums.get(mid-1)>x)
                high = mid-1;
            else if(mid<n-1 && nums.get(mid+1)>x)
                low = mid+1;
            else {
                peakIdx = mid;
                break;
            }
        }
        int x = searchL(0,peakIdx,nums);
        if(x!=-1) return x;
        x = searchR(peakIdx+1,n-1,nums);
        return x;
    }
};