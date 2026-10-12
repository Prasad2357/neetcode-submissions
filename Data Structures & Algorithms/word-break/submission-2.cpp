// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         //base case
//         return dfs(s, wordDict, 0);
//     }

// private:
//     bool dfs(const string& s, const vector<string>& wordDict, int i){
//         if (i==s.length())
//         {
//             return true;
//         }

//         for(const string& w : wordDict)
//         {
//             if(i+ w.length() <= s.length() &&
//                s.substr(i, w.length())== w) {
//                 if(dfs(s, wordDict, i+ w.length())) {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[s.size()] = true;

        for (int i = s.size()-1; i>=0; i--)
        {
            for(const auto&w : wordDict)
            {
                if((i + w.size()) <= s.size() &&
                    s.substr(i, w.size()) == w){
                        dp[i] = dp[i +w.size()];
                    }
                    if(dp[i])
                    {
                        break;
                    }
            }
        }
        return dp[0];

    }
};

