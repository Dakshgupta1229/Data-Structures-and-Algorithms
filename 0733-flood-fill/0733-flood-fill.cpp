class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int old_color = image[sr][sc];
        vector<vector<int>> visited(image.size(),vector<int>(image[0].size(),0));
        queue<pair<int,int>> q;
        q.push({sr,sc});
        visited[sr][sc] = 1;
        while(q.size()>0){
            int row = q.front().first;
            int column = q.front().second;
            q.pop();
            image[row][column] = color;
            int delrow[] = {-1,0,1,0};
            int delcol[] = {0,-1,0,1};
            for(int i=0;i<4;i++){
                int newrow = row + delrow[i];
                int newcol = column + delcol[i];
                if(newrow>=0 && newrow<image.size() && newcol>=0 && newcol<image[0].size() && image[newrow][newcol]==old_color && visited[newrow][newcol]==0){
                    visited[newrow][newcol] = 1;
                    q.push({newrow,newcol});
                }
            }
        }
        return image;

    }
};