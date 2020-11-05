#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

class Solution {
public:
	static bool cmp(vector<int> a, vector<int> b){//按照右区间大小排序，若右区间相同，则按 
		if(a[1] < b[1] || (a[1] == b[1] && a[0] > b[0]))
			return true;
		else
			return false;
	}
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    	sort(intervals.begin(), intervals.end(), cmp);
    	int count = 1, com = intervals[0][1];
    	for(vector<int> v: intervals)
    		if(v[0] >= com){
    			count++;
    			com = v[1];
			}
		return intervals.size() - count;
    }
};
int main(){
	vector<vector<int>> intervals;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		vector<int> v(2);
		cin >> v[0] >> v[1];
		intervals.push_back(v);
	}
	cout << Solution().eraseOverlapIntervals(intervals);
	return 0;
}
