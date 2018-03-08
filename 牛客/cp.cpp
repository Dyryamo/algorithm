#include <iostream>
#include <cstdio>
#include<cstring>
using namespace std;
int main(){
	int data[1001];
	int n;
	while(1){
		memset(data,0,sizeof(data));
		scanf("%d",&n);
		int flag=0;
		if(n==0)
			return 0;	
		int tmp;
		for(int i=0;i<n;i++){
			scanf("%d",&tmp);
			data[tmp]++;
		}
		for(int i=0;i<101;i++){
			if(data[i]%2==1){
				flag=1;
				break;
			}
		}
		if(flag){
			printf("Win\n");
		}
		else
			printf("Lose\n");
	}
	

}