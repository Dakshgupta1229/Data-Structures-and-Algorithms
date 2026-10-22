class Solution {
    public int maximumUnits(int[][] boxTypes, int truckSize) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b) -> Integer.compare(b[1],a[1]));
        for(int i=0;i<boxTypes.length;i++){
            int ele1 = boxTypes[i][0];
            int ele2 = boxTypes[i][1];
            pq.offer(new int[]{ele1,ele2});
        }
        int sum = 0;
        while(pq.size()>0){
            int[] arr = pq.peek();
            int first = arr[0];
            int second = arr[1];
            pq.poll();
            if(first<=truckSize){
                sum = sum + (first * second);
                truckSize -= first;
            }
            else{
                sum = sum + (truckSize * second);
                break;
            }
        }
        return sum;
    }
}