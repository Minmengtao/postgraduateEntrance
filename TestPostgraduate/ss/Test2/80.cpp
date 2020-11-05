#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
    	unordered_map<int, vector<int>> need;
    	for(int i = 0; i < arr.size(); i++)
    		need[arr[i]].push_back(i);
    	queue<int> q;
    	unordered_map<int, int> window, cnt;//记录每次遍历的数组索引，并且每次遍历都不重复
		q.push(0);
		window[0] = 0;
		while(!q.empty()){
			int x = q.front(), step = window[x];
			q.pop();
			if(x == arr.size() - 1)
				return step;
            //每次遍历到这里的时候都会重复计算，所以重新该处代码只遍历一遍
            if(!cnt.count(arr[x])){//加一个cnt映射，表明相同的arr[i]只遍历一次
			    for(int i = 0; i < need[arr[x]].size(); i++)
				    if(!window.count(need[arr[x]][i])){
				    	q.push(need[arr[x]][i]);
				    	window[need[arr[x]][i]] = step + 1;
				    }
                cnt[arr[x]] = 1;
            }
			if(x+1<arr.size() && !window.count(x+1)){
				q.push(x+1);
				window[x+1] = step + 1;
			}
			if(x-1>=0 && !window.count(x-1)){
				q.push(x-1);
				window[x-1] = step + 1;
			}
		}
		return -1;
    }
};
int main(){
	int n, data;
	vector<int> arr;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> data;
		arr.push_back(data);
	}
	cout << Solution().minJumps(arr);
	return 0;
}
