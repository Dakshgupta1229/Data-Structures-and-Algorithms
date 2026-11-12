class Solution {

    public void bfs(ArrayList<ArrayList<Integer>> list,int[] visited,int start){
        Queue<Integer> q = new LinkedList<>();
        q.offer(start);
        visited[start] = 1;
        while(q.size()>0){
            int ele = q.peek();
            q.poll();
            ArrayList<Integer> list2 = list.get(ele);
            for(int i=0;i<list2.size();i++){
                int value = list2.get(i);
                if(visited[value]!=1){
                    visited[value] = 1;
                    q.offer(value);
                }
            }
        }
    }

    public int findCircleNum(int[][] isConnected) {
        ArrayList<ArrayList<Integer>> list = new ArrayList<ArrayList<Integer>>();
        for(int i=0;i<isConnected.length+1;i++){
            list.add(new ArrayList<Integer>());
        }
        for(int i=0;i<isConnected.length;i++){
            for(int j=0;j<isConnected[i].length;j++){
                if(isConnected[i][j]==1 && i!=j){
                    list.get(i+1).add(j+1);
                }
            }
        }
        int count = 0;
        int[] visited = new int[isConnected.length+1];
        Arrays.fill(visited,0);
        for(int i=1;i<isConnected.length+1;i++){
            if(visited[i]!=1){
                count++;
                bfs(list,visited,i);
            }
        }
        return count;
    }
}