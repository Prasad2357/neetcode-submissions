class Solution {
public:
    int findMin(vector<int> &nums) {
        // int ans = nums[0], left = 0, right = nums.size()-1;

        // while(left <= right)
        // {
        //     if(nums[left] < nums[right])
        //     {
        //         ans = min(ans, nums[left]);  //ascending order
        //         break;
        //     }
        //     int mid = left+(right-left)/2;
        //     ans = min(ans, nums[mid]);

        //     if(nums[mid] >= nums[left])
        //     {
        //         left = mid+1;   //ignore left
        //     }

        //     else
        //     {
        //         right = mid-1;
        //     }
        // }

        // return ans;


        int left = 0, right = nums.size()-1;

        while(left < right)
        {
            int mid = left+(right - left)/2;

            if(nums[mid] < nums[right])
            {
                right = mid;
            }
            else
            {
                left = mid+1;
            }

        }
        return nums[left];

        
    }
};
