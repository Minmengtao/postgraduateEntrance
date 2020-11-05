#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minArray(vector<int>& numbers) {
    	for(int i = 1; i < numbers.size(); i++){
    		if(numbers[i] < numbers[i-1])
    			return numbers[i];
		}
		return numbers[0];
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
	cout << Solution().minArray(numbers);
	return 0;
} 
