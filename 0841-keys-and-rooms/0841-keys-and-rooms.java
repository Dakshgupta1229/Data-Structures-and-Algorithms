class Solution {
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        int[] visited = new int[rooms.size()];
        Queue<Integer> q = new LinkedList<>();
        q.offer(0);
        visited[0] = 1;
        while(q.size()>0){
            int ele = q.peek();
            q.poll();
            List<Integer> list = rooms.get(ele);
            for(int i=0;i<list.size();i++){
                int val = list.get(i);
                if(visited[val]!=1){
                    visited[val] = 1;
                    q.offer(val);
                }
            }
        }
        for(int i=0;i<visited.length;i++){
            if(visited[i]!=1) return false;
        }
        return true;
    }
}