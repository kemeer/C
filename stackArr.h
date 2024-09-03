#ifndef stackArr
#define stackArr

struct s
{
    int boyut;
    int tepe;
    int *dizi;
};
typedef s stack;

stack* tanim(); 
int pop(stack* s);
void push(int ,stack*);
void bastir(stack*);

#endif