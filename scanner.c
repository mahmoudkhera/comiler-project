 #include"scanner.h"

 

    int is_operator(char ch)
    {
        if (ch == '+' || ch == '-' || ch == '*' ||
            ch == '/' || ch == '%' || ch == '=' ||
            ch == '<' || ch == '>' ) 
                return 1;
             
        return 0;
    }
    int special_char(char ch)
    {
        if( ch == '+' || ch == '-' || ch == '*' || ch == '/' || 
            ch == '=' || ch == '<' || ch == '>' || ch == ' ' || 
            ch == ',' || ch == ';' ||  ch == '(' || ch == ')' ||
            ch == '[' || ch == ']' || ch == '{' || ch == '}')
            return 1;
        return 0;
    }

 int is_identifier(char *word)
 {
    // Check the first character: it must be a letter or underscore
    if (!isalpha(word[0]) && word[0] != '_') {
        return 0;
    }

     for (int i = 1; i < strlen(word); i++) {
        // Each character must be a letter, digit, or underscore
        if (!isalnum(word[i]) && word[i] != '_') {
            return 0;
        }
     }

    return 1; //if passes
 }

int iskeyword(char *str)
{
    char* key_words[] = {
    "auto", "break", "case", "char", "const", "continue", "default",
    "do", "double", "else", "enum", "extern", "float", "for", "goto",
    "if", "int", "long", "register", "return", "short", "signed",
    "sizeof", "static", "struct", "switch", "typedef", "union",
    "unsigned", "void", "volatile", "while"};
    for (int i=0; i<number_of_kewords; i++)
    {
        if(strcmp(str,key_words[i])==0)
            return 1;
    }
    return 0;

}

int is_integer(char *word)
{
    int lenght=strlen(word);
    if(lenght ==0)
        return 0;
    for(int i=0; i<lenght; i++)
    {
        if(!isdigit(word[i]))
            return 0;
    }
    return 1;
}

int is_real_num(char *word)
{
    int dot_flag=0;
    int lenght = strlen(word);
    if(lenght==0)
        return 0;
    for(int i=0; i<lenght;i++)
    {
        if((!isdigit(word[i])) && word[i]!='.')
            return 0;
        if(word[i] == '.')
           dot_flag++; //to check there is onlye one dot in the number
    }
    return (dot_flag==1)? 1:0;
    
}


int read_file(char **output_code,char * input_file)
{
      FILE *file=NULL;

    file =fopen(input_file,"r");
    //cheeck if the file is exist 
    if (file != NULL)
    {
       char chr;
        char *buffer=malloc(sizeof(char)*(max_length_of_code)); // this is an array of charcter and not a string 
        int length =0;
        while((chr = fgetc(file)) != EOF ) // loop until you see the end of the file
        {
            if(chr =='\n')    //skip the new line character 
            continue;
           buffer[length]=chr;
            length++;  // the length count additional one  aftter all caracter are stroed
        
        }
        fclose(file);
        buffer[length]= '\0'; // put termination charcter at the end o character stream
        * output_code=(char*) realloc(buffer,length*sizeof(char));
        buffer=NULL;
        
        return length;

    }
    else
        printf("file does not exist");
    return 0;
        
}

int tokens (char*words,int length)
{
    int current =0;
    int word_counter=0;
    int word_flage =0;
    char * word = (char * ) malloc (word_max*sizeof(char));
    
    while ( current!=(length+1))
    {
        if( special_char(words[current])==0)
        {
            word[word_counter]=words[current];
            word_counter++;
            word_flage =1;
            word[word_counter]='\0';
        }
        else if( special_char(words[current])==1)
        {
            if(word_flage==1)
            {
                word_counter=0;
                word_flage=0;
                if(iskeyword(word)==1)
                    printf(" <%s,keyword> \n",word);
                else if (is_identifier(word)==1)
                     printf(" <%s,identifier> \n",word);
                else if (is_integer(word)==1)
                    printf(" <%s,integer> \n",word);
                else if (is_real_num(word)==1)
                    printf(" <%s,real number> ",word);
                else
                     printf(" <%s,not in the language>",word);
            }

            if(is_operator(words[current]))
                printf(" <%c,operator> \n",words[current]); 
            else if(words[current] !=' ') //skip the witespace 
                printf(" <%c,special character> \n",words[current]);
        }
        current++;
    }

}
