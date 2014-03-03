class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        int m = matrix.size();
        int n;
        if(m!=0)
            n = matrix[0].size();
        else
            return res;
        int lowX=0,lowY=0,highX=m-1,highY=n-1;
        while(true)
        {
            
        	for(int iy=lowY;iy<=highY;iy++)
        	{
        	    res.push_back(matrix[lowX][iy]);
        	}
        	lowX++;
        	if(lowX>highX || lowY>highY)
        	    break;
        	for(int ix=lowX;ix<=highX;ix++)
        	{
        	    res.push_back(matrix[ix][highY]);
        	}
        	highY--;
        	if(lowX>highX || lowY>highY)
        	    break;
        	for(int iy=highY;iy>=lowY;iy--)
        	{
        	    res.push_back(matrix[highX][iy]);
        	}
        	highX--;
        	if(lowX>highX || lowY>highY)
        	    break;
        	for(int ix=highX;ix>=lowX;ix--)
        	{
        	    res.push_back(matrix[ix][lowY]);
        	}
        	lowY++;
        	if(lowX>highX || lowY>highY)
        	    break;
        }
        return res;
    }

};
