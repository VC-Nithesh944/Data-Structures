//This has a runtime of 1ms and TIme Complexity of O(N).
//This a medium level question which was easier than the 121]
//Approach whenever find a next element greater than current add the difference to profit.
int maxProfit(int* prices, int pricesSize) {
    int i , j;
    int min = 10000;
    int profit = 0 ;
    for (i = 1 ; i < pricesSize ; i++ ){
        if (prices[i-1] < prices[i]){
            profit += (prices[i] - prices[i-1]);
        }
    }
    return profit;
}
