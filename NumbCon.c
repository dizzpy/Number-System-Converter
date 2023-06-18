#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>  // For the sleep() function

// ANSI escape codes for text color
#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_RESET   "\x1b[0m"


// Function declarations
void mainText(void); // main text menu
void checkOption(void); //check option 
void exitProgram(void); // Exit program

void binToOctal(void); // Binary
void binToDeci(void);
void binToHexa(void);

void octToBinary(void); // Octal
void octToDecimal(void);
void octToHexa(void);

void deciToOctal(void); // Decimal
void deciToBinary(void);
void deciToHexa(void);

void hexaToOctal(void); // Hexadecimal
void hexaToDecimal(void);
void hexaToBinary(void);

void developerInfo(void);//developer Information
void printTypewriterEffect(const char* str);//typewriter effect in developer information


//main function start( -- programme start is here -- )
int main() {

    //variabals
    int choise;
    
    mainText();//called main text function
    printf("Please enter the number corresponding to the number system conversion you wish to perform : ");
    scanf("%d", &choise);

    //option check
    switch (choise)
    {
    case 1:
        binToOctal();
        break;
    case 2:
        binToDeci();
        break;
    case 3:
        binToHexa();
        break;
    case 4:
        octToBinary();
        break;
    case 5:
        octToDecimal();
        break;
    case 6:
        octToHexa();
        break;
    case 7:
        deciToOctal();
        break;
    case 8:
        deciToBinary();
        break;
    case 9:
        deciToHexa();
        break;
    case 10:
        hexaToOctal();
        break;
    case  11:
        hexaToDecimal();
        break;
    case 12:
        hexaToBinary();
        break;
    case 100:
        exitProgram();
        break;
    case 101:
        developerInfo();
        break;
    
    default:
        printf("Invalid Number!\n");
        break;
    }
    
    return 0 ;
}



//main test print function
void mainText(){
    printf("\n\n");
    printTypewriterEffect("\t -----| \033[32m Number System Converter \033[0m |-----\n\n");


    printf("Please select the number system you would like to convert from,\nand enter the corresponding number for your choice.\n\n");
    printf("    + \033[1mBinary Number System\033[0m :\n\n");
    printf("\t1. Binary -> Octal\n");
    printf("\t2. Binary -> Decimal\n");
    printf("\t3. Binary -> HexaDecimal\n");

    printf("\n\n");

    printf("    + \033[1mOctal Number System\033[0m :\n\n");
    printf("\t4. Octal -> Binary\n");
    printf("\t5. Octal -> Decimal\n");
    printf("\t6. Octal -> HexaDecimal\n");

    printf("\n\n");

    printf("    + \033[1mDecimal Number System\033[0m :\n\n");
    printf("\t7. Decimal -> Octal\n");
    printf("\t8. Decimal -> Binary\n");
    printf("\t9. Decimal -> HexaDecimal\n");

    printf("\n\n");

    printf("    + \033[1mHexaDecimal Number System\033[0m :\n\n");
    printf("\t10. HexaDecimal -> Octal\n");
    printf("\t11. HexaDecimal -> Decimal\n");
    printf("\t12. HexaDecimal -> Binary\n");

    printf("\n\n");

    printf("    + \033[1mOther Commands\033[0m :\n\n");
    printf("\t100. Exit Programme\n");
    printf("\t101. Developer Information\n");

    printf("\n\n");
}


