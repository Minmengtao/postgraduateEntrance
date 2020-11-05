#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
    	unordered_map<int, int> need;
    	int maxDot = 0;
    	int m = wall.size();
    	for(int i = 0; i < m; i++){
    		int x = 0;
			//cout << wall[i].size() << endl;
    		for(int j = 0; j < wall[i].size() - 1; j++){
    			x += wall[i][j];
    			need[x]++;
				//cout << "x = " << x << " need[x] = " << need[x] << endl;
    			maxDot = max(maxDot, need[x]);
			}
			//cout << endl;
		}
		return m - maxDot;
    }
};

vector<int> string2int(string str){
    vector<int> nums;
    int num;
    stringstream sstream(str);
    while(sstream >> num)
        nums.push_back(num);
    return nums;
}
int main(){
    vector<vector<int> > wall;
    vector<int> v;
    string aLine;
    int n,k,data;
    cin>>n;
    getchar();
    for(int i=0; i<n; i++){
        getline(cin,aLine);
        v=string2int(aLine);
        wall.push_back(v);
    }
    int res=Solution().leastBricks(wall);
    cout<<res<<endl;
    return 0;
}
