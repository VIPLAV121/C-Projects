#include<stdio.h>
#include<string.h>
typedef struct Book
{
	char bname[90];
	int id;
	char author[90];
	double price;
	float rating;
}Book;
int n;
void storebook(Book*,int);
void display (Book*,int);
void search_by_id(Book*,int);
void search_by_bname(Book*,int);
void search_by_author(Book*,int);
void update_by_price(Book*,int,int);
void update_by_rating(Book*,int,int);
void delete_by_id(Book*,int);
void sort_by_price(Book*,int);
void sort_by_rating(Book*,int);
void main()
{
	printf("\nEnter the size of the Array:- ");
	scanf("%d",&n);
	Book a1[n];
 	storebook (a1,n);
	int choice;
	int ch;
	int exit=1;
	do
	{
	printf("\n********************************************************************************************************************\n");
		printf("\npress 1=>Display\npress 2=>Search\npress 3=>update\npress 4=>delete\npress 5=>Sort\npress 6=>Exit \n\n");
	printf("\n********************************************************************************************************************\n");
		printf("\n\n   |Enter the choice|: ");
		scanf("%d",&choice);
		if(choice==1)
			{	
				display(a1,n);
			}
		else if(choice==2)
		{
			//printf("\npress 1=>Display\npress 2=>Search\npress 3=>update\npress 4=>delete\npress 5=>Sort\npress 6=>Exit \n");
			printf("\nSearch by Id press        => 1");
			printf("\nSearch by Book Name press => 2");
			printf("\nSearch by Author press    => 3");
			printf("\n\nEnter the choice: ");
			scanf("%d",&ch);
			{
			if(ch==1)
				{
					search_by_id(a1,n);
				}
			else  if(ch==2)
				{
					search_by_bname(a1,n);
				}
			else if(ch==3)
				{
					search_by_author(a1,n);
				}
			else
				{
					printf("\n\nEnter the correct choice\n\n");
				}
			}
		}
		else if(choice==3)
		{
			printf("\n\nUpdate by id press\n=> 1\n");
			printf("search by name press 2\n");
			printf("\n\nenter the choice:");
			scanf("%d",&ch);
			if(ch==1)
			{
				int searchid;
				printf("enter the id update the price: ");
				scanf("%d",&searchid);
				update_by_price(a1,n,searchid);
			}
		else if(ch==2) 
			{
				int searchid;
				printf("\nEnter the id update the Book name:");
				scanf("%d",&searchid);
				update_by_rating(a1,n,searchid);
			}
			else
			{
				printf("\n\nEnter the correct choice\n");	
			}
		}
		else if(choice==4)	
			{
				delete_by_id(a1,n);
			}
		else if(choice==5)
		{
			int A,B;
			
			printf("\n\nenter 1 for sort by price\n 2 for sort by rating:");
			scanf("%d",&ch);
			
			if(ch==1)
			{
				sort_by_price(a1,n);
			}
			else if(ch==2)
			{
				sort_by_rating(a1,n);
			}
			else
			{
			printf("\n---------------------------------------Enter The Correct Choice---------------------------------------------\n");
			}
		}
		printf("\n****************************************************************************************************************\n");
		printf("\n\nDo you want to continue\n1=>For continue\n2=>for exit\n\n");
		scanf("%d",&exit);
	}while(exit==1);
}
void storebook(Book* a1,int n)
{
	int i;
	printf("************************************************************************************************************************");
	for(i=0;i<n;i++)
	{
		fflush(stdin);
		printf("\nEnter the Bookname    : ");
		gets(a1[i].bname);
		printf("\nEnter the Id          : ");
		scanf("%d",&a1[i].id);
		fflush(stdin);
		printf("\nEnter the Author name : ");
		gets(a1[i].author);
		printf("\nEnter the Price       : ");
		scanf("%lf",&a1[i].price);
		printf("\nEnter the Rating      : ");
		scanf("%f",&a1[i].rating);
		printf("******************************************************************************************************************\n");
	}
	
}
void display (Book* a1,int n)
{
	int i;
	for(i=0;i<n;i++)
	printf("\n\nBook name is    : %s\nId is           : %d\nAuthor name is  : %s\nPrice is        : %lf\nRating is       : %f\n",a1[i].bname,a1[i].id,a1[i].author,a1[i].price,a1[i].rating);
}
void search_by_id(Book* a1,int n)
{
	int i;
	int num;
	printf("Enter the Id:");
	scanf("%d",&num);
	for(i=0;i<n;i++)
	{
		if(num==a1[i].id)
		{
			printf("\n---------------------------------------The record is found--------------------------------------------------\n");
			printf("\n Book name  :%s",a1[i].bname);
			printf("\n Book id    :%d",a1[i].id);
			printf("\n Book author:%s",a1[i].author);
			printf("\n Book price :%lf",a1[i].price);
			printf("\n Book rating: %f",a1[i].rating);
		}
	}
}
void search_by_bname(Book* a1,int n)
{
	int i;
	char name[200];
	fflush(stdin);
	printf("\nEnter the Book name:");
	//scanf("%s",&name);	
	gets(name);
	for(i=0;i<n;i++)
	{
		if(strcmp(a1[i].bname,name)==0)
		{
			printf("\n---------------------------------------The record is found--------------------------------------------------\n");
			printf("\n Book name  : %s",a1[i].bname);
			printf("\n Book id    : %d",a1[i].id);
			printf("\n Book author: %s",a1[i].author);
			printf("\n Book price : %lf",a1[i].price);
			printf("\n Book rating: %f",a1[i].rating);
		}
	}
}
void search_by_author(Book*a1,int n)
{
	int i;
	char name[90];
	fflush(stdin);	
	printf("enter the author name:");
	gets(name);
	for(i=0;i<n;i++)
	{
		if(strcmp(a1[i].author,name)==0)
		{
			printf("\n---------------------------------------The record is found--------------------------------------------------\n");
			printf("\n Book name  : %s",a1[i].bname);
			printf("\n Book id    : %d",a1[i].id);
			printf("\n Book author: %s",a1[i].author);
			printf("\n Book price : %lf",a1[i].price);
			printf("\n Book rating: %f",a1[i].rating);
		}
	}
}
	
