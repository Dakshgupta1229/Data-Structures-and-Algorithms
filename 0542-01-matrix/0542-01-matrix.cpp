class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> visited(mat.size(),vector<int>(mat[0].size(),0));
        vector<vector<int>> distance(mat.size(),vector<int>(mat[0].size(),0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    visited[i][j] = 1;
                }
            }
        }
        while(q.size()>0){
            int row = q.front().first.first;
            int column = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            distance[row][column] = dist;
            int delrow[] = {-1,0,1,0};
            int delcol[] = {0,-1,0,1};
            for(int i=0;i<4;i++){
                int newrow = row + delrow[i];
                int newcol = column + delcol[i];
                if(newrow>=0 && newrow<mat.size() && newcol>=0 && newcol<mat[0].size() && visited[newrow][newcol]!=1){
                    q.push({{newrow,newcol},dist+1});
                    visited[newrow][newcol] = 1;
                }
            }
        }
        return distance;
    }
};