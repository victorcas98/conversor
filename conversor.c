#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define tamPadrao 255

void decimalParaBase(int num, int base) {
   char resto[17] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'}, numeroConvertido[tamPadrao];
   int i = 0;
   while(num > 0) {
       numeroConvertido[i] = resto[num % base];
       num /= base;
       i++;
   }

   i -= 1;

   switch(base) {
       case 2 : printf("BINÁŔIO: "); break;
       case 8 : printf("OCTAL: "); break;
       case 16 : printf("HEXADECIMAL: "); break;
   }
    
   for(i; i >= 0; i--){
       printf("%c", numeroConvertido[i]);
   } 
   printf("\n");
}

void baseParaDecimal(char* num, int base) {
    int i = 0, exp = 0, tam = 0, dec = 0, num1 = 0;
    
    while(num[tam] != '\0') {
        tam++;
    }
    
    for(exp, i=(tam-1); exp < tam; exp++, i--) {
        if(base == 16) {
            switch(num[i]) {
                case 'A' : 
                    num1 = 10; 
                    break;
                case 'a' : 
                    num1 = 10; 
                    break;
                case 'B' : 
                    num1 = 11; 
                    break;
                case 'b' : 
                    num1 = 11; 
                    break;
                case 'C' : 
                    num1 = 12; 
                    break;
                case 'c' : 
                    num1 = 12; 
                    break;
                case 'D' : 
                    num1 = 13; 
                    break;
                case 'd' : 
                    num1 = 13; 
                    break;
                case 'E' : 
                    num1 = 14; 
                    break;
                case 'e' : 
                    num1= 14; 
                    break;
                case 'F' : 
                    num1 = 15; 
                    break;
                case 'f' : 
                    num1 = 15; 
                    break;
                default : 
                    num1 = (int)num[i] - (int)'0';
            }
        }
        else
            num1 = (int)num[i] - (int)'0';

        if(num1 > (base-1) || num1 < 0) {
            printf("Numero invalido!\n");
            exit(0);
        }
        dec += num1 * pow(base, exp);
    }

    printf("DECIMAL: %d\n", dec);
}

int main(void) {
    int op, num;
    char str[tamPadrao];

    printf("QUAL OPERACAO DESEJA REALIZAR? \n\n");
    printf("1- BINARIO para DECIMAL\n");
    printf("2- DECIMAL para BINARIO\n");
    printf("3- OCTAL para  DECIMAL\n");
    printf("4- DECIMAL para OCTAL\n");
    printf("5- HEXADECIMAL para DECIMAL\n");
    printf("6- DECIMAL para HEXADECIMAL\n");
    printf("0- SAIR\n\n");
    printf("Digite a opercao que deseja realizar:\n");
    scanf("%d", &op);

    switch (op){
    case 0:
        printf("Saindo...\n");
        exit(0);
    case 1:
        printf("BINARIO: ");
        scanf("%s", str);
        baseParaDecimal(str, 2);
        break;
    case 2:
        printf("DECIMAL: ");
        scanf("%d", &num);
        decimalParaBase(num, 2);
        break;
    case 3:
        printf("OCTAL = ");
        scanf("%s", str);
        baseParaDecimal(str, 8);
        break;
    case 4:
        printf("DECIMAL = ");
        scanf("%d", &num);
        decimalParaBase(num, 8);
        break;
    case 5:
        printf("HEXADECIMAL = ");
        scanf("%s", str);
        baseParaDecimal(str, 16);
        break;
    case 6:
        printf("DECIMAL: ");
        scanf("%d", &num);
        decimalParaBase(num, 16);
        break;
    default:
        printf("OPÇAO NAO PERMITIDA!\nTENTE NOVAMENTE\n");
        break;
    }

    return 0; 
}