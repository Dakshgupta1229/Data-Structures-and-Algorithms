class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initial = image[sr][sc];
        vector<vector<int>> visited(image.size(),vector<int>(image[0].size(),0));
        queue<pair<int,int>> q;
        q.push({sr,sc});
        visited[sr][sc] = 1;
        while(q.size()>0){
            int r = q.front().first;
            int c = q.front().second;
            image[r][c] = color;
            q.pop();
            if(r-1>=0 && c>=0 && image[r-1][c]==initial && visited[r-1][c]!=1){
                q.push({r-1,c});
                visited[r-1][c] = 1;
            }
            if(r>=0 && c-1>=0 && image[r][c-1]==initial && visited[r][c-1]!=1){
                q.push({r,c-1});
                visited[r][c-1] = 1;
            }
            if(r+1<image.size() && c>=0 && image[r+1][c]==initial && visited[r+1][c]!=1){
                q.push({r+1,c});
                visited[r+1][c] = 1;
            }
            if(r>=0 && c+1<image[0].size() && image[r][c+1]==initial && visited[r][c+1]!=1){
                q.push({r,c+1});
                visited[r][c+1] = 1;
            }
        }

        return image;
    }
};