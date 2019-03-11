#include "stdio.h"
#include "stdlib.h"
#include"string.h"
#include"conio.h" 
typedef struct book
{
   int id;                    /*������*/
   char name[20];               /*����*/
   char author[20];             /*����*/
   char publish[30];            /*������*/
   int price;               /*�۸�*/
   int lend;               /*���*/
   int remein;             /*���*/
   struct book *next;
}Book;
/*���ͼ����Ϣ*/
void insertBook(Book **head)
{
  char ch;
  Book *p,*q=*head;
  while(1)
  {
    p=(Book*)malloc(sizeof(Book));
    printf("\t\t\t\t==============================================\n");
    printf("\t\t\t\t          *****���ͼ����Ϣ*****              \n");
    printf("\t\t\t\t==============================================\n");
    printf("\t\t\t\t�������ͼ��ļ�������:\t");
    scanf("%d",&p->id);
    printf("\t\t\t\t%s","����ͼ������:\t");
    scanf("%s",p->name);
    printf("\t\t\t\t%s","����ͼ������:\t");
    scanf("%s",p->author);
    printf("\t\t\t\t%s","����ͼ�������:\t");
    scanf("%s",p->publish);
    printf("\t\t\t\t%s","����ͼ��۸�:\t");
    scanf("%d",&p->price);
    printf("\t\t\t\t%s","����ͼ������:\t");
    scanf("%d",&p->lend);
    printf("\t\t\t\t%s","����ͼ������:\t");
    scanf("%d",&p->remein);
    p->next=NULL;
    if(!q)//q������ִ�� 
    {
      *head=p;
     }
    else
    {
      while(q->next)
       {
         q=q->next;
        }
      q->next=p;
     }
    printf("\t\t\t\t�Ƿ��������(y/n):");
    getchar();
	scanf("%c",&ch);
    if(ch == 'N'||ch == 'n') 
       break;		
    fflush(stdin);
   }
}
/*��ʾ����ͼ����Ϣ*/
void printall(Book *head)
{
	Book *p=head->next;
	printf("\t\t\t\t======================================================================\n");
    printf("\t\t\t\t                       *****��ӡͼ����Ϣ*****                         \n");
    printf("\t\t\t\t======================================================================\n");
	if(p)
	{
      {
		printf("\t\t\t\t=====================================================================\n");
		printf("\t\t\t\t������     ����         ����     ������       �۸�   �����   �����\n");
	    printf("\t\t\t\t=====================================================================\n");
    	}
     while(p)
	 {
		printf("\t\t\t\t%d\t%s  \t%s \t%s  \t%d\t%d\t%d\n",p->id,p->name,p->author,p->publish,p->price,p->lend,p->remein);
		printf("\t\t\t\t---------------------------------------------------------------------\n");
		p=p->next;
      }
    }
   else
   {
   	printf("\t\t\t\tû��ͼ����Ϣ��\n");
   }
} 
 /*����Ϣ���浽������*/
void save(Book *h)
{
     struct book *stu;
     FILE *fp;
     char filename[20];
    printf("\t\t\t\t==============================================\n");
    printf("\t\t\t\t          *****�洢ͼ����Ϣ*****              \n");
    printf("\t\t\t\t==============================================\n");
     printf("\t\t\t\t������Ҫ������ļ���:");
     scanf("%s",filename);
     if((fp=fopen(filename,"wt")) == NULL)
     {
            printf("\t\t\t\t�����ļ�ʧ��!\n");
            exit(1);
     }
	 else
	{           
      for(stu=h->next;stu!=NULL;stu=stu->next)
      {
	    fprintf(fp,"%d %s %s %s %d %d %d\n",stu->id,stu->name,stu->author,stu->publish,stu->price,stu->lend,stu->remein);
       }
        printf("\t\t\t\t�����ļ��ɹ�!\n");
	} 
    fclose(fp);
}
/*�Ӵ����ж�ȡ��Ϣ��������*/
struct book *read()
{
     struct book *head,*r,*stu;
     FILE *fp;
     char filename[20];
    printf("\t\t\t\t==============================================\n");
    printf("\t\t\t\t          *****����ͼ����Ϣ*****              \n");
    printf("\t\t\t\t==============================================\n");
     printf("\t\t\t\t������Ҫ��ȡ���ļ���:");
     gets(filename);
     fp=fopen(filename,"rt");
     if(fp == NULL)
     {
           printf("\t\t\t\t�ļ���ʧ�ܣ�\n");
           return NULL;
     }
	 head=(struct book *)malloc(sizeof(struct book));
     head->next=NULL;
     r=head;
     while(!feof(fp))//�ļ������� 
     {
     	stu=(struct book *)malloc(sizeof(struct book));
     	fscanf(fp,"%d %s %s %s %d %d %d\n",&stu->id,stu->name,stu->author,stu->publish,&stu->price,&stu->lend,&stu->remein);
     	r->next=stu;
     	r=stu;
	 }
	 r->next=NULL;
	 printf("\t\t\t\t�ļ��򿪳ɹ�!\n");
	 fclose(fp); 
	 return head;
 }
