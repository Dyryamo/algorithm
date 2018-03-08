#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#include <vector>
#define  N 1005
vector<double>pajian[N];
struct gun
{
	int weight;
	int k;
	std::vector<int> canbe;
}p[N];
int main(){
	int n , m;
	int tmp;
	double tmp2;
	while(~scanf("%d%d",&n,&m)){
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&p[i].weight,&p[i].k);
			for(int j=0;j<p[i].k;j++){
				scanf("%d",&tmp);
				p[i].canbe.push_back(tmp);
			}	

		}
		for(int i=0;i<m;i++){
			scanf("%d%lf",&tmp,&tmp2);
			pajian[tmp].push_back(tmp2);
		}
		for(int i=1;i<=m;i++){
			sort(pajian[i].begin(), pajian[i].end(),greater<double>());
		}
		
		double max = 0;
		double sum = 1;
		for(int i=1;i<=n;i++){
			sum=1;
			for(int j = 0;j<p[i].k;j++){
            
				sum+=pajian[p[i].canbe[j]][0];
			}
			if(max<p[i].weight*sum){
				max=p[i].weight*sum;
			}
		}
		printf("%.4lf\n",max);
        for(int i=0;i<m;i++){
            pajian[i].clear();
        }
        for(int i=0;i<n;i++){
            p[i].canbe.clear();
        }
	}

}


