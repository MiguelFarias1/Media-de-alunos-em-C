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

void VerificaNota(Aluno *aluno);

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

        printf("Digite a nota 1 do nota do aluno: %s!\n", aluno[i].nome);
        scanf("%f", &aluno[i].nota1);

        VerificaNota(&aluno[i]);

        fflush(stdin);

        printf("Digite a nota 2 do nota do aluno: %s !\n", aluno[i].nome);
        scanf("%f", &aluno[i].nota2);

        VerificaNota(&aluno[i]);

        fflush(stdin);

        printf("Digite a nota 3 do nota do aluno: %s !\n", aluno[i].nome);
        scanf("%f", &aluno[i].nota3);

        VerificaNota(&aluno[i]);

        CalculaMedia(&aluno[i]);
    }
}

void VerificaNota(Aluno *aluno)
{
        if(aluno->nota1 > 10 || aluno->nota1 < 0)
        {
            while (aluno->nota1 > 10 || aluno->nota1 < 0)
            {
                printf("Você tem que digitar uma nota entre 0 e 10 !\n");
                printf("Digite a nota 1 do nota do aluno: %s!\n", aluno->nome);

                fflush(stdin);
                scanf("%f", &aluno->nota1);
            }
        }
        else if (aluno->nota2 > 10 || aluno->nota2 < 0)
        {
            while (aluno->nota2 > 10 || aluno->nota2 < 0)
            {
                printf("Você tem que digitar uma nota entre 0 e 10 !\n");
                printf("Digite a nota 2 do nota do aluno: %s!\n", aluno->nome);
                scanf("%f", &aluno->nota2);
            }

        }
        else if (aluno->nota3 > 10 || aluno->nota3 < 0)
        {
            while (aluno->nota3 > 10 || aluno->nota3 < 0)
            {
                printf("Você tem que digitar uma nota entre 0 e 10 !\n");
                printf("Digite a nota 3 do nota do aluno: %s!\n", aluno->nome);
                scanf("%f", &aluno->nota3);
            }
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
