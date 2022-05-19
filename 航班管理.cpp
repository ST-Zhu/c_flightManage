#include <stdio.h>
#include <stdlib.h>
#define NULL 0
struct date
{
	int shi;
	int fen;
	int miao;
};
struct people
{
	char name[10];
	long number;
	struct people *next;
};
struct information
{
	int num;
	char chufa;
	char mudi;
	struct date qifei;
	struct date luodi;
	char jixing;
	int zuowei;
	int jiage;
	struct people pa;
	struct information *next;
};
int n, m;
struct information *creat(void)
{
	struct information *head, *p, *tail;
	head = NULL;
	n = 0;
	tail = (struct information *)malloc(sizeof(struct information));
	p = tail;
	printf("��������?ֹ���벢�������˵�������0\n");
	scanf("%d,%c,%c,%d,%d,%d,%d,%d,%d,%c,%d,%d", &p->num, &p->chufa, &p->mudi, &p->qifei.shi, &p->qifei.fen, &p->qifei.miao, &p->luodi.shi, &p->luodi.fen, &p->luodi.miao, &p->jixing, &p->zuowei, &p->jiage);
	while (p->num != 0)
	{
		n++;
		if (n == 1)
			head = p;
		else
			tail->next = p;
		tail = p;
		p = (struct information *)malloc(sizeof(struct information));
		printf("��������?ֹ���벢�������˵�������0\n");
		scanf("%d,%c,%c,%d,%d,%d,%d,%d,%d,%c,%d,%d", &p->num, &p->chufa, &p->mudi, &p->qifei.shi, &p->qifei.fen, &p->qifei.miao, &p->luodi.shi, &p->luodi.fen, &p->luodi.miao, &p->jixing, &p->zuowei, &p->jiage);
	}
	tail->next = NULL;
	return (head);
}
void print(struct information *head)
{
	struct information *p;
	printf("�ѵǼǵĺ�������:%d\n", n);
	p = head;
	if (head != NULL)
		do
		{
			printf("����ţ�?%d,������?�?%c,Ŀ�ĵ�?�?%c,���ʱ��?%dʱ%d��%d��,���ʱ��?%dʱ%d��%d��,���û���?�?%c,��λ����%d,�۸�%d\n", p->num, p->chufa, p->mudi, p->qifei.shi, p->qifei.fen, p->qifei.miao, p->luodi.shi, p->luodi.fen, p->luodi.miao, p->jixing, p->zuowei, p->jiage);
			p = p->next;
		} while (p != NULL);
}
struct information *insert(struct information *head, struct information *information1)
{
	struct information *a;
	if (head == NULL)
	{
		head = information1;
		information1->next = NULL;
		return (head);
	}
	if (head->num > information1->num)
	{
		information1->next = head;
		head = information1;
		return (head);
	}
	a = head;
	while ((a->next != NULL) && (a->next->num < information1->num))
		a = a->next;
	information1->next = a->next;
	a->next = information1;
	return (head);
}
struct information *del(struct information *head, int num)
{
	struct information *p, *a;
	if (head == NULL)
	{
		printf("�޺�����Ϣ!\n");
		return (head);
	}
	p = head;
	while ((num != p->num) && (p->next != NULL))
	{
		a = p;
		p = p->next;
	}
	if (num == p->num)
	{
		if (p == head)
			head = p->next;
		else
			a->next = p->next;
		printf("��ɾ����\n");
		n = n - 1;
	}
	else
		printf("���к�����Ϣ���޴˱�ţ�\n");
	return (head);
}
struct information *find1(struct information *head, int num)
{
	struct information *a, *p;
	struct people *head1, *p1, *tail1;
	if (head == NULL)
	{
		printf("�޺�����Ϣ!\n");
		return (head);
	}
	p = head;
	while ((num != p->num) && (p->next != NULL))
	{
		a = p;
		p = p->next;
	}
	if (num == p->num)
	{
		printf("������˿�����֤�ţ�?18λ��������������������?ֹ���벢���ز��������뺽���������?0����");
		head1 = NULL;
		m = 0;
		tail1 = (struct people *)malloc(sizeof(struct people));
		p1 = tail1;
		scanf("%ld,%s", &p1->number, p1->name);
		if (p1->number != 0)
			printf("��?�һ���?�\n");
		while (p1->number != 0)
		{
			m++;
			if (m == 1)
				head1 = p1;
			else
				tail1->next = p1;
			tail1 = p1;
			p1 = (struct people *)malloc(sizeof(struct people));
			printf("������˿�����֤�ţ�?18λ��������������������?ֹ���벢���ز��������뺽���������?0����");
			scanf("%ld,%s", &p1->number, p1->name);
			if (p1->number != 0)
				printf("��?�һ���?�\n");
		}
		head1 = &a->pa;
		tail1->next = NULL;
	}
	else
		printf("���к�����Ϣ���޴˱�ţ�\n");
	return (head);
}
struct information *find2(struct information *head, int num)
{
	struct information *p, *a;
	struct people *head1, *p1, *tail1, *a1;
	long number;
	if (head == NULL)
	{
		printf("�޺�����Ϣ��\n");
		return (head);
	}
	p = head;
	while ((num != p->num) && (p->next != NULL))
	{
		a = p;
		p = p->next;
	}
	if (num == p->num)
	{
		printf("������˿�����֤�ţ�?18λ��������������?ֹ���벢���ز��������뺽���������?0����");
		scanf("%ld", &number);
		head1 = &a->pa;
		if (head1 == NULL)
			printf("������֤��Ϣ��\n");
		p1 = head1;
		while ((number != p1->number) && (p1->next != NULL))
		{
			a1 = p1;
			p1 = p1->next;
		}
		if (number == p1->number)
		{
			if (p1 == head1)
				head1 = p1->next;
			else
				a1->next = p1->next;
			printf("����?���\n");
			m = m - 1;
		}
		else
			printf("�޴�������Ϣ��\n");
	}
	else
		printf("���к�����Ϣ���޴˱�ţ�\n");
	return (head);
}
main()
{
	struct information *head, *information1;
	int i, num1, num2, num3;
	printf("���뺽����Ϣ��\n");
	head = creat();
sta:
	printf("���˵���\n1.��ʾ����\n2.���Ӻ���\n3.ɾ������\n4.���ඩ?�\n5.�����˶�\n6.����˿���ʾ\n7.�������\n8.���ļ�����\n9.�˳�\n");
	printf("����������Ҫѡ���ܵı�ţ�?");
	scanf("%d", &i);
	if (i == 1)
	{
		print(head);
		goto sta;
	}
	if (i == 2)
	{
		printf("�����������Ӻ������Ϣ���������ֹͣ���벢�������˵�������0����");
		information1 = (struct information *)malloc(sizeof(struct information));
		scanf("%d,%c,%c,%d,%d,%d,%d,%d,%d,%c,%d,%d", &information1->num, &information1->chufa, &information1->mudi, &information1->qifei.shi, &information1->qifei.fen, &information1->qifei.miao, &information1->luodi.shi, &information1->luodi.fen, &information1->luodi.miao, &information1->jixing, &information1->zuowei, &information1->jiage);
		while (information1->num != 0)
		{
			head = insert(head, information1);
			printf("�����������Ӻ������Ϣ���������ֹͣ���벢�������˵�������0����");
			information1 = (struct information *)malloc(sizeof(struct information));
			scanf("%d,%c,%c,%d,%d,%d,%d,%d,%d,%c,%d,%d", &information1->num, &information1->chufa, &information1->mudi, &information1->qifei.shi, &information1->qifei.fen, &information1->qifei.miao, &information1->luodi.shi, &information1->luodi.fen, &information1->luodi.miao, &information1->jixing, &information1->zuowei, &information1->jiage);
			n++;
		}
		goto sta;
	}
	if (i == 3)
	{
		printf("������ɾ���ĺ�����Ϣ����������?ֹ���벢�������˵�������0����");
		scanf("%d", &num1);
		while (num1 != 0)
		{
			head = del(head, num1);
			printf("������ɾ���ĺ�����Ϣ����������?ֹ���벢�������˵�������0����");
			scanf("%d", &num1);
		}
		goto sta;
	}
	if (i == 4)
	{
		printf("�����뺽��ţ��������ֹͣ���벢�������˵�������0����");
		scanf("%d", &num2);
		while (num2 != 0)
		{
			head = find1(head, num2);
			printf("�����뺽��ţ��������ֹͣ���벢�������˵�������0����");
			scanf("%d", &num2);
		}
		goto sta;
	}
	if (i == 5)
	{
		printf("�����뺽��ţ��������ֹͣ���벢�������˵�������0����");
		scanf("%d", &num3);
		while (num3 != 0)
		{
			head = find2(head, num3);
			printf("�����뺽��ţ��������ֹͣ���벢�������˵�������0����");
			scanf("%d", &num3);
		}
		goto sta;
	}
	if (i == 6)
	{
		printf("�˹�����δ��ͨ��\n");
		goto sta;
	}
	if (i == 7)
	{
		printf("�˹�����δ��ͨ��\n");
		goto sta;
	}
	if (i == 8)
	{
		printf("�˹�����δ��ͨ��\n");
		goto sta;
	}
	if (i == 9)
	{
		printf("�˹�����δ��ͨ��\n");
		goto sta;
	}
}