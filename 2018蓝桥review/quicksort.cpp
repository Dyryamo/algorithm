
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 10050
using namespace std;
int n,k;
int p[N];
int QKpass(int start,int end){
	int tmp = p[start];
	int low = start,high = end;
	while( low < high ){
		while(low < high && p[high] < tmp)
				high--;
		p[low] = p[high];
		while(low < high && p[low] > tmp )
				low ++;
		p[high]= p[low];
	}
	p[low] = tmp;
	
	return low;
}
int find_k(int start,int end,int k ){
	if(start >end)
			return 0;
	int pos = QKpass(start,end);
	find_k(start,pos-1,k);
	find_k(pos+1,end,k);
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i =0;i < n; i++ ){
		scanf("%d",&p[i]);
	}
	find_k(0,n-1,k);
	for(int i = 0; i < n ;i++){
		printf("%d ",p[i] );
	}
	return 0;
}