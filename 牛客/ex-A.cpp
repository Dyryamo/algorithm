#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 10050
using namespace std;
int n,m;
int p[N];
int swi;
int equ(int l,int r,int k){
	std::vector<int> v;
	for(int i=l;i<=r;i++){
		v.push_back(p[i]);
	}
	sort(v.begin(), v.end());
	return v[k];
}
int main(){

    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
		scanf("%d",&p[i]);
    }
    for(int i=0;i<m;i++){
    	scanf("%d",&swi);
    	if(swi==1){
    		int l,r,x,y;
    		scanf("%d%d%d%d",&l,&r,&x,&y);
    		for(int j=l;j<=r;j++){
    			if(p[j]==x)
    				p[j]=y;
    		}

    	}
    	else if(swi==2){
    		int l,r,k;
    		scanf("%d%d%d",&l,&r,&k);
    		printf("%d\n",equ(l,r,k));
    	}
    }
    return 0;
    
}