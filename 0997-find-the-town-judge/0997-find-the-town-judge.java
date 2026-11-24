class Solution {
    public int findJudge(int n, int[][] trust) {
        int[] visited = new int[n+1];
        int[] visited2 = new int[n+1];
        Arrays.fill(visited,0);
        Arrays.fill(visited2,0);
        for(int i=0;i<trust.length;i++){
            int ele1 = trust[i][0];
            int ele2 = trust[i][1];
            visited[ele1] = visited[ele1] + 1;
            visited2[ele2] = visited2[ele2] + 1;
        }
        for(int i=1;i<=n;i++){
            if(visited[i]==0 && visited2[i]==n-1) return i;
        }
        return -1;
    }
}