class Solution {
public:
    int maxArea(vector<int> &height) {
        int currArea = 0;
        int maxArea = INT_MIN;
        int high = height.size()-1;
        int low = 0;
        while(low <= high)
        {
            currArea = (high-low) * min(height[low], height[high]);
            maxArea = max(currArea, maxArea);
            if(height[low] <= height[high])
                low++;
            else
                high--;
        }
        return maxArea;
    }
};
