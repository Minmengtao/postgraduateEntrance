#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
2、分治法：在累积和的基础上，我们计算有多少个区间的大小落在[lower, upper]之间，一个朴素的算法就是枚举各个区间，
其时间复杂度是O(n^2)。一个更好的方法是利用分治法来处理，即利用归并排序算法将数组分成左右两边，在合并左右数组之前，
对于左边数组中的每一个元素，在右边数组找到一个范围，使得在这个范围中的元素与左边元素构成的区间和落在[lower, upper]之间，
即在右边数组中找到两个边界，设为m，n，其中m是在右边数组中第一个使得sum[m] - sum[i] >= lower的位置，
而n是第一个使得sum[n] - sum[i] > upper的位置，这样n-m就是与左边元素i所构成的位于[lower, upper]范围的区间个数。
因为左右两边都是已经有序的，这样就可以避免不必要的比较（这也是为什么我们能将时间复杂度从O(n^2)降低到O(nlogn)的秘诀所在）。
————————————————
版权声明：本文为CSDN博主「魔豆Magicbean」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/magicbean2/article/details/76576674*/
class Solution{
public:
	int lower, upper;
	vector<long> v;
	int countRangeSum(vector<int> nums, int lower, int upper){
		v.push_back(0);
		for(int i = 0; i < nums.size(); i++)
			v.push_back(v.back() + nums[i]);//记录nums的前缀和 
		this->lower = lower;
		this->upper = upper;
		return dfs(0, v.size());
	}
	int dfs(int low, int high){
		if(high - low <= 1)
			return 0;
		int mid = (high + low) / 2, cnt = 0;
		int m = mid, n = mid;
		cnt = dfs(low, mid) + dfs(mid, high);
		for(int i = low; i < mid; i++) {
            while(m < high && v[m] - v[i] < lower)  ++m;
            while(n < high && v[n] - v[i] <= upper) ++n;
            cnt += (n - m);
        }
        inplace_merge(v.begin() + low, v.begin() + mid, v.begin() + high);
        return cnt;
	}
}; 
int main(){
    vector<int> nums;
    int n,data,lower,upper;
    cin>>n;
    for(int j=0; j<n; j++){
        cin>>data;
        nums.push_back(data);
    }
    cin>>lower>>upper;
    int res=Solution().countRangeSum(nums,lower,upper);
    cout<<res<<endl;
    return 0;
}
