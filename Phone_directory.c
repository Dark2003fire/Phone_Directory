#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
    char firstname[20];
    char lastname[20];
    int number[15];
    struct node *next;
};

struct node *start=NULL;

struct node *getnode()
{
    return((struct node *)malloc(sizeof(struct node)));
} 


void display(struct node *start)
{
    struct node *temp;
    temp=start;
    while(temp!=NULL)
    {
        printf("%s\n",temp->firstname);
        printf("%s\n",temp->lastname);
        printf("%d\n",temp->number);
        temp=temp->next;
    }
}
/*void sort()
{
    struct node *temp,*pretemp;
    char *p;
    temp=start;
    pretemp=start->next;
    while(pretemp!=NULL)
    {
    if(strcmp(temp->lastname,pretemp->lastname)>0)
    {
        if(temp->lastname==pretemp->lastname)
        {
            if(strcmp(temp->firstname,pretemp->firstname)>0)
            {
                p=temp->firstname;
                temp->firstname=pretemp->firstname;
                pretemp->firstname=p;   
            }
        }
        else
        {
                p=temp->lastname;
                temp->lastname=pretemp->firstname;
                pretemp->firstname=p;
        }
    }
    }
}
*/
void insert()
{
    struct node *temp,*nn;
    nn=getnode();
    temp=start;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        
    }
    printf("Enter First name:\n");
    scanf("%s",&nn->firstname);
    printf("Enter Last name:\n");
    scanf("%s",&nn->lastname);
    printf("Enter number:\n");
    scanf("%d",&nn->number);
    temp->next=nn;
    nn->next=NULL;
    display(start);
}

struct node *create()
{
    struct node *temp,*nn;
    if(start!=NULL)
        insert();
    else
    {
    nn=getnode();
    start=nn;
    temp=start;
    printf("Enter First name:\n");
    scanf("%s",&nn->firstname);
    printf("Enter Last name:\n");
    scanf("%s",&nn->lastname);
    printf("Enter number:\n");
    scanf("%d",&nn->number);
    nn->next=NULL;
    display(start);
    }
}
void search()
{
    struct node *temp;
    char *f,*l;
    temp=start;
    printf("Enter name to be searched:\n");
    scanf("%s",&f);
    scanf("%s",&l);
    while((temp->firstname==f)&&(temp->lastname==l))
    {
        temp=temp->next;
    }
    printf("%s\n",temp->firstname);
    printf("%s\n",temp->lastname);
    printf("%d\n",temp->number);
}

void del()
{
    struct node *pretemp,*temp;
    char *f,*l;
    temp=start;
    pretemp=start->next;
    printf("Enter name :");
    scanf("%s",&f);
    scanf("%s",&l);
    while(temp!=NULL)
    {
        if((pretemp->firstname==f)&&(pretemp->lastname==l))
        {
            printf("%s ",temp->firstname);
            printf("%s ",temp->lastname);
            printf("%s ",temp->number);
            temp->next=pretemp->next;
            free(pretemp);
            break;
        }
        else 
        {
            temp=temp->next;
            pretemp=pretemp->next;
        }
        
        
    }
}

int main()
{
    int op,ch;
    do{
        printf("-------Welcome--------\n ");
        printf("1.Create\n2.Insert\n3.Display\n4.Delete\n5.Search\n6.Sort\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: create();
            break;
            case 2: insert();
            break;
            case 3: display(start);
            break;
            case 4: del();
            break;
            case 5:search();
            break;
            /*case 6:sort();
            break;*/
        }
        printf("Do you want to quit ? 1 for no / 0 for yes:");
        scanf("%d",&op);
    }while(op!=0);
return 0;
}




/*
OUTPUT:--------->
-------Welcome--------
 1.Create
2.Insert
3.Display
4.Delete
5.Search
6.Sort
Enter your choice:1
Enter First name:
Hitesh
Enter Last name:
Jha
Enter number:
7218449402
Hitesh
Jha
1144445672
Do you want to quit ? 1 for no / 0 for yes:1
-------Welcome--------
 1.Create
2.Insert
3.Display
4.Delete
5.Search
6.Sort
Enter your choice:2
Enter First name:
Hitesh 
Enter Last name:
Jha
Enter number:
8446049402
Hitesh
Jha
1144445672
Hitesh
Jha
1144445800
Do you want to quit ? 1 for no / 0 for yes:1
-------Welcome--------
 1.Create
2.Insert
3.Display
4.Delete
5.Search
6.Sort
Enter your choice:3
Hitesh
Jha
1144445672
Hitesh
Jha
1144445800
Do you want to quit ? 1 for no / 0 for yes:4
-------Welcome--------
 1.Create
2.Insert
3.Display
4.Delete
5.Search
6.Sort
Enter your choice:4
Enter name :Hitesh
Num has been deleted




*/
