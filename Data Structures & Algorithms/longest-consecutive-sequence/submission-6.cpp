class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int subsequence = 1;
        int long_subsequence = 1;
        
        set<int> s(nums.begin(), nums.end());
        nums.assign(s.begin(), s.end());

        int n = nums.size();

        if(n == 0 || n==1)
        {
            return n;
        }

        for(int i=0; i<n; i++)
        {
            subsequence = 1;
            for(int j=i; j<n-1; j++)
            {
                if(abs(nums[j+1] - nums[j]) == 1 )
                {
                    subsequence = j+1-i+1;
                    long_subsequence = max(long_subsequence,subsequence);
                }
                else if (nums[j+1] - nums[j] == 0)
                {
                    continue;
                }
                else
                {
                    break;
                }
            }
        }

        return long_subsequence;
        
    }
};
