class Solution {

    public boolean bfs(int[][] graph,int[] visited,int start){
        visited[start] = 0;
        Queue<Integer> q = new LinkedList<>();
        q.offer(start);
        while(q.size()>0){
            int ele = q.peek();
            q.poll();
            for(int i=0;i<graph[ele].length;i++){
                int value = graph[ele][i];
                if(visited[value]==-1){
                    if(visited[ele]==0) visited[value] = 1;
                    else visited[value] = 0;
                    q.offer(value);
                }
                else if(visited[value]==visited[ele]) return true;
            }
        }
        return false;
    }

    public boolean isBipartite(int[][] graph) {
        int[] visited = new int[graph.length];
        Arrays.fill(visited,-1);
        for(int i=0;i<graph.length;i++){
            if(visited[i]==-1){
                if(bfs(graph,visited,i)) return false;
            }
        }
        return true;
    }
}