#include<stdio.h>
int main(){
     char letters[] = {'A', 'C', 'G', 'T'};
    int n = 4; // number of letters
    int count = 0;
     for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
               
                    printf("%c%c%c\n", letters[i], letters[j], letters[k]);
                    count++;
                
            }
        }
    }
    printf("%d", count);
    return 0;
}