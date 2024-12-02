#include<stdio.h>
int main()
{
    FILE *fp;
    int ch; 

    fp = fopen("write.txt", "w+");
    for(ch = 33; ch <= 100; ch++){
        fputc(ch, fp);
        fputc('\n', fp);

    }
    fclose(fp);
    return 0;
}