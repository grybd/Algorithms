#include<iostream>
using namespace std;
typedef int  ElemType; //假设线性表中的元素均为整型

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

void ListCreate_L_Rec(LinkList &L,int n)
{

//递归边界：创建空表时只需将L赋空即可；
//递归关系：创建非空表时，将链表看做两部分：首元素组成的子表La， 第二个元素及其后元素构成的子表Lb。
//子表La容易创建(只需开辟一个节点)
//子表Lb由于规模小可以递归创建完成（类似数学归纳法的假设，只要小的都可以建设能完成）

//最后将两个子表拼接即可。
  LNode *La;
  if(n==0) {
    L=NULL;
    return;
  }
  else{
    La=new LNode;  //开辟子表La
    cin>>La->data;
    ListCreate_L_Rec(L,n-1); //递归创建子表Lb
    La->next = L;  //两个子表拼结
    L=La;  //第一个子表的地址赋给L。请思考为什这样处理不会使得主函数中的L取错值？
  }
}

void ListPrint_L_Rec(LinkList L)
{
    if(L==NULL)
        return ;
    else
    {
        cout<<" "<<L->data;
        ListPrint_L_Rec(L->next);
    }
}
int main()
{
    LinkList L;
    int n;
    cin>>n;
    ListCreate_L_Rec(L,n);
    ListPrint_L_Rec (L);
    return 0;
}
