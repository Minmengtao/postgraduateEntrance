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
    	unordered_map<int, int> window, cnt;//��¼ÿ�α�������������������ÿ�α��������ظ�
		q.push(0);
		window[0] = 0;
		while(!q.empty()){
			int x = q.front(), step = window[x];
			q.pop();
			if(x == arr.size() - 1)
				return step;
            //ÿ�α����������ʱ�򶼻��ظ����㣬�������¸ô�����ֻ����һ��
            if(!cnt.count(arr[x])){//��һ��cntӳ�䣬������ͬ��arr[i]ֻ����һ��
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
