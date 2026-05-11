class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        // Brute Force: Nested Loops
        int n = s.size();
        int count = 0, max_count = 0;
        // int max_count = 0;

        for(int i=0; i<n; i++)
        {
            unordered_set <char> st;
            count = 0;
            
            for(int j=i; j<n; j++)
            {
                if(st.count(s[j]) == 0)
                {
                    st.insert(s[j]);
                    count++;
                    max_count = max(max_count, count);
                }

                else
                {
                    break;
                }
            }
        }

        return max_count;



        
    }
};
