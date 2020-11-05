#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
    	vector<int> vec(26);
		for(char ch: tasks)
			vec[ch -'A']++;
		sort(vec.rbegin(), vec.rend());
		int sum = 1;
		while(sum < vec.size() && vec[sum] == vec[0])
			sum++;
		return max(sum+(n-1)*vec[0]-1, tasks.size());
    }
};
int main(){
    vector<char> v;
    int len,n;
    char data;
    cin>>len;
    for(int i=0; i<len; i++){
        cin>>data;
        v.push_back(data);
    }
    cin>>n;
    int result=Solution().leastInterval(v,n);
    cout<<result<<endl;
    return 0;
}