//binary nuber system conversion
void binToOctal(){// 1 binary to octal

    long long binary, tempBinary;
    int digit, octal = 0, position = 0;
    int bcmenu;

    printf("\n\n");
    printf("\t\033[43m   Binary to Octal Conversion  \033[0m \n\n");
    printf("\033[31m      ! Enter Only 1 and 0. bcz Binary number system have only two digits !\033[0m\n\n");

    printf("Enter a binary number: ");
    scanf("%lld", &binary);

    // check binary input
    tempBinary = binary;
    while (tempBinary != 0) {
        digit = tempBinary % 10;
        if (digit != 0 && digit != 1) {
            printf("\n\n\t\033[31m ----- ! Invalid Input Enter a Valid Binary Number Again ! ----- \033[0m\n\n");
            binToOctal();
            return;  // Removed the 'return 0;' statement
        }
        tempBinary /= 10;
    }

    // Converting binary to octal
    tempBinary = binary;
    while (tempBinary != 0) {
        int group = 0;
        int i;
        for (i = 0; i < 3; i++) {
            digit = tempBinary % 10;
            group += digit * pow(2, i);
            tempBinary /= 10;
        }
        octal += group * pow(10, position);
        position++;
    }

    printf("\n\n\t\033[32mHere is the Octal value : %d\n\n\n\033[0m", octal); //print output


    //repeat again
    printf("    + \033[1mSelect Option to Continue\033[0m :\n\n");
    printf("\t98.  Converter Again Binary to Octal\n");
    printf("\t99.  Main Menu\n");
    printf("\t100. Exit Program\n");

    printf("\n\n\nPlease enter the number corresponding to the option : ");
    scanf("%d", &bcmenu);


    switch (bcmenu)
    {
    case 98:
        binToOctal();
        break;

    case 99:
        main();
        break;

    case 100:
        exitProgram();
        break;
            
    default:
        printf("\033[31m Invalid Input ! \033[0m\n\n");
        break;
    }
    
}
void binToDeci(){// 2 binary to decimal

    long long binary;
    int decimal = 0, position = 0, digit;
    int bdmenu;

    printf("\n\n");
    printf("\t\033[43m   Binary to Decimal Conversion  \033[0m \n\n");
    printf("\033[31m      ! Enter Only 1 and 0. Binary numbers consist of only two digits !\033[0m\n\n");

    printf("Enter a binary number: ");
    scanf("%lld", &binary);

    // Validating the binary input
    long long tempBinary = binary;
    while (tempBinary != 0) {
        digit = tempBinary % 10;
        if (digit != 0 && digit != 1) {
            printf("\n\n\t\033[31m ----- ! Invalid Input Enter a Valid Binary Number Again ! ----- \033[0m\n\n");
            binToDeci();
            return;
        }
        tempBinary /= 10;
    }

    // Converting binary to decimal
    tempBinary = binary;
    while (tempBinary != 0) {
        digit = tempBinary % 10;
        decimal += digit * pow(2, position);
        position++;
        tempBinary /= 10;
    }

    printf("\n\n\t\033[32mHere is the Decimal value: %d\n\n\033[0m", decimal);

    //repeat
    printf("    + \033[1mSelect Option to Continue\033[0m :\n\n");
    printf("\t98.  Converter Again Binary to Octal\n");
    printf("\t99.  Main Menu\n");
    printf("\t100. Exit Program\n");

    printf("\n\n\nPlease enter the number corresponding to the option : ");
    scanf("%d", &bdmenu);


    switch (bdmenu)
    {
    case 98:
        binToDeci();
        break;

    case 99:
        main();
        break;

    case 100:
        exitProgram();
        break;
            
    default:
        printf("\033[31m Invalid Input ! \033[0m\n\n");
        break;
    }

}
void binToHexa(){// 3 binary to hexadeciaml
    long long binary;
    int position = 0, digit;
    char hexadecimal[50];
    int bhmenu;

    printf("\n\n");
    printf("\t\033[43m   Binary to Hexadecimal Conversion  \033[0m \n\n");
    printf("\033[31m      ! Enter Only 1 and 0. Binary numbers consist of only two digits !\033[0m\n\n");

    printf("Enter a binary number: ");
    scanf("%lld", &binary);

    // Validating the binary input
    long long tempBinary = binary;
    while (tempBinary != 0) {
        digit = tempBinary % 10;
        if (digit != 0 && digit != 1) {
            printf("\n\n\t\033[31m ----- ! Invalid Input Enter a Valid Binary Number Again ! ----- \033[0m\n\n");
            binToHexa();
            return;
        }
        tempBinary /= 10;
    }

    // Converting binary to hexadecimal
    tempBinary = binary;
    while (tempBinary != 0) {
        int group = 0;
        int i;
        for (i = 0; i < 4; i++) {
            digit = tempBinary % 10;
            group += digit * pow(2, i);
            tempBinary /= 10;
        }
        if (group < 10)
            hexadecimal[position++] = group + '0';
        else
            hexadecimal[position++] = group - 10 + 'A';
    }
    hexadecimal[position] = '\0';

    // Reversing the hexadecimal string
    int len = position;
    int i;
    for (i = 0; i < len / 2; i++) {
        char temp = hexadecimal[i];
        hexadecimal[i] = hexadecimal[len - i - 1];
        hexadecimal[len - i - 1] = temp;
    }

    printf("\n\n\t\033[32mHere is the Hexadecimal value: %s\n\n\033[0m", hexadecimal);

    printf("    + \033[1mSelect Option to Continue\033[0m :\n\n");
    printf("\t98.  Converter Again Binary to HexaDecimal\n");
    printf("\t99.  Main Menu\n");
    printf("\t100. Exit Program\n");

    printf("\n\n\nPlease enter the number corresponding to the option : ");
    scanf("%d", &bhmenu);


    switch (bhmenu)
    {
    case 98:
        binToHexa();
        break;

    case 99:
        main();
        break;

    case 100:
        exitProgram();
        break;
            
    default:
        printf("\033[31m Invalid Input ! \033[0m\n\n");
        break;
    }
}


