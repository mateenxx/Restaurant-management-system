#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

// maximum no of orders for delivery
#define omax 50
// number of delivery boys available 
#define maxdb 10
// user id for cook
#define user_id_cook "2023111"
// password for cook
#define pass_cook "ckckck"
// user id for manager
#define user_id_manager "2023555"
// password for manager
#define pass_manager "manman"

// structure for table status
struct Table //NAMAN
{
    char table_status[100];//vacant or reserved
    int table_number;
    char customer_name[100] ;
    char customer_number[13];
};


struct Table available_tables2[5];// array of structure table 2-seater
struct Table available_tables4[5];// array of structure table 4-seater
struct Table available_tables6[5];// array of structure table 6-seater
// table num 1-5 are 2seater ; 6-10 are 4seater ; 11-15 are 6seater 

// all functions
void reserve_table(int table_size);//ABBAS
void vacat_table(int table_num);//ABBAS
void table_status(int table_num);//ABBAS
int table_status_check(int table_size);//NAMAN
void tables_available(int table_size);//NAMAN
void delivery_order(); //MAHARSHI
void delivery_order_cancel(int order_num); //MAHARSHI
void delivery_order_status(int order_num);//MAHARSHI
void delivery_preparing_order(int order_num); //MAHARSHI
void dispatch_delivery_order(int order_num);//MAHARSHI
void delivery_boy_initialize();//NAMAN
void delivery_boy_unavailable(char id[]); //MATEEN
int verify_delivery_boy(char id[], char password[]); //MATEEN
void order_delivered(int order_num);//MATEEN
int delivery_boy_available();//MATEEN 
int assign_delivery_boy();//MATEEN

// function for booking tables 
void reserve_table(int table_size)//ABBAS
{
    int check=table_status_check(table_size);
    if(check==-1)
    {
        printf("All table of this size is full \n");
        return;
    }
    else if(table_size<=2)
    {
        available_tables2[check].table_number=check+1;
        printf("Enter customers name : ");
        scanf(" %[^\n]", available_tables2[check].customer_name);
        printf("Enter customers number : ");
        scanf(" %[^\n]", available_tables2[check].customer_number);
        strcpy(available_tables2[check].table_status,"reserved");
        printf("Your table number is %d",available_tables2[check].table_number);
    }
    else if(table_size<=4 && table_size>2)
    {
        available_tables4[check].table_number=check+6;
        printf("Enter customers name : ");
        scanf(" %[^\n]", available_tables4[check].customer_name);
        printf("Enter customers number : ");
        scanf(" %[^\n]", available_tables4[check].customer_number);
        strcpy(available_tables4[check].table_status,"reserved");
        printf("Your table number is %d",available_tables4[check].table_number);
    }
    else if(table_size<=6 && table_size>4)
    {
        available_tables6[check].table_number=check+11;
        printf("enter customers name : ");
        scanf(" %[^\n]", available_tables6[check].customer_name);
        printf("enter customers number : ");
        scanf(" %[^\n]", available_tables6[check].customer_number);
        strcpy(available_tables6[check].table_status,"reserved");
        printf("your table number is %d \n",available_tables6[check].table_number);
    }
    else
    {
        printf("table of such size is not available");
    }   
}

// function for vacating the table
void vacat_table(int table_num)//ABBAS
{
    int x,a;
    if(table_num>10 && table_num<16)
    {
        x=table_num-11;
        a=strcmp(available_tables6[x].table_status,"vacant");
        if(a==0)
        {
            printf("The table is already vacant");
        }
        strcpy(available_tables6[x].table_status,"vacant");
        strcpy(available_tables6[x].customer_name,"");
        strcpy(available_tables6[x].customer_number,"");
    }
    else if (table_num>5 && table_num<11)
    {
        x=table_num-6;
        a=strcmp(available_tables4[x].table_status,"vacant");
        if(a==0)
        {
            printf("Table is already Vacant");
        }
        strcpy(available_tables4[x].table_status,"vacant");
        strcpy(available_tables4[x].customer_name,"");
        strcpy(available_tables4[x].customer_number,"");
    }
    else if (table_num>0 && table_num<6)
    {
        x=table_num-1;
        a=strcmp(available_tables2[x].table_status,"vacant");
        if(a==0)
        {
            printf("The table is already vacant");
        }
        x=table_num-1;
        strcpy(available_tables2[x].table_status,"vacant");
        strcpy(available_tables2[x].customer_name,"");
        strcpy(available_tables2[x].customer_number,"");
    }
    else
    {
        printf("Such table number does not exist");
    }
}


