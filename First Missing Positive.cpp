class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        if(n == 1)
        {
            if(A[0] != 1)
                return 1;
            else
                return 2;
        }
        if(n == 0)
            return 1;
        for(int i=0;i<n;i++)
        {
            while(A[i] != i+1 && A[i] > 0 && A[i] - 1 < n)
            {
                if(A[i] == A[A[i]-1])
                    break;
                swap(A[i], A[A[i]-1]);
            }
        }
        int i=0;
        for(;i<n;i++)
        {
            if(A[i] != i+1)
                return i+1;
        }
        return i+1;
    }
    
    void swap(int & a, int & b)
    {
        a = a + b;
        b = a - b;
        a = a - b;
    }
};
