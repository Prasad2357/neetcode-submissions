class Solution {
public:
    string minWindow(string s, string t) {

        // Optimal: Sliding Window

        int left =0, right =0;
        int n = s.size();
        unordered_map <char,int> tmpp;
        unordered_map <char,int> submpp;
        string ans = "";
        int matched = 0;

        for(char c: t)
        {
            tmpp[c]++;
        }

        while(right < n)
        {
            submpp[s[right]]++;

            // useful char matched
            if(submpp[s[right]] <= tmpp[s[right]])
            {
                matched++;
            }

            //window valid

            while(matched == t.size())
            {
                string curr = s.substr(left, right-left+1);
                if (ans=="" || ans.size() > curr.size())
                {
                    ans = curr;
                }

                //remove left
                submpp[s[left]]--;

                //window became invalid
                if(submpp[s[left]] < tmpp[s[left]])
                {
                    matched--;
                }

                left++;
            }
            right++;
        }

        return ans;
        
    }
};
