class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        vector<vector<int>> visited(image.size(),vector<int>(image[0].size(),0));
        queue<pair<int,int>> q;
        q.push({sr,sc});
        visited[sr][sc] = 1;
        int value = image[sr][sc];
        while(q.size()>0){
            auto it = q.front();
            q.pop();
            int i1 = it.first;
            int j1 = it.second;
            image[i1][j1] = color;
            if(i1-1>=0 && image[i1-1][j1]==value && visited[i1-1][j1]==0){
                visited[i1-1][j1] = 1;
                q.push({i1-1,j1});
            }
            if(i1+1<image.size() && image[i1+1][j1]==value && visited[i1+1][j1]==0){
                visited[i1+1][j1] = 1;
                q.push({i1+1,j1});
            }
            if(j1-1>=0 && image[i1][j1-1]==value && visited[i1][j1-1]==0){
                visited[i1][j1-1] = 1;
                q.push({i1,j1-1});
            }
            if(j1+1<image[0].size() && image[i1][j1+1]==value && visited[i1][j1+1]==0){
                visited[i1][j1+1] = 1;
                q.push({i1,j1+1});
            }
        }
        return image;
    }
};