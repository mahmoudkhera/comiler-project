#ifndef scanner
#define scanner
    #include <stdio.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include <string.h>
    
    #define number_of_kewords 32
    #define max_lenght_of_code 1000


    /*creat substring  and return a pointer to subtring */
    char* substring(char *source_str, int left ,int right);
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

    /* tokenizer function that parse the code into tokens */
    int  tokens_genrator(char *source_code);
    /*read the source code from anoter file  */
    void read_code(char **output_code,char * input_file);
#endif 

