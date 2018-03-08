#include<iostream>
#include<cstdio>
#include<stdlib.h>
#define N 20
using namespace std;
int p[N+5],p2[N+5];
void mergesort(int p[],int low,int high){
	if(high-low<=1)
		return;
	int mid = low + (high-low)/2;
	mergesort(p,low,mid);
	mergesort(p,mid,high);
	int l=low ;
	int r=mid;
	int tmp[N*2+10],k=low;
	while(l<mid||r<high){
		if(l>=mid||(r<high&&p[r]<p[l])){
			tmp[k++]=p[r++];
		}
		else {
			tmp[k++]=p[l++];
		}
	}
	for(int i = low;i<high;i++){
		p[i]=tmp[i];
	}
}
int qkpass(int p[],int low,int high){
	int x = p[low];
	int l=low,r = high;
	while(l<r){
		while(l < r && p[r]>=x )
			r--;
		if(l < r ){
			p[l++]=p[r];
				
		}
		while(l<r && p[l]<x)
			l++;
		if(l < r ){
			p[r--]=p[l];
		}
	}
	p[l]=x;
	return l;
}
void quicksort(int p[],int low,int high){
	if(high > low)
	{
		int pos = qkpass(p,low,high);
		quicksort(p,low, pos-1);
		quicksort(p,pos+1,high);
	}
}
void print(int p[]){
	for(int i = 0 ; i < N; i++){
		printf("%d ",p[i]);
	}
	printf("\n");
}
int main(){

	int T = 10;
	while(T--){
		for(int i=0;i<N;i++){
			p[i]=rand()%100;
			p2[i]=p[i];
		}
		printf("原始：");
		print(p);
		printf("归并排序	");
		mergesort(p,0,N);
		print(p);
		printf("快速排序	");
		quicksort(p,0,N-1);
		print(p2);
		printf("\n");
	}
	return 0;
}
