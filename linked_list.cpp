#include <bits/stdc++.h>

using namespace std;
struct node
{
    int data;
    struct node* next;
};

//CASE 1 O(1)
struct node* insertatfirst(struct node*head,int data)
{
    struct node* ptr=(struct node*)malloc(sizeof(struct node*));
    ptr->next=head;
    ptr->data=data;
    return ptr;
}
// CASE 2 0(N)
struct node* insertatlast(struct node*head,int data)
{
    struct node* ptr=(struct node*)malloc(sizeof(struct node*));
    ptr->data=data;
    struct node* p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
    
}
// CASE 3 O(N)
struct node* insertatindex(struct node*head,int data,int index)
{
    struct node* ptr=(struct node*)malloc(sizeof(struct node*));
    struct node* p=head;
    int i=0;
    while(i!=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return ptr;
}
//CASE 4 O(1)
struct node* insertafternode(struct node*prevnode,int data)
{
    struct node* ptr=(struct node*)malloc(sizeof(struct node*));
    ptr->data=data;
    ptr->next=prevnode->next;
    prevnode->next=ptr;
    return ptr;
}
void linklisttraversal(struct node* ptr)
{
    while(ptr!=NULL)
    {
        cout<<"value is "<<ptr->data<<endl;
        ptr=ptr->next;
    }
}

int main()
{
    struct node* head;
    struct node* second;
    struct node* third;
    struct node* forth;
    
    head=(struct node*)malloc(sizeof(struct node*));
    second=(struct node*)malloc(sizeof(struct node*));
    third=(struct node*)malloc(sizeof(struct node*));
    forth=(struct node*)malloc(sizeof(struct node*));
    
    
    head->data=7;
    head->next=second;
    
    
    second->data=66;
    second->next=third;
    
    
    third->data=44;
    third->next=forth;
    
    
    forth->data=20;
    forth->next=NULL;
    cout<<"before insertion"<<endl;
    linklisttraversal(head);
      //head=insertatfirst(head,56);
      //insertatindex(head,56,2);
      //insertatlast(head,56);
      insertafternode(second,42);
      cout<<"after insertion"<<endl;
      linklisttraversal(head);
    
    return 0;
}
