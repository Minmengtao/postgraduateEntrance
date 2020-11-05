#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();
        //if(!n)
        //    return 0;
        unordered_map<int, int> need;
        unordered_map<int, int>::iterator iter;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(answers[i] == 0){
                cnt++;
                continue;
            }
            need[answers[i]]++;
            if(need[answers[i]] >= 1 + answers[i]){
                cnt += (1 + answers[i]);
                need[answers[i]] -= (1 + answers[i]);
            }
        }
        for(iter = need.begin(); iter != need.end(); iter++)
            if(iter->second != 0)
                cnt += (1 + iter->first);
        return cnt;
    }
};
int main(){
	vector<int> answers;
	int n, data;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> data;
		answers.push_back(data);
	}
	cout << Solution().numRabbits(answers);
	return 0;
}