//octal number system conversion
void octToBinary(){// 4 octal to binary


    char octal[20];
    int cmenu;

    printf("\n\n");
    printf("\t\033[43m   Octal to Binary Conversion  \033[0m \n\n");
    printf("\033[31m      ! Enter Only 0 to 7. bcz Octal number system have only 0 to 7 !\033[0m\n\n");


    printf("Enter an Octal Number : ");
    scanf("%s", octal);

    int length = strlen(octal);
    bool isValid = true;

    // Check if the octal number is valid
    for (int i = 0; i < length; i++) {
        if (octal[i] < '0' || octal[i] > '7') {
            isValid = false;
            break;
        }
    }

    if (!isValid) {
        printf("\n\n\t\033[31m ----- ! Invalid Input Enter a Valid Octal Number Again ! ----- \033[0m\n\n");
        octToBinary();
    }

    printf("\n\n\033[32m Here is the Binary Value : ");

// Convert octal to binary
for (int i = 0; i < length; i++) {
    switch (octal[i]) {
        case '0':
            printf("\033[32m000");
            break;
        case '1':
            printf("\033[32m001");
            break;
        case '2':
            printf("\033[32m010");
            break;
        case '3':
            printf("\033[32m011");
            break;
        case '4':
            printf("\033[32m100");
            break;
        case '5':
            printf("\033[32m101");
            break;
        case '6':
            printf("\033[32m110");
            break;
        case '7':
            printf("\033[32m111");
            break;
    }
    printf("\033[0m"); // Reset text color to default
}

    printf("\n\n");
    printf("\n    + \033[1mSelect Option to Continue\033[0m :\n\n");
    printf("\t98.  Converter Again Octal to Binary\n");
    printf("\t99.  Main Menu\n");
    printf("\t100. Exit Program\n");

    printf("\n\n\nPlease enter the number corresponding to the option : ");
    scanf("%d", &cmenu);


    switch (cmenu)
    {
    case 98:
        octToBinary();
        break;

    case 99:
        main();
        break;

    case 100:
        exitProgram();
        break;
            
    default:
        printf("\033[31m Invalid Input ! \033[0m\n\n");
        break;
    }
}
void octToDecimal(){// 5 Octal to decimal
    int octal, decimal = 0, base = 1;
    int odmenu;

    printf("\n\n");
    printf("\t\033[43m   Octal to Decimal Conversion  \033[0m \n\n");
    printf("\033[31m      ! Enter Only 0 and 7. bcz Octal number system have only 0 to 7 !\033[0m\n\n");

    printf("Enter an octal number: ");
    scanf("%d", &octal);

    // Validate octal number
    int temp = octal;
    while (temp > 0) {
        int digit = temp % 10;
        if (digit >= 8) {
            printf("\n\n\t\033[31m----- ! Invalid Input Enter a Valid Octal Number Again ! -----\033[0m\n\n");
            octToDecimal();
            return ;
        }
        temp /= 10;
    }

    // Convert octal to decimal
    while (octal > 0) {
        int remainder = octal % 10;
        decimal += remainder * base;
        octal /= 10;
        base *= 8;
    }

    // Print decimal value
    printf("\n\n\t\033[32mHere is the Decimal value : %d\n\n\n\033[0m", decimal);

    // Repeat options
    printf("    + \033[1mSelect Option to Continue\033[0m :\n\n");
    printf("\t98.  Converter Again Octal to Decimal\n");
    printf("\t99.  Main Menu\n");
    printf("\t100. Exit Program\n");

    // Menu input
    printf("\n\n\nPlease enter the number corresponding to the option : ");
    scanf("%d", &odmenu);

    switch (odmenu) {
        case 98:
            octToDecimal();
            break;

        case 99:
            main();
            break;

        case 100:
            exitProgram();
            break;

        default:
            printf("\033[31mInvalid Input!\033[0m\n\n");
            break;
    }

    return ;
}
void octToHexa(){// 6 octal to hexadecimal

    char octal[20];
    int ohmenu;

    printf("\n\n");
    printf("\t\033[43m   Octal to HexaDecimal Conversion  \033[0m \n\n");
    printf("\033[31m      ! Enter Only 0 and 7. bcz Octal number system have only 0 to 7 !\033[0m\n\n");


    printf("Enter an octal number: ");
    scanf("%s", octal);

    int length = strlen(octal);
    bool isValid = true;

    // Check if the octal number is valid
    for (int i = 0; i < length; i++) {
        if (octal[i] < '0' || octal[i] > '7') {
            isValid = false;
            break;
        }
    }

    if (!isValid) {
        printf("\n\n\t\033[31m----- ! Invalid Input Enter a Valid Octal Number Again ! -----\033[0m\n\n");
        octToHexa();
        return ;
    }

    // Convert octal to decimal
    int decimal = 0;
    int base = 1;
    for (int i = length - 1; i >= 0; i--) {
        decimal += (octal[i] - '0') * base;
        base *= 8;
    }

    // Convert decimal to hexadecimal
    char hexadecimal[20];
    int index = 0;
    while (decimal > 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hexadecimal[index] = '0' + remainder;
        } else {
            hexadecimal[index] = 'A' + (remainder - 10);
        }
        decimal /= 16;
        index++;
    }
    hexadecimal[index] = '\0';

    // Reverse the hexadecimal string
    int start = 0;
    int end = index - 1;
    while (start < end) {
        char temp = hexadecimal[start];
        hexadecimal[start] = hexadecimal[end];
        hexadecimal[end] = temp;
        start++;
        end--;
    }

    printf("\n\n\t\033[32mHexadecimal representation: %s\n\n\n\033[0m", hexadecimal);

    //repeat option
    printf("    + \033[1mSelect Option to Continue\033[0m :\n\n");
    printf("\t98.  Converter Again Octal to HexaDecimal\n");
    printf("\t99.  Main Menu\n");
    printf("\t100. Exit Program\n");

    // Menu input
    printf("\n\n\nPlease enter the number corresponding to the option : ");
    scanf("%d", &ohmenu);

    switch (ohmenu) {
        case 98:
            octToHexa();
            break;

        case 99:
            main();
            break;

        case 100:
            exitProgram();
            break;

        default:
            printf("\033[31mInvalid Input!\033[0m\n\n");
            break;
    }

}


