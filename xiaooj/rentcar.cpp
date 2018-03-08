#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 10050
using namespace std;
int main(){
	int p[N];
	int n;
	int a,b;
	memset(p,0,sizeof(p));
	scanf("%d",&n);
	int maxx=0;
	for(int i=0;i<n;i++){
		scanf("%d,%d",&a,&b);
		for(int j=a;j<=b;j++){
			p[j]++;
		}
		if(maxx<b) maxx=b;
	}
	int max=0;
	for(int i=0;i<maxx;i++){
		if(max<p[i]) max=p[i];
	}
	printf("%d\n",max);
	return 0;
}
