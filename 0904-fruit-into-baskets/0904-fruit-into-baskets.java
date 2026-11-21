class Solution {
    public int totalFruit(int[] fruits) {
        Map<Integer,Integer> map = new HashMap<>();
        int i=0;
        int j=0;
        int count = 0;
        int max_count = 0;
        while(j<fruits.length){
            if(!map.containsKey(fruits[j])) map.put(fruits[j],1);
            else map.put(fruits[j],map.get(fruits[j])+1);
            count++;
            if(map.size()<=2){
                if(max_count<count) max_count = count;
            }
            else{
                while(map.size()>2 && i<fruits.length){
                    int freq = map.get(fruits[i]);
                    if(freq==1) map.remove(fruits[i]);
                    else map.put(fruits[i],freq-1);
                    count--;
                    i++;
                }
            }
            j++;
        }
        if(max_count<count) max_count = count;
        return max_count;
    }
}