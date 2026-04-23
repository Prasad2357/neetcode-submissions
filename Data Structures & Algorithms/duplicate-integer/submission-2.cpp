class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

        //Brute Force 1:

        // int n = nums.size();
        // for (int i=0; i<n; i++)
        // {
        //     for (int j=i+1; j<n; j++)
        //     {
        //         if (nums[i]== nums[j])
        //         {
        //             return true;
        //         }
        //     }
        // }
        // return false;



        //Brute Force 2:

        // int n = nums.size();

        // sort(nums.begin(), nums.end());
        // for (int i=0; i<n-1; i++)
        // {
        //     if(nums[i]==nums[i+1])
        //     {
        //         return true;
        //     }
        // }
        // return false;


        // Optimal

        int n = nums.size();
        map <int,int> mpp;
        for(int i=0; i<n; i++)
        {
            mpp[nums[i]]++; //store the frequency in the map
        }

        // traverse the map
        for( auto it: mpp)
        {
            if(it.second > 1)  //if the frequency is greater than 1
            {
                return true;
            }
        }

        return false;

    }
};