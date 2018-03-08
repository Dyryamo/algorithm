#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
#define N 55
#define M 2005
int maps[N][M];
int dist[N];
bool vis[N];
#define INF 1<<15
int n,m;//定点数，
void init(){
    memset(vis,0,sizeof(vis));
    for(int i=0;i<=n;i++ ){
        dist[i]=INF;
    }
    memset(maps,0,sizeof(maps));
}
void dijsktra(){
    for(int i=1;i<=n;i++){
        if(maps[1][i]){
            dist[i]=1;
        }
    }
    vis[1]=true;
    for(int i=1;i<=n;i++){
        int mins=1<<15;
        int k=1;
        for(int j=1;j<=n;j++){
            if(!vis[j]&&dist[j]<mins){
                mins=dist[j];k=j;
            }
        }
        vis[k]=true;
        for(int j=1;j<=n;j++){
            if(maps[k][j])
            if(!vis[j]&&k!=j&&dist[j]>mins+maps[k][j]){
                dist[j]=mins+maps[k][j];
            }
        }
    }
}
int main(){

    int a,b;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        init();
        for(int i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            maps[a][b]=1;
        }
        dijsktra();
        for(int i=1;i<=n;i++ ){
            cout<<dist[i]<<' ';
        }
        cout<<endl;
        dist[n]!=INF?printf("Yes\n"):printf("No\n");
    }

}
