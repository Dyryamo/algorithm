#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 105
using namespace std;
int anss=0;
int nn;
void prim(int a[][N],int u[],int w[],int b[],int n)
{
    int i=0,j=0,m=0,mins=1<<31;
    for(i=0;i<n;i++)
    {
        u[i]=0;//初始化0，说明没有访问过
        w[i]=a[0][i];//初始每个顶点最短路径为到0顶点的距离
        b[i]=0;//初始每个顶点都指向0顶点
    }
    u[0]=1;//赋值1，从0顶点开始

    for(i=1;i<n;i++)
    {
        mins=1<<31;
        j=0;
        for(m=1;m<n;m++)
        {
            if(!u[m] && w[m]<mins)//很关键，得到到访问顶点到未访问顶点的最短路径以及对应顶点j
            {
                mins=w[m];
                j=m;
            }
        }
        u[j]=1;//把下一个顶点标为已访问

       anss+=mins;
        for(m=1;m<n;m++)
        {
            if(!u[m] && a[j][m]<w[m])//此时，u集合里面多了一个顶点j，要重新更新最短路径以及对应的顶点
            {
                w[m]=a[j][m];
                b[m]=j;
            }
        }
    }

  /* for(int i=1;i<nn;i++ ){
    printf("%d ",w[i]);
        anss+=w[i];
    }*/
}
int main(){
    int c,m;
    int u[N],w[N],b[N],a[N][N];

        while(scanf("%d%d%d",&c,&nn,&m)!=EOF){
        anss=0;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                a[i][j]=1<<31;
            }
        }
        for(int i=0;i<nn;i++){
            int start,ends,cost;
            scanf("%d%d%d",&start,&ends,&cost);
            a[start-1][ends-1]=cost;
            a[ends-1][start-1]=cost;
        }
         prim(a,u,w,b,m);
         printf("%d",anss);
         anss<c?printf("Yes\n"):printf("No\n");
    }
}
