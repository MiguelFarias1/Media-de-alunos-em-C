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

void VerificaNota(Aluno *aluno,int i);

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


        VerificaNota(&aluno[i],i);

        fflush(stdin);

        printf("Digite a nota 2 do nota do aluno: %s !\n", aluno[i].nome);
        scanf("%f", &aluno[i].nota2);

        VerificaNota(&aluno[i],i);

        fflush(stdin);

        printf("Digite a nota 3 do nota do aluno: %s !\n", aluno[i].nome);
        scanf("%f", &aluno[i].nota3);

        VerificaNota(&aluno[i],i);
    }
}

void VerificaNota(Aluno *aluno, int i)
{
        if(aluno[i].nota1 > 10 || aluno[i].nota1<0)
            while(aluno[i].nota1 > 10 || aluno[i].nota1<0)
            {
                fflush(stdin);

                printf("Você tem que digitar uma nota entre 0 e 10 !\n");
                printf("Digite a nota 1 do nota do aluno: %s!\n", aluno[i].nome);
                scanf("%f", &aluno[i].nota1);
            }

        else if(aluno[i].nota2 > 10 || aluno[i].nota2<0)
            while(aluno[i].nota2 > 10 || aluno[i].nota2<0)
            {
                fflush(stdin);

                printf("Você tem que digitar uma nota entre 0 e 10 !\n");
                printf("Digite a nota 2 do nota do aluno: %s!\n", aluno[i].nome);
                scanf("%f", &aluno[i].nota2);
            }

        else if(aluno[i].nota3 > 10 || aluno[i].nota3<0)
            while(aluno[i].nota3 > 10 || aluno[i].nota3<0)
            {
                fflush(stdin);

                printf("Você tem que digitar uma nota entre 0 e 10 !\n");
                printf("Digite a nota 3 do nota do aluno: %s!\n", aluno[i].nome);
                scanf("%f", &aluno[i].nota3);
            }
}

float CalculaMedia(Aluno * aluno, int i)
{
    float soma = aluno[i].nota1 + aluno[i].nota2 + aluno[i].nota3;

    return soma / 3 ;
}

#endif //MEDIA_BIBLIOTECA_H
