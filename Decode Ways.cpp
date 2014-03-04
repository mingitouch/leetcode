class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        if(len == 0)
            return 0;
        int dp[len];
        for(int i=0;i<len;i++)
            dp[i] = 0;
        for(int i=0;i<len;i++)
        {
            if(i == 0)
            {
                if(s[i] >= '1' && s[i] <= '9')
                    dp[i] = 1;
                else
                    return 0;
            }
            else if(i == 1)
            {
                int a = (s[i-1]-'0')*10+(s[i]-'0');
                if(s[i] == '0')
                {
                    if(a>=1 && a<=26)
                    {
                        if(s[i-1] == '0')
                            return 0;
                        dp[i] = 1;
                    }
                    else
                        return 0;
                }
                else if(a>=1 && a<=26)
                {
                    if(s[i] >= '1' && s[i] <= '9')
                        dp[i] = dp[i-1] + 1;
                    else
                        dp[i] = dp[i-1];
                }
                else
                {
                    dp[i] = dp[i-1];
                }
            }
            else
            {
                int a = (s[i-1]-'0')*10+(s[i]-'0');
                if(s[i] == '0')
                {
                    if(a>=1 && a<=26)
                    {
                        if(s[i-1] == '0')
                            return 0;
                        dp[i] = dp[i-2];
                    }
                    else
                        return 0;
                }
                else if(a>=1 && a<=26)
                {
                    if(s[i] >= '1' && s[i] <= '9' && s[i-1] > '0')
                        dp[i] = dp[i-1] + dp[i-2];
                    else
                        dp[i] = dp[i-1];
                }
                else
                {
   //                 if(dp[i-2] == dp[i-1])
//                        return 0;
                    dp[i] = dp[i-1];
                }
            }
        }
        return dp[len-1];
    }
};
