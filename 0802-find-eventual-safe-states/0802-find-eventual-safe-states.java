class Solution {
    public List<Integer> eventualSafeNodes(int[][] graph) {
        List<Integer> list = new ArrayList<>();
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        for(int i=0;i<graph.length;i++){
            adj.add(new ArrayList<>());
        }
        int[] indegree = new int[graph.length];
        Arrays.fill(indegree,0);
        for(int i=0;i<graph.length;i++){
            for(int j=0;j<graph[i].length;j++){
                int ele = graph[i][j];
                adj.get(ele).add(i);
                indegree[i]++;
            }
        }
        Queue<Integer> q = new LinkedList<>();
        for(int i=0;i<indegree.length;i++){
            int ele = indegree[i];
            if(ele==0) q.offer(i);
        }
        while(q.size()>0){
            int ele = q.peek();
            list.add(ele);
            q.poll();
            ArrayList<Integer> list2 = adj.get(ele);
            for(int i=0;i<list2.size();i++){
                int val = list2.get(i);
                indegree[val]--;
                if(indegree[val]==0) q.offer(val);
            }
        }
        Collections.sort(list);
        return list;
    }
}