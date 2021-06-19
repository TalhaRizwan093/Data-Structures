#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
int main()
{
   //clrscr();
   int top=-1,len,b=-1,a,c;
   char q[30],st[15],p[30],ch,temp;
   cout<<"ENTER THE LENGTH OF EXPRESSION :";
    cin>>len;
   cout<<"ENTER THE EXPRESSION  :";
   for(a=0; a<len; a++)
    cin>>q[a];
   st[++top]='#';

   for(a=0; a<len; a++)
   {
     ch=q[a];
     if(ch>=65 && ch<=90|| ch>=97 && ch<=122 || ch>='0' && ch<='9' )
      p[++b]=ch;
     else
      {
	if(ch=='(')
	 st[++top]=ch;
	else if(ch==')')
	{
	  c=top;
	  while(st[c]!='(')
	  {
	    p[++b]=st[top--];
	    c--;
	  }
	  top--;

	}
	else if(ch=='^')
	 st[++top]=ch;
	else if(ch=='*'|| ch=='/'|| ch=='%')
	{
	  c=top;
	  while(st[c]!='#')
	   {
	     if(st[c]=='(' )
	      break;
	     temp=st[top];
	     if(temp=='^')
	       p[++b]=st[top--];
	     else if(temp=='*' || temp=='/'|| temp=='%')
	       p[++b]=st[top--];
	     c--;
	   }
	   st[++top]=ch;
	}
       else if(ch=='+'||ch=='-')
       {
	c=top;
	while(st[c]!='#')
	 {
	   if(st[c]=='(')
	    break;
	   else
	    p[++b]=st[top--];
	    c--;
	 }
	 st[++top]=ch;
       }
      }
   }
   while(st[top]!='#')
    if(st[top]!='(')
      p[++b]=st[top--];
    else
      top--;

 for(a=0; a<=b; a++)
  cout<<p[a];
  getche();
}
