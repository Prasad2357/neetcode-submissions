class Solution {
public:
    int search(vector<int>& nums, int target) {
    //     int l = 0, r = nums.size()-1;

    //     while(l < r)
    //     {
    //         int m = l+(r-l)/2;
    //         if(nums[m] > nums[r])
    //         {
    //             l = m + 1;
    //         }
    //         else
    //         {
    //             r = m;
    //         }
    //     }        
    //     int pivot = l;

    //     int result = binarySearch(nums, target, 0, pivot-1);
    //     if (result != -1)
    //     {
    //         return result;
    //     }

    //     return binarySearch(nums, target, pivot, nums.size()-1);
    // }

    // int binarySearch(vector <int> &nums, int target, int left, int right)
    // {
    //     while(left <= right)
    //     {
    //         int mid = left + (right-left)/2;
    //         if(nums[mid] == target)
    //         {
    //             return mid;
    //         }
    //         else if (nums[mid] <target)
    //         {
    //             left = mid+1;
    //         }
    //         else
    //         {
    //             right = mid-1;
    //         }
    //     }
    //     return -1;


        int l =0, r= nums.size()-1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(target == nums[mid])
            {
                return mid;
            }

            if(nums[l] <= nums[mid])
            {
                //ignore left (left sorted)
                if(target > nums[mid] || target< nums[l])
                {
                    l = mid+1; 
                }
                else
                {
                    r = mid-1;
                }
            }

            else 
            {
                //ignore right (right sorted)
                if(target < nums[mid] || target > nums[r])
                {
                    r = mid-1;
                } 
                else
                {
                    l = mid+1;
                }
            }
        }
        return -1;
    }
};