//decimal number system conversion
void deciToOctal(){// 7 decimal to octal
    int decimal;
    int domenu;

    printf("\n\n");
    printf("\t\033[43m   Decimal to Octal Conversion  \033[0m \n\n");
    printf("\033[31m      ! Enter Only decimal values !\033[0m\n\n");

    printf("Enter a decimal number : ");

    if (scanf("%d", &decimal) != 1) {
        printf("\n\n\t\033[31m ----- ! Invalid Input Enter a Valid Decimal Number Again ! ----- \033[0m\n\n");
        deciToOctal();
        return ;
    }

    // Check for any remaining characters in the input
    char remaining;
    if (scanf("%c", &remaining) != EOF && !isspace(remaining)) {
        printf("\n\n\t\033[31m ----- ! Invalid Input Enter a Valid Decimal Number Again ! ----- \033[0m\n\n");
        deciToOctal();
        return ;

    }

    int octal[20];
    int index = 0;

    // Convert decimal to octal
    while (decimal > 0) {
        octal[index] = decimal % 8;
        decimal /= 8;
        index++;
    }

    // Print the octal representation in reverse order
    printf("\n\n\t\033[32mHere is the Octal value : ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", octal[i]);
    }
    printf("\n\n\n\033[0m");

    //repeat again
    printf("    + \033[1mSelect Option to Continue\033[0m :\n\n");
    printf("\t98.  Converter Again Decimal to Octal\n");
    printf("\t99.  Main Menu\n");
    printf("\t100. Exit Program\n");

    printf("\n\n\nPlease enter the number corresponding to the option : ");
    scanf("%d", &domenu);


    switch (domenu)
    {
    case 98:
        deciToOctal();
        break;

    case 99:
        main();
        break;

    case 100:
        exitProgram();
        break;
            
    default:
        printf("\033[31m Invalid Input ! \033[0m\n\n");
        break;
    }


}
void deciToBinary(){// 8 decimal to binary
    int decimal;
    int dbmenu;

    printf("\n\n");
    printf("\t\033[43m   Decimal to Binary Conversion  \033[0m \n\n");
    printf("\033[31m      ! Enter Only decimal value !\033[0m\n\n");


    printf("Enter a decimal number : ");
    if (scanf("%d", &decimal) != 1) {
        printf("\n\n\t\033[31m ----- ! Invalid Input Enter a Valid Decimal Number Again ! ----- \033[0m\n\n");
        deciToBinary();
        return ;
    }

     if (decimal < 0) {
        printf("\n\n\t\033[31m ----- ! Invalid Input Enter a Valid Decimal Number Again ! ----- \033[0m\n\n");
        deciToBinary();
        return ;
    }

    if (decimal == 0) {
        printf("\n\n\t\033[32mHere is the Binary Value : 0\n\033[0m");
    } else {
        int binary[32];
        int index = 0;

        while (decimal > 0) {
            binary[index] = decimal % 2;
            decimal /= 2;
            index++;
        }

        printf("\n\n\t\033[32mHere is the Binary Value : ");
        for (int i = index - 1; i >= 0; i--) {
            printf("\033[32m%d\033[0m", binary[i]);
        }
        printf("\n\n\n");
    }


    //repeat again
    printf("    + \033[1mSelect Option to Continue\033[0m :\n\n");
    printf("\t98.  Converter Again Decimal to Binary\n");
    printf("\t99.  Main Menu\n");
    printf("\t100. Exit Program\n");

    printf("\n\n\nPlease enter the number corresponding to the option : ");
    scanf("%d", &dbmenu);


    switch (dbmenu)
    {
    case 98:
        deciToBinary();
        break;

    case 99:
        main();
        break;

    case 100:
        exitProgram();
        break;
            
    default:
        printf("\033[31m Invalid Input ! \033[0m\n\n");
        break;
    }

}
void deciToHexa(){// 9 decimal to hexadecimal
    int decimal;
    int dhmenu;

    printf("\n\n");
    printf("\t\033[43m Decimal to HexaDecimal Conversion  \033[0m \n\n");
    printf("\033[31m      ! Enter Only Decimal Value !\033[0m\n\n");


    printf("Enter a decimal number: ");
    if (scanf("%d", &decimal) != 1) {
        printf("\n\n\t\033[31m ----- ! Invalid Input Enter a Valid Decimal Number Again ! ----- \033[0m\n\n");
        deciToHexa();
        return ;
    }

    if (decimal < 0) {
        printf("\n\n\t\033[31m ----- ! Invalid Input Enter a Valid Decimal Number Again ! ----- \033[0m\n\n");
        deciToHexa();
        return ;
    }

    if (decimal == 0) {
        printf("\n\n\t\033[32mHexadecimal representation: 0\033[0m");
    }

    char hexadecimal[20];
    int index = 0;

    while (decimal > 0) {
        int remainder = decimal % 16;

        if (remainder < 10) {
            hexadecimal[index] = remainder + '0';
        } else {
            hexadecimal[index] = remainder - 10 + 'A';
        }

        decimal /= 16;
        index++;
    }

    printf("\n\n\t\033[32mHexadecimal representation: \033[0m");
    for (int i = index - 1; i >= 0; i--) {
        printf("\033[32m%c\033[0m", hexadecimal[i]);
    }

    printf("\n\n\n");


    //repeat again
    printf("    + \033[1mSelect Option to Continue\033[0m :\n\n");
    printf("\t98.  Converter Again Decimal to HexaDesimal\n");
    printf("\t99.  Main Menu\n");
    printf("\t100. Exit Program\n");

    printf("\n\n\nPlease enter the number corresponding to the option : ");
    scanf("%d", &dhmenu);


    switch (dhmenu)
    {
    case 98:
        deciToHexa();
        break;

    case 99:
        main();
        break;

    case 100:
        exitProgram();
        break;
            
    default:
        printf("\033[31m Invalid Input ! \033[0m\n\n");
        break;
    }

}