/*��ѯͼ����Ϣ����*/ 
Book *findbook(Book *head)
 {  
    int id;
    int flag=0;
    Book *p=head->next;
 	printf("\t\t\t\t������Ҫ��ѯ��id��");
	scanf("%d",&id);
   while(p)
   {  
      if(p->id==id)
      { 
        flag++;
        break;
        } 
      p=p->next;
    }
    if(flag==0)
    {
    	printf("\t\t\t\t%s\n","û�в�ѯ����Ϣ,��������������ţ�");
	}
 	return p;
  } 
/*��ѯͼ����Ϣ*/
void printbook(Book *book)
{
	 int id;
	 int flag;
	 struct book *p=book->next;
	 char ch;
	 while(1)
	 { 
	  printf("\t\t\t\t������Ҫ��ѯ��id��");
	  scanf("%d",&id);
      while(p)//���p��Ϊ�� 
      {
   	    flag=0;
        if(p->id==id)
        { 
          flag++;
          break;
         } 
        p=p->next;
       }
      if(flag==0)
       {
    	printf("\t\t\t\t%s\n","û�в�ѯ����Ϣ,�����²�ѯ��");
    	break;
	   }
	  printf("\t\t\t\t=====================================================================\n");
      printf("\t\t\t\t������     ����         ����     ������       �۸�   �����   �����\n");
      printf("\t\t\t\t=====================================================================\n");
      printf("\t\t\t\t%d\t%s  \t%s \t%s  \t%d\t%d\t%d\n",p->id,p->name,p->author,p->publish,p->price,p->lend,p->remein);
      printf("\t\t\t\t�Ƿ������ѯ(y/n):");
      getchar();  
	  scanf("%c",&ch);
      if(ch == 'N'||ch == 'n') 
       	break;
	  }
  }
