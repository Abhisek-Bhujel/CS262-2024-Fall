#include<stdio.h>
#include<string.h>
void ceaserCipher(char arr[], char newarr[], int shift);

int main(){
    char words[6]= "hello";
    char cipheredWord[6]="";
    ceaserCipher(words,cipheredWord,23456617);
    printf("%s", cipheredWord);


}
void ceaserCipher(char arr[], char newarr[], int shift)
{
    char alphabets[26] = "abcdefghijklmnopqrstuvwxyz";
    int index;
    for(int i = 0; i < strlen(arr); i++){
        char a = arr[i];
        for (int j = 0; j < 26; j++)
        {
            if(a == alphabets[j]){
                index = j;
            }
        }
        if((index+shift) < 26){
            newarr[i] = alphabets[index+shift];
        }
        else if((index+shift) > 25){
            newarr[i] = alphabets[((index+shift)%26)];
        }
        index  = 0;
        
    }

}