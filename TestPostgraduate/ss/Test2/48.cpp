#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
    	map<int, int> out, in;//出度以及入度 
    	for(int i = 0; i < trust.size(); i++){
    		out[trust[i][0]]++;
    		in[trust[i][1]]++;
		}
		int judge = -1;
		for(int i = 1; i <= N; i++){
			if(out[i])
				continue;
			else if(in[i] == N-1){
				judge = i;
				break;
			}
		} 
		return judge;
    }
};

int main(){
    int N,M;
    vector<vector<int> > trust;
    cin>>N>>M;
    int p1,p2;
    for(int i=0; i<M; i++){
        cin>>p1>>p2;
        vector<int> oneTrust;
        oneTrust.push_back(p1);
        oneTrust.push_back(p2);
        trust.push_back(oneTrust);
    }
    int res=Solution().findJudge(N, trust);
    cout<<res<<endl;
}
