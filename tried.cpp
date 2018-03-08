#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct node
{
	int cnt;
	bool exist;
	node* next[26];
	node (){
		cnt = 0;
		exist = false;
		memset(next,0,sizeof(next));
	} 
};
node* createnode(){
	return new node();
}
class tried
{
	node* root;
public:
	tried();
	~tried(){
	}
	bool insert(string ins);
	int query(string ans);
	
};
tried::tried(){
	root = createnode();
}
bool tried::insert(string ins){
	node* p = this->root; 
	int insi=0 ,lenins = ins.length();
	while(insi < lenins ){
		int id = ins[insi]-'a';//make char to int
		if(p->next[id] != NULL){// if has been exsited,do nothing;
			p->cnt++;
			p = p->next[id];
			insi++;
		}
		else{
			//node* tmp = createnode();
			p->cnt++;
			p->next[id] = createnode();
			p=p->next[id];
			insi++;
		}
	}
	if( insi == lenins){
		p->exist = true;
	}
}  
int tried::query(string ans){
	node* p = this->root;
	int ansi=0, lenans = ans.length();
	while( ansi <lenans ){
		int id = ans[ansi]-'a';
		if(p->next[id] != NULL){
			p = p->next[id];
			ansi ++;
		}
		else return 0;
		//printf("%dquerying\n",ansi);
	}
	return p->cnt;
}
int main(){
	int n;//get size of dictionary
	string tmp;
	tried trie;
	scanf("%d",&n);
	for(int i=0; i<n;i++){
		cin>>tmp;
	trie.insert(tmp);
	}
	scanf("%d",&n);//get query
	for (int i = 0; i < n; ++i)
	{
		/* code */	
		cin>>tmp;
		printf("%d\n",trie.query(tmp));
	}
	//printf("over\n");
	return 0;
}
