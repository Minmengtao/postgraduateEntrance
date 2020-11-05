#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
const int MAXN = 50 + 1;
vector<int> graph[MAXN];	//�ڽӱ�
int P, R;
bool vis[MAXN];		//��¼����Ƿ����
int dis[MAXN];		//������Ĳ���
map<string, int> People;
int ans = 0;
void Bfs(int u) {		//��׼��Bfs��ʽ��������������ȣ���΢����
	memset(dis, 0, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	queue<int> Q;
	vis[u] = 1;
	Q.push(u);
	int num = 1;		//��¼���ʵĽ�����
	while (!Q.empty()) {
		int now = Q.front();
		if (num == P && Q.size() == 1)	//�жϽ���Ƿ񶼷��ʹ��ˣ����������һ�����
			ans = max(ans, dis[now]);
		Q.pop();
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i];
			if (!vis[next]) {
				vis[next] = 1;
				dis[next] = dis[now] + 1;		//������1
				num++;			//�ѷ��ʵĽ���1
				Q.push(next);
			}
		}
	}
}
int main() {
	int ccase = 0;
	while (scanf("%d%d", &P, &R) && P&&R) {
		People.clear();
		for (int i = 0; i < MAXN; i++)
			graph[i].clear();
		ccase++;
		ans = 0;
		int k = 1;
		char c[20],d[20];
		for (int i = 0; i < R; i++) {
			scanf("%s%s",c,d);
			if(!People[c])		//��stringӳ�䵽int
				People[c] = k++;
			if(!People[d])
				People[d] = k++;
			graph[People[c]].push_back(People[d]);
			graph[People[d]].push_back(People[c]);
		}
		for (int i = 1; i <= P; i++) 
			Bfs(i);
		if (ans == 0)
			printf("Network %d: DISCONNECTED\n\n", ccase);
		else
			printf("Network %d: %d\n\n", ccase, ans);
	}
	return 0;
}
