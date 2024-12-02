#include <stdio.h>

struct packed_struct
{
    int count;
    char c;
    unsigned int : 3;
    unsigned int f1 : 1;
    unsigned int f2 : 1;
    unsigned int f3 : 1;
    unsigned int type : 8;
    unsigned int index : 18;
};

int main()
{
    struct packed_struct packed_data;
    unsigned int bit = packed_data.type;
    unsigned int i = packed_data.index / 5 + 1;

    if (packed_data.f2)
        return 0;
}