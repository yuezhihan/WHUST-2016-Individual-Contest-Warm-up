#include <cstdio>
#include <cstring>
#include <climits>
#include <queue>
#include <algorithm>
using namespace std;
#define MAXM 608000
#define MAXN 200008
#define fromto(from,to,i) for(int i=(from);i<=(to);++i)
#define edgesof(x,i) for(int i=V[(x)]; i!=-1; i=E[i].last)
struct edge {
	int v,d,last;
};
edge E[MAXM];
int E_len;
int V[MAXN];

void G_init()
{
	E_len = 0;
	memset(V,-1,sizeof(V));
}

void add_edge(int u,int v,int d)
{
	E[E_len] = (edge){v,d,V[u]};
	V[u] = E_len++;
}

int N;
int dis[MAXN];
bool spfa(int s)
{
	fill(dis,dis+N+1,INT_MAX);
	static bool inq[MAXN];
	static int cnt[MAXN];
	memset(inq,false,sizeof(inq));
	memset(cnt,0,sizeof(cnt));
	queue<int> q;
	dis[s] = 0;
	q.push(s);
	inq[s] = true;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		inq[u]=false; ++cnt[u];
		if(cnt[u]>N) return false;
		edgesof(u,i) {
			int v = E[i].v, d = E[i].d;
			if(dis[v]>dis[u]+d) {
				dis[v]=dis[u]+d;
				if(!inq[v]) {
					inq[v] = true;
					q.push(v);
				}
			}
		}
	}
	return true;
}

int main()
{
	scanf("%d",&N);
	G_init();
	fromto(1,N-1,i) {
		add_edge(i,i+1,1);
		add_edge(i+1,i,1);
	}
	fromto(1,N,u) {
		int v;
		scanf("%d",&v);
		add_edge(u,v,1);
	}
	spfa(1);
	fromto(1,N,i) printf("%d\n",dis[i]);
	return 0;
}
