#include<iostream>
using namespace std;
struct sll
  {int data;
   sll* next;
   sll(int d)
    {
        data = d;
        next = NULL;
    }
  };

struct queue
{
 struct sll *front;
 struct sll *rear;
 queue()
 {front=NULL;
 rear=NULL;}
};

void q_enque(int d, queue *Q)
{if(Q->front==NULL&&Q->rear==NULL)
{sll* n = new sll(d);
 Q->front=n;
 Q->rear=n;
}
else
{sll* n = new sll(d);
 Q->rear->next=n;
 Q->rear=n;
}
}

void cq_enque(int d, queue *Q)
{sll* n1 = new sll(d);
  if(Q->front==NULL&&Q->rear==NULL)
{
 Q->front=n1;
 Q->rear=n1;
}
else
{sll* n = new sll(d);
 n->next=n1;
 Q->rear->next=n;
 Q->rear=n;

}
}

int q_deque(queue* Q)
{if(Q->front==Q->rear)
{sll *t=new sll(0);
 t=Q->front;
 Q->front=NULL;
 Q->rear=NULL;
 return t->data;
 delete t;
}
else
{sll *t=new sll(0);
t=Q->front;
Q->front=Q->front->next;
return t->data;
delete t;
}    
}

int cq_deque(queue* Q)
{if(Q->front==Q->rear)
{sll *t=new sll(0);
 t=Q->front;
 Q->front=NULL;
 Q->rear=NULL;
 return t->data;
}
else
{sll *t=new sll(0);
t=Q->front;
Q->front=Q->front->next;
return t->data;
}    
}
int q_peek(queue *Q)
{
    return Q->front->data;

}

int cq_peek(queue *Q)
{
    return Q->front->data;

}

int main()
{queue Q,P;
cout<<"Normal queue implementation:\n";
q_enque(5,&Q);
q_enque(7,&Q);
q_enque(8,&Q);
q_enque(9,&Q);
q_enque(11,&Q);
q_enque(12,&Q);
cout<<"Removed element= "<<q_deque(&Q)<<endl;
cout<<"Now queue is as follows: ";
sll* t=new sll(0);
t=Q.front;
    cout<<t->data<<"  ";
          while(t->next!=NULL)
         {t=t->next;
         cout<<t->data<<"  ";
         }
cout<<"\nFront element= "<<q_peek(&Q)<<endl;
q_enque(4,&Q);
cout<<"Removed element= "<<q_deque(&Q)<<endl;

cout<<"\n\nCicular queue implementation:\n";
cq_enque(5,&P);
sll* n1=new sll(0);
cq_enque(7,&P);
cq_enque(8,&P);
cq_enque(9,&P);
cq_enque(11,&P);
cq_enque(12,&P);
cout<<"Removed element= "<<cq_deque(&P)<<endl;
cout<<"Now queue is as follows: ";
sll* u=new sll(0);
u=P.front;
    cout<<u->data<<"  ";
          do
         {u=u->next;
         cout<<u->data<<"  ";
         }while(u->next!=P.rear->next);
cout<<"\nFront element= "<<cq_peek(&P)<<endl;
cq_enque(4,&P);
cout<<"Removed element= "<<cq_deque(&P)<<endl;
return 0;

return 0;

}