#include<iostream>
using namespace std;


typedef struct Node
{
	int date;
	struct Node* pNext;
}pNode, * PNode;

void InitNode(PNode);
bool emptyNode(PNode);
void LastCreatlink(PNode);   //尾插法创建列表
void HeadCreatlink(PNode);   //头插法创建列表
void showlist(PNode);
void AddNode(PNode, int, int);
void DeletNode(PNode, int);


int main()
{
	pNode p;
	InitNode(&p);
	//LastCreatlink(&p);
	HeadCreatlink(&p);
	showlist(&p);
	cout << endl;
	DeletNode(&p, 5);
	showlist(&p);

	return 0;
}

bool emptyNode(PNode p)
{
	if (p->pNext == NULL)
	{
		cout << "链表为空" << endl;
		return false;
	}
	else
		return true;
}

void InitNode(PNode p)
{
	p->pNext = nullptr;
	p->date = 0;
}

/*
void LastCreatlink(PNode d)
{
	int i, k;
	PNode s = NULL;
	PNode p = d;
	cout << "请问要生成多少个节点：" << endl;
	cin >> i;
	for (k = 0; k < i; k++)
	{
		s = new pNode;
		cout << "第" << k + 1 << "节点的值是：" << endl;
		cin >> s->date;
		s->pNext = nullptr;  //
		p->pNext = s;
		p = s;
	}
}
*/

void HeadCreatlink(PNode p);
{
	int i,n;
	PNode k = new PNode;
	pNode s;
	p->pNext = NULL;

	cout << "请输入生成的节点数："<<endl;
	cin >> n;

	for (i = 0; i < n; i++)
	{
		s = new pNode;
		cout << "第" << n + 1 << "节点的值是：" << endl;
		cin >> k->date;
		k->pNext = p->pNext;
		p = k;
	}
	
}

void showlist(PNode p)
{
	int i;
	PNode k = p->pNext;
	if (emptyNode(p) == NULL)
	{
		cout << "结束链表" << endl;
	}
	else
	{
		cout << "链表的数值是：";
		while (k != NULL)
		{
			cout << k->date << " ";
			k = k->pNext;
		}
	}
}

void AddNode(PNode p, int size, int a)
{
	int count = 0;
	PNode k = p;
	PNode s;
	for (int i = 1; i <= size; i++)
	{
		count++;
		if (count == size)
		{
			s = (PNode)malloc(sizeof(pNode));
			s->date = a;
			s->pNext = k->pNext;
			k->pNext = s;
		}
		else
		{
			k = k->pNext;
		}
	}
}

void DeletNode(PNode p, int size)
{
	int count = 0;
	PNode k = p;
	PNode s;

	while (k->pNext && count < size)
	{
		k = k->pNext;
		count++;
	}
	if (!(k->pNext) || count > size)
	{
		cout << "超出了范围，没有删除元素" << endl;
	}
	if (count = size)
	{
		s = k->pNext;
		k->pNext = s->pNext;
		cout << "删除的数是：" << s->date << endl;
		free(s);
	}
}


