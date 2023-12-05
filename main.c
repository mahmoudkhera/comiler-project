#include "scanner.h"
#include <time.h>


int main(int argc,char *argv[])
{
    char *store_code=NULL;

    clock_t start_time = clock();

    read_code(&store_code,argv[1]); //   read the input file fromm cmd

    printf("%s",store_code);
   tokens_genrator(store_code);

    clock_t end_time = clock();

    double elapsed_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    // Print the result
    printf("Time taken: %f seconds\n", elapsed_time);
    
   

}
