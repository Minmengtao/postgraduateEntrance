#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

class Solution {
public:
	vector<int> A;
	int cnt;
	map<vector<int>, int> m;
    int numSquarefulPerms(vector<int>& A) {
    	sort(A.begin(), A.end());
    	this->A = A;
    	cnt = 0;
    	dfs(0);
    	return cnt;
    }
    void dfs(int x){
    	if(x == A.size()){
			vector<int> v = A;
			reverse(v.begin(), v.end());
			if(!m.count(A)){
    			cnt++;
				m[A] = 1;
			}
			if(!m.count(v)){
    			cnt++;
				m[v] = 1;
			}
    		return;
		}
		for(int i = x; i < A.size(); i++){
			if(i != x && A[x] == A[i])
				continue;
			swap(A[i], A[x]);
			if(x == 0 || judge(A[x]+A[x-1]))
				dfs(x+1);
		}
	}
	bool judge(int n){
        if(n == (int)sqrt(n)*(int)sqrt(n))
            return true;
        return false;
    }
};
int main(){
	vector<int> A;
	int n;
	cin >> n;
	for(int i =0; i < n; i++){
		int num;
		cin >> num;
		A.push_back(num);
	}
	cout << Solution().numSquarefulPerms(A);
	return 0;
}
