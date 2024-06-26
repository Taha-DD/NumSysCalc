#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>

unsigned todecimal(char number[], char kind[])
{
    int length = strlen(number);
    unsigned decimal = 0, d = 16;
    
    if (strcmp(kind, "decimal") == 0)
        return atoi(number);
        
    else if (strcmp(kind, "binary") == 0)
        d = 2;
        
    else if (strcmp(kind, "octal") == 0)
        d = 8;
        
    else if (strcmp(kind, "hexadecimal") == 0)
        for (int i = 0; i < length; i++)
            if (tolower(number[i]) >= 'a' && tolower(number[i]) <= 'f')
                number[i] = tolower(number[i]) - 'a' + 10 + '0';
                
                
    for (int i = length - 1, j = 0; i >= 0; i--, j++)
        if (number[i] > '0')
            decimal += (number[i] - '0') * pow(d, j);
            
    return decimal;
}

int isBinary(const char *binary)
{
    for (int i = 0; binary[i] != '\0'; i++)
        if (binary[i] != '0' && binary[i] != '1')
            return 1;
    
    return 0;
}
char* binary(unsigned n, unsigned u, char *result, char operation) 
{
    unsigned long long int o;
    
    switch (operation)
    {
        case '+':
            o = (unsigned long long int)n + u;
            break;
        case '-':
            o = (unsigned long long int)n - u;
            break;
        case '*':
            o = (unsigned long long int)n * u;
            break;
        case '/':
            o = (unsigned long long int)n / u;
            break;
        case '?':
            o = n;
            break;
    }
    
    int size = floor(log2(o)+1);
    int i = size - 1;
    
    if (o <= 0)
        return result;
        
    while (i >= 0)
    {
        result[i] = '0' + (o % 2);
        o = floor( o / 2 );
        i--;
    }
    
    result[size] = '\0';
    
    return result;
}

char* octal(unsigned n, unsigned u, char *result, char operation) 
{
    unsigned long long int o;
    int octal[100], size = 0;
    
    switch (operation)
    {
        case '+':
            o = (unsigned long long int)n + u;
            break;
        case '-':
            o = (unsigned long long int)n - u;
            break;
        case '*':
            o = (unsigned long long int)n * u;
            break;
        case '/':
            o = (unsigned long long int)n / u;
            break;
        case '?':
            o = n;
            break;
    }
    
    while (o)
    {
        octal[size] = o % 8;
        o = floor(o / 8);
        size++;
    }
    
    for (int j = size - 1, i = 0; j >= 0; j--, i++)
        sprintf(&result [i],"%d", octal[j]);
}

char* hexadecimal (unsigned n, unsigned u, char *result, char operation) 
{
    unsigned long long int o;
    int i = 0, j, temp, remainder;
    char hexnum[100];
    
    switch (operation)
    {
        case '+':
            o = (unsigned long long int)n + u;
            break;
        case '-':
            o = (unsigned long long int)n - u;
            break;
        case '*':
            o = (unsigned long long int)n * u;
            break;
        case '/':
            o = (unsigned long long int)n / u;
            break;
        default:
            o = n;
            break;
    }
    
    while (o != 0)
    {
        temp = o % 16;
        if (temp < 10)
            temp = temp + 48;
        else
            temp = temp + 55;

        hexnum[i++] = temp;
        o = floor(o / 16);
    }

    for (j = i - 1; j >= 0; j--)
        result[i - 1 - j] = hexnum[j];

    result[i] = '\0';
    
    return result;
}

