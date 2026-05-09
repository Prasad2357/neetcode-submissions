class Solution {
public:
    int maxArea(vector<int>& heights) {
        //Brute Force: Nested loops

        // int n = heights.size();
        // int max_amount = 0;

        // for(int i=0; i<n-1; i++)
        // {

        //     for(int j=i+1; j<n;j++)
        //     {
        //         int width = j-i;
        //         int amount = min(heights[i],heights[j]) * width;
        //         max_amount = max(amount, max_amount);

        //     }
        // }
        // return max_amount;


        //Optimal: Two pointers

        int n = heights.size();
        int max_amount = 0;

        int left = 0;
        int right = n-1;

        while(left < right)
        {
            int width = right - left;
            int amount = min(heights[right], heights[left]) * width;
            max_amount = max(max_amount, amount);

            if(heights[left] <= heights[right])
            {
                left++;
            }

            else
            {
                right--;
            }
        }
        return max_amount;
    }
};