//hexa decimal number sysytem conversion
void hexaToOctal(){// 10 hexadecimal to octal
    char hexadecimal[20];
    int homenu;

    printf("\n\n");
    printf("\t\033[43m   HexaDecimal to Octal Conversion  \033[0m \n\n");
    printf("\033[31m      ! Enter Only Hexa Decimal Values !\033[0m\n\n");


    printf("Enter a hexadecimal number: ");
    if (scanf("%s", hexadecimal) != 1) {
        printf("\n\n\t\033[31m ----- ! Invalid Input Enter a Valid HexaDecimal Number Again ! ----- \033[0m\n\n");
        hexaToOctal();
        return ;
    }

    int length = strlen(hexadecimal);
    for (int i = 0; i < length; i++) {
        if (!((hexadecimal[i] >= '0' && hexadecimal[i] <= '9') || (hexadecimal[i] >= 'A' && hexadecimal[i] <= 'F') || (hexadecimal[i] >= 'a' && hexadecimal[i] <= 'f'))) {
            printf("\n\n\t\033[31m ----- ! Invalid Input Enter a Valid HexaDecimal Number Again ! ----- \033[0m\n\n");
            hexaToOctal();
            return ;
        }
    }

    long long decimal = strtol(hexadecimal, NULL, 16);

    int octal[20];
    int index = 0;

    while (decimal > 0) {
        octal[index] = decimal % 8;
        decimal /= 8;
        index++;
    }

    printf("\n\n\t\033[32mOctal representation: ");
    if (index == 0) {
        printf("\033[32m0\033[0m");
        printf("\n\n\n");
    } else {
        for (int i = index - 1; i >= 0; i--) {
            printf("\033[32m%d\033[0m", octal[i]);
        }
    }
    printf("\n\n\n");


    //repeat again
    printf("    + \033[1mSelect Option to Continue\033[0m :\n\n");
    printf("\t98.  Converter Again HexaDecimal to Octal\n");
    printf("\t99.  Main Menu\n");
    printf("\t100. Exit Program\n");

    printf("\n\n\nPlease enter the number corresponding to the option : ");
    scanf("%d", &homenu);


    switch (homenu)
    {
    case 98:
        hexaToOctal();
        break;

    case 99:
        main();
        break;

    case 100:
        exitProgram();
        break;
            
    default:
        printf("\033[31m Invalid Input ! \033[0m\n\n");
        break;
    }

}
void hexaToDecimal(){// 11 hexadecimal to decimal
    char hexadecimal[20];
    int hddmenu;


    printf("\n\n");
    printf("\t\033[43m   HexaDecimal to Decimal Conversion  \033[0m \n\n");
    printf("\033[31m      ! Enter Only Hexa Decimal Values !\033[0m\n\n");


    printf("Enter a hexadecimal number: ");
    if (scanf("%s", hexadecimal) != 1) {
        printf("\n\n\t\033[31m ----- ! Invalid Input Enter a Valid HexaDecimal Number Again ! ----- \033[0m\n\n");
        hexaToDecimal();
        return ;
    }

    int length = strlen(hexadecimal);
    for (int i = 0; i < length; i++) {
        if (!((hexadecimal[i] >= '0' && hexadecimal[i] <= '9') || (hexadecimal[i] >= 'A' && hexadecimal[i] <= 'F') || (hexadecimal[i] >= 'a' && hexadecimal[i] <= 'f'))) {
            printf("\n\n\t\033[31m ----- ! Invalid Input Enter a Valid HexaDecimal Number Again ! ----- \033[0m\n\n");
            hexaToDecimal();
            return ;
        }
    }

    long long decimal = strtol(hexadecimal, NULL, 16);

    printf("\n\n\t\033[32mDecimal representation: %lld\n\n\n\033[0m", decimal);



    //repeat again
    printf("    + \033[1mSelect Option to Continue\033[0m :\n\n");
    printf("\t98.  Converter Again HexaDecimal to Decimal\n");
    printf("\t99.  Main Menu\n");
    printf("\t100. Exit Program\n");

    printf("\n\n\nPlease enter the number corresponding to the option : ");
    scanf("%d", &hddmenu);


    switch (hddmenu)
    {
    case 98:
        hexaToDecimal();
        break;

    case 99:
        main();
        break;

    case 100:
        exitProgram();
        break;
            
    default:
        printf("\033[31m Invalid Input ! \033[0m\n\n");
        break;
    }


}
void hexaToBinary(){// 12 hexadecimal to binary
    char hexadecimal[20];
    int hbmenu;


    printf("\n\n");
    printf("\t\033[43m   HexaDecimal to Binary Conversion  \033[0m \n\n");
    printf("\033[31m      ! Enter Only Hexa Decimal Values ! \033[0m\n\n");


    printf("Enter a hexadecimal number: ");
    if (scanf("%s", hexadecimal) != 1) {
        printf("\n\n\t\033[31m ----- ! Invalid Input Enter a Valid HexaDecimal Number Again ! ----- \033[0m\n\n");
        hexaToBinary();
        return ;
    }

    int length = strlen(hexadecimal);
    for (int i = 0; i < length; i++) {
        if (!((hexadecimal[i] >= '0' && hexadecimal[i] <= '9') || (hexadecimal[i] >= 'A' && hexadecimal[i] <= 'F') || (hexadecimal[i] >= 'a' && hexadecimal[i] <= 'f'))) {
            printf("\n\n\t\033[31m ----- ! Invalid Input Enter a Valid HexaDecimal Number Again ! ----- \033[0m\n\n");
            hexaToBinary();
            return ;
        }
    }

    long long decimal = strtol(hexadecimal, NULL, 16);

    int binary[64];
    int index = 0;

    while (decimal > 0) {
        binary[index] = decimal % 2;
        decimal /= 2;
        index++;
    }

    printf("\n\n\t\033[32mBinary representation: \033[0m");
    if (index == 0) {
        printf("\033[32m0\033[0m");
    } else {
        for (int i = index - 1; i >= 0; i--) {
            printf("\033[32m%d\033[0m", binary[i]);

        }
    }
    printf("\n\n\n");


    //repeat again
    printf("    + \033[1mSelect Option to Continue\033[0m :\n\n");
    printf("\t98.  Converter Again HexaDecimal to Binary\n");
    printf("\t99.  Main Menu\n");
    printf("\t100. Exit Program\n");

    printf("\n\n\nPlease enter the number corresponding to the option : ");
    scanf("%d", &hbmenu);


    switch (hbmenu)
    {
    case 98:
        hexaToBinary();
        break;

    case 99:
        main();
        break;

    case 100:
        exitProgram();
        break;
            
    default:
        printf("\033[31m Invalid Input ! \033[0m\n\n");
        break;
    }
}





    //other functions
