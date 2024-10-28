//Beats 100% has time complexity of O(N) and runtime of 2ms

//Approach : Iterate through array once 
//Keep track of the min element from the array once
//continuosly find profit by current price and min price
//Keep track of the max profit

int maxProfit(int* prices, int pricesSize) {
    int i;
    int min=10000;
    int profit = 0;
    for (i = 0;i<pricesSize;i++){
        if(prices[i] < min){
            min= prices[i];
        }
        if (prices[i]-min > profit){
            profit = prices[i] - min;
        }
    }
    return profit;
}
