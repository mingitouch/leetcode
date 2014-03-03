class Solution {
public:
    void sortColors(int A[], int n) {
        int begin = 0;
        int end = n-1;
        while(begin<end)
        {
            while(begin < n && A[begin] == 0)
                begin++;
            while(end >= 0 && (A[end] == 1 || A[end] == 2))
                end--;
            if(begin < end)
                swap(A[begin], A[end]);
            begin++;
            end--;
        }
        begin = 0;
        end = n-1;
        while(A[begin] == 0)
            begin++;
        while(begin<end)
        {
            while(begin < n && A[begin] == 1)
                begin++;
            while(end >= 0 && (A[end] == 2))
                end--;
            if(begin < end)
                swap(A[begin], A[end]);
            begin++;
            end--;
        }
    }
    
    void swap(int & a, int & b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
};
