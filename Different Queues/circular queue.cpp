/*Repeat the assignment of 6 into circular queue*/
#include<conio.h>
#include<iostream.h>
int split(int[]);
#define m 10
int ary[m]={1,2,3,4,5,6,7,8,9,10},ary1[5],ary2[5];
int front=6,rear=5,front1=0,rear1=0,front2=0,rear2=0;
void main()
{
clrscr();
split (ary);
getch();
}
int split (int ary [])
{
	int a,b=0,c=0;
	if (rear==-1)
	{
	cout <<"cq overflow";
	return(0);
	}
	if (front<rear)
	{
		for (a=front;a<=rear;a++)
		{
			if (a%2==0)
			{
			ary1[b]=ary[a];
			rear1++;
			b++;
			}
			else
			{
			ary2[c]=ary[a];
			rear2++;
			c++;
			}
		}
	}
	else
	{
		for (a=front;a<m;a++)
		{
			if (a%2==0)
			{
			ary1[b]=ary[a];
			rear1++;
			b++;
			}
			else
			{
			ary2[c]=ary[a];
			rear2++;
			c++;
			}
		}
		for(a=0;a<=rear;a++)
		{
			if (a%2==0)
			{
			ary1[b]=ary[a];
			rear1++;
			b++;
			}
			else
			{
			ary2[c]=ary[a];
			rear2++;
			c++;
			}
		}
	}
cout<<"The odd queue ";
for(a=front1;a<=rear1;a++)
cout<<"\n"<<ary1[a];
cout<<"the queue2";
for(a=front2;a<rear2;a++)
cout<<"\n"<<ary2[a];

 }