/*��ϲ�ѯ��Ϣ*/
void printbook1(Book *book)
{
	 int id;
	 char author[10];
	 int flag;
	 struct book *p=book->next;
	 char ch;
	 while(1)
	 {  
	    printf("\t\t\t\t������Ҫ��ѯ��id�����ߣ�");
	    scanf("%d%s",&id,author);
        while(p) 
        {
   	      flag=0;
          if(p->id==id&&strcmp(p->author,author)==0)
          { 
            flag++;
            break;
           } 
         p=p->next;
        }
      if(flag==0)
      {
    	printf("\t\t\t\t%s\n","û�в�ѯ����Ϣ,�����²�ѯ��");
    	break;
	   }
	 printf("\t\t\t\t=====================================================================\n");
     printf("\t\t\t\t������     ����         ����     ������       �۸�   �����   �����\n");
     printf("\t\t\t\t=====================================================================\n");
   	 printf("\t\t\t\t%d\t%s  \t%s \t%s  \t%d\t%d\t%d\n",p->id,p->name,p->author,p->publish,p->price,p->lend,p->remein);
     printf("\t\t\t\t�Ƿ������ѯ(y/n):");
     getchar();  
	 scanf("%c",&ch);
     if(ch == 'N'||ch == 'n') 
       	break;
	}
}
void printbook2(Book *book)
{
	int x,y;
    printf("\t\t\t\t======================================================================\n");
    printf("\t\t\t\t                       *****��ѯͼ����Ϣ*****                          \n");
    printf("\t\t\t\t======================================================================\n");
	printf("\t\t\t\t�������ѯ��ʽ��  1.id��ѯ   2.id�����߲�ѯ \t");
	scanf("%d",&x);
	switch(x)
	{
		case 1:printbook(book);break;
		case 2:printbook1(book);break;
	 } 
}
/*�޸�ͼ����Ϣ*/
void modifyBook(Book *head,int id)
{
    Book *p=head->next;
    printf("\t\t\t\t==============================================\n");
    printf("\t\t\t\t          *****�޸�ͼ����Ϣ*****              \n");
    printf("\t\t\t\t==============================================\n");
	printf("\t\t\t\t��������Ҫ�޸ĵ���ļ�����:");
	scanf("%d",&id);
	while(p&&p->id!=id)//���p��Ϊ����p����Ҫ�ҵ�id 
	{
		p=p->next;
	}
	if(p)
	{	
		printf("\t\t\t\t%s","�����µ�ͼ�����ƣ�");
		scanf("%s",p->name);
		printf("\t\t\t\t%s","�����µ�ͼ�����ߣ�");
		scanf("%s",p->author);
		printf("\t\t\t\t%s","�����µ�ͼ������磺");
		scanf("%s",p->publish);
		printf("\t\t\t\t%s","�����µ�ͼ��۸�");
		scanf("%d",&p->price);
		printf("\t\t\t\t%s","�����µ�ͼ��������");
		scanf("%d",&p->lend);
		printf("\t\t\t\t%s","�����µ�ͼ��������");
		scanf("%d",&p->remein);
	}
	else
	{
		printf("\t\t\t\tδ��ѯ����ͼ�����Ϣ����������.\n");
	}
}
/*ɾ��ͼ����Ϣ*/
void deleteBook(Book *head)
{
	int id; 
	char ch; 
	printf("\t\t\t\t==============================================\n");
    printf("\t\t\t\t            *****ɾ��ͼ����Ϣ*****            \n");
    printf("\t\t\t\t==============================================\n");
	printf("\t\t\t\t������Ҫɾ����ͼ�������:");
	scanf("%d",&id);
	Book *q,*p=head->next;
	if(p->id==id)//id�ǵ�һ��� 
	  {
	    head->next=p->next;
	    free(p);
       }
    else
     {
	    while(p)
		 {
		  if(p->id==id)
	       {
	  		q->next=p->next;
			free(p);
			break;
			}
		  q=p;
		  p=p->next;
	     }
      }
  }
/*�����µ�ͼ����Ϣ*/
Book *infix(Book *head)
{
	int id;
	printf("\t\t\t\t==============================================\n");
    printf("\t\t\t\t          *****����ͼ����Ϣ*****              \n");
    printf("\t\t\t\t==============================================\n");
	printf("\t\t\t\t������Ҫ�����λ��ǰ���ͼ��ļ�����(Ϊ������һ��):");
	scanf("%d",&id);
	Book *q,*r;
	Book *p=head->next;
	q=(Book *)malloc(sizeof(Book));
	printf("\t\t\t\t�������ͼ��ļ�������:");
    scanf("%d",&q->id);
	printf("\t\t\t\t%s","����ͼ������:\t");
    scanf("%s",q->name);
    printf("\t\t\t\t%s","����ͼ������:\t");
    scanf("%s",q->author);
    printf("\t\t\t\t%s","����ͼ�������:\t");
    scanf("%s",q->publish);
    printf("\t\t\t\t%s","����ͼ��۸�:\t");
    scanf("%d",&q->price);
    printf("\t\t\t\t%s","����ͼ������:\t");
    scanf("%d",&q->lend);
    printf("\t\t\t\t%s","����ͼ������:\t");
    scanf("%d",&q->remein);
	if(id!=0)
	{
	 while(p)
	 {
	  if(p->id==id) 
	        break;
	  p=p->next;  
		
	 } 
	r=p->next;
	p->next=q;
	q->next=r;
	return head;
    }
    else
    {
    		q->next=p;
    		head->next=q;
    		return head;
	}
}
/*����ͼ����Ϣf*/ 
void sortbookf(Book *head)
{
	Book *p,*q,*r,*f;
	for(f=0;f!=head->next;f=r->next)
	{
	    for(r=head;r->next->next!=f;r=r->next)
	    {
	      	if(r->next->price>r->next->next->price)
	      	{
	      		p=r->next;
				q=r->next->next;
				r->next=q;
				p->next=q->next;
				q->next=p; 
			 }
		 } 
	 } 
 }
 /*����ͼ����Ϣ0*/ 
