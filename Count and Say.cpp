#include <sstream>

class Solution {
public:
    string countAndSay(int n) {
        int s = 0;
        int init=1;
        for(int i=1;i<n;i++)
        {
            int val=-1;
			int count=0;
			s = 0;
            while(init>0)
            {
                int pre = init % 10;
                if(val == -1)
                {
                    val = pre;
                    count++;
                }
                else if(val == pre)
                {
                    count++;
                }
                else
                {
                    if(s==0)
                        s = count*10+val;
                    else
                        s = (count*10+val) * pow(10, int(log10(s))+1) + s;
                    val = pre;
                    count = 1;
                }
                if(init / 10 == 0)
                {
                    if(s==0)
                        s = count*10+val;
                    else
                        s = (count*10+val) * pow(10, int(log10(s))+1) + s;
                    val = pre;
                    count = 1;
                }
                init = init / 10;
            }
            init = s;
        }
        string str;
        stringstream ss;
        ss << init;
        ss >> str;
        return str;
    }
};
