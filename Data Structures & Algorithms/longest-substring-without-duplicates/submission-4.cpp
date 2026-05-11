class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        // // Brute Force: Nested Loops
        // int n = s.size();
        // int count = 0, max_count = 0;
        // // int max_count = 0;

        // for(int i=0; i<n; i++)
        // {
        //     unordered_set <char> st;
        //     count = 0;

        //     for(int j=i; j<n; j++)
        //     {
        //         if(st.count(s[j]) == 0)
        //         {
        //             st.insert(s[j]);
        //             count++;
        //             max_count = max(max_count, count);
        //         }

        //         else
        //         {
        //             break;
        //         }
        //     }
        // }
        // return max_count;

        // Optimal: Sliding Window

        int left = 0, right = left;
        int n = s.size();
        unordered_set <char> st;
        int max_count = 0;

        while(right< n)
        {
            //unique elements
            if(st.count(s[right])== 0)  //duplicate char not found
            {
                st.insert(s[right]);
                max_count = max(max_count, right-left+1);

                right++;
            }

            else
            {
                while(st.count(s[right]))
                {
                    st.erase(s[left]);
                    left++;
                }
            }
        }

        return max_count;   
    }
};
