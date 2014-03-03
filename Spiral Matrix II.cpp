class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<int> a(n,0);
        vector<vector<int> > res(n, a);
        
        int lowX=0,lowY=0,highX=n-1,highY=n-1;
        int count=1;
        while(true)
        {
            
        	for(int iy=lowY;iy<=highY;iy++)
        	{
        	    res[lowX][iy] = count;
        	    //res.push_back(matrix[lowX][iy]);
        	    count++;
        	}
        	lowX++;
        	if(lowX>highX || lowY>highY)
        	    break;
        	for(int ix=lowX;ix<=highX;ix++)
        	{
        	    res[ix][highY] = count;
        	    count++;
        	}
        	highY--;
        	if(lowX>highX || lowY>highY)
        	    break;
        	for(int iy=highY;iy>=lowY;iy--)
        	{
        	    res[highX][iy] = count;
        	    count++;
        	}
        	highX--;
        	if(lowX>highX || lowY>highY)
        	    break;
        	for(int ix=highX;ix>=lowX;ix--)
        	{
        	    res[ix][lowY] = count;
        	    count++;
        	}
        	lowY++;
        	if(lowX>highX || lowY>highY)
        	    break;
        }
        return res;
    }
    
};
