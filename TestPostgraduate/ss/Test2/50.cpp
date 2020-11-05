#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

//找出根节点到叶结点最长的距离 
class Solution{
public:
	int networkDelayTime(vector<vector<int>>& times, int N, int K){
		vector<int> vec(N + 1, INT_MAX);
		int res = 0;
		vec[K] = 0;
		for(int i = 1; i < N; i++)
			for(auto e: times){
				int u = e[0], v = e[1], w = e[2];
				if(vec[v] > vec[u] + w && vec[u] != INT_MAX)
					vec[v] = vec[u] + w;
			}
		for(int i = 1; i <= N; i++)
			res = max(res, vec[i]);
		return res;
	}
};

int main(){
    int N,M,K;
    vector<vector<int> > times;
    cin>>N>>M>>K;
    int u,v,w;
    for(int i=0; i<M; i++){
        cin>>u>>v>>w;
        vector<int> time;
        time.push_back(u);
        time.push_back(v);
        time.push_back(w);
        times.push_back(time);
    }
    int res=Solution().networkDelayTime(times,N,K);
    cout<<res<<endl;
}