void sortbookz(Book *head)
{
	Book *p,*q,*r,*f;
	for(f=0;f!=head->next;f=r->next)
	{
	    for(r=head;r->next->next!=f;r=r->next)
	    {
	      	if(strcmp(r->next->author,r->next->next->author)>0)
	      	{
	      		p=r->next;
				q=r->next->next;
				r->next=q;
				p->next=q->next;
				q->next=p; 
			 }
		 } 
	 } 
	printall(head);
 }
 /*����ͼ����Ϣc*/
 void sortbookc(Book *head)
{
	Book *p,*q,*r,*f;
	for(f=0;f!=head->next;f=r->next)
	{
	    for(r=head;r->next->next!=f;r=r->next)
	    {
	      	if(strcmp(r->next->publish,r->next->next->publish)>0)
	      	{
	      		p=r->next;
				q=r->next->next;
				r->next=q;
				p->next=q->next;
				q->next=p; 
			 }
		 } 
	 } 
	printall(head);
 }
/*����ͼ����Ϣ1*/ 
void sortbook1(Book *head)
{
	Book *p,*q,*r,*f;
	for(f=0;f!=head->next;f=r->next)
	{
	    for(r=head;r->next->next!=f;r=r->next)
	    {
	      	if(r->next->price>r->next->next->price)
	      	{
	      		p=r->next;
				q=r->next->next;
				r->next=q;
				p->next=q->next;
				q->next=p; 
			 }
		 } 
	 } 
	printall(head);
 }
/*����ͼ����Ϣ2*/
void sortbook2(Book *head)
{
	Book *p,*q,*r,*f;
	for(f=0;f!=head->next;f=r->next)
	{
	    for(r=head;r->next->next!=f;r=r->next)
	    {
	      	if(r->next->lend>r->next->next->lend)
	      	{
	      		p=r->next;
				q=r->next->next;
				r->next=q;
				p->next=q->next;
				q->next=p; 
			 }
		 } 
	 } 
	printall(head);
 }
 /*����ͼ����Ϣ3*/
void sortbook3(Book *head)
{
	Book *p,*q,*r,*f;
	for(f=0;f!=head->next;f=r->next)
	{
	    for(r=head;r->next->next!=f;r=r->next)
	    {
	      	if(r->next->remein>r->next->next->remein)
	      	{
	      		p=r->next;
				q=r->next->next;
				r->next=q;
				p->next=q->next;
				q->next=p; 
			 }
		 } 
	 } 
	printall(head);
 }
 /*����ͼ����Ϣ4*/
 void sortBook1(Book *head)
{
	Book *p,*q,*r,*f;
	for(f=0;f!=head->next;f=r->next)
	{
	    for(r=head;r->next->next!=f;r=r->next)
	    {
	      	if(r->next->price<r->next->next->price)
	      	{
	      		p=r->next;
				q=r->next->next;
				r->next=q;
				p->next=q->next;
				q->next=p; 
			 }
		 } 
	 } 
	printall(head);
 }
 /*����ͼ����Ϣ5*/ 
 void sortBook2(Book *head)
{
	Book *p,*q,*r,*f;
	for(f=0;f!=head->next;f=r->next)
	{
	    for(r=head;r->next->next!=f;r=r->next)
	    {
	      	if(r->next->lend<r->next->next->lend)
	      	{
	      		p=r->next;
				q=r->next->next;
				r->next=q;
				p->next=q->next;
				q->next=p; 
			 }
		 } 
	 } 
	printall(head);
 }
