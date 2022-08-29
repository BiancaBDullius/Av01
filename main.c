#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void registrarTipo();
void adicionarInt();
void adicionarFloat();
void adicionarDouble();
void alocarMemoria();
void imprimirBuffer(char imprimir);
int calcularPosicaoBuffer();
void *buffer;
char *tiposBuffer;
int qtdInt = 0;
int qtdFloat = 0;
int qtdDouble = 0;
int opcao = 1;

int main()
{
    buffer = (void *)malloc(1);
    tiposBuffer = (char *)malloc(sizeof(char) * 1);

    while (opcao != 0)
    {
        registrarTipo();
    }

    free(buffer);
    free(tiposBuffer);
    return 0;
}

void registrarTipo()
{

    int tipo = 0;
    printf("Digite o tipo do numero que sera adicionado:\n1 - int\n2 - float\n3 - double\n4 - Parar a entrada\n");
    scanf("%d", &tipo);

    switch (tipo)
    {
    case 1:
        adicionarInt();
        break;
    case 2:
        adicionarFloat();
        break;
    case 3:
        adicionarDouble();
        break;
    case 4:
        printf("Serie em sequencia:\n");
        imprimirBuffer('t');
        printf("\nSerie em ordem:\n");
        imprimirBuffer('i');
        imprimirBuffer('f');
        imprimirBuffer('d');
        opcao = 0;
        break;
    default:
        opcao = 0;
        break;
    }
}

void alocarMemoria()
{
    buffer = realloc(buffer, (sizeof(void) + (sizeof(int) * qtdInt) + (sizeof(float) * qtdFloat) + (sizeof(double) * qtdDouble)));
    tiposBuffer = realloc(tiposBuffer, strlen(tiposBuffer) + (sizeof(char) * 2));
}

void adicionarInt()
{
    int *numero;
    qtdInt++;
    alocarMemoria();
    int soma = calcularPosicaoBuffer();
    strcat(tiposBuffer, "i");
    numero = buffer + soma;
    printf("\nDigite o numero:\n");
    scanf("%d", numero);
}

void adicionarFloat()
{
    float *numero;
    qtdFloat++;
    alocarMemoria();
    int soma = calcularPosicaoBuffer();
    strcat(tiposBuffer, "f");
    numero = buffer + soma;
    printf("\nDigite o numero:\n");
    scanf("%f", numero);
}

void adicionarDouble()
{
    double *numero;
    qtdDouble++;
    alocarMemoria();
    int soma = calcularPosicaoBuffer();
    strcat(tiposBuffer, "d");
    numero = buffer + soma;
    printf("\nDigite o numero:\n");
    scanf("%lf", numero);
}

void imprimirBuffer(char imprimir)
{
    int soma = 0;
    for (int i = 0; i < strlen(tiposBuffer); i++)
    {

        if (tiposBuffer[i] == 'i')
        {
            if (imprimir == 'i' || imprimir == 't')
            {
                printf("%d\n", *(int *)(buffer + soma));
            }
            soma += sizeof(int);
        }
        if (tiposBuffer[i] == 'f')
        {
            if (imprimir == 'f' || imprimir == 't')
            {
                printf("%.2f\n", *(float *)(buffer + soma));
            }
            soma += sizeof(float);
        }
        if (tiposBuffer[i] == 'd')
        {
            if (imprimir == 'd' || imprimir == 't')
            {
                printf("%.2lf\n", *(double *)(buffer + soma));
            }
            soma += sizeof(double);
        }
    }
}

int calcularPosicaoBuffer()
{
    int calculo = 0;

    for (int i = 0; i < strlen(tiposBuffer); i++)
    {
        if (tiposBuffer[i] == 'i')
        {
            calculo += sizeof(int);
        }
        if (tiposBuffer[i] == 'f')
        {
            calculo += sizeof(float);
        }
        if (tiposBuffer[i] == 'd')
        {
            calculo += sizeof(double);
        }
    }
    return calculo;
}