//Circular Linked List
#include<iostream>
using namespace std;
int main()
{
 struct cll
  {int data;
   cll* next;
  };
cout<<"Enter the data\n";
int new_data;
char c;
cin>>new_data;
cll *head;
cll *tail;
cll *n;
n= new cll;
n->data=new_data;
head=n;
tail=n;
cout<<"Do you want to enter more data?(Y/N)\n";
cin>>c;
 while(c=='Y'||c=='y')
  { cout<<"Enter the data\n";
   cin>>new_data;
   n=new cll;
   n->data=new_data;
   tail->next=n;
   tail=n;
   cout<<"Do you want to enter more data?(Y/N)\n";
   cin>>c;
  }
 tail->next=head;
 int choice;
 q: cout<<"Enter the operation to be performed 1.Insert 2.Delete 3.Print\n";
cin>>choice;
cll *t;
 switch(choice)
  {
    case 1 :
    {t=head;
        cout<<"Enter the position to insert element with position of head=0 and data to be inserted\n";
          int pos,count=0;
          cin>>pos>>new_data;
          while(t!=tail)
           {count++;
           t=t->next;
           }
        if(pos==0)
        {n=new cll;
         n->data=new_data;
         n->next=head;
         head=n;
         tail->next=head;}
        else if(pos==count)
        {n=new cll;
         n->data=new_data;
         n->next=head;
         tail->next=n;
         tail=n;
         }
         else
        {t=head;
        for(int i=0;i<pos-1;i++)
        t=t->next;
        n=new cll;
        n->data=new_data;
        n->next=t->next;
        t->next=n;
        }}
        break;
  case 2:{t=head;
  if(head->next!=head)
    {cout<<"Enter the element to be deleted\n";
         int ele;
         cin>>ele;
         cll *u;
         while(t->data!=ele)
         {  u=t;
            t=t->next;
         if(t==head)
         {cout<<"Element not found\n";
          }}
         if(t==head)
         {head=t->next;
         tail->next=head;}
         else if(t==tail)
         u->next=head;
         else
         u->next=t->next;
         }
         else cout<<"Not possible";} break;
  case 3:{t=head;
    cout<<t->data<<"  ";
          while(t->next!=head)
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