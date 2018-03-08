#include <bits/stdc++.h>
using namespace std;

//int dist[105][1005];
int dist[105][105];
int n,m;

void print(){
	for(int i=1;i<=n;i++){
		for(int j = 1;j<=n;j++)
		{
			if(i!=j){
				printf("%d ",dist[i][j] );
			}
			else printf("0 ");
		}
		printf("\n");
	}
//	printf("\n");
}
void floyd(){
	for(int k = 1 ; k <=n ;k++  ){
		for(int i = 1 ; i<=n; i++ ){
			for(int j = 1 ;j<=n;j++){
				if(dist[i][j]>dist[i][k]+dist[k][j]){
					dist[i][j]=dist[i][k]+dist[k][j];
				}
			}
		}
		// print();
	}	
}
int main(){
	
	scanf("%d%d",&n,&m);

	for(int i=0;i<105;i++)
		fill(dist[i],dist[i]+105,1<<16);
	for(int i = 0 ;i<m;i++  ){
		int tmpfrom,tmpto,tmpweight;
		scanf("%d%d%d",&tmpfrom,&tmpto,&tmpweight);
		if(dist[tmpfrom][tmpto]>tmpweight)
		{
			dist[tmpfrom][tmpto]=tmpweight;
			dist[tmpto][tmpfrom]=tmpweight;
		}
	}
	//print();
	floyd();
	print();
}