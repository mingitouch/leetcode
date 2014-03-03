class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int high = n-1;
        int low = 0;
        int mid = (high+low)/2;
        vector<int> result;
        while(low<=high)
        {
            if(A[mid] == target)
            {
                high = mid;
                low = mid;
                while(high < n && A[high] == target)
                    high++;
                while(low >= 0 && A[low] == target)
                    low--;
                result.push_back(low+1);
                result.push_back(high-1);
                return result;
            }
            if(A[mid] < target)
            {
                low = mid + 1;
                mid = (low+high)/2;
            }
            else
            {
                high = mid - 1;
                mid = (low+high)/2;
            }
            
        }
        result.push_back(-1);
        result.push_back(-1);
        return result;
    }
};
