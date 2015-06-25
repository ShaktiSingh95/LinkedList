#include<stdio.h>
#include<stdlib.h>
struct linkedList
{
    int value;
    struct linkedList *next;
};
int index=0;
typedef struct linkedList linkedList;
linkedList *head=NULL;
linkedList *tail=NULL;
int main()
{
    int n,flag=1,ele,ind=-1,disp;
    int *errorCode;
    while(flag)
    {
        printf("\n\n--------------------------------------------------------------------------");
        printf("\n\n|-------------------->1.Insert in a link list.                            |");
        printf("\n\n|-------------------->2.Fetch a perticular value out of a link list.      |");
        printf("\n\n|-------------------->3.display linked list.                              |");
        printf("\n\n|-------------------->0.to exit                                           |");;
        printf("\n\n--------------------------------------------------------------------------\n\n\t");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            printf("\nEnter the element to be inserted:");
            scanf("%d",&ele);
            insert(ele);
            break;
        case 2:
            printf("\nValue in head is %d",head->value);
            printf("please Enter the index");
            scanf("%d",&ind);
            disp=fetch(&errorCode,ind);
            if(errorCode==0)
            {
                printf("\nThis index not available");
                break;
            }
            printf("Item at index %d is %d",ind,disp);
            break;
        case 3:
            display(*errorCode,ind);
            if(errorCode==-1)
            {
                printf("linked list is empty");
            }
            break;
        case 0:
            flag=0;
            break;
        default:
            printf("Wrong entry.");
        }
    }
    return 0;
}
void insert(int ele)
{
    if(head==NULL)
    {
        head=(linkedList *)malloc(sizeof(linkedList));
        head->value=ele;
        tail=head;
        tail->next=NULL;
    }
    else
    {
        tail->next=(linkedList *)malloc(sizeof(linkedList));
        tail=tail->next;
        tail->value=ele;
        tail->next=NULL;
    }
    index++;
}
void display(int *error)
{
    linkedList *copy;

    if(head==NULL)
    {
        error=-1;
    }
    else
    {
        copy=head;
        do
        {
            printf("\n%d\n",copy->value);
            copy=copy->next;
        }
        while(copy!=NULL);
    }
}
int fetch(int *error,int ind)
{
    linkedList *copy;
    copy=head;
    int i=1;
    if(i>ind)
    {
        error=0;
    }
    while(i<ind)
    {
        copy=copy->next;
        if(copy==NULL)
        {
            error=0;
            break;
        }
        i++;
    }
    if(error!=0)
    {
        return copy->value;
    }
}
