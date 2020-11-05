#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
    	if(arr[start] == 0)
    		return true;
    	unordered_map<int, int> need;
    	queue<int> q;
    	q.push(start);
    	need[start] = 1;
    	while(!q.empty()){
    		int begin = q.front();
    		q.pop();
    		for(int i = begin - arr[begin]; i <= begin + arr[begin]; i += 2*arr[begin])
    			if(i >= 0 && i < arr.size() && !need.count(i)){
    				if(arr[i] == 0)
    					return true;
    				q.push(i);
    				need[i] = 1;
				}
		}
		return false;
    }
};
int main(){
	vector<int> arr;
	int n, start, data;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> data;
		arr.push_back(data);
	}
	cin >> start;
	bool res = Solution().canReach(arr, start);
	cout<<(res?"true":"false")<<endl;
	return 0;
}
