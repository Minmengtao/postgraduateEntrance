#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
	int trap(vector<int>& height){
		//填充本函数完成功能 
		vector<int> maxl(height.size()), maxr(height.size());
		int sum = 0;
		for(int i = 1; i < height.size()-1; i++)
			maxl[i] = max(maxl[i-1], height[i-1]);
		for(int j = height.size()-2; j>=0; j--)
			maxr[j] = max(maxr[j+1], height[j+1]);
		for(int i = 0; i < height.size()-1; i++){
			int mi = min(maxr[i], maxl[i]);
			if(mi > height[i])
				sum += (mi - height[i]);
		}
		return sum;
	}
};
int main(){
    int h;
    vector<int> v;
    while(cin>>h)
        v.push_back(h);
    int res=Solution().trap(v);
    cout<<res<<endl;
    return 0;
}
