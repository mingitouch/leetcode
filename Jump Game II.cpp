class Solution {
public:
    int jump(int A[], int n) {
        if(n == 1)
            return 0;
        int count=0;
        int index=0;
        
        for(int i=0;i<n-1;)
        {
            if(index>=n-1)
                break;
            int ma=INT_MIN;
            while(i<=index)
            {
                ma = max(ma, i+A[i]);
                i++;
            }
            count++;
            index = ma;
        }
        return count;
    }
};
