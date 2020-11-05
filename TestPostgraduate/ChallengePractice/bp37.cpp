#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
const int MAXN = 50 + 1;
vector<int> graph[MAXN];	//邻接表
int P, R;
bool vis[MAXN];		//记录结点是否访问
int dis[MAXN];		//到达结点的步数
map<string, int> People;
int ans = 0;
void Bfs(int u) {		//标准的Bfs格式，因本题求最大分离度，略微复杂
	memset(dis, 0, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	queue<int> Q;
	vis[u] = 1;
	Q.push(u);
	int num = 1;		//记录访问的结点个数
	while (!Q.empty()) {
		int now = Q.front();
		if (num == P && Q.size() == 1)	//判断结点是否都访问过了，并且是最后一个结点
			ans = max(ans, dis[now]);
		Q.pop();
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i];
			if (!vis[next]) {
				vis[next] = 1;
				dis[next] = dis[now] + 1;		//步数加1
				num++;			//已访问的结点加1
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
			if(!People[c])		//将string映射到int
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
