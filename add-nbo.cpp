#include <stddef.h> 
#include <stdint.h> 
#include <stdio.h> 
#include <netinet/in.h>
#include <string.h>

uint32_t add_nbo(uint32_t thous,uint32_t five){
    uint32_t thousval = ntohl(thous);
    uint32_t fiveval = ntohl(five);

    uint32_t add = thousval+fiveval;
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)", thousval, thousval, fiveval, fiveval, add,add);
    return 0;
}

int main(int argc, char** argv){
    uint32_t thous;
    uint32_t five;

    FILE* thousfd = fopen(argv[1], "r");
    FILE* fivefd = fopen(argv[2], "r");
    fread(&thous, 4,1, thousfd);
    fread(&five, 4,1, fivefd);

    add_nbo(thous, five);

    fclose(thousfd);
    fclose(fivefd);
    return 0;
}