// function to check the status of a perticular table
void table_status(int table_num)//ABBAS
{
    if(table_num<6)
    printf("%s\n",available_tables2[(table_num-1)].table_status);
    else if(table_num<11)
    printf("%s\n",available_tables4[(table_num-6)].table_status);
    else if(table_num<16)
    printf("%s\n",available_tables6[(table_num-11)].table_status);
    else
    printf("invalid table number\n");
}


// function for ckecking table status 
int table_status_check(int table_size) //NAMAN
{
    int s=0,i,a;
    if(table_size<=2)
    {
        for( i=0;i<5;i++)
        {
            a=strcmp(available_tables2[i].table_status,"vacant");
            if(a==0)
            {
                s=1;
                break;
            }
        }   
    }
    else if(table_size<=4 && table_size>2)
    {
        for( i=0;i<5;i++)
        {
            a=strcmp(available_tables4[i].table_status,"vacant");
            if(a==0)
            {
                s=1;
                break;
            }
        }   
    }
    else if(table_size<=6 && table_size>4)
    {
        for( i=0;i<5;i++)
        {
            a=strcmp(available_tables6[i].table_status,"vacant");
            if(a==0)
            {
                s=1;
                break;
            }
        }   
    }
    else
    {
        printf("table of such size is not available\n");
    }
    if(s==1)
        return i;
    else
        return -1;
}

// function to check number of tables available of a perticular table-size
void tables_available(int table_size)//NAMAN
{
    int count=0,a;
    if(table_size==2)
    {
        for (int i = 0; i < 5; i++)
        {
            a=strcmp(available_tables2[i].table_status,"vacant");
            if(a==0)
            count++;
        }
        printf("number of 2-seater tables availabe are = %d\n",count);
    }
    else if(table_size==4)
    {
        for (int i = 0; i < 5; i++)
        {
            a=strcmp(available_tables4[i].table_status,"vacant");
            if(a==0)
            count++;
        }
        printf("number of 4-seater tables availabe are = %d\n",count);
    }
    else if(table_size==6)
    {
        for (int i = 0; i < 5; i++)
        {
            a=strcmp(available_tables6[i].table_status,"vacant");
            if(a==0)
            count++;
        }
        printf("number of 6-seater tables availabe are = %d\n",count);
    }
    else
    {
        printf("tables of such size is not available\n");
    }
}


// structure for a delivery order
struct DeliveryOrder   //MAHARSHI
{
    int Order_Number;
    char customer_name[50];
    char delivery_adress[200]; 
    char delivery_instructions[200];
    char delivery_status[200];//1.preparing order  2.order dispatched 3.delivered
    int delivery_boy_index;

};

struct DeliveryOrder deliveryorder[200];//array of structure DeliveryOrder
int delivery_order_count=0;  //no of delivery orders pending
int delivery_order_num=0;  //no of delivery orders
int deliveryboy_num=0;  //no of delivery orders

