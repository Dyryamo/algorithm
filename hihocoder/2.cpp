#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
	int T;
	string a;
	int k;
	int af;
	scanf("%d",&T);
	while(T--){
		cin>>a>>k;
		af=a[a.lenth()-1]-1;
		if(af%2!=k%2){
			printf("-1\n");
		}
		else{
			
		}

	}

	return ;
}
