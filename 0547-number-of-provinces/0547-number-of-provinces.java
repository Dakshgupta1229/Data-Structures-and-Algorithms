class Solution {

    public void bfs(ArrayList<ArrayList<Integer>> adj,int[] visited,int start){
        Queue<Integer> q = new LinkedList<>();
        q.offer(start);
        visited[start] = 1;
        while(q.size()>0){
            int value = q.peek();
            q.poll();
            ArrayList<Integer> list2 = adj.get(value);
            for(int i=0;i<list2.size();i++){
                int ele = list2.get(i);
                if(visited[ele]!=1){
                    visited[ele] = 1;
                    q.offer(ele);
                }
            }
        }
    }

    public int findCircleNum(int[][] isConnected) {
        ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>>();
        int n = isConnected.length;
        for(int i=0;i<n;i++){
            adj.add(new ArrayList<>());
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<isConnected[i].length;j++){
                if(isConnected[i][j]==1){
                    adj.get(i).add(j);
                }
            }
        }
        int[] visited = new int[n];
        Arrays.fill(visited,0);
        int count = 0;
        for(int i=0;i<n;i++){
            if(visited[i]!=1){
                count++;
                bfs(adj,visited,i);
            }
        }
        return count;
    }
}