/*����ͼ����Ϣ6*/ 
 void sortBook3(Book *head)
{
	Book *p,*q,*r,*f;
	for(f=0;f!=head->next;f=r->next)
	{
	    for(r=head;r->next->next!=f;r=r->next)
	    {
	      	if(r->next->remein<r->next->next->remein)
	      	{
	      		p=r->next;
				q=r->next->next;
				r->next=q;
				p->next=q->next;
				q->next=p; 
			 }
		 } 
	 } 
	printall(head);
 }
 void sortbook(Book *head)
{
	int x,y;
    printf("\t\t\t\t======================================================================\n");
    printf("\t\t\t\t                      ******����ͼ����Ϣ******                         \n");
    printf("\t\t\t\t======================================================================\n");
	printf("\t\t\t\t��ѡ������ʽ:    1.�Ӹߵ���    2.�ӵ͵��� \t\n");
	printf("\t\t\t\t");
	scanf("%d",&y);
	printf("\t\t\t\t������ѡ��ʽ����ţ� 1.ͼ��۸�  2.ͼ������  3.ͼ������\t\n");
	printf("\t\t\t\t");
	scanf("%d",&x);
	switch(y)
	{
	  case 1:
	  switch(x)
	   {
	   	 case 1:sortBook1(head);break;
	   	 case 2:sortBook2(head);break;
	  	 case 3:sortBook3(head);break;
	     };break;
	  case 2:
	  	switch(x)
	  	{
	  	  case 1:sortbook1(head);break;
		  case 2:sortbook2(head);break;
	      case 3:sortbook3(head);break;	
		 };break;
	  }
 }
 /*ͼ��ͳ��1*/
void statics1(Book *head)
{
	int n=1,i;
	sortbookz(head);
	Book *p=head->next,*r=head->next,*q=head->next->next;
	while(r)
	{
		r=r->next; 
	    n++;
     }
         printf("\n\t\t\t\t������Ϊ��%s�����������£�\n",p->author);
         printf("\t\t\t\t=====================================================================\n");
		 printf("\t\t\t\t������     ����         ����     ������       �۸�   �����   �����\n");
	     printf("\t\t\t\t=====================================================================\n");
	     printf("\t\t\t\t%d\t%s  \t%s \t%s  \t%d\t%d\t%d\n",p->id,p->name,p->author,p->publish,p->price,p->lend,p->remein);
	 for(i=0;i<n-2;i++)//n�ǽ��������д��һ����ʣn-1��
	 {
	   if(strcmp(p->author,q->author)!=0)
	   {
	   	 printf("\n\t\t\t\t������Ϊ��%s�����������£�\n",q->author);
	   	 printf("\t\t\t\t=====================================================================\n");
		 printf("\t\t\t\t������     ����         ����     ������       �۸�   �����   �����\n");
	     printf("\t\t\t\t=====================================================================\n");
	     printf("\t\t\t\t%d\t%s  \t%s \t%s  \t%d\t%d\t%d\n",q->id,q->name,q->author,q->publish,q->price,q->lend,q->remein);
	    }
	   else
	   {
	   	 	 printf("\t\t\t\t%d\t%s  \t%s \t%s  \t%d\t%d\t%d\n",q->id,q->name,q->author,q->publish,q->price,q->lend,q->remein);
		 }
		p=p->next;
		q=q->next;   
      }
}
 /*ͼ��ͳ��1*/
