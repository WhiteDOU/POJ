#include <iostream>
#include <algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
int N,X,Y,M,T,d[1010][2];
struct Floor{
	int l,r,h;
	bool operator<(Floor a){return h<a.h;}
};
Floor f[1010];
int main(){
	cin>>T;
	while(T--){
		cin>>N>>X>>Y>>M;
		for(int i=1;i<=N;i++){
			int a,b,c;
			cin>>a>>b>>c;
			f[i].l=a,f[i].r=b,f[i].h=c;
		}
		sort(f+1,f+N+1);
		f[N+1].l=X,f[N+1].r=X,f[N+1].h=Y;
		f[0].l=-20010,f[0].r=20010,f[0].h=0;
		for(int i=1;i<=N+1;i++)
			for(int j=0;j<2;j++){
				int x=j?f[i].r:f[i].l;
				d[i][j]=INF;
				for(int k=i-1;k>=0;k--){
					int l=f[k].l,r=f[k].r,dh=f[i].h-f[k].h;
					if(dh>M) break;
					if(x>=l&&x<=r){
						int dl=k?x-l:0,dr=k?r-x:0;
						d[i][j]=min(d[k][0]+dl,d[k][1]+dr)+dh;
						break;
					}
				}
				if(i==N+1) break;
			}
		cout<<d[N+1][0]<<endl;
	}
	return 0;
}
