#include <stdio.h>
#include <string.h>
#include <math.h>
#define Max 100

char valorBase[Max];
int valorDecimal;

void inverterVetor(char *Vetor, int cont)
{
    int j = 0, k = 0;
    char aux_troca[Max];
    j = 0;
    k = cont - 1;
    while (j < k)
    {
        aux_troca[j] = Vetor[j];
        Vetor[j] = Vetor[k];
        Vetor[k] = aux_troca[j];
        j++;
        k--;
    }
}

char* decimalTodasBases(int Valordecimal, int Base){
    int i = 0, valor = 0;
    while (Valordecimal) {
        valor = Valordecimal%Base;
        if (Base <= 10 || valor < 10) {
            valorBase[i] = valor+48;
        }
        else {
            valorBase[i] = valor+55;
        }
        Valordecimal /= Base;
        i++;
    }
    valorBase[i] = '\0';
    inverterVetor(valorBase, i);
    return valorBase;
}

int todasBasesDecimal(char *N, int Base){
    int tamanho = 0,i;
    tamanho = (int)strlen(N);
    inverterVetor(N, (int)strlen(N));
    for (i = 0; i < tamanho; i++) {
        if (N[i] >= 48 && N[i] <= 59) {
            valorDecimal += pow(Base, i)*(N[i]-48);
        }
        else {
            valorDecimal += pow(Base, i)*(N[i]-65+10);
        }
    }
    return valorDecimal;
}

int main(){
    int option= 0, value = 0, base = 0;

    printf("Conversor de bases\n\n");
    printf("Digite um numero para escolher uma opcao.\n1-Decimal.\n2-Binario.\n3-Octal.\n4-Hexadecimal.\nOpcao: ");
    scanf("%d", &option);

    switch (option){
        case 1:
            printf("Digite um numero de decimal para converter: ");
            scanf("%d", &value);
            printf("Digite a base para qual deseja converter (2, 8 e 16): ");
            scanf("%d", &base);
            if (base == 2|| base == 8 || base == 16){
                printf("O valor convertido eh: %s", decimalTodasBases(value, base));
                break;
            }else{
                printf("Base não encontarda ou não permitida!\n");
                break;
            }
            
            case 2:
                printf("Digite um numero em binario para converter para qualquer base: ");
                scanf("%s", valorBase);
                printf("Digite a base para qual deseja converter (8, 10 e 16): ");
                scanf("%d", &base);
                if (base == 8 || base == 10 || base == 16){
                    printf("O valor convertido eh: %s", decimalTodasBases(todasBasesDecimal(valorBase, 2), base));
                    break;
                }
                else{
                    printf("Base não encontarda ou não permitida!\n");
                    break;
                }

            case 3:
                printf("Digite um numero em octal converter para qualquer base: ");
                scanf("%s", valorBase);
                printf("Digite a base para qual deseja converter (2, 10 e 16): ");
                scanf("%d", &base);
                if (base == 2 || base == 8 || base == 16){
                    printf("O valor convertido eh: %s", decimalTodasBases(todasBasesDecimal(valorBase, 8), base));
                    break;
                }
                else{
                    printf("Base não encontarda ou não permitida!\n");
                    break;
                }

            case 4:
                printf("Digite um numero em octal converter para qualquer base: ");
                scanf("%s", valorBase);
                printf("Digite a base para qual deseja converter (2, 8 e 10): ");
                scanf("%d", &base);
                if (base == 2 || base == 8 || base == 10){
                    printf("O valor convertido eh: %s", decimalTodasBases(todasBasesDecimal(valorBase, 16), base));
                    break;
                }else{
                    printf("Base não encontarda ou não permitida!\n");
                    break;
                }

        default:
            printf("Base não encontarda!\n");
            break;
    }

    return 0;
}