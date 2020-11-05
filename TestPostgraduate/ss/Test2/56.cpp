#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
class Solution{
public:
	static bool cmp(vector<int>& a, vector<int>& b){
		if(a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]))
			return true;
		else
			return false;
	};
	vector<int> findRightInterval(vector<vector<int> >& intervals){
		map<vector<int>, int> ma;
		int m = intervals.size(), n = intervals[0].size();
		for(int i = 0; i < m; i++)
			ma[intervals[i]] = i;
		sort(intervals.begin(), intervals.end(), cmp);
		vector<int> vec(m);
		for(int i = 0; i < m; i++){
			int j;
			for(j = i+1; j < m; j++)
				if(intervals[i][1] <= intervals[j][0])
					break;
			if(j < m)
				vec[ma[intervals[i]]] = ma[intervals[j]];
			else
				vec[ma[intervals[i]]] = -1;
		}
		return vec;
	}
};
int main(){
    vector<vector<int> > intervals;
    int n,start,end;
    cin>>n;
    for(int j=0; j<n; j++){
        vector<int> aInterval;
        cin>>start>>end;
        aInterval.push_back(start);
        aInterval.push_back(end);
        intervals.push_back(aInterval);
    }
    vector<int> res=Solution().findRightInterval(intervals);
    for(int i=0; i<res.size(); i++){
        if (i>0)
            cout<<" ";
        cout<<res[i];
    }
    return 0;
}


