#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
    	int ans = 0;
    	int n = price.size();
    	for(int i = 0; i < n; i++)
    		ans += price[i] * needs[i];
    	for(auto bag: special){
    		bool res = true;
    		for(int i = 0; i < n && res; i++)
    			if(needs[i] < bag[i])
    				res = false;
    		if(res){//¹ºÂò´óÀñ°ü 
    			for(int i = 0; i < n; i++)
    				needs[i] -= bag[i];
    			ans = min(ans, shoppingOffers(price, special, needs) + bag.back());
    			for(int i = 0; i < n; i++)
    				needs[i] += bag[i];
			}
		}
    	return ans;
    }
};
int main(){
    vector<int> price;
    vector<vector<int>> special;
    vector<int> needs;
    int n,m;
    cin>>n;
    int p,need;
    for(int i=0; i<n; i++){
        cin>>p;
        price.push_back(p);
    }
    for(int i=0; i<n; i++){
        cin>>need;
        needs.push_back(need);
    }
    cin>>m;
    for(int i=0; i<m; i++){
        vector<int> oneSpecial;
        int qty;
        for(int j=0; j<n; j++){
            cin>>qty;
            oneSpecial.push_back(qty);
        }
        int amount;
        cin>>amount;
        oneSpecial.push_back(amount);
        special.push_back(oneSpecial);
    }
    int res=Solution().shoppingOffers(price, special, needs);
    cout<<res<<endl;
    return 0;
}
