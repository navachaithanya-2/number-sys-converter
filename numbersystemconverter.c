#include <stdio.h>

int dectobin(int x){
	if (x == 0){
		return 0;
	}
	else if (x == 1){
		return 1;
	}
	else{
		return (x%2)+10*dectobin(x/2);
	}
}

int dectoocta(int x){
	if (x==0){
		return 0;
	}
	else if(x==1){
		return 1;
	}
	else if(x==2){
		return 2;
	}
	else if(x==3){
		return 3;
	}
	else if(x==4){
		return 4;
	}
	else if(x==5){
		return 5;
	}
	else if(x==6){
		return 6;
	}
	else if(x==7){
		return 7;
	}
	else{
		return (x%8)+10*dectoocta(x/8);
	}
}

char* dectohexa(int x) {
    static char hex[33];
    int i = 0;

    if (x == 0) {
        hex[0] = '0';
        hex[1] = '\0';
        return hex;
    }

    while (x > 0) {
        int rem = x % 16;
        if (rem < 10) {
            hex[i++] = rem + '0';
        } else {
            hex[i++] = rem - 10 + 'A';
        }
        x /= 16;
    }
    hex[i] = '\0';

    for (int j = 0; j < i / 2; j++) {
        char temp = hex[j];
        hex[j] = hex[i - j - 1];
        hex[i - j - 1] = temp;
    }

    return hex;
}

int bintodec(int x){
	if (x==0){
		return 0;
	}
	else if(x==1){
		return 1;
	}
	else{
		return x%10 + 2*bintodec(x/10);
	}
}

int bintoocta(int x){
	return dectoocta(bintodec(x));
}

int bintohexa(int x){
	return dectohexa(bintodec(x));
}

int octatodec(int x){
	if (x==0){
		return 0;
	}
	else if(x==1){
		return 1;
	}
	else if(x==2){
		return 2;
	}
	else if(x==3){
		return 3;
	}
	else if(x==4){
		return 4;
	}
	else if(x==5){
		return 5;
	}
	else if (x==6){
		return 6;
	}
	else if(x==7){
		return 7;
	}
	else{
		return x%10 + 8*octatodec(x/10);
	}
}

int octatobin(int x){
	return dectobin(octatodec(x));
}

int octatohexa(int x){
	return dectohexa(octatodec(x));
}

int hexatodec(char *hex) {
    int dec = 0;

    for (int i = 0; hex[i] != '\0'; i++) {
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

int hexatobin(char *x) {
    return dectobin(hexatodec(x));
}

int hexatoocta(char *x) {
    return dectoocta(hexatodec(x));
}

int main(){
	int inputchoice, outputchoice;
	
	printf("===========================\n");
	printf("  Number System Converter  \n");
	printf("===========================\n");
	
	printf("Enter the Source Number System\n");
	printf("1. Decimal(Base 10)\n2. Binary(Base 2)\n3. Octa(Base 8)\n4. Hexa(Base 16)\n");
	printf("Enter choice(1-4):  ");
	scanf("%d", &inputchoice);
	
	
	
	printf("Enter the Target Number System\n");
	printf("1. Decimal(Base 10)\n2. Binary(Base 2)\n3. Octa(Base 8)\n4. Hexa(Base 16)\n");
	printf("Enter choice(1-4):  ");
	scanf("%d", &outputchoice);
	
	switch(inputchoice){
		case 1:
			int inputno;
			printf("Enter the Number in the choosen System:  ");
			scanf("%d", &inputno);
			switch(outputchoice){
				case 1:
					printf("The input %d is already a Decimal", inputno);
					break;
				case 2:
					printf("The converted number is %d", dectobin(inputno));
					break;
				case 3:
					printf("The converted number is %d", dectoocta(inputno));
					break;
				case 4:
					printf("The converted number is %s", dectohexa(inputno));
					break;
				default:
					printf("Invalid Input...");
					break;
			}
			break;
		case 2:
			int inputno;
			printf("Enter the Number in the choosen System:  ");
			scanf("%d", &inputno);
			switch(outputchoice){
				case 1:
					printf("The converted number is %d", bintodec(inputno));
					break;
				case 2:
					printf("The input %d is already Binary", inputno);
					break;
				case 3:
					printf("The converted number is %d", bintoocta(inputno));
					break;
				case 4:
					printf("The converted number is %s", bintohexa(inputno));
					break;
				default:
					printf("Invalid Input...");
					break;
			}
			break;
		case 3:
			int inputno;
			printf("Enter the Number in the choosen System:  ");
			scanf("%d", &inputno);
			switch(outputchoice){
				case 1:
					printf("The converted number is %d", octatodec(inputno));
					break;
				case 2:
					printf("The converted number is %d", octatobin(inputno));
					break;
				case 3:
					printf("The input %d is already Octadecimal", inputno);
					break;
				case 4:
					printf("The converted number is %s", octatohexa(inputno));
					break;
				default:
					printf("Invalid Input...");
					break;
			}
			break;
		case 4:
			char inputno[20];
			printf("Enter the Number in the choosen System:  ");
			scanf("%s", inputno);
			switch(outputchoice){
				case 1:
					printf("The converted number is %d", hexatodec(inputno));
					break;
				case 2:
					printf("The converted number is %d", hexatobin(inputno));
					break;
				case 3:
					printf("The converted number is %d", hexatoocta(inputno));
					break;
				case 4:
					printf("The input %s is already Hexadecimal", inputno);
					break;
				default:
					printf("Invalid Inmput...");
					break;
			}
			break;
		default:
			printf("Invalid Input...");
			break;
	}
}
