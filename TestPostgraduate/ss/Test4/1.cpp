#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
	int CalcCost(vector<vector<int>>& costs){
		//飞往两个城市的优先级不一样，如果飞往的价钱差不多优先为价格差距大的安排城市
		//先计算到A的和到B的差距
		vector<int> cost;
		int sum = 0;
		for(int i = 0; i < costs.size(); i++){
			cost.push_back(costs[i][1] - costs[i][0]);
			sum += costs[i][0];
		}
		sort(cost.begin(), cost.end());
		for(int i = 0; i < cost.size() / 2; i++)//直接前半部分去B，后半部分去A
			sum += cost[i];
		return sum;
	}
};
int main(){
    int N;
    vector<vector<int> > costs;
    cin>>N;
    int costA,costB;
    for(int i=0; i<2*N; i++){
        cin>>costA>>costB;
        vector<int> onePerson;
        onePerson.push_back(costA);
        onePerson.push_back(costB);
        costs.push_back(onePerson);
    }
    int res=Solution().CalcCost(costs);
    cout<<res<<endl;
}
