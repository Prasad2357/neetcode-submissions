class Solution {
    //Brute Force

private:
    bool isPalindrome(string s, int left, int right){
        while(left< right)
        {
            if(s[left]!= s[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }


public:
    string longestPalindrome(string s) {
        int n = s.length();
        int maxlen=0;
        int start=0;

        //generate all the substrings
        for(int i=0; i<n; i++)
        {
            for(int j=i; j<n; j++)
            {
                //check if the string is palindrome
                if(isPalindrome(s,i,j))
                {
                    if(j-i+1 > maxlen)
                    {
                        maxlen = j-i+1;
                        start =i;
                    }
                }
            }
        }
        return s.substr(start,maxlen);
        
    }
};
