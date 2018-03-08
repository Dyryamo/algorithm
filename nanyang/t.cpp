#include<cstdio>
#include<malloc.h>
struct node
{
	int data;
	node *next;
};
void create(int n,node **head)
{
	int data;
	*head=(node *)malloc(sizeof(node)); 
	node *p1;
	node *p2=*head;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&data);
		p1=(node *)malloc(sizeof(node));
		p1->data=data;
		p1->next=NULL;
		p2->next=p1;
		p2=p1;
	}
}

int removex(int x,node *head)
{
	int cnt=0;	
	node *p=head->next;
	node *p2=head;
	while(p)
	{
		if(x==p->data)
		{
			node *tt=p;
			p2->next=p->next;
			p=p->next;
			free(tt);
		}
		else 
		{
			p2=p2->next;
			p=p->next;
		}
	}
}
void print(node *head)
{
	node *p=head->next;
	while(p)
	{
		printf("%d",p->data);
		p=p->next;
	}
}
int main()
{
	int n;
	node *head;
	scanf("%d",&n);
	create(n,&head);
	removex(2,head);
	print(head);
	return 0;
}
