/*Department of Computer Engineering has student's club named 'Pinnacle Club'. Students of Second, third and final year of department can be granted membership on request. Similarly one may cancel the membership of club. First node is reserved for president of club and last node is reserved for secretary of club. Write C++ program to maintain club member‘s information using singly linked list. Store student PRN and Name. Write functions to

a) Add and delete the members as well as president or even secretary.
b) Compute total number of members of club
c) Display members
d) Display list in reverse order using recursion
e) Two linked lists exists for two divisions. Concatenate two lists.*/
/*-------------------------------------------------------------------------------------------------------------------------------*/

#include <iostream>
#include <string.h>
using namespace std;
class node
{
	friend class list;
	int prnno;
	char name[30];
	node *next;//pointer to object
public:
	node(int d,char s[10])
	{
	prnno=d;
		strcpy(name,s);
		next=NULL;
	}
};
class list
{
	node *start;
public:
	list()
    {
		start=NULL;
    }
void display()
{
	node *ptr;
	ptr=start;
	cout<<"\n info is : \n";
	while(ptr!=NULL)
	{
		cout<<"\n"<<ptr->prnno;
		cout<<"\t"<<ptr->name;
		ptr=ptr->next;
	}
}
	void insertmember();
	void createmember();
	void insertpresident();
	void insertsecretary();
	void deletemember();
	void delete1();
	void deletesecretary();
	void deletepresident();
	void count();
	void reverse(node *);
	void reverse1()
	{
		reverse(start);
	}
	void concatinate(list,list);
};
void list::insertmember()
{
	int prnno;
	char name[30];
	node *ptr,*temp;
	cout<<"\n enter prnno : ";
	cin>>prnno;
	cout<<"\n enter name : ";
	cin>>name;
	temp=new node(prnno,name);
	if(start==NULL)
	{
		start=temp;
	}
	else
	{
		ptr=start;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=temp;
	}
}
void list::insertpresident()
{
	int prnno;
	char name[30];
		node *temp;
		cout<<"\n enter prnno : ";
		cin>>prnno;
		cout<<"\n enter name : ";
		cin>>name;
		temp=new node(prnno,name);
		temp->next=start;
		start=temp;
}
void list::insertsecretary()
{
	int prnno;
	char name[30];
			node *ptr,*temp;
			cout<<"\n enter prnno : ";
			cin>>prnno;
			cout<<"\n enter name : ";
			cin>>name;
			temp=new node(prnno,name);
			ptr=start;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			ptr->next=temp;
}
void list::createmember()
{
	int ch;
	char ans;
	do
	{
	cout<<"\n choose : ";
	cout<<"\n 1-member\n 2-secretary\n 3-president";
	cin>>ch;
	switch(ch)
	{
	case 1: insertmember();
		    break;
	case 2: insertsecretary();
		    break;
	case 3: insertpresident();
		    break;
	default:cout<<"invalid choice ! ";
		    break;
	}
	cout<<"\n insert more ?";
	cin>>ans;
	}while(ans=='y');
}
void list::delete1()
{
		int ch;
		char ans;
		do
		{
		cout<<"\n choose : ";
		cout<<"\n 1-member\n 2-secretary\n 3-president";
		cin>>ch;
		switch(ch)
		{
		case 1:deletemember();
			   break;
		case 2:deletesecretary();
			   break;
		case 3:deletepresident();
			   break;
		default:cout<<"invalid choice ! ";
			    break;
		}
		cout<<"\n delete more ?";
		cin>>ans;
		}while(ans=='y');
	}
