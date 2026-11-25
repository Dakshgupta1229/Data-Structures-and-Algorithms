class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        for(int i=0;i<numCourses;i++){
            adj.add(new ArrayList<>());
        }
        for(int i=0;i<prerequisites.length;i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj.get(v).add(u);
        }
        int[] indegree = new int[numCourses];
        Arrays.fill(indegree,0);
        for(int i=0;i<adj.size();i++){
            ArrayList<Integer> list = adj.get(i);
            for(int j=0;j<list.size();j++){
                int ele = list.get(j);
                indegree[ele] = indegree[ele] + 1;
            }
        }
        Queue<Integer> q = new LinkedList<>();
        for(int i=0;i<indegree.length;i++){
            int ele = indegree[i];
            if(ele==0) q.offer(i);
        }
        List<Integer> result = new ArrayList<>();
        while(q.size()>0){
            int ele = q.peek();
            result.add(ele);
            q.poll();
            ArrayList<Integer> list = adj.get(ele);
            for(int i=0;i<list.size();i++){
                int val = list.get(i);
                indegree[val]--;
                if(indegree[val]==0) q.offer(val);
            }
        }
        if(result.size()==numCourses){
            int[] res = new int[numCourses];
            for(int i=0;i<result.size();i++){
                res[i] = result.get(i);
            }
            return res;
        }
        return new int[]{};
    }
}