class Solution {

    boolean dfs(int start,int[][] graph,int[] visited,int[] path_visited,int[] check){
        visited[start] = 1;
        path_visited[start] = 1;
        for(int i=0;i<graph[start].length;i++){
            int ele = graph[start][i];
            if(visited[ele]!=1){
                if(dfs(ele,graph,visited,path_visited,check)) return true;
            }
            else if(visited[ele]==1 && path_visited[ele]==1){
                return true;
            }
        }
        path_visited[start] = 0;
        check[start] = 1;
        return false;
    }

    public List<Integer> eventualSafeNodes(int[][] graph) {
        List<Integer> list = new ArrayList<>();
        int[] visited = new int[graph.length];
        Arrays.fill(visited,0);
        int[] path_visited = new int[graph.length];
        Arrays.fill(visited,0);
        int[] check = new int[graph.length];
        Arrays.fill(check,0);
        for(int i=0;i<graph.length;i++){
            if(visited[i]!=1){
                dfs(i,graph,visited,path_visited,check);
            }
        }
        for(int i=0;i<graph.length;i++){
            if(check[i]==1) list.add(i);
        }
        return list;
    }
}