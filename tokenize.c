#include <stdio.h>
#include <stdlib.h>

char **tokenizeD(char *str, char delim);
char **tokenizeS(char *str, char delim);
char *Strcpy(char *dest, char *src);
int Strlen(char *str);

int main(void)
{
    char sentence[] = "This is a sentence.";

    char **tokensD = tokenizeD(sentence, ' ');
    char **tokensS = tokenizeS(sentence, ' ');

    printf("Test Sentence: %s\n\n", sentence);
    printf("TokenizeD tokens:\n");
    while (*tokensD != NULL)
    {
        printf("%s\n", *tokensD);
        tokensD++;
    }

    printf("\n\nTokenizeS tokens:\n");
    while (*tokensS != NULL)
    {
        printf("%s\n", *tokensS);
        tokensS++;
    }

    

    return 0;
}

char **tokenizeD(char *str, char delim)
{
    char *start= malloc((Strlen(str)+1) * sizeof(char));
    Strcpy(start, str);
    int delimCount = 0;

    while (*str != '\0')
    {
        if (*str == delim)
        {
            delimCount++;
        }
        str++;
    }

    char **tokens = malloc((delimCount + 2) * sizeof(char *));
    *tokens = start;
    char **hold = tokens;
    tokens++;

    while (*start != '\0')
    {
        if (*start == delim)
        {
            *start = '\0';
            start++;
            *tokens = start;
            tokens++;
        }
        else
        {
            start++;
        }
    }

    *tokens = NULL;
    return hold;
}

char **tokenizeS(char *str, char delim)
{
    static char copy[100];
    Strcpy(copy, str);

    char *start=copy;
    static char *tokens[10];
    char **current = tokens;

    *current = start;
    current++;
    while (*start != '\0')
    {
        if (*start == delim)
        {
            *start = '\0';
            start++;
            *current = start;
            current++;
        }
        else{
            start++;
        }
    }
    *current=NULL;
    return tokens;
}

char *Strcpy(char *dest, char *src){
    char *start=dest;
    while (*src != '\0'){
        *dest = *src;
        src++;
        dest++;
    }
    *dest='\0';
    return start;
}

int Strlen(char *str) {
    int len = 0;
    while (*str != '\0'){
        len++;
        str++;
    }
    return len;
}
