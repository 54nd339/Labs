import java.util.*;
class Solution {
    public int coinChange(int[] coins, int amount) {
        int[] minCountToGetSum = new int[amount + 1];
        Arrays.fill(minCountToGetSum,-1);
        minCountToGetSum[0] = 0;
        for(int amt = 1; amt <= amount; ++amt){
            int min = Integer.MAX_VALUE;
            for(int coin: coins){
                if(amt - coin >= 0 && minCountToGetSum[amt - coin] != -1){
                    min = 1 + minCountToGetSum[amt - coin] < min ? 1 + minCountToGetSum[amt - coin] : min;
                }
            }
            
            minCountToGetSum[amt] = min == Integer.MAX_VALUE ? -1 : min;
        }
        return minCountToGetSum[amount];
    }
}
public class coin{
    public static void main(String args[]) {
        Solution ob = new Solution();
        int arr[] = { 2, 5, 20 };
        System.out.println(ob.coinChange(arr, 73));
    }
}