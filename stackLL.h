#ifndef stackLL
#define stackLL

struct n
{
    n *next;
    int data;
};
typedef n node;

int pop(node*);
node* push(node *,int);
#endif