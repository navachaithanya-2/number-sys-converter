#include <stdio.h>
#include <stdlib.h>

char* dectobin(int x) {
    static char bin[33];
    int i = 0;
    int j;
    char temp;

    if (x == 0) {
        bin[0] = '0';
        bin[1] = '\0';
        return bin;
    }

    while (x > 0) {
        bin[i++] = (char)((x % 2) + '0');
        x /= 2;
    }
    bin[i] = '\0';

    for (j = 0; j < i / 2; j++) {
        temp = bin[j];
        bin[j] = bin[i - j - 1];
        bin[i - j - 1] = temp;
    }
    return bin;
}

int dectoocta(int x) {
    if (x < 8) {
        return x;
    }
    return (x % 8) + 10 * dectoocta(x / 8);
}

char* dectohexa(int x) {
    static char hex[33];
    int i = 0;
    int j;
    char temp;

    if (x == 0) {
        hex[0] = '0';
        hex[1] = '\0';
        return hex;
    }

    while (x > 0) {
        int rem = x % 16;
        if (rem < 10) {
            hex[i++] = (char)(rem + '0');
        } else {
            hex[i++] = (char)(rem - 10 + 'A');
        }
        x /= 16;
    }
    hex[i] = '\0';

    for (j = 0; j < i / 2; j++) {
        temp = hex[j];
        hex[j] = hex[i - j - 1];
        hex[i - j - 1] = temp;
    }
    return hex;
}

int bintodec(int x) {
    if (x == 0) 
		return 0;
    if (x == 1) 
		return 1;
    return (x % 10) + 2 * bintodec(x / 10);
}

int bintoocta(int x) {
    return dectoocta(bintodec(x));
}

char* bintohexa(int x) {
    return dectohexa(bintodec(x));
}

int octatodec(int x) {
    if (x < 8) {
        return x;
    }
    return (x % 10) + 8 * octatodec(x / 10);
}

char* octatobin(int x) {
    return dectobin(octatodec(x));
}

char* octatohexa(int x) {
    return dectohexa(octatodec(x));
}

int hexatodec(char *hex) {
    int dec = 0;
    int i;

    for (i = 0; hex[i] != '\0'; i++) {
        char ch = hex[i];
        int val;

        if (ch >= '0' && ch <= '9') {
            val = ch - '0';
        } else if (ch >= 'A' && ch <= 'F') {
            val = ch - 'A' + 10;
        } else if (ch >= 'a' && ch <= 'f') {
            val = ch - 'a' + 10;
        } else {
            return -1;
        }

        dec = dec * 16 + val;
    }
    return dec;
}

char* hexatobin(char *x) {
    return dectobin(hexatodec(x));
}

int hexatoocta(char *x) {
    return dectoocta(hexatodec(x));
}

int main(void) {
    int inputchoice, outputchoice;
    int inputno;
    char hexinput[20];

    printf("===========================\n");
    printf("  Number System Converter  \n");
    printf("===========================\n");

    printf("Enter the Source Number System\n");
    printf("1. Decimal(Base 10)\n2. Binary(Base 2)\n3. Octal(Base 8)\n4. Hexadecimal(Base 16)\n");
    printf("Enter choice(1-4): ");
    if (scanf("%d", &inputchoice) != 1) return 1;

    printf("Enter the Target Number System\n");
    printf("1. Decimal(Base 10)\n2. Binary(Base 2)\n3. Octal(Base 8)\n4. Hexadecimal(Base 16)\n");
    printf("Enter choice(1-4): ");
    if (scanf("%d", &outputchoice) != 1) return 1;

    switch(inputchoice) {
        case 1:
            printf("Enter Decimal number: ");
            scanf("%d", &inputno);
            switch(outputchoice) {
                case 1: 
					printf("Result: %d\n", inputno); 
					break;
                case 2: 
					printf("Result: %s\n", dectobin(inputno)); 
					break;
                case 3: 
					printf("Result: %d\n", dectoocta(inputno)); 
					break;
                case 4: 
					printf("Result: %s\n", dectohexa(inputno)); 
					break;
                default: 
					printf("Invalid output choice.\n"); 
					break;
            }
            break;

        case 2:
            printf("Enter Binary number: ");
            scanf("%d", &inputno);
            switch(outputchoice) {
                case 1: 
					printf("Result: %d\n", bintodec(inputno)); 
					break;
                case 2: 
					printf("Result: %d\n", inputno); 
					break;
                case 3: 
					printf("Result: %d\n", bintoocta(inputno)); 
					break;
                case 4: 
					printf("Result: %s\n", bintohexa(inputno)); 
					break;
                default: 
					printf("Invalid output choice.\n"); 
					break;
            }
            break;

        case 3:
            printf("Enter Octal number: ");
            scanf("%d", &inputno);
            switch(outputchoice) {
                case 1: 
					printf("Result: %d\n", octatodec(inputno)); 
					break;
                case 2: 
					printf("Result: %s\n", octatobin(inputno)); 
					break;
                case 3: 
					printf("Result: %d\n", inputno); 
					break;
                case 4: 
					printf("Result: %s\n", octatohexa(inputno)); 
					break;
                default: 
					printf("Invalid output choice.\n"); 
					break;
            }
            break;

        case 4:
            printf("Enter Hexadecimal number: ");
            scanf("%19s", hexinput);
            switch(outputchoice) {
                case 1: 
					printf("Result: %d\n", hexatodec(hexinput)); 
					break;
                case 2: 
					printf("Result: %s\n", hexatobin(hexinput)); 
					break;
                case 3: 
					printf("Result: %d\n", hexatoocta(hexinput)); 
					break;
                case 4: 
					printf("Result: %s\n", hexinput); 
					break;
                default: 
					printf("Invalid output choice.\n"); 
					break;
            }
            break;

        default:
            printf("Invalid source choice.\n");
            break;
    }

    return 0;
}
