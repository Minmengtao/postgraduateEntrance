#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
	int CalcCost(vector<vector<int>>& costs){
		//�����������е����ȼ���һ������������ļ�Ǯ�������Ϊ�۸����İ��ų���
		//�ȼ��㵽A�ĺ͵�B�Ĳ��
		vector<int> cost;
		int sum = 0;
		for(int i = 0; i < costs.size(); i++){
			cost.push_back(costs[i][1] - costs[i][0]);
			sum += costs[i][0];
		}
		sort(cost.begin(), cost.end());
		for(int i = 0; i < cost.size() / 2; i++)//ֱ��ǰ�벿��ȥB����벿��ȥA
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
