class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        ArrayList<ArrayList<Integer>> list = new ArrayList<>();
        for(int i=0;i<numCourses;i++){
            list.add(new ArrayList<>());
        }
        for(int i=0;i<prerequisites.length;i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            list.get(u).add(v);
        }
        int[] indegree = new int[numCourses];
        Arrays.fill(indegree,0);
        for(int i=0;i<list.size();i++){
            ArrayList<Integer> list2 = list.get(i);
            for(int j=0;j<list2.size();j++){
                int ele = list2.get(j);
                indegree[ele] = indegree[ele] + 1;
            }
        }
        Queue<Integer> q = new LinkedList<>();
        for(int i=0;i<indegree.length;i++){
            int ele = indegree[i];
            if(ele==0) q.offer(i);
        }
        int count = 0;
        while(q.size()>0){
            int ele = q.peek();
            count++;
            q.poll();
            ArrayList<Integer> list2 = list.get(ele);
            for(int i=0;i<list2.size();i++){
                int val = list2.get(i);
                indegree[val]--;
                if(indegree[val]==0) q.offer(val);
            }
        }
        if(count==numCourses) return true;
        return false;
    }
}