// function for placing orders for delivery
void delivery_order() //MAHARSHI
{
    if (delivery_order_count >= omax)//checking whether the order can be accepted or not.
    {
        printf("Maximum number of delivery orders reached. Please wait for a while.\n");
        return;
    }
    if (deliveryboy_num>=maxdb)//checking whether the all the delivery boys are busy or not
    {
        printf("Delivery partners are busy , Order might be delayed,PLS cooperate, Thank you for your patience\n");
    }
    
    deliveryorder[delivery_order_num].Order_Number=delivery_order_num+1;
    
    printf("Enter customer name : ");
    scanf(" %[^\n]", deliveryorder[delivery_order_num].customer_name);

    printf("Enter delivery address : ");
    scanf(" %[^\n]",  deliveryorder[delivery_order_num].delivery_adress);
    
    printf("Enter delivery instructions : ");
    scanf(" %[^\n]",  deliveryorder[delivery_order_num].delivery_instructions);

    printf("Your order is successfully accepted \n");
    strcpy( deliveryorder[delivery_order_count].delivery_status ,"order accepted");

    printf("Your order number is : %d\n ",deliveryorder[delivery_order_count].Order_Number);
    delivery_order_num++;
    delivery_order_count++;
}

// function to be called to cancel the order
void delivery_order_cancel(int order_num) //MAHARSHI 
{
    if((strcmp(deliveryorder[(order_num-1)].delivery_status,"preparing order"))==0)
    {
        printf("Sorry! the order cannot be cancelled , Your order is being prepared\n");
    }
    else if((strcmp(deliveryorder[(order_num-1)].delivery_status,"order dispatched"))==0)
    {
        printf("Sorry! the order cannot be cancelled , Your order is out for delivery\n");
    }
    else if((strcmp(deliveryorder[(order_num-1)].delivery_status,"order delivered"))==0)
    {
        printf("Sorry! the order cannot be cancelled , Your order is already delivered\n");
    }
    else if((strcmp(deliveryorder[(order_num-1)].delivery_status,"invalid order number"))==0)
    {
        printf("invaild order number\n");
    }
    else
    {
        strcpy( deliveryorder[(order_num-1)].delivery_status ,"order cancelled");
        delivery_order_count--;
        printf("Your order is Successfully cancelled \n");
    }
}

// function for checking order status 
void delivery_order_status(int order_num)//MAHARSHI
{
    if(strcmp( deliveryorder[(order_num-1)].delivery_status ,"invalid order number")==0)
    {
        printf("invalid order number\n");
    }
    else
    {
        printf("delivery boy name: %s",delivery_boy[deliveryorder[(order_num-1)].delivery_boy_index].name);
        printf("delivery boy name: %s",delivery_boy[deliveryorder[(order_num-1)].delivery_boy_index].number);                          
        printf("delivery status : %s \n",deliveryorder[(order_num-1)].delivery_status);
    }
}

// function to be called when the food is being prepared 
void delivery_preparing_order(int order_num) //MAHARSHI
{
    if(strcmp( deliveryorder[(order_num-1)].delivery_status ,"order accepted")==0)
    {
        strcpy( deliveryorder[(order_num-1)].delivery_status ,"preparing order");
        printf("Your order is being prepared \n");
    }
    else
    {
        printf("The should not be prepared \n");
    }
    printf("delivery status %s\n ", deliveryorder[(order_num-1)].delivery_status );
}
    

// funtion to be called when order is dispatched
void dispatch_delivery_order(int order_num)//MAHARSHI
{
    if(strcmp( deliveryorder[(order_num-1)].delivery_status ,"preparing order")==0)
    {
        strcpy( deliveryorder[(order_num-1)].delivery_status ,"order dispatched");
        deliveryboy_num++; 
        delivery_order_count--;
        int index=assign_delivery_boy();
        deliveryorder[(order_num-1)].delivery_boy_index=index;
        delivery_boy[index].order_num=order_num;
        printf("order is out for delivery\n");
    }
    else
    {
        printf("The cannot not be despatched\n");
        printf("delivery status %s\n ", deliveryorder[(order_num-1)].delivery_status );
    }

}

// structure for delivery boy
struct DeliveryBoy   //MATEEN
{
    char name[25];
    char number[13];
    char user_id[7];
    char pass[6];
    int order_num;
    char delivery_boy_status[10];//available or unavailable 
};

struct DeliveryBoy delivery_boy[maxdb] ;// array of structure Delivery_Boy

