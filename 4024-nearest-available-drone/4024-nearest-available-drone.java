class Solution {
    public int nearestDrone(int[][] drones, int[] target) {
        int idx = -1;
        int min_sum = Integer.MAX_VALUE;
        for(int i=0;i<drones.length;i++){
            int x1 = drones[i][0];
            int y1 = drones[i][1];
            int t = drones[i][2];
            int sum = Math.abs(x1 - target[0]) + Math.abs(y1 - target[1]);
            if(sum<=t && min_sum>sum){
                idx = i;
                min_sum = sum;
            }
        }
        return idx;
    }
}