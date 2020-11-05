#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& numbers) {
        //1自动排序O(NlogN)
        //sort(numbers.begin(), numbers.end());
        //return numbers[0];
        //2.直接查找O(n)
        //for(int i = 1; i < numbers.size(); i++)
    	//	if(numbers[i] < numbers[i-1])
    	//		return numbers[i];
		//return numbers[0];
        //二分查找
        int low = 0, high = numbers.size() - 1, mid;
        while(low <= high){
        	mid = (low + high) / 2;
        	if(numbers[mid] < numbers[high])
        		high = mid;
        	else if(numbers[mid] > numbers[high])
        		low = mid + 1;
        	else
        		high--;
		}
		return numbers[low];
    }
};
int main(){
	int n, data;
	vector<int> numbers;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> data;
		numbers.push_back(data);
	}
	cout << Solution().findMin(numbers);
	return 0;
}