// data set : containing information of delivery boys
void delivery_boy_initialize()//NAMAN
{
    // DELIVERY BOY 1
    strcpy(delivery_boy[0].name,"Aarav Sharma");
    strcpy(delivery_boy[0].number,"4581265842");
    strcpy(delivery_boy[0].user_id,"2022001");
    strcpy(delivery_boy[0].pass,"xxxxxx");
    strcpy(delivery_boy[0].delivery_boy_status,"available");
    // DELIVERY BOY 2
    strcpy(delivery_boy[1].name,"Ananya Patel");
    strcpy(delivery_boy[1].number,"5123697458");
    strcpy(delivery_boy[1].user_id,"2022002");
    strcpy(delivery_boy[1].pass,"nxhdbr");
    strcpy(delivery_boy[1].delivery_boy_status,"available");
    // DELIVERY BOY 3
    strcpy(delivery_boy[2].name,"Rohan Desai");
    strcpy(delivery_boy[2].number,"2541698358");
    strcpy(delivery_boy[2].user_id,"2022003");
    strcpy(delivery_boy[2].pass,"xxxxxx");
    strcpy(delivery_boy[2].delivery_boy_status,"available"); 
    // DELIVERY BOY 4
    strcpy(delivery_boy[3].name,"Nisha Kapoor");
    strcpy(delivery_boy[3].number,"5125976848");
    strcpy(delivery_boy[3].user_id,"2022004");
    strcpy(delivery_boy[3].pass,"xcbhgx");
    strcpy(delivery_boy[3].delivery_boy_status,"available"); 
    // DELIVERY BOY 5
    strcpy(delivery_boy[4].name,"Arjun Singh");
    strcpy(delivery_boy[4].number,"5123015975");
    strcpy(delivery_boy[4].user_id,"2022005");
    strcpy(delivery_boy[4].pass,"xxiudj");
    strcpy(delivery_boy[4].delivery_boy_status,"available");  
    // DELIVERY BOY 6
    strcpy(delivery_boy[5].name,"Diya Mehra");
    strcpy(delivery_boy[5].number,"9458762458");
    strcpy(delivery_boy[5].user_id,"2022006");
    strcpy(delivery_boy[5].pass,"knxxxx");
    strcpy(delivery_boy[5].delivery_boy_status,"available"); 
    // DELIVERY BOY 7
    strcpy(delivery_boy[6].name,"Aditya Verma");
    strcpy(delivery_boy[6].number,"5157642215");
    strcpy(delivery_boy[6].user_id,"2022007");
    strcpy(delivery_boy[6].pass,"uytrew");
    strcpy(delivery_boy[6].delivery_boy_status,"available");  
    // DELIVERY BOY 8
    strcpy(delivery_boy[7].name,"Priya Reddy");
    strcpy(delivery_boy[7].number,"5697845548");
    strcpy(delivery_boy[7].user_id,"2022008");
    strcpy(delivery_boy[7].pass,"xxxxxx");
    strcpy(delivery_boy[7].delivery_boy_status,"available");  
    // DELIVERY BOY 9
    strcpy(delivery_boy[8].name,"Vikram Mehta");
    strcpy(delivery_boy[8].number,"8495627130");
    strcpy(delivery_boy[8].user_id,"2022009");
    strcpy(delivery_boy[8].pass,"iopjhg");
    strcpy(delivery_boy[8].delivery_boy_status,"available");  
    // DELIVERY BOY 10
    strcpy(delivery_boy[9].name,"Pooja Khanna");
    strcpy(delivery_boy[9].number,"7854123690");
    strcpy(delivery_boy[9].user_id,"2022010");
    strcpy(delivery_boy[9].pass,"poweva");
    strcpy(delivery_boy[9].delivery_boy_status,"available");  
}
// function for delivery boys to mark themselves unavailable
void delivery_boy_unavailable(char id[]) //MATEEN
{
    for(int i=0;i<maxdb;i++)
    {
        if (strcmp(delivery_boy[i].user_id,id)==0)
        {
            strcpy(delivery_boy[i].delivery_boy_status,"unavailable");
        }
        printf("marked unavailable");
    }
}
// function to verify delivery boy
int verify_delivery_boy(char id[], char password[]) //MATEEN
{
    int c=0;
    for(int i=0;i<maxdb;i++)
    {
        if((strcmp(delivery_boy[i].user_id,id)==0) && (strcmp(delivery_boy[i].pass,password)==0))
        {
            c=i;
            break;
        }
    }
    return c;
}
// funtion to be called when order is delivered
void order_delivered(int order_num)//MATEEN
{
    if(strcmp( deliveryorder[(order_num-1)].delivery_status ,"order dispatched")==0)
    {
        strcpy( deliveryorder[(order_num-1)].delivery_status ,"order delivered");
        deliveryboy_num--;    
        printf("order is delivered\n");
    }
    else
    {
        printf("The cannot not be delivered\n");
        printf("delivery status %s\n ", deliveryorder[(order_num-1)].delivery_status );
    }
}
// function to get number of delivery boys available
int delivery_boy_available()//MATEEN
{
    int count=0;
    for(int i=0;i<maxdb;i++)
    {
        if(strcmp(delivery_boy[i].delivery_boy_status,"available")==0)
        count++;
    }
    return count;
}

