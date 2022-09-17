//
// Created by Miguel on 16/09/2022.
//
#ifndef MEDIA_BIBLIOTECA_H
#define MEDIA_BIBLIOTECA_H
#include<locale.h>

struct Aluno
{
    char nome[100];
    int matricula;
    float nota1,nota2,nota3;
};
typedef struct Aluno Aluno;

void CalculaMedia(Aluno *aluno);

void Preenche(Aluno *aluno, int quantidade)
{
    setlocale(LC_ALL,"portuguese");

    for (int i = 0; i < quantidade; i++)
    {
        fflush(stdin);

        printf("Digite o nome do aluno %d !\n", i + 1);
        gets(aluno[i].nome);

        fflush(stdin); // Comando necessário para limpar o buffer do teclado !

        printf("Digite a matrícula do aluno !\n");
        scanf("%d", &aluno[i].matricula);

        fflush(stdin);

        do
        {
            printf("Digite a nota 1 do nota do aluno: %s!\n", aluno[i].nome);
            scanf("%f", &aluno[i].nota1);

            if(aluno[i].nota1 > 10 || aluno[i].nota1 < 0)
            {
                printf("Você tem que digitar uma nota entre 0 e 10 !\n");
            }
        }
        while (aluno[i].nota1 > 10 || aluno[i].nota1 < 0);

        fflush(stdin);

        do
        {
            printf("Digite a nota 2 do nota do aluno: %s !\n", aluno[i].nome);
            scanf("%f", &aluno[i].nota2);

            if(aluno[i].nota2 > 10 || aluno[i].nota2 < 0)
            {
                printf("Você tem que digitar uma nota entre 0 e 10 !\n");
            }
        }
        while (aluno[i].nota2 > 10 || aluno[i].nota2 < 0);

        fflush(stdin);

        do
        {
            printf("Digite a nota 3 do nota do aluno: %s !\n", aluno[i].nome);
            scanf("%f", &aluno[i].nota3);

            if(aluno[i].nota3 > 10 || aluno[i].nota3 < 0)
            {
                printf("Você tem que digitar uma nota entre 0 e 10 !\n");
            }
        }
        while (aluno[i].nota3 > 10 || aluno[i].nota3 < 0);

        CalculaMedia(&aluno[i]);
    }
}

void CalculaMedia(Aluno *aluno)
{
    float soma = aluno->nota1 + aluno->nota2 + aluno->nota3;

    double media = soma / 3 ;

    if (media >= 7)
        printf("O aluno %s tem a média %.2f e está aprovado !\n", aluno->nome ,media);
    else if(media < 7 && media >=4)
        printf("O aluno %s tem a média %.2f e está de avaliação final !\n",aluno->nome , media);
    else if(media<4)
        printf("O aluno %s tem a media %.2f e está reprovado !\n",aluno->nome,media);

    printf("\n");

    soma = 0;
    media = 0;
}

#endif //MEDIA_BIBLIOTECA_H
