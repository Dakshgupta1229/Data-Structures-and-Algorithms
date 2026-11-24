class Solution {

    boolean dfs(int start,int parent,int[][] graph,int[] visited){
        if(parent==-1) visited[start] = 0;
        else if(visited[parent]==0) visited[start] = 1;
        else if(visited[parent]==1) visited[start] = 0;
        for(int i=0;i<graph[start].length;i++){
            int ele = graph[start][i];
            if(visited[ele]==-1){
                boolean result = dfs(ele,start,graph,visited);
                if(result==true) return true;
            }
            else if(visited[ele]==visited[start]) return true;
        }
        return false;
    }

    public boolean isBipartite(int[][] graph) {
        int[] visited = new int[graph.length];
        Arrays.fill(visited,-1);
        for(int i=0;i<graph.length;i++){
            if(visited[i]==-1){
                boolean result = dfs(i,-1,graph,visited);
                if(result==true) return false;
            }
        }

        return true;
    }
}