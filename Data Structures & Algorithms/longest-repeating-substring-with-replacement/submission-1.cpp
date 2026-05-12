class Solution {
public:
    int characterReplacement(string s, int k) {

        // //Brute Force: Nested Loops

        // int result = 0;
        // for(int i=0; i<s.size(); i++)
        // {
        //     unordered_map <char,int> count;
        //     int maxf = 0;

        //     for(int j=i; j<s.size(); j++)
        //     {
        //         count[s[j]]++;
        //         maxf = max(maxf, count[s[j]]);     //char with max freq
 
        //         if((j-i+1) - maxf <=k)
        //         {
        //             result = max(result, j-i+1);
        //         }
        //     }
        // }
        // return result;

        // Optimal: Sliding Window

        int left = 0, right = 0;
        int result = 0;
        int n = s.size();
        unordered_map <char, int> count;
        int maxf = 0;

        while(right < n)
        {
            count[s[right]]++;
            maxf = max(maxf, count[s[right]]);

            while((right-left+1) - maxf > k)
            {
                count[s[left]]--;   //shrink the window from left side
                left++;
            }

            result = max(result, right-left+1);
            right++;

        }

        return result;
        
    }
};
