#include<stdio.h>
#include<stdlib.h>

#define PI 3.14
#define AREA
#define concat(a,b) a##b
int main()
{
    float r = 5.0;
    #ifdef AREA
    printf("Area of circle is %f\n",(PI *r *r) );
    #endif
    printf("Circumference of a circle is %f\n", (2 * PI * r));

    int xy = 30;
    printf("%d", concat(x,y));
    return 0;
}
