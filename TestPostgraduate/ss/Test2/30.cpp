#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool cmp(vector<int> a,vector<int> b) {
    	if((a[0]==b[0] && a[1]>b[1]) || a[0]<b[0])
    		return true;
    	else
    		return false;
    }
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int len = intervals.size(), i = intervals.size(), cnt = 0;
        vector<int> todos(len,2);
        while(--i>=0){
            for(int val=intervals[i][0]; val<intervals[i][0]+todos[i]; val++)
                for(int j=i-1; j>=0; j--)
                    if(todos[j] && val<=intervals[j][1])
                        todos[j]--;
            cnt += todos[i];
        }
        return cnt;
    }
};
int main(){
    int m,n,data;
    vector<vector<int> > intervals;
    cin>>m;
    for(int j=0; j<m; j++){
        vector<int> aRow;
        for(int i=0; i<2; i++){
            cin>>data;
            aRow.push_back(data);
        }
        intervals.push_back(aRow);
    }
    int res=Solution().intersectionSizeTwo(intervals);
    cout<<res;
    return 0;
}
