//Single Linked List
#include<iostream>
using namespace std;
int main()
{
 struct sll
  {int data;
   sll* next;
  };
cout<<"Enter the data\n";
int new_data;
char c;
cin>>new_data;
sll *head;
sll *tail;
sll *n;
n= new sll;
n->data=new_data;
head=n;
tail=n;
cout<<"Do you want to enter more data?(Y/N)\n";
cin>>c;
 while(c=='Y'||c=='y')
  { cout<<"Enter the data\n";
   cin>>new_data;
   n=new sll;
   n->data=new_data;
   tail->next=n;
   tail=n;
   cout<<"Do you want to enter more data?(Y/N)\n";
   cin>>c;
  }
 tail->next=NULL;
 int choice;
 q: cout<<"Enter the operation to be performed 1.Insert 2.Delete 3.Print\n";
cin>>choice;
sll *t;
 switch(choice)
  {
    case 1 :
    {t=head;
        cout<<"Enter the position to insert element with position of head=0 and data to be inserted\n";
          int pos,count=0;
          cin>>pos>>new_data;
          while(t->next!=NULL)
           {count++;
           t=t->next;
           }
        if(pos==0)
        {n=new sll;
         n->data=new_data;
         n->next=head;
         head=n;}
        else if(pos==count+1)
        {n=new sll;
         n->data=new_data;
         n->next=NULL;
         tail->next=n;
         tail=n;
         }
         else
        {t=head;
        for(int i=0;i<pos-1;i++)
        t=t->next;
        n=new sll;
        n->data=new_data;
        n->next=t->next;
        t->next=n;
        }}
        break;
  case 2:{t=head;
  if(head->next!=NULL)
    {cout<<"Enter the element to be deleted\n";
         int ele;
         cin>>ele;
         sll *u;
         while(t->data!=ele)
         {  u=t;
            t=t->next;
         if(t==NULL)
         {cout<<"Element not found\n";
          }}
         if(t==head)
         head=t->next;
         else if(t==tail)
         u->next=NULL;
         else
         u->next=t->next;
         }
         else cout<<"Not possible";} break;
  case 3:{t=head;
    cout<<t->data<<"  ";
          while(t->next!=NULL)
         {t=t->next;
         cout<<t->data<<"  ";
         }}
        break;
  default:cout<<"Invalid input\n";
  }

cout<<"Do you want to perform more options?(Y/N)\n";
cin>>c;
if(c=='y'||c=='Y')
goto q;
return 0;
}