#ifndef scanner
#define scanner
    #include <stdio.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include <string.h>
    
    #define number_of_kewords 32
    #define max_lenght_of_code 1000
    #define word_max    100
    /*check if token is operator*/
    int is_operator(char chr);
    /*check if token special character*/
    int special_char(char chr);
    /*check if token  is valid identifier*/
    int is_identifier(char *str);
    /*check if token is keyword*/
    int iskeyword(char *str);
    /*check if the token is integer value*/
    int is_integer(char *str);  
    /*check if the token is real number*/
    int is_real_num (char *str);

    /*read the source code from anoter file  */
    int  read_file(char **output_code,char * input_file);
     /*generate  the tokens */
    int tokens (char*words,int length);
#endif 

