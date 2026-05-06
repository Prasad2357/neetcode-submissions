class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        // Brute Force: Sorting and check adjacent ele

        // int subsequence = 1;
        // int long_subsequence = 1;
        
        // set<int> s(nums.begin(), nums.end());
        // nums.assign(s.begin(), s.end());

        // int n = nums.size();

        // if(n == 0 || n==1)
        // {
        //     return n;
        // }

        // for(int i=0; i<n; i++)
        // {
        //     subsequence = 1;
        //     for(int j=i; j<n-1; j++)
        //     {
        //         if(abs(nums[j+1] - nums[j]) == 1 )
        //         {
        //             subsequence = j+1-i+1;
        //             long_subsequence = max(long_subsequence,subsequence);
        //         }

        //         else
        //         {
        //             break;
        //         }
        //     }
        // }

        // return long_subsequence;


        // Optimal: Hash Set (num-1) check

        unordered_set <int> s(nums.begin(), nums.end());
        int longest = 0;

        for(int num: s)
        {
            //beginning of the sequence
            if(s.find(num-1) == s.end())
            {
                int current = num;
                int length = 1;
                while(s.find(current+1) != s.end())  //num+1 is present
                {
                    current++;
                    length++;
                }
                longest = max(longest, length);
            }  
        }
        return longest;
        
    }
};
