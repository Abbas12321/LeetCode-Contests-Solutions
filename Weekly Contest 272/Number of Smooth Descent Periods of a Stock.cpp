class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans=prices.size(); // all single day price will be included
        if(ans==1) // if size is 1
            return ans;
        long long cnt=0;
		// for checking contiguous unit decrease in price
        for(long long i=1;i<prices.size();i++){
            if(prices[i-1]-prices[i]==1){
                cnt++;
                ans+=cnt; // this is the cumulative sum of number of contiguous array
            }else{
                cnt=0;
            }
        }
        return ans;
    }
};
