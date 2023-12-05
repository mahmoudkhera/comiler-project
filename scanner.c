 #include"scanner.h"

      
 
char * substring(char *word, int left, int right)

    {
    int sub_length =right -left+1;
     char *word_pointer =(char*) malloc(sizeof(char)*(sub_length + 1));  //the is to for the null string \0
       
    if (word_pointer == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }  

  
    for (int i = left; i <= right && word[i] != '\0'; i++) {
        *word_pointer = word[i];
        word_pointer++;
    }

    *word_pointer = '\0';  // Append the null character

    return word_pointer-sub_length;  // Return the original pointer
}

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

    // Check the rest of the characters
 

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

int tokens_genrator(char *source_code)
{
    int left = 0 , right = 0; //refrence identifiy the start and end of each token
    int len =strlen(source_code);

    while(right<=len && left<=right)
    {
        if(special_char(source_code[right])==0) // if the char not a special character skip it
            right++;
        
        if(special_char(source_code[right])==1 && right==left)
        {
            if(is_operator(source_code[right]))
                printf(" <%c,operator> \n",source_code[right]);
            
            else if(source_code[right]!=' ') //skip the witespace 
                printf(" <%c,special character> \n",source_code[right]);
            else if (source_code[right]==';')
                printf(" <%c,semicolon>\n",source_code[right]);

            //set the new refrence to the new token
            right++;
            left=right; 
        }
        else if(special_char(source_code[right])==1 && left!=right || (left!=right && right==len) )
        {
            //remove the delimeter or spa ce from the string
            char *word =substring(source_code,left,right-1); 
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
            
            left =right;

        } 

    }
    return 0;

}

void read_code(char **output_code,char * input_file)
{
      FILE *file=NULL;

    file =fopen(input_file,"r");
    //cheeck if the file is exist 
    if (file != NULL)
    {
       char chr;
        char *store_buffer=malloc(sizeof(char)*(max_lenght_of_code)); // this is an array of charcter and not a string 
        int lenght =0;
        while((chr = fgetc(file)) != EOF ) // loop until you see the end of the file
        {
            if(chr =='\n')    //skip the new line character 
            continue;
            store_buffer[lenght]=chr;
            lenght++;  // the lenght count additional one  aftter all caracter are stroed
        
        }
        fclose(file);
        store_buffer[lenght]= '\0'; // put termination charcter at the end o character stream
        * output_code=store_buffer;

    }
    else
        printf("file does not exist");

        
}