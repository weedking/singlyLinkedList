//
//  main.cpp
//  singlyLinkedList
//
//  Created by 李海明 on 16/7/20.
//  Copyright © 2016年 李海明. All rights reserved.
//

#include <iostream>
typedef int DataType;

class Item
{
public:
    DataType data;
    Item * next;
    Item() {next = NULL;}
};

class Link
{
public:
    Item *head;//链表头指针 123
    Link() {head = NULL;}//构造函数
    ~Link() {DeleteAll();}//析构函数
    void Initiate();//初始化
    void DeleteAll();//删除所有结点
    void HeadCreate(int n);//从头建链表
    void TailCreate(int n);//从尾建链表
    void HeadCreateWithHead(int n);//从头尾建立带空白头结点的链表
    void TailCreateWithHead(int n);//从表尾建立带空白头结点的链表
    int Length();//求链表长度
    Item *Locatex(DataType x);//查找值为x的数据元素
    Item *Locatei(int i);//按序号查找
    DataType Get(int i);//取第i个元素值
    bool PreInsert(DataType x,int i);//前插结点，在链表第i个结点之前插入x
    bool BehindInsert(DataType x,int i);//后插结点，在链表第i个结点之后插入x
    bool Delete(int i);//删除链表中第i个结点
    void Print();//打印链表
    
};

void Link::Initiate()
{
    DeleteAll();
    head = NULL;
}

void Link::TailCreate(int n)
{
    DeleteAll();
    Item *s,*p;
    int i;
    p = NULL;
    for(i=1; i<=n; i++)
    {
        s = new Item();
        std::cin>>s->data;
        s->next=p;
        p=s;
    }
    head=p;
}

void Link::HeadCreate(int n)
{
    Item *s,*r = nullptr,*p;
    int i;
    DeleteAll();
    p=NULL;
    for(i=1;i<=n;i++)
    {
        s=new Item();
        std::cin>>s->data;
        if(p==NULL) p=r=s;
        else{
            r->next=s;//将新结点插入r所指结点后面
            r=s;//将r指向新结点
        }
    }
    head=p;
}

void Link::TailCreateWithHead(int n)
{
    Item *s,*p;
    int i;
    DeleteAll();
    p=new Item();
    p->next=NULL;
    for(i=1;i<=n;i++)
    {
        s=new Item();
        std::cin>>s->data;
        s->next=p->next;
        p->next=s;
    }
    head=p;
}

void Link::HeadCreateWithHead(int n)
{
    Item *s,*r,*p;
    int i;
    DeleteAll();
    p=new Item();
    p->next=NULL;
    r=p;
    for(i=1;i<=n;i++)
    {
        s=new Item();
        std::cin>>s->data;
        r->next=s;
        r=s;
    }
    r->next=NULL;
    head=p;
}

int Link::Length()
{
    int j;
    Item *p;
    j=1;
    p=head->next;
    while(p!=NULL)
    {
        j++;
        p=p->next;
    }
    return --j;
}

Item * Link::Locatei(int i)
{
    int j=1;
    Item *p;
    if(i==0) return head;
    p=head->next;
    while((p!=NULL)&&(j<i))
    {
        p=p->next;
        j++;
    }
    if(j==i) return p;
    else{
        std::cout<<"位置不正确！"<<std::endl;
        return NULL;
    }
}

Item * Link::Locatex(DataType x)//按值查找即定位
{
    Item *p;
    p=head->next;
    while ((p!=NULL)&&(p->data!=x)) {
        p=p->next;
    }
    if(p) return p;
    else{
        std::cout<<x<<" is not exist!"<<std::endl;
        return NULL;
    }
}

DataType Link::Get(int i)
{
    int j;
    Item *p;
    j=1;
    p=head->next;
    while ((j<i)&&(p!=NULL)) {
        j++;
        p=p->next;
    }
    if((p==NULL)||(j>i))
    {
        std::cout<<"位置不正确！"<<std::endl;
        return NULL;
    }
    else return p->data;
}

bool Link::PreInsert(DataType x, int i)
{
    Item *p,*s;
    p = Locatei(i-1);
    if(p==NULL)
    {
        std::cout<<"位置不正确！"<<std::endl;
        return false;
    }
    s=new Item();
    s->data=x;
    s->next=p->next;
    p->next=s;
    return true;
}

bool Link::BehindInsert(DataType x, int i)
{
    Item *p,*s;
    p = Locatei(i);
    if(p==NULL)
    {
        std::cout<<"位置不正确！"<<std::endl;
        return false;
    }
    s=new Item();
    s->next=p->next;
    s->data=x;
    p->next=s;
    return true;
}

void Link::Print()
{
    Item *p;
    p=head->next;
    std::cout<<"链表是：";
    while (p!=NULL) {
        std::cout<<p->data<<" ";
        p=p->next;
    }
    std::cout<<std::endl;
}

bool Link::Delete(int i)
{
    Item *p=Locatei(i-1);
    Item *q;
    if(p==NULL)
    {
        std::cout<<"位置不正确！"<<std::endl;
        return false;
    }
    q=p->next;
    if(q!=NULL)
    {
        p->next=q->next;
        delete q;
        return true;
    }else{
        std::cout<<"位置不正确！"<<std::endl;
        return false;
    }
}

void Link::DeleteAll()
{
    Item *p=head,*q;
    while(p!=NULL)
    {
        q=p->next;
        delete p;
        p=q;
    }
    head=NULL;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...新的东西
//    std::cout << "Hello, World!\n";
    int result;
    Link myLink;
    myLink.HeadCreateWithHead(3);
    myLink.Print();
    myLink.PreInsert(9, 2);
    myLink.Print();
    myLink.BehindInsert(18, 3);
    myLink.Print();
    myLink.Delete(5);
    myLink.Print();
    result=myLink.Get(2);
    std::cout<<"获取的值＝"<<result<<std::endl;
    return 0;
}
