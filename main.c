#include <stdio.h>
#include<stdlib.h>
#include<locale.h>

struct Aluno
{
    char nome[100];
    int matricula;
    float nota1,nota2,nota3;
};
typedef struct Aluno Aluno;

int main()
{

    setlocale(LC_ALL,"portuguese");

    int quantidade = 0;

    printf("Digite a quantidade de alunos da turma !\n");
    scanf("%d",&quantidade);

    while(quantidade < 0)   // While para garantir que vai ser um número positivo !
    {
        printf("Digite a quantidade de alunos da turma !\n");
        scanf("%d",&quantidade);

        if(quantidade > 0)
            break;
    }

    Aluno * aluno = (Aluno *) calloc(quantidade,sizeof (Aluno));

    for(int i=0; i<quantidade; i++)
    {
        fflush(stdin);

        printf("Digite o nome do aluno %d !\n",i+1);
        gets(aluno[i].nome);

        fflush(stdin); // Comando necessário para limpar o buffer do teclado !

        printf("Digite a matrícula do aluno !\n");
        scanf("%d",&aluno[i].matricula);

        fflush(stdin);

        printf("Digite a nota 1 do nota do aluno: %s!\n",aluno[i].nome);
        scanf("%f",&aluno[i].nota1);

        fflush(stdin);

        printf("Digite a nota 2 do nota do aluno: %s !\n",aluno[i].nome);
        scanf("%f",&aluno[i].nota2);

        fflush(stdin);

        printf("Digite a nota 3 do nota do aluno: %s !\n",aluno[i].nome);
        scanf("%f",&aluno[i].nota3);
    }

    float media = 0;

    for(int i=0; i<quantidade;i++)
    {
        media = aluno[i].nota1 + aluno[i].nota2 + aluno[i].nota3;
        media /= 3;

        if(media >=7)
            printf("O aluno %s está aprovado !\n",aluno[i].nome);
        else if(media <7 && media >=4)
            printf("O aluno %s está de avaliação final !\n",aluno[i].nome);
        else if(media < 4)
            printf("O aluno %s está eprovado !",aluno[i].nome);
    }
    return 0;
}
