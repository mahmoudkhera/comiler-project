#include "scanner.h"
#include <time.h>


int main(int argc,char *argv[])
{
    char *store_code=NULL;

    clock_t start_time = clock();

     int length =read_file(&store_code,argv[1]);    // argv to read the input file fromm cmd
     tokens(store_code,length);

    clock_t end_time = clock();

    double elapsed_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    // Print the result
    printf("Time taken: %f seconds\n", elapsed_time);
    
   

}
