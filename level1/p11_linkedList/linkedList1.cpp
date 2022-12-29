#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>

typedef struct Node
{
	int data;
	struct Node* next;
} Node, * PNode;

typedef struct List
{
	PNode first;
	PNode last;
	size_t size;
}List;

void InitList(List* list);
void push_back(List* list, int x);
void show_list(List* list);
void resver(List* list);
Node* find(List* list, int key);
Node* find2(List* list, int key);
int x;

int main()
{
	List Linklist;
	Node* p = NULL;
	int Item;
	InitList(&Linklist);
	printf("Input:\n");
	while (scanf("%d", &Item), Item != -1)
	{
		push_back(&Linklist, Item);
	}
	show_list(&Linklist);
	resver(&Linklist);
	show_list(&Linklist);
	resver(&Linklist);
	printf("Find:\n");
	scanf("%d",&Item);
	p = find(&Linklist, Item);
	if (p == NULL)
	{
		printf("Not Found!\n");
	}
	else
	{
		printf("%d\n",x);
	}
	p = find2(&Linklist, Item);
	if (p == NULL)
	{
		printf("Not Found!\n");
	}
	else
	{
		printf("%d\n", x);
	}
	return 0;
}

void InitList(List* list)
{
	list->first = list->last = (Node*)malloc(sizeof(Node));
	assert(list->first != NULL);
	list->first->next = NULL;
	list->size = 0;
}

void push_back(List* list, int x)
{
	Node* s = (Node*)malloc(sizeof(Node));
	assert(s != NULL);
	s->data = x;
	s->next = NULL;
	list->last->next = s;
	list->last = s;
	list->size++;
}

void resver(List* list)
{
	if (list->size == 0 || list->size == 1) return;
	Node* p = list->first->next;
	Node* q = p->next;
	list->last = p;
	list->last->next = NULL;
	while (q != NULL)
	{
		p = q;
		q = p->next;
		p->next = list->first->next;
		list->first->next = p;
	}
}

void show_list(List* list)
{
	Node* p = list->first->next;
	while (p != NULL)
	{
		printf("%d", p->data);
		p = p->next;
		if(p!=NULL) printf("->"); else printf("\n");
	}
	printf("Nul.\n");
}

Node* find(List* list, int key)
{
	x = 1;
	Node* p = list->first->next;
	while (p != NULL && p->data != key)
	{
		x++;
		p = p->next;
	}
	return p;
}

Node* find2(List* list, int key)
{
	x = 1;
	Node* p = list->first->next;
	while (p != NULL && p->data != key)
	{
		x++;
		p = p->next;
	}
	if (p == NULL) return p;
	p = p->next;
	x++;
	while (p != NULL && p->data != key)
	{
		x++;
		p = p->next;
	}
	return p;
}