void statics2(Book *head)
{
	int n=1,i;
    sortbookc(head);
	Book *p=head->next,*r=head->next,*q=head->next->next;
	while(r)
	{
		r=r->next; 
	   n++;
     }
         printf("\n\t\t\t\t������Ϊ��%s�����������£�\n",p->publish);
         printf("\t\t\t\t=====================================================================\n");
		 printf("\t\t\t\t������     ����         ����     ������       �۸�   �����   �����\n");
	     printf("\t\t\t\t=====================================================================\n");
	     printf("\t\t\t\t%d\t%s  \t%s \t%s  \t%d\t%d\t%d\n",p->id,p->name,p->author,p->publish,p->price,p->lend,p->remein);
	 for(i=0;i<n-2;i++)
	 {
	   if(strcmp(p->publish,q->publish)!=0)
	   {
	   	 printf("\n\t\t\t\t������Ϊ��%s�����������£�\n",q->publish);
	   	 printf("\t\t\t\t=====================================================================\n");
		 printf("\t\t\t\t������     ����         ����     ������       �۸�   �����   �����\n");
	     printf("\t\t\t\t=====================================================================\n");
	     printf("\t\t\t\t%d\t%s  \t%s \t%s  \t%d\t%d\t%d\n",q->id,q->name,q->author,q->publish,q->price,q->lend,q->remein);
	    }
	   else
	   {
	   	 printf("\t\t\t\t%d\t%s  \t%s \t%s  \t%d\t%d\t%d\n",q->id,q->name,q->author,q->publish,q->price,q->lend,q->remein);
		 }
		p=p->next;
		q=q->next;   
	  }
}
 /*ͼ��ͳ��1*/
void statics3(Book *head)
{
	int n=1,i;
	sortbook1(head);
	Book *p=head->next,*r=head->next,*q=head->next->next;
	while(r)
	{
		r=r->next; 
	   n++;
     }
         printf("\n\t\t\t\t�۸�Ϊ��%d�����������£�\n",p->price);
         printf("\t\t\t\t=====================================================================\n");
		 printf("\t\t\t\t������     ����         ����     ������       �۸�   �����   �����\n");
	     printf("\t\t\t\t=====================================================================\n");
	     printf("\t\t\t\t%d\t%s  \t%s \t%s  \t%d\t%d\t%d\n",p->id,p->name,p->author,p->publish,p->price,p->lend,p->remein);
	 for(i=0;i<n-2;i++)
	 {
	   if(p->price!=q->price)
	   {
	   	 printf("\n\t\t\t\t�۸�Ϊ��%d�����������£�\n",q->price);
	   	 printf("\t\t\t\t=====================================================================\n");
	     printf("\t\t\t\t������     ����         ����     ������       �۸�   �����   �����\n");
	     printf("\t\t\t\t=====================================================================\n");
	     printf("\t\t\t\t%d\t%s  \t%s \t%s  \t%d\t%d\t%d\n",q->id,q->name,q->author,q->publish,q->price,q->lend,q->remein);
	    }
	   else
	   {
	   	 printf("\t\t\t\t%d\t%s  \t%s \t%s  \t%d\t%d\t%d\n",q->id,q->name,q->author,q->publish,q->price,q->lend,q->remein);
		 }
		p=p->next;
		q=q->next;   
	  }
}
 /*ͼ�����ͳ��*/
