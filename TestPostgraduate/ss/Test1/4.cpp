#include <stdio.h>
#include <stdlib.h>
struct student
{
	int  num;
	struct student  *next;
};
struct student *createByTail()//����ͷ�������� 
{
	struct student *head;
	struct student *p1,*p2;
	int n;
	n=0;
	p1=p2=(struct student*)malloc(sizeof(struct student));
	scanf("%d",&p1->num);
	head=NULL;  //����������Ϊ������
	while(p1->num!=-1)    //numΪ-1����ζ���û��������
	{
		n=n+1;
		if(n==1)            //������һ�����
			head=p1;
		else
			p2->next=p1;
		p2=p1;            //p2ʼ��ָ�����һ����㣨��βָ�룩
		p1=(struct student*)malloc(sizeof(struct student)); //p1ָ���½��
        scanf("%d",&p1->num);
	}
	p2->next=NULL;  //�мǣ����һ������next��ֵΪNULL
	return head;
}
//��������е���Ϣ��num��
void  displayLink(struct student *head)
{
	struct student *p;
    p=head;
	printf("head-->");
	while(p!= NULL)
	{
		printf("%d-->",p->num);
		p=p->next;
	}
	printf("tail\n");
}
struct student *insertNodeInOrder(struct student *head,struct student *stu)
{
	struct student *p0,*p1,*p2;
	p1=head;
	p0=stu;
	if(head== NULL) //Ŀǰ���ǿ�����
	{
        p0->next=head;
        head=p0;
	}
	else
	{
		while((p0->num>p1->num)&&(p1->next!= NULL))
		{//���Ҳ���λ�ã�p2ָ��p1��ǰ��
			p2=p1;
			p1=p1->next;
		}
		//whileѭ���Ľ���������������������Ҫ�ж������ĸ������˳�ѭ��
		if(p0->num<=p1->num)
		{//��whileѭ�������ĵ�һ�������˳�ѭ������˿ɲ���p1���֮ǰ
            if(head==p1)     head=p0;
            else   p2->next=p0;
            p0->next=p1;
		}
        else
        {//��whileѭ�������ĵڶ��������˳�ѭ�������p0->num���Ҫ�������
            p1->next=p0;
            p0->next= NULL;
        }
	}
	return head;
}
struct student *sort(struct student *head)
{
    struct student *p,*s;
    p=head;
    head= NULL;
    while(p)
    {
		s=p;
		p=p->next;
		head=insertNodeInOrder(head, s);
    }
    return head;
}
struct student * merge(struct student *LA, struct student *LB)
{
	struct student  *p,*s;
    p=LB;
    while(p)
    {
		s=p;
		p=p->next;
		LA=insertNodeInOrder(LA, s);
    }
    return LA;
}
struct student* subtract(struct student* LA, struct student* LB)
{
	struct student *q, * p=LB;
	struct student *pre=NULL;//preָ��q��ǰ���������ʼ��ΪNULL
    while(p!=NULL) //��LB�������
     {
        q=LA;
        while (q!=NULL && q->num!=p->num)
        {
            pre=q;
            q=q->next; //��LA�в����Ƿ���Ԫ����p->num��ͬ
        }
        if (q!=NULL) //�ҵ�����ͬ��Ԫ�أ���ɾ��q��ָ����
        {
            if (q==LA) //���ɾ����һ�����
            {
                LA = LA -> next;
                free(q);
            }
            else
            {
                 pre->next=q->next;
                 free(q);
            }
        }
        p=p->next;
     }
     return LA;
}
void purge(struct student * head)
{
	struct student  *p,*q;
	if(head== NULL || head->next == NULL)
	   return;
	p=head;
	while(p->next!= NULL)
	{
		if(p->num == p->next->num)
		{
		    q=p->next;
		    p->next=q->next;
		    free(q);
		}
		else
		{
		   p=p->next;
	    }
	}
}
struct student* fun(struct student* L1, struct student* L2)
{
/*******************************��д������************************************/
	struct student *p, *q;
	L1 = merge(L1, L2);
	p = L1;
	while(p && p->next && p->num == p->next->num){//ɾ��ͷ�����ڶ��������ֵһ���� 
		struct student *p1 = p, *p2 = p->next;
		p = p->next->next;
		L1 = p;
		free(p1);free(p2); 
	} 
	while(p && p->next){
		if(p->num == p->next->num){
			struct student *p1 = p, *p2 = p->next;
			p = p->next->next;
			q->next = p;
			free(p1);free(p2);
		}else{
			q = p;
			p = p->next;
		}
	}
	return L1;
}
int main()
{
    struct student *headA, *headB, *headC, *headD;
    int i=0,n;
    scanf("%d", &n);
	while( i<n)
    {
        headA=createByTail();//��������A
        headB=createByTail();//��������B
        headC=createByTail();//��������C
        headD=createByTail();//��������D
        headA = sort(headA);//����A����
        headB = sort(headB);//����B����
        headC = sort(headC);//����C����
        headD = sort(headD);//����D����

        headA = merge(headA, headB);//������B�ϲ�������A��
        purge(headA);//ɾ������A���ظ�Ԫ��
        headA = subtract(headA, headC);//������A�м�ȥ����C��Ԫ��
        headA=fun(headA, headD);//������A������D����fun����
        displayLink(headA);//�������A�е�Ԫ��
        i++;
    }
    return 0;
}
