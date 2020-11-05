#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	int sum = 0;
    	for(int i = 1; i < prices.size(); i++)
    		if(prices[i] > prices[i-1])
    			sum += prices[i] - prices[i-1];
		return sum;
    }
};
int main(){
    int n,data;
    vector<int> prices;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>data;
        prices.push_back(data);
    }
    int res=Solution().maxProfit(prices);
    cout<<res;
    return 0;
}
