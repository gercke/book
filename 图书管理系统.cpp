#include "stdio.h"
#include "stdlib.h"
#include"string.h"
#include"conio.h" 
typedef struct book
{
   int id;                    /*检索号*/
   char name[20];               /*书名*/
   char author[20];             /*作者*/
   char publish[30];            /*出版社*/
   int price;               /*价格*/
   int lend;               /*借出*/
   int remein;             /*库存*/
   struct book *next;
}Book;
/*添加图书信息*/
void insertBook(Book **head)
{
  char ch;
  Book *p,*q=*head;
  while(1)
  {
    p=(Book*)malloc(sizeof(Book));
    printf("\t\t\t\t==============================================\n");
    printf("\t\t\t\t          *****添加图书信息*****              \n");
    printf("\t\t\t\t==============================================\n");
    printf("\t\t\t\t分配给该图书的检索号是:\t");
    scanf("%d",&p->id);
    printf("\t\t\t\t%s","输入图书名称:\t");
    scanf("%s",p->name);
    printf("\t\t\t\t%s","输入图书作者:\t");
    scanf("%s",p->author);
    printf("\t\t\t\t%s","输入图书出版社:\t");
    scanf("%s",p->publish);
    printf("\t\t\t\t%s","输入图书价格:\t");
    scanf("%d",&p->price);
    printf("\t\t\t\t%s","输入图书借出数:\t");
    scanf("%d",&p->lend);
    printf("\t\t\t\t%s","输入图书库存数:\t");
    scanf("%d",&p->remein);
    p->next=NULL;
    if(!q)//q不存在执行 
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
    printf("\t\t\t\t是否继续输入(y/n):");
    getchar();
	scanf("%c",&ch);
    if(ch == 'N'||ch == 'n') 
       break;		
    fflush(stdin);
   }
}
/*显示所有图书信息*/
void printall(Book *head)
{
	Book *p=head->next;
	printf("\t\t\t\t======================================================================\n");
    printf("\t\t\t\t                       *****打印图书信息*****                         \n");
    printf("\t\t\t\t======================================================================\n");
	if(p)
	{
      {
		printf("\t\t\t\t=====================================================================\n");
		printf("\t\t\t\t检索号     书名         作者     出版社       价格   借出数   库存数\n");
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
   	printf("\t\t\t\t没有图书信息！\n");
   }
} 
 /*将信息保存到磁盘中*/
void save(Book *h)
{
     struct book *stu;
     FILE *fp;
     char filename[20];
    printf("\t\t\t\t==============================================\n");
    printf("\t\t\t\t          *****存储图书信息*****              \n");
    printf("\t\t\t\t==============================================\n");
     printf("\t\t\t\t请输入要保存的文件名:");
     scanf("%s",filename);
     if((fp=fopen(filename,"wt")) == NULL)
     {
            printf("\t\t\t\t保存文件失败!\n");
            exit(1);
     }
	 else
	{           
      for(stu=h->next;stu!=NULL;stu=stu->next)
      {
	    fprintf(fp,"%d %s %s %s %d %d %d\n",stu->id,stu->name,stu->author,stu->publish,stu->price,stu->lend,stu->remein);
       }
        printf("\t\t\t\t保存文件成功!\n");
	} 
    fclose(fp);
}
/*从磁盘中读取信息存入链表*/
struct book *read()
{
     struct book *head,*r,*stu;
     FILE *fp;
     char filename[20];
    printf("\t\t\t\t==============================================\n");
    printf("\t\t\t\t          *****读出图书信息*****              \n");
    printf("\t\t\t\t==============================================\n");
     printf("\t\t\t\t请输入要读取的文件名:");
     gets(filename);
     fp=fopen(filename,"rt");
     if(fp == NULL)
     {
           printf("\t\t\t\t文件打开失败！\n");
           return NULL;
     }
	 head=(struct book *)malloc(sizeof(struct book));
     head->next=NULL;
     r=head;
     while(!feof(fp))//文件不结束 
     {
     	stu=(struct book *)malloc(sizeof(struct book));
     	fscanf(fp,"%d %s %s %s %d %d %d\n",&stu->id,stu->name,stu->author,stu->publish,&stu->price,&stu->lend,&stu->remein);
     	r->next=stu;
     	r=stu;
	 }
	 r->next=NULL;
	 printf("\t\t\t\t文件打开成功!\n");
	 fclose(fp); 
	 return head;
 }
/*查询图书信息辅助*/ 
Book *findbook(Book *head)
 {  
    int id;
    int flag=0;
    Book *p=head->next;
 	printf("\t\t\t\t请输入要查询的id：");
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
    	printf("\t\t\t\t%s\n","没有查询到信息,请重新输入检索号：");
	}
 	return p;
  } 
