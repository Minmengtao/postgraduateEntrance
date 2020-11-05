#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
    	sort(people.begin(), people.end());//升序排序 
    	int i = 0, j = people.size() - 1, cnt = 0;
    	while(i <= j){
    		if(people[i] + people[j] > limit)//只能承载j 
    			j--;
			else if(people[i] + people[j] <= limit){//i和j都能承载 
				i++;
				j--;
			}
			cnt++;
		}
		return cnt;
    }
};
int main(){
    int n,data, limit;
    vector<int> people;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>data;
        people.push_back(data);
    }
    cin >> limit;
    int res=Solution().numRescueBoats(people, limit);
    cout<<res;
    return 0;
}
