#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Node
{
    int serial_no, warranty, unit_price;
    char name[30];
    struct Node *next;
}*top1 = NULL;

void push(int serial_no, char *name,int warranty, int unit_price)
{
   struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

   newNode->serial_no = serial_no;
   newNode->warranty = warranty;
   newNode->unit_price = unit_price;
   strcpy(newNode->name, name);
   if(top1 == NULL)
      newNode->next = NULL;
   else
      newNode->next = top1;
   top1 = newNode;
}

struct stackNode
{
   int serial_no, warranty, unit_price, ammount, qty;
    char name[30];
   struct stackNode *next;
}*top = NULL;

void stackPush(int key,int qty)
{
   struct stackNode *newNode = (struct stackNode*)malloc(sizeof(struct stackNode));
   struct Node *node = top1;
   while(node->serial_no != key)
   {
       node = node->next;
   }
    newNode->serial_no  = node->serial_no;
    newNode->warranty  = node->warranty;
    newNode->unit_price = node->unit_price;
    newNode->qty = qty;
    newNode->ammount = (node->unit_price*qty);
    strcpy(newNode->name, node->name);
   if(top == NULL)
      newNode->next = NULL;
   else
      newNode->next = top;
   top = newNode;
   printf("\nInsertion is Success!!!\n");
}
void display();
void stackDisplay();
void custom();
void select();
void select2();
void total();
int main()
{
    int choice,  invoice_no = 121701 ;

    push(1015, "Intel Core i7 8700K 8th Gen. ", 3, 31200);
    push(1014, "Intel Core i7 7700K 7th Gen.", 3, 28300);
    push(1013, "Intel Core i7 7700 7th Gen.", 3, 25200);
    push(1012, "Intel Core i5 8600K 8th Gen. ", 3, 23200);
    push(1011, "Intel Core i5 7600K 7th Gen. ", 3, 20500);
    push(1010, "Intel Core i3 8350K 8th Gen. ", 3, 16500);
    push(1009, "Intel Core i5 7500 7th Gen", 3, 16200);
    push(1008, "Intel Core i5 7400 7th Gen.", 3, 14600);
    push(1007, "Intel Core i7 3820 3rd Gen. ", 3, 12300);
    push(1006, "Intel Core i3 8100 8th Gen. ", 3, 10400);
    push(1005, "Intel Core i3 7100 7th Gen.", 3, 9300);
    push(1004, "Intel Core i3 6100 6th Gen.", 3, 9200);
    push(1003, "Intel PDC G4560 7th Gen.", 3, 5400);
    push(1002, "Intel Pentium G3260 4th Gen.", 3,  5100);
    push(1001, "Intel PDC G4400 6th Gen.", 3, 4700);

    while(1)
    {
        printf("\n***** Welcome to BL(Believe in Logic) Computers *****\n(The Largest Intel Processor Wholesale Market)\n\n");
        printf("Choose your option\n");
        printf("1. Invoice Making\n2. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                {
                    custom();
                    printf("\n\t\t\t\t\t\tInvoice\nInvoice No: %d\nBill Date: ", invoice_no++);
                    time_t mytime;
                        mytime = time(NULL);
                        printf(ctime(&mytime));
                    printf("\nSerial No\tDescription\t\t\tWarranty\tUnit Price\tQty\tAmmount\n");
                    stackDisplay();
                    total();
                    select2();
                    top = NULL;
                }
                break;
            case 2: exit(0);
            default: printf("\nWrong selection!!! Try again!!!");
        }
    }
    return 0;
}

void display()
{
   if(top1 == NULL)
      printf("\nStack is Empty!!!\n");
   else{
      struct Node *temp = top1;
      while(temp != NULL){
	 printf("%d\t\t%s\t%d years\t\t%d\n",temp->serial_no, temp->name, temp->warranty, temp->unit_price);
	 temp = temp -> next;
      }
   }
}

void stackDisplay()
{
   if(top == NULL)
      printf("\nStack is Empty!!!\n");
   else{
      struct stackNode *temp = top;
      while(temp != NULL){
	 printf("%d\t\t%s\t%d years\t\t%d\t\t%d\t%d\n",temp->serial_no, temp->name, temp->warranty, temp->unit_price, temp->qty,temp->ammount);
	 temp = temp -> next;
      }
   }
}

void custom ()
{
    int serial_no, unit_number;
    printf("\nWhich processor do the customer prefer : \n");
    printf("\nSerial No\tDescription\t\t\tWarranty\tUnit Price \n");
    display();
    printf("\nEnter the serial No of the product that customer want to buy : ");
    scanf("%d", &serial_no);
    printf("Enter the Quantity :");
    scanf("%d", &unit_number);
    stackPush(serial_no, unit_number);
    select();
}

 void select ()
 {
     int choice;
     printf("Do the customer need any other Processor :\n1. Yes\t\t2. No\n");
    scanf("%d", &choice);
    if(choice == 1)
        custom();
    else if(choice == 2)
        return;
    else
    {
            printf("Wrong selection!!! Please try again.\n");
            select();
    }
 }

 void select2()
 {
     int choice;
     printf("Do You want to EXIT?\n1. Yes\t\t2. No\n");
    scanf("%d", &choice);
    if(choice == 1)
            exit(0);
    else if (choice == 2)
        return;
    else
    {
        printf("Wrong Insertion!!! Please Enter Correct Option.\n");
        select2();
    }
 }

 void total()
{
    struct stackNode *node = top;
    int sum = 0;
    while(node != NULL)
    {
        sum = sum + (node->ammount);
        node = node->next;
    }
    printf("\n\t\t\t\t\t\t\t\t\tTotal Amount : %d\n", sum);
}
