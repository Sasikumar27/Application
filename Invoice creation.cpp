#include <stdio.h>
struct customer{
    int cid;
    char phno[20],cname[20];
}customer[100];

struct item{
    char iname[20];
    int iprice,iid;
}item[100];

struct bill{
    int billno,cid,no_items,total;
    struct items{
        int qty,price,itemid;
        char itemname[10];
    }it[100];
   
}bill[100];

int i,j,nobill=0,cuid=0,ino=0,id,now;

void customer_creation()
{
    printf("enter your name :");
    scanf("%s",customer[cuid].cname);
    printf("enter your phone number :");
    scanf("%s",customer[cuid].phno);
    if(cuid!=0)
	{
	    now=cuid;
    	for(int i=0;i<now;i++)
    	{
    	if(customer[cuid].phno==customer[i].phno)
			{
			    customer[cuid].cid=i;
			    printf("your customer id is %d\n",i);
			    cuid++;
			    break;
			}
		else
		{
		    customer[cuid].cid=cuid;
            printf("your customer id is %d\n",cuid);
            cuid++;
            break;
		}
	 	}	
	}
    else
		{
		    customer[cuid].cid=cuid;
            printf("your customer id is %d\n",cuid);
            cuid++;
		}
}
void item_creation()
{
    printf("enter the item name:");
    scanf("%s",item[ino].iname);
    printf("enter item price :");
    scanf("%d",&item[ino].iprice);
    if(item[ino].iprice<=0)
        printf("\nenter the inputs again with valid price\n");
    else
    {
    item[ino].iid=ino;
    printf("\nthe item id is %d\n",ino);
    ino++;
    }
}
void bill_creation()
{
    printf("\nEnter your customer id\n");
    scanf("%d",&bill[nobill].cid);
    printf("\nCustomer Name: %s\n",customer[bill[nobill].cid].cname);
    printf("\nEnter number of items you want to purchase\n");
    scanf("%d",&bill[nobill].no_items);
    bill[nobill].billno=nobill;
    for(i=1;i<=bill[nobill].no_items;i++)
    {
        printf("\nEnter the item id\n");
        scanf("%d",&bill[nobill].it[i].itemid);
        //printf("+++%d\n",bill[nobill].it[i].itemid);
        printf("\nItem name :%s\n",item[bill[nobill].it[i].itemid].iname);
        //scanf("%s",bill[nobill].it[i].itemname);
        printf("\nEnter item quantity\n");
        scanf("%d",&bill[nobill].it[i].qty);
        printf("\nItem price: %d\n",item[bill[nobill].it[i].itemid].iprice);
        //scanf("%d",&bill[nobill].it[i].price);
        bill[nobill].total+=item[bill[nobill].it[i].itemid].iprice*bill[nobill].it[i].qty;
    }
    printf("your bill no is %d\n",nobill);
    nobill++;
}
void customer_list()
{
    if(cuid==0)
        printf("\nEmpty customer list\n");
    else
    {
    printf("\tid\tname\tphno\t");
    for(i=0;i<cuid;i++)
        printf("\n\t%d\t %s\t %s\n",customer[i].cid,customer[i].cname,customer[i].phno);
    }
}
void item_list()
{
    if(ino==0)
        printf("\nempty item list\n");
    else
    {
    printf("\titem id\tname\tprice\n");
    for(i=0;i<ino;i++)
        printf("\t%d\t %s\t %d\n",item[i].iid,item[i].iname,item[i].iprice);
    }
   
}
void bill_list()
{
    for(i=0;i<nobill;i++)
    {
       
        printf("\nbill no : %d\ncustomer id : %d\ncustomer name: %s\n",bill[i].billno,bill[i].cid,customer[i].cname);
        printf("id\tname\tquantity\t");
        for(j=1;j<=bill[i].no_items;j++)
        {
            printf("\n%d\t%s\t%d\t\t\n",bill[i].it[j].itemid,item[bill[i].it[j].itemid].iname,bill[i].it[j].qty); 
        }
        printf("Total price :%d\n",bill[i].total);
    }
}
void bill_based_on_customer(){
    printf("enter your customer id\n");
    scanf("%d",&id);
    for(i=0;i<cuid;i++)
    {
        if(id==customer[i].cid)
        {
        printf("\nbill no : %d\ncustomer id : %d\ncustomer name: %s\n",bill[i].billno,bill[i].cid,customer[i].cname);
        printf("id\tname\tquantity\t");
        for(j=1;j<=bill[i].no_items;j++)
        {
            printf("\n%d\t%s\t%d\t\t\n",bill[i].it[j].itemid,item[bill[i].it[j].itemid].iname,bill[i].it[j].qty); 
        }
        printf("Total price :%d\n",bill[i].total);
        }
    }
}
void bill_based_on_billno()
{
    printf("Enter your bill number :");
    scanf("%d",&id);
    for(i=0;i<nobill;i++)
    {
        if(id==bill[i].billno)
        {
        printf("\nbill no : %d\ncustomer id : %d\ncustomer name: %s\n",bill[i].billno,bill[i].cid,customer[i].cname);
        printf("id\tname\tquantity\t");
        for(j=1;j<=bill[i].no_items;j++)
        {
            printf("\n%d\t%s\t%d\t\t\n",bill[i].it[j].itemid,item[bill[i].it[j].itemid].iname,bill[i].it[j].qty); 
        }
        printf("Total price :%d\n",bill[i].total);
           
        }
    }
}
void total_amount()
{
    int amt=0;
    printf("enter your customer id :");
    scanf("%d",&id);
    for(i=0;i<=nobill;i++)
    {
        if(id==bill[i].cid)
            amt+=bill[i].total;
    }
    printf("The total amount purchased by the customer was for %d rs\n",amt);
}
int main()
{
    int opt;
    while(1)
    {
        printf("\n\n1.customer creation\n2.item creation\n3.bill creation\n4.customer list\n5.item list\n6.bill list\n7.bill based on customer\n8.bill based on billno\n9.total amount\n");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
               customer_creation();
               break;
            case 2:
               item_creation();
               break;
            case 3:
               bill_creation();
               break;
            case 4:
               customer_list();
               break;
            case 5:
               item_list();
               break;
            case 6:
               bill_list();
               break;
            case 7:
               bill_based_on_customer();
               break;
            case 8:
               bill_based_on_billno();
               break;
            case 9:
               total_amount();
               break;
        }
    }
    return 0;
}