//exit programme function
void exitProgram() {
    char animationChars[] = { '|', '/', '-', '\\' };

    int i;
    for (i = 0; i < 10; i++) {
        switch (i % 4) {
    case 0:
        printf("\rExiting the program.. %c", animationChars[i % 4]);
        break;
    case 1:
        printf("\rExiting the program.. %c", animationChars[i % 4]);
        break;
    case 2:
        printf("\rExiting the program.. %c", animationChars[i % 4]);
        break;
    case 3:
        printf("\rExiting the program.. %c", animationChars[i % 4]);
        break;
}


         fflush(stdout);
        usleep(170000);  // Sleep for 500 milliseconds
    }
     printf("\033[2J");  // Clear the screen
     fflush(stdout);     // Clear the Screen

    printf("\r%sExit Successfully !%s      \n", COLOR_GREEN, COLOR_RESET);
    
}

// Developer Information function
void developerInfo() {
    int devMenu;

    printf("\n\n\n");
    printTypewriterEffect(COLOR_GREEN "  -----|  Developer Information  |-----  \n" COLOR_RESET);
    printf("\n");
    printTypewriterEffect("Program Developer : Dizzpy \n");
    printf("\n");
    printTypewriterEffect(COLOR_YELLOW "Description:\n" COLOR_RESET);
    printTypewriterEffect("This program is a sleek and efficient number system converter designed to make conversion between binary, octal, decimal, and hexadecimal number systems a breeze.\n");
    printf("\n");
    printTypewriterEffect(COLOR_YELLOW "Features:\n" COLOR_RESET);
    printTypewriterEffect("- Conversion between various number systems\n");
    printTypewriterEffect("- Intuitive and user-friendly interface\n");
    printTypewriterEffect("- Fast and accurate conversion algorithms\n");
    printf("\n");
    printTypewriterEffect(COLOR_YELLOW "Future Enhancements:\n" COLOR_RESET);
    printTypewriterEffect("- Addition of more number systems\n");
    printTypewriterEffect("- Enhanced error handling and input validation\n");
    printTypewriterEffect("- Advanced arithmetic operations within a specific number system\n");
    printf("\n");
    printTypewriterEffect(COLOR_YELLOW "Contact:\n" COLOR_RESET);
    printTypewriterEffect("Your feedback is valuable! If you have any questions, suggestions, or issues, feel free to reach out to us on [GitHub](https://github.com/dizzpy).\n");
    printf("\n");
    printTypewriterEffect("Thank you for using our number system converter!\n");
    printf("\n\n");

    // Go to back menu
    printf("    + \033[1mSelect Option to Continue\033[0m :\n\n");
    printf("\t99.  Main Menu\n");
    printf("\t100. Exit Program\n");

    printf("\n\n\nPlease enter the number corresponding to the option: ");
    scanf("%d", &devMenu);

    switch (devMenu) {
        case 99:
            main();
            break;

        case 100:
            exitProgram();
            break;
            
        default:
            printf("\033[31m Invalid Input! \033[0m\n\n");
            break;
    }
}

// printTypewriterEffect function
void printTypewriterEffect(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        putchar(str[i]);
        fflush(stdout);  // Flush the output buffer to display the character immediately
        usleep(20000);   // Delay in microseconds (adjust as needed)
    }
}




