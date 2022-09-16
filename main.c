#include <stdio.h>
#include<stdlib.h>
#include "Biblioteca.h"

int main()
{
    setlocale(LC_ALL,"portuguese");

    int quantidade = 0;

    printf("Digite a quantidade de alunos da turma !\n");
    scanf("%d",&quantidade);

    while(quantidade < 0)   // While para garantir que vai ser um número positivo!
    {
        printf("Digite a quantidade de alunos da turma !\n");
        scanf("%d",&quantidade);

        if(quantidade > 0)
            break;
    }

    Aluno * aluno = (Aluno *) calloc(quantidade,sizeof (Aluno));

    Preenche(aluno,quantidade);

    for(int i=0; i<quantidade;i++)
    {
        float media = CalculaMedia(&aluno[i], i);
        // Armazenei o retorno da função em uma variável para o código ficar mais legível.

        if ( media >= 7)
            printf("O aluno %s tem a média %.2f e está aprovado !", aluno[i].nome ,media);
        else if(media < 7 && media >=4)
            printf("O aluno %s tem a média %.2f e está de avaliação final !",aluno[i].nome , media);
        else if(media<4)
            printf("O aluno %s tem a media %.2f e está reprovado !",aluno[i].nome,media);
    }
    return 0;
}
