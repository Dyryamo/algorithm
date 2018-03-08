#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
struct node
{
	node* post;
	node* next[26];
	bool danger;
	node(){
		memset(next,0,sizeof(next));
		danger = false;
	}
};
node* createnode(){
	return new node();
}
class triegraph{
	node* root;
public:
	triegraph();
	void insert(string a);
	bool query(string a);
	void addpost();
};
triegraph::triegraph(){
	root = createnode();
}
/*
查找每个节点的后缀结点
层序遍历Trie树的每个结点：
对于根节点root的后缀结点是根节点root本身；
对于根节点root的儿子结点，即根节点的下层结点，它们的后缀结点是根节点root；
对于其余的结点的后缀结点的查找：
设当前结点为q，结点q的父结点为结点p，结点p指向结点q的边上的字符为‘A’，结点p的后缀结点是结点p2。那么结点q的后缀结点就是结点p2沿标有字符'A'的边走一步后到达的结点。
*/
void triegraph::addpost(){//afler trie tree built,add post node for trie tree
	queue<node*>p;
	p.push(root);
	root->post = root;
	while(!p.empty()){
		//printf("1\n");
		node* tmp = p.front();
		p.pop();
		for(int i = 0; i < 26 ;i++){
			if(tmp->next[i] !=NULL){
				p.push(tmp->next[i]);
				node* tmp2 = tmp;
				while( (tmp2->post)->next[i]==NULL){
					tmp2 = tmp2->post;
				//	printf("2\n");
				}
				tmp->next[i]->post = (tmp2->post)->next[i];//当前节点的儿子i节点的后缀节点位当前节点的后缀节点的i
				
					
			}
		}	
	}
}
bool triegraph::query(string a){
	node* p = root;
	int ia=0,lena = a.length();
	while(ia !=lena){
		int id = a[ia]-'a';
		//printf("3\n");
		if(p->next[id]!=NULL){
			ia++;
			p=p->next[id];
		}
		else{
			p=p->post;
			ia++;
		}
		if(p->danger)
			return true;
	}
	return false;
}
void triegraph::insert(string a){
	node* p = root;
	int ia=0,lena = a.length();
	while(ia != lena){
		int id = a[ia] - 'a';
		if(p->next[id] != NULL){
			ia++;
			p = p->next[id];
		}
		else {
			p->next[id] = createnode();
			ia++;
			p=p->next[id];
		}
	}
	p->danger = true;
}

int main(){
	triegraph mytrie;
	int n, m;
	string tmp;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		cin>>tmp;
		mytrie.insert(tmp);

	}
	mytrie.addpost();
	for(int i=0;i<m;i++){
		cin>>tmp;
		mytrie.query(tmp)?printf("1\n"):printf("0\n");;
	//printf("%d\n",mytrie.query(tmp));
	}
	//cin>>tmp;
	//mytrie.query(tmp)?printf("YES\n"):printf("NO\n");
	
	return 0;
}
