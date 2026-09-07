class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int MaxProfit=0;
        int MinProfit=prices[0];
        for(int i=1;i<n;i++){
            MinProfit=min(MinProfit,prices[i]);
            MaxProfit=max(MaxProfit,prices[i]-MinProfit);
        }
        return MaxProfit;
    }
};