/*查询图书信息*/
void printbook(Book *book)
{
	 int id;
	 int flag;
	 struct book *p=book->next;
	 char ch;
	 while(1)
	 { 
	  printf("\t\t\t\t请输入要查询的id：");
	  scanf("%d",&id);
      while(p)//如果p不为空 
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
    	printf("\t\t\t\t%s\n","没有查询到信息,请重新查询！");
    	break;
	   }
	  printf("\t\t\t\t=====================================================================\n");
      printf("\t\t\t\t检索号     书名         作者     出版社       价格   借出数   库存数\n");
      printf("\t\t\t\t=====================================================================\n");
      printf("\t\t\t\t%d\t%s  \t%s \t%s  \t%d\t%d\t%d\n",p->id,p->name,p->author,p->publish,p->price,p->lend,p->remein);
      printf("\t\t\t\t是否继续查询(y/n):");
      getchar();  
	  scanf("%c",&ch);
      if(ch == 'N'||ch == 'n') 
       	break;
	  }
  }
/*组合查询信息*/
void printbook1(Book *book)
{
	 int id;
	 char author[10];
	 int flag;
	 struct book *p=book->next;
	 char ch;
	 while(1)
	 {  
	    printf("\t\t\t\t请输入要查询的id和作者：");
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
    	printf("\t\t\t\t%s\n","没有查询到信息,请重新查询！");
    	break;
	   }
	 printf("\t\t\t\t=====================================================================\n");
     printf("\t\t\t\t检索号     书名         作者     出版社       价格   借出数   库存数\n");
     printf("\t\t\t\t=====================================================================\n");
   	 printf("\t\t\t\t%d\t%s  \t%s \t%s  \t%d\t%d\t%d\n",p->id,p->name,p->author,p->publish,p->price,p->lend,p->remein);
     printf("\t\t\t\t是否继续查询(y/n):");
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
    printf("\t\t\t\t                       *****查询图书信息*****                          \n");
    printf("\t\t\t\t======================================================================\n");
	printf("\t\t\t\t请输入查询方式：  1.id查询   2.id和作者查询 \t");
	scanf("%d",&x);
	switch(x)
	{
		case 1:printbook(book);break;
		case 2:printbook1(book);break;
	 } 
}
/*修改图书信息*/
void modifyBook(Book *head,int id)
{
    Book *p=head->next;
    printf("\t\t\t\t==============================================\n");
    printf("\t\t\t\t          *****修改图书信息*****              \n");
    printf("\t\t\t\t==============================================\n");
	printf("\t\t\t\t请输入你要修改的书的检索号:");
	scanf("%d",&id);
	while(p&&p->id!=id)//如果p不为空且p不是要找的id 
	{
		p=p->next;
	}
	if(p)
	{	
		printf("\t\t\t\t%s","输入新的图书名称：");
		scanf("%s",p->name);
		printf("\t\t\t\t%s","输入新的图书作者：");
		scanf("%s",p->author);
		printf("\t\t\t\t%s","输入新的图书出版社：");
		scanf("%s",p->publish);
		printf("\t\t\t\t%s","输入新的图书价格：");
		scanf("%d",&p->price);
		printf("\t\t\t\t%s","输入新的图书借出数：");
		scanf("%d",&p->lend);
		printf("\t\t\t\t%s","输入新的图书库存数：");
		scanf("%d",&p->remein);
	}
	else
	{
		printf("\t\t\t\t未查询到该图书的信息，请检查输入.\n");
	}
}
/*删除图书信息*/
void deleteBook(Book *head)
{
	int id; 
	char ch; 
	printf("\t\t\t\t==============================================\n");
    printf("\t\t\t\t            *****删除图书信息*****            \n");
    printf("\t\t\t\t==============================================\n");
	printf("\t\t\t\t请输入要删除的图书检索号:");
	scanf("%d",&id);
	Book *q,*p=head->next;
	if(p->id==id)//id是第一结点 
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
/*插入新的图书信息*/
Book *infix(Book *head)
{
	int id;
	printf("\t\t\t\t==============================================\n");
    printf("\t\t\t\t          *****插入图书信息*****              \n");
    printf("\t\t\t\t==============================================\n");
	printf("\t\t\t\t请输入要插入的位置前面的图书的检索号(为零则插第一个):");
	scanf("%d",&id);
	Book *q,*r;
	Book *p=head->next;
	q=(Book *)malloc(sizeof(Book));
	printf("\t\t\t\t分配给该图书的检索号是:");
    scanf("%d",&q->id);
	printf("\t\t\t\t%s","输入图书名称:\t");
    scanf("%s",q->name);
    printf("\t\t\t\t%s","输入图书作者:\t");
    scanf("%s",q->author);
    printf("\t\t\t\t%s","输入图书出版社:\t");
    scanf("%s",q->publish);
    printf("\t\t\t\t%s","输入图书价格:\t");
    scanf("%d",&q->price);
    printf("\t\t\t\t%s","输入图书借出数:\t");
    scanf("%d",&q->lend);
    printf("\t\t\t\t%s","输入图书库存数:\t");
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
/*排序图书信息f*/ 
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
 /*排序图书信息0*/ 
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
 /*排序图书信息c*/
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
/*排序图书信息1*/ 
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
/*排序图书信息2*/
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
 /*排序图书信息3*/
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
 /*排序图书信息4*/
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
 /*排序图书信息5*/ 
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
/*排序图书信息6*/ 
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
    printf("\t\t\t\t                      ******排序图书信息******                         \n");
    printf("\t\t\t\t======================================================================\n");
	printf("\t\t\t\t请选择排序方式:    1.从高到低    2.从低到高 \t\n");
	printf("\t\t\t\t");
	scanf("%d",&y);
	printf("\t\t\t\t请输入选择方式的序号： 1.图书价格  2.图书借出数  3.图书库存数\t\n");
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
 /*图书统计1*/
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
         printf("\n\t\t\t\t作者名为“%s”的书有以下：\n",p->author);
         printf("\t\t\t\t=====================================================================\n");
		 printf("\t\t\t\t检索号     书名         作者     出版社       价格   借出数   库存数\n");
	     printf("\t\t\t\t=====================================================================\n");
	     printf("\t\t\t\t%d\t%s  \t%s \t%s  \t%d\t%d\t%d\n",p->id,p->name,p->author,p->publish,p->price,p->lend,p->remein);
	 for(i=0;i<n-2;i++)//n是结点数上面写了一个，剩n-1个
	 {
	   if(strcmp(p->author,q->author)!=0)
	   {
	   	 printf("\n\t\t\t\t作者名为“%s”的书有以下：\n",q->author);
	   	 printf("\t\t\t\t=====================================================================\n");
		 printf("\t\t\t\t检索号     书名         作者     出版社       价格   借出数   库存数\n");
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
 /*图书统计1*/
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
         printf("\n\t\t\t\t出版社为“%s”的书有以下：\n",p->publish);
         printf("\t\t\t\t=====================================================================\n");
		 printf("\t\t\t\t检索号     书名         作者     出版社       价格   借出数   库存数\n");
	     printf("\t\t\t\t=====================================================================\n");
	     printf("\t\t\t\t%d\t%s  \t%s \t%s  \t%d\t%d\t%d\n",p->id,p->name,p->author,p->publish,p->price,p->lend,p->remein);
	 for(i=0;i<n-2;i++)
	 {
	   if(strcmp(p->publish,q->publish)!=0)
	   {
	   	 printf("\n\t\t\t\t出版社为“%s”的书有以下：\n",q->publish);
	   	 printf("\t\t\t\t=====================================================================\n");
		 printf("\t\t\t\t检索号     书名         作者     出版社       价格   借出数   库存数\n");
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
 /*图书统计1*/
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
         printf("\n\t\t\t\t价格为“%d”的书有以下：\n",p->price);
         printf("\t\t\t\t=====================================================================\n");
		 printf("\t\t\t\t检索号     书名         作者     出版社       价格   借出数   库存数\n");
	     printf("\t\t\t\t=====================================================================\n");
	     printf("\t\t\t\t%d\t%s  \t%s \t%s  \t%d\t%d\t%d\n",p->id,p->name,p->author,p->publish,p->price,p->lend,p->remein);
	 for(i=0;i<n-2;i++)
	 {
	   if(p->price!=q->price)
	   {
	   	 printf("\n\t\t\t\t价格为“%d”的书有以下：\n",q->price);
	   	 printf("\t\t\t\t=====================================================================\n");
	     printf("\t\t\t\t检索号     书名         作者     出版社       价格   借出数   库存数\n");
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
 /*图书组合统计*/
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
         printf("\n\t\t\t\t价格“%d”和借出数“%d”都相同的书有以下：\n",p->price,p->lend);
         printf("\t\t\t\t=====================================================================\n");
		 printf("\t\t\t\t检索号     书名         作者     出版社       价格   借出数   库存数\n");
	     printf("\t\t\t\t=====================================================================\n");
	     printf("\t\t\t\t%d\t%s  \t%s \t%s  \t%d\t%d\t%d\n",p->id,p->name,p->author,p->publish,p->price,p->lend,p->remein);
	 for(i=0;i<n-2;i++)
	 {
	   if(p->price!=q->price||p->lend!=q->lend)
	   {
	   	 printf("\n\t\t\t\t价格“%d”和借出数“%d”都相同的书有以下：\n",q->price,q->lend);
	     printf("\t\t\t\t=====================================================================\n");
		 printf("\t\t\t\t检索号     书名         作者     出版社       价格   借出数   库存数\n");
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
/*统计图书信息*/ 
void statics(Book *head)
{
	int x,y;
    printf("\t\t\t\t======================================================================\n");
    printf("\t\t\t\t                       *****统计图书信息*****                         \n");
    printf("\t\t\t\t======================================================================\n");
	printf("\t\t\t\t请输入统计方式：1.作者相同   2.出版社相同  3.价格相同 \t\n");
	printf("\t\t\t\t                4.价格和借出数都相同     \t");
	scanf("%d",&x);
	switch(x)
	{
		case 1:statics1(head);break;
		case 2:statics2(head);break;
		case 3:statics3(head);break;
		case 4:statics4(head);break;
	}
}
/*主函数*/
int main()
{
	int choice,a;
	Book *head;
	int Book_id;
	head=(Book *)malloc(sizeof(Book));
	head->next=NULL;
	printf("\t\t\t\t-------------------------------------------\n");
    printf("\t\t\t\t**********欢迎使用图书信息管理系统*********\n");
    printf("\t\t\t\t-------------------------------------------\n");
	printf("\t\t\t\t登录界面请输入管理员密码：");
	scanf("%d",&a);
	if(a!=666)
	{
		printf("\t\t\t\t密码不正确！！！");
		exit(1);
	}
	else{
	do
	{ 
		printf("\n\n");
        printf("\t\t\t\t-------------------------------------------\n");
        printf("\t\t\t\t**********欢迎使用图书信息管理系统*********\n");
        printf("\t\t\t\t-------------------------------------------\n");
        printf("\t\t\t\t*             1-录入图书信息              * \n");
        printf("\t\t\t\t*             2-查询图书信息              * \n");
        printf("\t\t\t\t*             3-修改图书信息              * \n");
        printf("\t\t\t\t*             4-删除图书信息              * \n");
        printf("\t\t\t\t*             5-插入图书信息              * \n");
        printf("\t\t\t\t*             6-打印图书信息              * \n");
        printf("\t\t\t\t*             7-排序图书信息              * \n");
        printf("\t\t\t\t*             8-统计图书信息              * \n");
        printf("\t\t\t\t*             9-存储图书信息              * \n");
        printf("\t\t\t\t*            10-读出文件信息              * \n");
        printf("\t\t\t\t*            11-  退出程序                * \n");
        printf("\t\t\t\t-------------------------------------------\n");
        printf("\t\t\t\t请选择功能 1--11\n");
        printf("                                ");
        scanf("%d",&choice);
        system("cls");
        getchar();
		switch(choice)
		{
		   case 1: insertBook(&head);printf("\t\t\t\t按任意键返回菜单！");getch();system("cls");break; 
	       case 2: printbook2(head);printf("\t\t\t\t按任意键返回菜单！");getch();system("cls");break;
		   case 3: modifyBook(head,head->id);printf("\t\t\t\t按任意键返回菜单！");getch();system("cls");break;
		   case 4: deleteBook(head);printf("\t\t\t\t按任意键返回菜单！");getch();system("cls");break;
		   case 5: infix(head);printf("\t\t\t\t按任意键返回菜单！");getch();system("cls");break; 
		   case 6: printall(head);printf("\t\t\t\t按任意键返回菜单！");getch();break;
		   case 7: sortbook(head);printf("\t\t\t\t按任意键返回菜单！");getch();system("cls");break;
		   case 8: statics(head);printf("\t\t\t\t按任意键返回菜单！");getch();system("cls");break;
		   case 9: save(head);printf("\t\t\t\t按任意键返回菜单！");getch();system("cls");break;
		   case 10: head=read();printf("\t\t\t\t按任意键返回菜单！");getch();system("cls");break; 
		}
	}while(choice!=11);
  }
}

