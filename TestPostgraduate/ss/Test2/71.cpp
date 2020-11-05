#include <iostream>
#include <vector>
#include <queue>
using namespace std; 
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		vector<int> indegree(numCourses, 0);
		for(int i = 0; i < prerequisites.size(); i++)
			indegree[prerequisites[i][0]]++;//统计每个结点入度情况
		queue<int> q;
		int cnt = 0;
		for(int i = 0; i < numCourses; i++)
			if(indegree[i] == 0)
				q.push(i);
		while(!q.empty()){
			int p = q.front();
			q.pop();
			cnt++;
			for(int i = 0; i < prerequisites.size(); i++){
				if(p == prerequisites[i][1]){
					indegree[prerequisites[i][0]]--;
					if(indegree[prerequisites[i][0]] == 0)
						q.push(prerequisites[i][0]);
				}
			}
		}
		return cnt == numCourses;
    }
};
int main(){
    vector<vector<int>> prerequisites;
    int numCourses,m;
    cin>>numCourses>>m;
    int c1,c2;
    int ch;
    for(int i=0; i<m; i++){
        vector<int> aPrerequisite;
        cin>>c1>>c2;
        aPrerequisite.push_back(c1);
        aPrerequisite.push_back(c2);
        prerequisites.push_back(aPrerequisite);
    }
    bool res=Solution().canFinish(numCourses,prerequisites);
    cout<<(res?"true":"false")<<endl;
    return 0;
}
