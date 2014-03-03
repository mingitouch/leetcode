class Solution {
public:
    int singleNumber(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int bit[32];
        for(int i=0;i<32;i++)
            bit[i] = 0;
        for(int i=0;i<n;i++)
        {
            int count=31;
            int tmp = A[i];
            if(tmp<0)
            {
                bit[0] += 1;
                if(bit[0] == 3)
                    bit[0] = 0;
                tmp = tmp * (-1);
            }
            while(tmp)
            {
                if(tmp % 2 == 1)
                {
                    bit[count] += 1;
                    if(bit[count] == 3)
                        bit[count] = 0;
                }
                tmp = tmp / 2;
                count--;
            }
        }
        int sum = 0;
        bool flag = true;
        for(int i=1;i<32;i++)
        {
            if(bit[i] == 1)
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            for(int i=0;i<32;i++)
            {
                sum = sum * 2 + bit[i];
            }
            return sum;
        }
        else
        {
            for(int i=1;i<32;i++)
            {
                sum = sum * 2 + bit[i];
            }
        }
        if(bit[0] == 1)
            sum = sum * (-1);
        return sum;
    }
};
