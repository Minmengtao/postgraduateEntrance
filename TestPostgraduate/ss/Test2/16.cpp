#include <iostream>
#include <vector>
#include <deque> 
#include <algorithm>
using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
    	vector<int> vec;
    	vec.push_back(0);
    	for(int  i = 0; i < A.size(); i++)//¼ÆËãÇ°×ººÍ 
    		vec.push_back(A[i] + vec.back());
    	int sum = A.size() + 1;
    	deque<int> d;
    	for(int  i = 0; i <= A.size(); i++){
    		while(!d.empty() && vec[i] <= vec[d.back()])
    			d.pop_back();
    		while(!d.empty() && vec[i] - vec[d.front()] >= K){
    			sum = min(sum, i-d.front());
    			d.pop_front();
			}
    		d.push_back(i);
		}
		if(sum == A.size() + 1)
			return -1;
		else 
			return sum;
    }
};
int main(){
    vector<int> A;
    int n, data, k;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> data;
        A.push_back(data);
    }
    cin >> k;
    int result = Solution().shortestSubarray(A,k);
    cout << result << endl;
    return 0;
}