void list::deletesecretary()
{
	node *ptr,*prev;
	ptr=start;
	while(ptr->next!=NULL)
	{
		prev=ptr;
		ptr=ptr->next;
	}
		prev->next=NULL;
		delete ptr;
	    cout<<"\n deleted";
}
void list::deletepresident()
{
	node *ptr;
		ptr=start;
		start=start->next;
		delete ptr;
		cout<<"\n deleted";
}
void list::deletemember()
{
	node *ptr,*prev;
	int p;
	cout<<"\n enter prnno. to delete : ";
	cin>>p;
			ptr=start;
			while(ptr->next!=NULL)
			{
				prev=ptr;
				ptr=ptr->next;
				if(ptr->prnno==p)
				  break;
			}
			if(ptr->next==NULL)
			{
				cout<<"\n data not found !";
			}
			else if(ptr->prnno==p)
			{
				prev->next=ptr->next;
				ptr->next=NULL;
				delete ptr;
				cout<<"\n deleted";
			}
}
void list::count()
{
	node *ptr;
	int cnt=0;
	ptr=start;
	while(ptr!=NULL)
	{
		cnt++;
		ptr=ptr->next;
	}
	cout<<"\n total no. of nodes is : "<<cnt;
}
void list::reverse(node *ptr)
{
	if(ptr==NULL)
			return;
	else
	{
		reverse(ptr->next);
	}
		cout<<"\n"<<ptr->prnno;
		cout<<"\t"<<ptr->name;
}
void list::concatinate(list s1,list s2)
	{
	node *ptr;
	ptr=s1.start;
	while(ptr->next!=NULL)
		ptr=ptr->next;
		ptr->next=s2.start;
		s1.display();
	}
int main6()
{
	int ch;
	char ans;
	list sll1,sll2,s1,s2;
	do
	{
		cout<<"\n enter your choice : ";
	    cout<<"\n 1-create member\n 2-display\n 3-delete member\n 4-no. of nodes\n 5-reverse\n 6-concatenate";
        cin>>ch;
switch(ch)
{
   case 1: sll1.createmember();
		   break;
   case 2: sll1.display();
		   break;
   case 3: cout<<"\n enter the nodes to be deleted in list : ";
		   sll1.delete1();
		   break;
   case 4: cout<<"\n no. of nodes is:";
		   sll1.count();
		   break;
   case 5: cout<<"\n reversed is:";
		   sll1.reverse1();
		   break;
   case 6: sll2.createmember();
		   sll1.concatinate(sll1,sll2);
		   break;
   default: cout<<"\n invalid choice ! ";
		    break;
 }
		   cout<<"\n\n do you want to continue ? ";
		   cin>>ans;
	}while(ans=='y');
	return 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------

/******************OUTPUT*********************************
enter your choice :
1-create member
2-display
3-delete member
4-no. of nodes
5-reverse
6-concatinate1

choose :
1-member
2-secretory
3-president1

enter prn-no : 211

enter name : b

insert more ?y

choose :
1-member
2-secretory
3-president1

enter prn-no : 311

enter name : c

insert more ?y

choose :
1-member
2-secretory
3-president1

enter prn-no : 411

enter name : d

insert more ?y

choose :
1-member
2-secretory
3-president2

enter prn-no : 511

enter name : e

insert more ?y

choose :
1-member
2-secretory
3-president3

enter prn-no : 111

enter name : a

insert more ?n


do you want to continue ? y

enter your choice :
1-create member
2-display
3-delete member
4-no. of nodes
5-reverse
6-concatinate2

info is :

111	a
211	b
311	c
411	d
511	e

do you want to continue ? y

enter your choice :
1-create member
2-display
3-delete member
4-no. of nodes
5-reverse
6-concatinate4

no. of nodes is:
total no. of nodes is : 5

do you want to continue ? y

enter your choice :
1-create member
2-display
3-delete member
4-no. of nodes
5-reverse
6-concatinate5

reversed is:
511	e
411	d
311	c
211	b
111	a

do you want to continue ? y

enter your choice :
1-create member
2-display
3-delete member
4-no. of nodes
5-reverse
6-concatinate6

choose :
1-member
2-secretory
3-president1

enter prn-no : 412

enter name : f

insert more ?y

choose :
1-member
2-secretory
3-president1

enter prn-no : 121

enter name : j

insert more ?n

info is :

111	a
211	b
311	c
411	d
511	e
412	f
121	j

do you want to continue ? y

enter your choice :
1-create member
2-display
3-delete member
4-no. of nodes
5-reverse
6-concatinate3

enter the nodes to be deleted in list :
choose :
1-member
2-Secretary
3-president1

enter prn no. to delete : 211

deleted
delete more ?y

choose :
1-member
2-Secretary
3-president2

deleted
delete more ?y

choose :
1-member
2-Secretary
3-president3

deleted
delete more ?n


do you want to continue ? y

enter your choice :
1-create member
2-display
3-delete member
4-no. of nodes
5-reverse
6-concatinate2

info is :

311	c
411	d
511	e
412	f

do you want to continue ? n
  */
