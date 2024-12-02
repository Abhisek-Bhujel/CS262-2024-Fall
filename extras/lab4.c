#include<stdio.h>
void uniqueDigit(int firstNumber, int lastNumber);
int main(){
    uniqueDigit(1231, 1237);
    return 0;
}

void uniqueDigit(int firstNumber, int lastNumber){
    for(int i = firstNumber; i<= lastNumber; i++){
        int temp = i%10;
        while(i > 0){
            int j = i/10;
            int secondTemp = j%10;
            if(temp == secondTemp){
                break;
            }
            printf("%d", i);
            temp = secondTemp;
            i = i/10;

        }
    }
}