void statics4(Book *head)
{
	int n=1,i;
	sortbookf(head);
	Book *p=head->next,*r=head->next,*q=head->next->next;
	while(r)
	{
	   r=r->next; 
	   n++;
     }
         printf("\n\t\t\t\t�۸�%d���ͽ������%d������ͬ���������£�\n",p->price,p->lend);
         printf("\t\t\t\t=====================================================================\n");
		 printf("\t\t\t\t������     ����         ����     ������       �۸�   �����   �����\n");
	     printf("\t\t\t\t=====================================================================\n");
	     printf("\t\t\t\t%d\t%s  \t%s \t%s  \t%d\t%d\t%d\n",p->id,p->name,p->author,p->publish,p->price,p->lend,p->remein);
	 for(i=0;i<n-2;i++)
	 {
	   if(p->price!=q->price||p->lend!=q->lend)
	   {
	   	 printf("\n\t\t\t\t�۸�%d���ͽ������%d������ͬ���������£�\n",q->price,q->lend);
	     printf("\t\t\t\t=====================================================================\n");
		 printf("\t\t\t\t������     ����         ����     ������       �۸�   �����   �����\n");
	     printf("\t\t\t\t=====================================================================\n");
	     printf("\t\t\t\t%d\t%s  \t%s \t%s  \t%d\t%d\t%d\n",q->id,q->name,q->author,q->publish,q->price,q->lend,q->remein);
	    }
	   else
	   {
	   	  printf("\t\t\t\t%d\t%s  \t%s \t%s  \t%d\t%d\t%d\n",q->id,q->name,q->author,q->publish,q->price,q->lend,q->remein);
		 }
		p=p->next;
		q=q->next;   
	  }
}
/*ͳ��ͼ����Ϣ*/ 
void statics(Book *head)
{
	int x,y;
    printf("\t\t\t\t======================================================================\n");
    printf("\t\t\t\t                       *****ͳ��ͼ����Ϣ*****                         \n");
    printf("\t\t\t\t======================================================================\n");
	printf("\t\t\t\t������ͳ�Ʒ�ʽ��1.������ͬ   2.��������ͬ  3.�۸���ͬ \t\n");
	printf("\t\t\t\t                4.�۸�ͽ��������ͬ     \t");
	scanf("%d",&x);
	switch(x)
	{
		case 1:statics1(head);break;
		case 2:statics2(head);break;
		case 3:statics3(head);break;
		case 4:statics4(head);break;
	}
}
/*������*/
int main()
{
	int choice,a;
	Book *head;
	int Book_id;
	head=(Book *)malloc(sizeof(Book));
	head->next=NULL;
	printf("\t\t\t\t-------------------------------------------\n");
    printf("\t\t\t\t**********��ӭʹ��ͼ����Ϣ����ϵͳ*********\n");
    printf("\t\t\t\t-------------------------------------------\n");
	printf("\t\t\t\t��¼�������������Ա���룺");
	scanf("%d",&a);
	if(a!=666)
	{
		printf("\t\t\t\t���벻��ȷ������");
		exit(1);
	}
	else{
	do
	{ 
		printf("\n\n");
        printf("\t\t\t\t-------------------------------------------\n");
        printf("\t\t\t\t**********��ӭʹ��ͼ����Ϣ����ϵͳ*********\n");
        printf("\t\t\t\t-------------------------------------------\n");
        printf("\t\t\t\t*             1-¼��ͼ����Ϣ              * \n");
        printf("\t\t\t\t*             2-��ѯͼ����Ϣ              * \n");
        printf("\t\t\t\t*             3-�޸�ͼ����Ϣ              * \n");
        printf("\t\t\t\t*             4-ɾ��ͼ����Ϣ              * \n");
        printf("\t\t\t\t*             5-����ͼ����Ϣ              * \n");
        printf("\t\t\t\t*             6-��ӡͼ����Ϣ              * \n");
        printf("\t\t\t\t*             7-����ͼ����Ϣ              * \n");
        printf("\t\t\t\t*             8-ͳ��ͼ����Ϣ              * \n");
        printf("\t\t\t\t*             9-�洢ͼ����Ϣ              * \n");
        printf("\t\t\t\t*            10-�����ļ���Ϣ              * \n");
        printf("\t\t\t\t*            11-  �˳�����                * \n");
        printf("\t\t\t\t-------------------------------------------\n");
        printf("\t\t\t\t��ѡ���� 1--11\n");
        printf("                                ");
        scanf("%d",&choice);
        system("cls");
        getchar();
		switch(choice)
		{
		   case 1: insertBook(&head);printf("\t\t\t\t����������ز˵���");getch();system("cls");break; 
	       case 2: printbook2(head);printf("\t\t\t\t����������ز˵���");getch();system("cls");break;
		   case 3: modifyBook(head,head->id);printf("\t\t\t\t����������ز˵���");getch();system("cls");break;
		   case 4: deleteBook(head);printf("\t\t\t\t����������ز˵���");getch();system("cls");break;
		   case 5: infix(head);printf("\t\t\t\t����������ز˵���");getch();system("cls");break; 
		   case 6: printall(head);printf("\t\t\t\t����������ز˵���");getch();break;
		   case 7: sortbook(head);printf("\t\t\t\t����������ز˵���");getch();system("cls");break;
		   case 8: statics(head);printf("\t\t\t\t����������ز˵���");getch();system("cls");break;
		   case 9: save(head);printf("\t\t\t\t����������ز˵���");getch();system("cls");break;
		   case 10: head=read();printf("\t\t\t\t����������ز˵���");getch();system("cls");break; 
		}
	}while(choice!=11);
  }
}

