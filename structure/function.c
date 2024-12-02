#include<stdio.h>
 struct funds{
        char bank[20];
        double bankfund;
        char save[20];
        double savefund;
    };
double sum(struct funds name){
    return (name.bankfund + name.savefund);
}
double sum2(struct funds *name){
    return(name->bankfund + name->savefund);
}

int main()
{
   
    struct funds stan = {"BankOfAmerica", 2000.0, "PNC", 2500.0};
    printf("Stan has total of $%.2f\n", sum(stan));
    printf("Stan has total of $%.2f\n", sum2(&stan));

}