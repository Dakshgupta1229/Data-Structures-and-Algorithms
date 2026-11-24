class Solution {
    public boolean validPath(int n, int[][] edges, int source, int destination) {
        List<List<Integer>> list = new ArrayList<>();
        for(int i=0;i<n;i++){
            list.add(new ArrayList<>());
        }
        for(int i=0;i<edges.length;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            list.get(u).add(v);
            list.get(v).add(u);
        }
        int[] visited = new int[n];
        Arrays.fill(visited,0);
        Queue<Integer> q = new LinkedList<>();
        q.offer(source);
        visited[source] = 1;
        while(q.size()>0){
            int ele = q.peek();
            q.poll();
            List<Integer> list2 = list.get(ele);
            for(int i=0;i<list2.size();i++){
                int val = list2.get(i);
                if(visited[val]!=1){
                    visited[val] = 1;
                    q.offer(val);
                }
            }
        }
        if(visited[destination]==1) return true;
        return false;
    }
}