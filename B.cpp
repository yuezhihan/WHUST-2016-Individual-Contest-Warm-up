#include <cstdio>
#include <algorithm>
using namespace std;
#define fromto(from,to,i) for(int i=(from);i<=(to);++i)
const int MAXN = 100008;
int A[MAXN];
int main()
{
	int n;
	scanf("%d",&n);
	fromto(1,n,i) {
		scanf("%d",&A[i]);
	}
	sort(A+1,A+n+1);
	int mex = 1;
	fromto(1,n,i) {
		if(A[i]<mex) continue;
		++mex;
	}
	printf("%d\n",mex);
	return 0;
}
