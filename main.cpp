#include <iostream>
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//����Ľڵ� 
struct node
{
	int val;
	node* next;
};

//��������
void initList(node** head)
{
	*head = (node*)malloc(sizeof(node));
	if(*head == NULL)
		exit(1);
	(*head)->next = NULL;
} 

//�����β��
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

//�����ݲ��뵽һ������������У���ȻΪ���� 
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

//��������������������������������Ϊһ����Ȼ���������������
node* combineTwoList(node* head1, node* head2)
{
	//�����ж��Ƿ���ȷ
	if(head1 == NULL || head2 == NULL )	return NULL;
	//�������������Ϊ������
	if(head1 -> next == NULL && head2->next == NULL)	return NULL;
	
	//���ڶ��������ֵ���κ͵�һ�������ֵ���Ƚϣ������뵽��һ������Ķ�Ӧλ��
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
	
	printf("���������������������������ϲ��������������ֵ���á�->���ָ���������á�,���ָ������磺1->2->4->6,2->4->5->8��:");
	
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
			while(1)			//�����ѭ������Ϊ����������ݿ��Դ���9��atoi�����Ὣ����������ת���ɶ�Ӧint���͵���ֵ��Ϊ�˷�ֹp++��ʱ���ظ���ȡ�����β��� 
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
