#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
2�����η������ۻ��͵Ļ����ϣ����Ǽ����ж��ٸ�����Ĵ�С����[lower, upper]֮�䣬һ�����ص��㷨����ö�ٸ������䣬
��ʱ�临�Ӷ���O(n^2)��һ�����õķ��������÷��η������������ù鲢�����㷨������ֳ��������ߣ��ںϲ���������֮ǰ��
������������е�ÿһ��Ԫ�أ����ұ������ҵ�һ����Χ��ʹ���������Χ�е�Ԫ�������Ԫ�ع��ɵ����������[lower, upper]֮�䣬
�����ұ��������ҵ������߽磬��Ϊm��n������m�����ұ������е�һ��ʹ��sum[m] - sum[i] >= lower��λ�ã�
��n�ǵ�һ��ʹ��sum[n] - sum[i] > upper��λ�ã�����n-m���������Ԫ��i�����ɵ�λ��[lower, upper]��Χ�����������
��Ϊ�������߶����Ѿ�����ģ������Ϳ��Ա��ⲻ��Ҫ�ıȽϣ���Ҳ��Ϊʲô�����ܽ�ʱ�临�Ӷȴ�O(n^2)���͵�O(nlogn)���ؾ����ڣ���
��������������������������������
��Ȩ����������ΪCSDN������ħ��Magicbean����ԭ�����£���ѭCC 4.0 BY-SA��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
ԭ�����ӣ�https://blog.csdn.net/magicbean2/article/details/76576674*/
class Solution{
public:
	int lower, upper;
	vector<long> v;
	int countRangeSum(vector<int> nums, int lower, int upper){
		v.push_back(0);
		for(int i = 0; i < nums.size(); i++)
			v.push_back(v.back() + nums[i]);//��¼nums��ǰ׺�� 
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
