#include <stdio.h>
#include <stdlib.h>
struct student{
	int  num;
	struct student  *next;
};
int len = 0;
//�Ӽ��̶������ݴ��������½����뵽β��
struct student *createByTail()
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
		len++;
		if(n==1)            //������һ�����
			head=p1;
		else
			p2->next=p1;
		p2=p1;            //p2ʼ��ָ�����һ����㣨��βָ�룩
		p1=(struct student*)malloc(sizeof(struct student)); //p1ָ���½��
        scanf("%d",&p1->num);
	}
	p2->next=NULL;  //���һ������next��ֵΪNULL
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
//�������е�index������sָ����ָ��Ľ�㡣index��1��ʼ��
//���ڿ��ܲ��ڵ�һ����㣬���Ժ�������ͷָ�����������
struct student *insertNode(struct student *head, struct student *s, int index){
	if(index < 1 || index > len+1){
		return head;
	}else if(index == 1){
		s->next = head;
		head = s;
		len++;
	}else{
		struct student *p;
		p = head;
		int i = 1;
		while(i+1 < index){//�ҵ���index��ǰ���ڵ� 
			p = p->next;
			i++;
		}
		s->next = p->next;
		p->next = s;
		len++;
	}
	return head; 
}
int main()
{
    struct student *head;
    int index,data;
	head=createByTail();
	while(scanf("%d%d", &index,&data) != -1)
    {
        struct student * s = (struct student *) malloc(sizeof(struct student));
        s->num = data;
        head=insertNode(head, s, index);
        displayLink(head);
    }
    return 0;
}
