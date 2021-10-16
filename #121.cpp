class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum=0,size = prices.size();
        for(int i=0;i<size-1;i++){
            if(prices.at(i)<prices.at(i+1)){
                sum+=prices.at(i+1)-prices.at(i);
            }
        }
        return sum;
    }
};
