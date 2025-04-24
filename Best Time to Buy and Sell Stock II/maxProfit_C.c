int maxProfit(int* prices, int pricesSize) {
    int max = 0;
    int start = prices[0];
    for(int i = 1;i<pricesSize; i++){
        if(start < prices[i]){
            max += prices[i] - start;
        }
        start = prices[i];
    }
    return max;
}