class Solution {

    void bfs(int start,List<List<Integer>> list,int[] visited){
        Queue<Integer> q = new LinkedList<>();
        q.offer(start);
        visited[start] = 1;
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
    }

    public int findCircleNum(int[][] isConnected) {
        List<List<Integer>> list = new ArrayList<>();
        for(int i=0;i<isConnected.length;i++){
            list.add(new ArrayList<>());
        }
        for(int i=0;i<isConnected.length;i++){
            for(int j=0;j<isConnected[i].length;j++){
                if(isConnected[i][j]==1){
                    if(i!=j){
                        list.get(i).add(j);
                    }
                }
            }
        }
        int[] visited = new int[list.size()];
        Arrays.fill(visited,0);
        int count = 0;
        for(int i=0;i<list.size();i++){
            if(visited[i]!=1){
                count++;
                bfs(i,list,visited);
            }
        }
        return count;
    }
}