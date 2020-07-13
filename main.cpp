#include <iostream>
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//链表的节点 
struct node
{
	int val;
	node* next;
};

//创建链表
void initList(node** head)
{
	*head = (node*)malloc(sizeof(node));
	if(*head == NULL)
		exit(1);
	(*head)->next = NULL;
} 

//链表的尾插
void push_back(node* head, int data)
{
	if(head == NULL)	return;
	node* p = head;
	while(p->next != NULL) p = p->next;
	node* newNode = (node*)malloc(sizeof(node));
	if(newNode == NULL)	return;
	newNode -> val = data;
	newNode->next = NULL;
	p->next = newNode;
}

//将数据插入到一个升序的链表中，仍然为升序 
void insert(node* head, int val)
{
	node* newNode = (node*)malloc(sizeof(node));
	if(newNode == NULL || head == NULL) return;
	newNode->val = val;
	
	node* p = head->next;
	while(p != NULL)
	{
		if(val > p->val)
		{
			head = p;
			p = head->next;
		}
		else
		{
			newNode->next = p;
			head->next = newNode;
			break;
		}
	}
	if(head->next == NULL) 
	{
		head->next = newNode;
		newNode->next = NULL;
	}

}

//输入两个有序的链表，函数将两个链表和为一个，然后再重新排序输出
node* combineTwoList(node* head1, node* head2)
{
	//参数判断是否正确
	if(head1 == NULL || head2 == NULL )	return NULL;
	//输入的两个链表都为空链表
	if(head1 -> next == NULL && head2->next == NULL)	return NULL;
	
	//将第二个链表的值依次和第一个链表的值做比较，并插入到第一个链表的对应位置
	node* p = NULL;
	for(p = head2->next;p != NULL;p=p->next)
	{
		insert(head1,p->val);
	}
	
	for(p = head1->next;p->next!= NULL; p= p->next)
	{
		printf("%d->",p->val);
	}
	printf("%d\n",p->val);
	
	return head1;
}



int main(int argc, char** argv) {
	
	printf("请输入两个升序的链表，程序将输出合并后有序的链表，数值间用“->”分隔，链表间用“,”分隔（例如：1->2->4->6,2->4->5->8）:");
	
	char listArray[1024]={0};
	scanf("%s",listArray);
	char* p = NULL;
	node* head1;
	node* head2;
	initList(&head1);
	initList(&head2);
	
	p = listArray;
	while(*p != 0)
	{
		if(*p == ',')	break;
		if(*p >= '0' && *p <= '9')
		{
			int val = atoi(p);
			push_back(head1, val);
			while(1)			//加入次循环，是为了输入的数据可以大于9，atoi函数会将连续的数字转换成对应int类型的数值，为了防止p++的时候重复读取，做次操作 
			{
				p++;
				if(*p >= '0' && *p <= '9');
				else
				{
					p--;
					break;
				}
			}
		}
		p++;		
		
	}
	
	while(*p != 0)
	{
		
		if(*p >= '0' && *p <= '9')
		{
			int val = atoi(p);
			push_back(head2, val);
			while(1)
			{
				p++;
				if(*p >= '0' && *p <= '9');
				else
				{
					p--;
					break;
				}
			}
		}
		p++;		
	
	}
	
	combineTwoList(head1,head2);
	
	return 0;
}
