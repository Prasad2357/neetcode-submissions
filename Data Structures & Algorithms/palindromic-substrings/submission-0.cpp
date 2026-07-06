class Solution {
private:
    bool isPalindrome(string s, int left, int right)
    {
        while(left< right)
        {
            if(s[left] != s[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

public:
    int countSubstrings(string s) {
        //generate all the substrings

        int n = s.length();
        int count = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=i; j<n; j++)
            {
                //check if the substring is palindrome
                if(isPalindrome(s,i,j))
                {
                    count++;
                }
            }
        }
        return count;
        
    }
};
