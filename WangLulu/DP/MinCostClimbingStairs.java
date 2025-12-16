package DP;

import java.util.HashMap;
import java.util.Map;

public class MinCostClimbingStairs {
        public int minCostClimbingStairs(int[] cost) {
        int n =cost.length;
        int [] minCost = new int [n+1];
        minCost[0] = 0;
        minCost[1] = 0;
        for(int i =2;i<=n;i++){
            minCost[i] = Math.min(cost[i-1]+minCost[i-1],cost[i-2]+minCost[i-2]);
        }
        return minCost[n];
    }
}
class Solution {
    private int[] cost;
    private Map<Integer,Integer> map = new HashMap<>();
    public int minCostClimbingStairs(int[] cost) {
        this.cost = cost;
        return MinCost(cost.length);
    }
    public int MinCost(int i){
        if(i == 0 || i==1){
            return 0;
        }
        if(map.containsKey(i)){
            return map.get(i);
        }
        int cost1 = MinCost(i - 1) + cost[i - 1];
        int cost2 = MinCost(i - 2) + cost[i - 2];
        int minCost = Math.min(cost1, cost2);
        map.put(i,minCost);
        return minCost;
    }
}
