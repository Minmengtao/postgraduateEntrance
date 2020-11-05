#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

class Solution{
public:
	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges){
		vector<int> vec;
		vector<vector<int>> ad(n);//��¼�¸����ߵ��ڽӱ� 
		if(n == 1){
			vec.push_back(0);
			return vec;
		}
		map<int, int> m;//��¼ÿ���ڵ���� 
		for(int i = 0; i < edges.size(); i++){
			m[edges[i][0]]++;
			m[edges[i][1]]++; 
			ad[edges[i][0]].push_back(edges[i][1]);
			ad[edges[i][1]].push_back(edges[i][0]);
		}
		queue<int> q;
		for(int i = 0; i < n; i++)
			if(m[i] == 1)
				q.push(i);
		while(!q.empty()){
			int len = q.size();
			vector<int> s;//�������ĸ���� 
			for(int i = 0; i < len; i++){
				int x = q.front();
				s.push_back(x); 
				q.pop();
				for(int j = 0; j < ad[x].size(); j++){//�����й���x���ڽӱ�ɾȥ 
					m[ad[x][j]]--;//������һ�����ж���ڽӱ�
					if(m[ad[x][j]] == 1)
						q.push(ad[x][j]);
				}
			}
			vec = s;
		}
		return vec;
	}
};
int main(){
    int n;
    vector<vector<int> > edges;
    cin>>n;
    int p1,p2;
    for(int i=0; i<n-1; i++){//�ߵ���ĿΪ�ڵ���Ŀ��1
        cin>>p1>>p2;
        vector<int> edge;
        edge.push_back(p1);
        edge.push_back(p2);
        edges.push_back(edge);
    }
    vector<int> res=Solution().findMinHeightTrees(n, edges);
    sort(res.begin(), res.end());
    for(int i=0; i<res.size(); i++)
    	cout<<res[i]<<" ";
    return 0;
}