void update_by_price(Book* a1,int n,int searchid)	
{
	int i ;
	double price,count=0;
	
	for(i=0;i<n;i++)
	{
		if(a1[i].id==searchid)
		{
			printf("update to enter new price: ");
			scanf("%lf",&price);
			a1[i].price=price;
			printf("\nnew updated price is,%lf",a1[i].price);
			count++;
		}
	}
	if(count==0)
		printf("Enter the correct Id");
}
void update_by_rating(Book* a1,int n,int searchid)	
{
	int i ;
	float rating,count=0;
	for(i=0;i<n;i++)
	{
		if(a1[i].id==searchid)
		{
			printf("For update to enter new rating: ");
			scanf("%f",&rating);
			a1[i].rating=rating;
			printf("New updated rating is,%f",a1[i].rating);
			count++;
		}
	}
	if(count==0)
	printf("Enter the correct Id");
}
void delete_by_id(Book*a1,int s)
{
	int i;
	int index=-1;
	int del;
	printf("\nEnter the id to be deleted\n");
	scanf("%d",&del);
	for(i=0;i<s;i++)
	{
		if(del==a1[i].id)
		index=i;
		break;
	}
	for(i=index;i<s;i++){

	if(index!=-1)
	{
		a1[i]=a1[i+1];
	}
}
	n--;
	display(a1,n);
}
void sort_by_price(Book*a1,int n)
{
	int i,j;
	Book temp;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if (a1[i].price<a1[j].price)
				{
					temp=a1[i];
					a1[i]=a1[j];
					a1[j]=temp;
				}
			}
		}
		for(i=0;i<3;i++)
		{
			printf("\n\n%f\n",a1[i].price);
		}
		
	
}
void sort_by_rating(Book*a1,int n)
{
	int i,j;
	Book temp;
	for(i=0;i<n;i++)
	{
		for(j=i+1;i<n;i++)
		{
			if (a1[i].rating<a1[i].rating)
				{
					temp=a1[i];
					a1[i]=a1[j];
					a1[j]=temp;
				}
		for(i=0;i<3;i++)
		{
			printf("%f\n",a1[i].rating);
		}
		}
	}
}


	