char* decimal (unsigned n, unsigned u, char *result, char operation) 
{
    unsigned long long int o;
    int size;
    int i;
    
    switch (operation)
    {
        case '+':
            o = (unsigned long long int)n + u;
            break;
            case '-':
            o = (unsigned long long int)n - u;
            break;
        case '*':
            o = (unsigned long long int)n * u;
            break;
        case '/':
            o = (unsigned long long int)n / u;
            break;
        case '?':
            o = n;
            break;
    }
    
    if (o == 0)
        return result;
        
    i = o;
    
    while ( i )
    {
        size++;
        i = floor (i / 10);
    }
    
    while (i >= 0)
    {
        result[i] = '0' + (o % 10);
        o = floor( o / 10 );
        i--;
    }
    
    result[size] = '\0';
    
    return result;
}
int main() {
    char result[900] = {0}, kind[20], operation, operations[19], conversion[20], number1[100], number2[100], answer[100];
    unsigned dnumber1 = 0, dnumber2 = 0;
    int key = 0;
    
    puts (" hey budd!");
    
    farmer1:
    
    printf(" what do you want?\n operations on:\n 1. binary\n 2. decimal\n 3. octal\n 4. hexadecimal\n »» ");
    scanf(" %s", &kind);
    
    if (strcasecmp(kind, "1" ) == 0 || strcasecmp(kind, "1." ) == 0 || strcasecmp(kind, "binary") == 0 || strcasecmp(kind, "1. binary") == 0 || strcasecmp(kind, "1.binary") == 0)
    {
        strcpy(kind, "binary");
        
        if (key)
        {
            puts (" you better be fuckin' with me get the hell outta here");
            return 0;
        }
    }
    
    else if (strcasecmp(kind, "2") == 0 || strcasecmp(kind, "2." ) == 0 || strcasecmp(kind, "decimal") == 0 || strcasecmp(kind, "2. decimal") == 0 || strcasecmp(kind, "2.decimal") == 0)
    {
        strcpy(kind,"decimal");
        
        if ( key )
            goto typo;
    }
    
    else if (strcasecmp(kind, "3") == 0 || strcasecmp(kind, "3." ) == 0 || strcasecmp(kind, "octal") == 0 || strcasecmp(kind, "3. octal") == 0 || strcasecmp(kind, "3.octal") == 0)
    {
        strcpy(kind,"octal") ;
        
        if ( key )
            goto typo;
    }
    
    else if (strcasecmp(kind, "4") == 0 || strcasecmp(kind, "4." ) == 0 || strcasecmp(kind, "hexadecimal") == 0 || strcasecmp(kind, "4. hexadecimal") == 0 || strcasecmp(kind, "4.hexadecimal") == 0)
    {
        strcpy(kind,"hexadecimal");
        
        if ( key )
            goto typo;
    }
    
    else
    {
        puts(" enter one of those four options, FFFFARMERRRR!!!");
        
        goto farmer1;
    }
    
    farmer2:
    
    printf(" nice, now choose an operation:\n 1. addition\n 2. subtraction\n 3. multiplication\n 4. division\n 5. conversion\n »» ");
    scanf (" %s", &operations);
    
    if ( strcasecmp(operations, "1") == 0 || strcasecmp(operations, "1.") == 0 || strcasecmp(operations, "addition") == 0 || strcasecmp(operations, "1.addition") == 0 )
        operation = '+';
        
    else if ( strcasecmp(operations, "2") == 0 || strcasecmp(operations, "2.") == 0 || strcasecmp(operations, "subtraction") == 0  || strcasecmp(operations, " 2.subtraction") == 0  )
        operation = '-';
        
    else if ( strcasecmp(operations, "3") == 0  || strcasecmp(operations, "3.") == 0  || strcasecmp(operations, "multiplication") == 0  || strcasecmp(operations, " 3.multiplication") == 0  )
        operation = '*';
        
    else if ( strcasecmp(operations, "4") == 0  || strcasecmp(operations, "4.") == 0 ||  strcasecmp(operations, "division") == 0  || strcasecmp(operations, "4.division") == 0  )
        operation = '/';
        
    else if ( strcasecmp(operations, "5") == 0  || strcasecmp(operations, "5.") == 0  || strcasecmp(operations, "conversion") == 0  || strcasecmp(operations, " 5.conversion") == 0 )
        operation = '?';
        
    else
    {
        puts("come the hell on don't you know how to write");
        
        goto farmer2;
    }
    
    if ( operation == '?' )
    {
        farmer3:
        if ( strcmp(kind,"binary") == 0 )
            printf(" from binary to:\n 1. decimal\n 2. octal\n 3. hexadecimal\n »» ");
            
        else if ( strcmp(kind, "decimal") == 0 )
            printf(" from decimal to:\n 1. binary \n 2. octal\n 3. hexadecimal\n »» ");
            
        else if ( strcmp(kind, "octal") == 0 )
            printf(" from octal to:\n 1. decimal\n 2. binary \n 3. hexadecimal\n »» ");
            
        else
            printf(" from hexadecimal to:\n 1. decimal\n 2. binary \n 3. octal\n »» ");
            
            
        scanf("%s", conversion);
        
        
        if ( strcmp(kind,"binary") == 0 )
        {
            if ( strcasecmp(conversion, "1") == 0 || strcasecmp(conversion, "1.") == 0 || strcasecmp(conversion, "decimal") == 0 || strcasecmp(conversion, "1. decimal") == 0 || strcasecmp(conversion, "1.decimal") == 0)
                strcpy(conversion,"decimal");
                
            else if ( strcasecmp(conversion, "2") == 0 || strcasecmp(conversion, "2.") == 0 || strcasecmp(conversion, "octal") == 0 || strcasecmp(conversion, "2. octal") == 0 || strcasecmp(conversion, "2.octal") == 0)
                strcpy(conversion, "octal");
                
            else if ( strcasecmp(conversion, "3") == 0 || strcasecmp(conversion, "3.") == 0 || strcasecmp(conversion, "hexadecimal") == 0 || strcasecmp(conversion, "3. hexadecimal") == 0 || strcasecmp(conversion, "3.hexadecimal") == 0)
                strcpy(conversion, "hexadecimal");
                
            else
            {
                puts(" and they ask me why I use robots instead of farmers");
                goto farmer3;
            }    
        }
        
        else if ( strcmp(kind, "decimal") == 0 )
        {
            if  (strcasecmp(conversion, "1" ) == 0 || strcasecmp(conversion, "1." ) == 0 || strcasecmp(conversion, "binary") == 0 || strcasecmp(conversion, "1. binary") == 0 || strcasecmp(conversion, "1.binary") == 0)
                strcpy(conversion, "binary");
                
            else if ( strcasecmp(conversion, "2") == 0 || strcasecmp(conversion, "2.") == 0 || strcasecmp(conversion, "octal") == 0 || strcasecmp(conversion, "2. octal") == 0 || strcasecmp(conversion, "2.octal") == 0)
                strcpy(conversion, "octal");
                
            else if ( strcasecmp(conversion, "3") == 0 || strcasecmp(conversion, "3.") == 0 || strcasecmp(conversion, "hexadecimal") == 0 || strcasecmp(conversion, "3. hexadecimal") == 0 || strcasecmp(conversion, "3.hexadecimal") == 0)
                strcpy(conversion, "hexadecimal");
                
            else {
                puts(" I shouldn't sell nina");
                goto farmer3;
            }    
        }
        
        else if ( strcmp(kind, "octal") == 0 )
        {
            if ( strcasecmp(conversion, "3") == 0 || strcasecmp(conversion, "3.") == 0 || strcasecmp(conversion, "hexadecimal") == 0 || strcasecmp(conversion, "3. hexadecimal") == 0 || strcasecmp(conversion, "3.hexadecimal") == 0)
                strcpy(conversion,"hexadecimal");
        
            else if ( strcasecmp(conversion, "1") == 0 || strcasecmp(conversion, "1.") == 0 || strcasecmp(conversion, "decimal") == 0 || strcasecmp(conversion, "1. decimal") == 0 || strcasecmp(conversion, "1.decimal") == 0)
                strcpy(conversion, "decimal");
                
            else if ( strcasecmp(conversion, "2" ) == 0 || strcasecmp(conversion, "2." ) == 0 || strcasecmp(conversion, "binary") == 0 || strcasecmp(conversion, "2. binary") == 0 || strcasecmp(conversion, "2.binary") == 0)
                strcpy(conversion, "binary");
                
            else
            {
                puts(" look at the bright side, oh yeah you're blind");
                goto farmer3;
            }
        }
        
        else if ( strcmp(kind, "hexadecimal") == 0 )
        {
            if ( strcasecmp(conversion, "3") == 0 || strcasecmp(conversion, "3.") == 0 || strcasecmp(conversion, "octal") == 0 || strcasecmp(conversion, "3. octal") == 0 || strcasecmp(conversion, "3.octal") == 0)
                strcpy(conversion, "octal") ;
                
            else if ( strcasecmp(conversion, "1") == 0 || strcasecmp(conversion, "1.") == 0 || strcasecmp(conversion, "decimal") == 0 || strcasecmp(conversion, "1. decimal") == 0 || strcasecmp(conversion, "1.decimal") == 0)
                strcpy(conversion, "decimal");
                
            else if ( strcasecmp(conversion, "2" ) == 0 || strcasecmp(conversion, "2." ) == 0 || strcasecmp(conversion, "binary") == 0 || strcasecmp(conversion, "2. binary") == 0 || strcasecmp(conversion, "2.binary") == 0)
                strcpy(conversion, "binary");
                
            else
            {
                puts(" uh god I prefer usin' sla... forget it dumbass");
                
                goto farmer3;
            }
        }        
    }
    
    if ( operation == '?' ) 
    {
        do {
            printf("enter your %s number\n »» ", kind);
            scanf(" %s", number1);
        
            
            
            if (number1[0] == '-')
                puts (" oh yeah about that... uh we dont do negative yet soooo yup okay you know what to do");
        
        } while ( number1[0] == '-' );
        
        dnumber1 = todecimal( number1, kind );
        
        if ( strcasecmp(conversion,"binary") == 0 )
            binary (dnumber1, 0, result, operation);
        
        else if ( strcasecmp(conversion,"decimal") == 0 )
           sprintf( result, "%u", dnumber1 );
           
        else if ( strcasecmp(conversion,"octal") == 0 )
            octal (dnumber1, 0, result, operation);
        
        else if ( strcasecmp(conversion,"hexadecimal") == 0 )
            hexadecimal (dnumber1, 0, result, operation);
    }
    
    else
    {
        typo:
        
        do {
            printf (" now enter your two %s numbers sweetpie\n first one:  ", kind);
            
            do {
                key = 0;
                
                scanf(" %s", number1);
                
                if ( strcmp(kind,"binary") == 0 )
                    for (int i = 0; number1[i] != '\0'; i++)
                        key = isBinary(number1);
                        
                if ( key )
                {
                    puts(" sweetheart that's not a binary num wanna change to another numerical form?");
                    scanf(" %s", &answer);
                    
                    if (strcasecmp(answer, "y") == 0 || strcasecmp(answer, "yeah") == 0 || strcasecmp(answer, "yes") == 0 || strcasecmp(answer, "yup") == 0 || strcasecmp(answer, "aha") == 0 || strcasecmp(answer, "1") == 0 )
                    {
                        puts (" you got it sweet face");
                        goto farmer1;
                    }
                    
                    else
                        puts(" alright prettyface re-enter your binary number");
                }    
                
            } while (key);
            
            printf(" now\n second one: ");
            
            do {
                key = 0;
                
                scanf(" %s", number2);
                
                if ( strcmp(kind,"binary") == 0 )
                    key = isBinary(number2);
                    
                if ( key )
                {
                    puts(" sweetheart you wanted binary didn't ya?\n");
                    scanf(" %s", &answer);
                    if (strcasecmp(answer, "n") == 0 || strcasecmp(answer, "nah") == 0 || strcasecmp(answer, "no") == 0 || strcasecmp(answer, "nope") == 0 || strcasecmp(answer, "aa") == 0 || strcasecmp(answer, "0") == 0 )
                    {
                        puts (" okay cute face");
                        
                        goto farmer1;
                    }
                    
                    else
                        puts(" alright pretty face re-enter your binary number");
                }
                
            } while (key);
            
            dnumber1 = todecimal( number1, kind );
            dnumber2 = todecimal( number2, kind );
            
            if ( tolower(operation) == '-' )
                if ( dnumber1 - dnumber2 < 0 )
                    puts (" cutehead it should be a positive combo let's try one more last time\n");
            
            else if ( dnumber1 < 0 || dnumber2 < 0 )
                puts (" sweetie it should be a positive num let's try again cutie\n");
        
        } while ( dnumber1 < 0 || dnumber2 < 0 );
        
        if ( strcmp(kind, "octal") == 0 )
            octal (dnumber1, dnumber2, result, operation);
            
        else if ( strcmp(kind, "decimal") == 0 )
            decimal (dnumber1, dnumber2, result, operation);
        
        else if ( strcmp(kind, "hexadecimal") == 0 )
            hexadecimal (dnumber1, dnumber2, result, operation);
        
        else if ( strcmp(kind,"binary") == 0 )
            binary (dnumber1, dnumber2, result, operation);
    }
    
    puts(result);
    
    return 0;
}