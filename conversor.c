#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define tamPadrao 255

// Recebe como parâmetro um número decimal (num_dec), e a base (base) cujo número será convertido.
void decimalParaBase(int num, int base) {
   char resto[17] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'}, numeroConvertido[tamPadrao];
   int i = 0;
   // Este loop realiza as operações de divisão. Os restos são guardados no vetor 'num_conv'
   while(num > 0) {
       numeroConvertido[i] = resto[num % base];
       num /= base;
       i++;
   }
   // Exclui o caractere especial '\0' do final da string
   i -= 1;
   // Utilizado para identificar a saída do programa
   switch(base) {
       case 2 : printf("BINÁŔIO: "); break;
       case 8 : printf("OCTAL: "); break;
       case 16 : printf("HEXADECIMAL: "); break;
   }
    
   // Inverte a string contida no vetor numeroConvertido
   for(i; i >= 0; i--){
       printf("%c", numeroConvertido[i]);
   } 
   printf("\n");
}

// Esta função permite converter um número na base 2, 8 ou 16 para a base decimal. 
// Recebe como parâmetro uma string (representação do número), e um número inteiro que 
// determina em qual base está o número do primeiro parâmetro.
void baseParaDecimal(char* num, int base) {
    int i = 0, exp = 0, tam = 0, dec = 0, num1 = 0;
    
    // Este loop determina o tamanho da string
    while(num[tam] != '\0') {
        tam++;
    }
    
    // Neste loop, a string é percorrida de trás para frente. Cada caractere é convertido
    // em um número inteiro, multiplicado pela base elevada ao expoente (0..Comprimento da string) 
    // e somado ao valor da variável 'dec', que recebe as somas sucessivas. 
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

        // Aqui avalia se o usuário digitou um número válido ou não!
        if(num1 > (base-1) || num1 < 0) {
            printf("Numero invalido!\n");
            exit(0);
        }
        dec += num1 * pow(base, exp);
    }

    // O número convertido para decimal é exibido
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