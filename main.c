#include <stdio.h>
#include<stdlib.h>
#include "Biblioteca.h"

int main()
{
    setlocale(LC_ALL,"portuguese");

    int quantidade = 0;

    printf("Digite a quantidade de alunos da turma !\n");
    scanf("%d",&quantidade);

    while(quantidade <= 0)   // While para garantir que vai ser um número positivo!
    {
        printf("Digite a quantidade de alunos da turma !\n");
        scanf("%d",&quantidade);

        if(quantidade > 0)
            break;
    }

    Aluno * aluno = (Aluno *) calloc(quantidade, sizeof (Aluno));

    if(aluno == NULL)
        printf("Memória insuficiente para tal quantidade !");

    Preenche(aluno,quantidade);

    return 0;
}
