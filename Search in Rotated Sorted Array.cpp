class Solution {
public:
    int search(int A[], int n, int target) {
        return find(A, 0, n-1, target);
    }
    
    int find(int A[], int low, int high, int target)
    {
        if(low>high)
            return -1;
        else if(low == high && A[low] != target)
            return -1;
            
        int mid = (low + high) / 2;
        if(A[mid] == target)
            return mid;
        if(A[low] <= A[mid])
        {
            if(target < A[low] || target > A[mid])  
                return find(A,mid+1,high,target);  
            else  
                return find(A,low,mid-1,target);
        }
        else
        {
            if(A[high] < target || A[mid] > target)
                return find(A, low, mid-1, target);
            else
                return find(A, mid+1, high, target);
        }
    }
};