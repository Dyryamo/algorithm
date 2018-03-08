#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<algorithm>
using namespace std;
#define PI 3.1615926535
double log8=log(8);
double f(int n){
	return (0.5*log(2)+0.572364929+0.5*log(n)+n*log(n)-n)/log8;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		if(n==1||n==0){
			printf("1\n");
		}
		else {
			printf("%d\n",(int)(f(n))+1);
		}
	}
}
