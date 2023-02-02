#include<iostream>
using namespace std;

struct queue
{int q[6];
int cq[6];
int front=-1,rear=-1;
};
void q_enque(int data,queue* Q)
{if(Q->rear==5)
 cout<<"Overflow\n";
 if(Q->rear==-1&&Q->front==-1)
 {Q->rear++;
 Q->front++;
 Q->q[Q->rear]=data;}
 else{
    Q->rear++;
    Q->q[Q->rear]=data;
 }
}
int q_deque(queue *Q)
{int data;
if(Q->rear==-1&&Q->front==-1)
cout<<"Underflow\n";
else
{ data=Q->q[Q->front];
 if(Q->front==Q->rear)
   {Q->front=-1;
    Q->rear=-1;
   }
 else Q->front++;
}
return data;
}

void cq_enque(int data,queue* Q)
{if(Q->front==(Q->rear+1)%6)
 cout<<"Overflow\n";
 else if(Q->rear==-1&&Q->front==-1)
 {Q->rear++;
 Q->front++;
 Q->cq[Q->rear]=data;}
 else if(Q->rear==5)
 Q->rear=0;
 else
   { Q->rear++;
    Q->cq[Q->rear]=data;
 }
}

int cq_deque(queue *Q)
{int data;
    if(Q->front==-1)
cout<<"Underflow\n";
else
{ data=Q->cq[Q->front];
 if(Q->front==5)
   {Q->front=0;
  }
 else 
 Q->front++;
}
return data;
}

int q_peek(queue *Q)
{
    return Q->q[Q->front];
}
int cq_peek(queue *Q)
{
    return Q->cq[Q->front];
}
int main()
{
queue Q,P;
cout<<"Normal queue implementation:\n";
q_enque(5,&Q);
q_enque(7,&Q);
q_enque(8,&Q);
q_enque(9,&Q);
q_enque(11,&Q);
q_enque(12,&Q);
cout<<"Removed element= "<<q_deque(&Q)<<endl;
cout<<"Now queue is as follows: ";
for(int i=Q.front;i<6;i++)
cout<<Q.q[i]<<"  ";
cout<<endl;
cout<<"Front element= "<<q_peek(&Q)<<endl;
q_enque(4,&Q);
cout<<"Removed element= "<<q_deque(&Q)<<endl;

cout<<"Cicular queue implementation:\n";
cq_enque(5,&P);
cq_enque(7,&P);
cq_enque(8,&P);
cq_enque(9,&P);
cq_enque(11,&P);
cq_enque(12,&P);
cout<<"Removed element= "<<cq_deque(&P)<<endl;
cout<<"Now queue is as follows: ";
for(int i=P.front;i<6;i++)
cout<<P.cq[i]<<"  ";
cout<<endl;
cout<<"Front element= "<<cq_peek(&P)<<endl;
cq_enque(4,&P);
cout<<"Removed element= "<<cq_deque(&P)<<endl;
return 0;
}