// function returns assinged delivery boy user id
int assign_delivery_boy()//MATEEN
{
    int z=-1;
    for(int i=0;i<maxdb;i++)
    {
        if(strcmp(delivery_boy[i].delivery_boy_status,"available"))
        {
            z=i;
            break;
        }
    }
    return z;
}

// main function
int main()
{
    int order_no,num,size,i;
    // initialising all the table status to vacant
    for( i=0;i<5;i++)
    {
        strcpy(available_tables2[i].table_status,"vacant");
        strcpy(available_tables4[i].table_status,"vacant");
        strcpy(available_tables6[i].table_status,"vacant");
    }
    // initialising all the delivery status
    for(int i=0;i<200;i++)
    {
        strcpy(deliveryorder[i].delivery_status ,"invalid order number");
    }
    // initialising all deliveryboy status
    delivery_boy_initialize();
    int c,cm,cd,cc;
    char user_id[10];
    char pass[20];
    while (1)
    {
        printf("\n Enter 1 : Manager");
        printf("\n Enter 2 : Delivery Boy");
        printf("\n Enter 3 : Chef");
        printf("\n Enter 4 : For exiting\n");
        printf("\nEnter Your Choice\n");
        scanf("%d",&c);
        switch (c)
        {
        case 1:
            printf("Enter user id and password\n");
            scanf(" %[^\n]",&user_id);
            scanf(" %[^\n]",&pass);
            if(strcmp(user_id,user_id_manager)==0 && strcmp(pass,pass_manager)==0)
            {
                
                while(1)
                {
                    printf("\n Enter 1: For booking table");
                    printf("\n Enter 2: For vacating table");
                    printf("\n Enter 3: For status of a tables");
                    printf("\n Enter 4: For checking non-reserved  tables");
                    printf("\n Enter 5: For placing order for delivery");
                    printf("\n Enter 6: For cancelling order for delivery");
                    printf("\n Enter 7: For dispatching order for delivery");
                    printf("\n Enter 8: For marking order delivered");
                    printf("\n Enter 9: For checking delivery status ");
                    printf("\n Enter 10: For displaying all the Delivery Order information");
                    printf("\n Enter 11: For displaying the number of delivery boys available");
                    printf("\n Enter 12: For exiting");
                    printf("\n Enter your choice :");
                    scanf("%d",&cm);

                    switch (cm)
                    {
                    case 1:
                        printf("Enter the number of members : ");
                        scanf("%d",&size);
                        reserve_table(size);
                        break;
                    case 2:
                        printf("Enter the table number : ");
                        scanf("%d",&num);
                        vacat_table(num);
                        break;
                    case 3://
                        printf("Enter table num : ");
                        scanf("%d",&num);
                        table_status(num);
                        break;
                    case 4:
                        tables_available(2);
                        tables_available(4);
                        tables_available(6);
                        break;
                    case 5:
                        delivery_order();
                        break;
                    case 6:
                        printf("Enter the order number : ");
                        scanf("%d",&order_no);
                        delivery_order_cancel(order_no);
                        break;
                    case 7:
                        printf("Enter the order number : ");
                        scanf("%d",&order_no);
                        dispatch_delivery_order(order_no);
                        break;
                    case 8:
                        printf("Enter the order number : ");
                        scanf("%d",&order_no);
                        order_delivered(order_no);
                        break;
                    case 9:
                        printf("Enter the order number : ");
                        scanf("%d",&order_no);
                        delivery_order_status(order_no);
                        break;
                    case 10:
                        for(i=0;i<delivery_order_num;i++)
                        {
                            printf("ORDER NUMBER: %d\n",deliveryorder[i].Order_Number);
                            printf("CUSTOMER NAME: %s\n",deliveryorder[i].customer_name);
                            printf("DELIVERY ADRESS: %s\n",deliveryorder[i].delivery_adress);
                            printf("delivery boy name: %s",delivery_boy[deliveryorder[i].delivery_boy_index].name);
                            printf("delivery boy name: %s",delivery_boy[deliveryorder[i].delivery_boy_index].number);
                            printf("DELIVERY STATUS: %s\n",deliveryorder[i].delivery_status);
                            printf("\n\n");
                        }
                        break;
                    case 11:
                        int y= delivery_boy_available();
                        printf("The number of delivery boys available = %d",y);
                        break;
                    case 12:
                        exit(0);
                        break;
                    default:
                        printf("Invalid choice\n");
                        break;
                    }
                }
            }
            else
            {
                printf("invalid userid or password\n");
            } 
            break;
        case 2:
                printf("Enter user id and password\n");
                scanf(" %[^\n]",&user_id);
                scanf(" %[^\n]",&pass);
                int x=verify_delivery_boy(user_id,pass);
                if(x==0)
                {
                    printf("invalid user id or password\n");
                }
                else
                {
                    while(1)
                    {
                        printf("Enter 1 for marking order as delivered \n");
                        printf("Enter 2 for marking yourself unavailable\n");
                        printf("Enter 3 for exiting");
                        printf("enter your choice :");
                        scanf("%d",&cd);
                        switch (cd)
                        {
                        case 1:
                            printf("Enter order number :");
                            scanf("%d",&order_no);
                            order_delivered(order_no);
                            break;
                        case 2:
                            delivery_boy_unavailable(user_id);
                            break;
                        case 3:
                            exit(0);
                            break;
                        default:
                            break;
                        }
                    }
                }
            break;
        case 3: 
            printf("Enter user id and password\n");
            scanf(" %[^\n]",&user_id);
            scanf(" %[^\n]",&pass);
            if(strcmp(user_id,user_id_cook)==0 && strcmp(pass_cook,pass)==0)
            {
                while(1)
                {
                    printf("Enter 1 for accepting order for preparing order\n");
                    printf("Enter 2 for despatching the order\n"); 
                    printf("Enter 3 for exiting");
                    printf("Enter Your Choice :");
                    scanf("%d",&cc);
                    switch (cc)
                    {
                    case 1:
                        printf("\nEnter the order number :");
                        scanf("%d",&order_no);
                        delivery_preparing_order(order_no);
                        break;
                    case 2:
                        printf("\nEnter the order number :");
                        scanf("%d",&order_no);
                        dispatch_delivery_order(order_no);
                        break;  
                    case 3:
                        exit(0);
                        break;
                    default:
                        printf("invalid choice\n");
                        break;
                    } 
                } 
            }
            else
            {
                printf("Invalid user id and password\n");
            }
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("invalid choice\n");
            break;
        }
    }
}