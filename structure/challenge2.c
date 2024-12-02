#include<stdio.h>
#include<stdlib.h>
struct item{
    char itemName[20];
    int quantity;
    float price;
    float amount; 
};

void readItem(struct item *items){
    char buffer[20];
    printf("Enter the name of item: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer,"%s", &items -> itemName);

    printf("Enter the quantity: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer,"%d", &items -> quantity);

    printf("Enter the price: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer,"%f", &items -> price);

    items -> amount = items->quantity * items-> price;

}

void printItem(struct item *items){
    printf("Total for %d no of %s of price %f each is %f", items->quantity, items->itemName,  items->price, items->amount );
}
int main()
{
    struct item item1;
    struct item *p;
    p = &item1;
    readItem(p);
    printItem(p);
    return 0;
}