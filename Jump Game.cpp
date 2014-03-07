class Solution {
public:
    bool canJump(int A[], int n) {
        if(n == 1)
            return true;
        for(int i=0;i<n-1;i++)
        {
            if(A[i] == 0)
                return false;
            if(i+A[i] >= n-1)
                return true;
            int index=INT_MIN;
            for(int j=i;j<=i+A[i];j++)
            {
                if(index<j+A[j])
                {
                    index=j+A[j];
                }
                if(index>=n-1)
                    return true;
            }
            i=index-1;
        }
        return false;
    }
};
