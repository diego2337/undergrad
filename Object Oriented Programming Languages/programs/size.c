#include <stdio.h>

typedef struct {
    int size; 
    enum {token=0x1} e; 
} Message;

int main(int argc, char * argv[])
{
    Message m;
    m.size = 30;
    printf("sizeof(int): %ld\n",sizeof(int));
    printf("sizeof(0x123456): %ld\n",sizeof(0x123456));
    printf("sizeof(Message): %ld\n",sizeof(Message));
    printf("sizeof(m): %ld\n",sizeof(m.e));
}
