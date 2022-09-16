#include <stdio.h>
#include<stdlib.h>
#include "Biblioteca.h"

int main()
{
    setlocale(LC_ALL,"portuguese");

    int quantidade = 0;

    printf("Digite a quantidade de alunos da turma !\n");
    scanf("%d",&quantidade);

    while(quantidade < 0)   // While para garantir que vai ser um n�mero positivo!
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
        // Armazenei o retorno da fun��o em uma vari�vel para o c�digo ficar mais leg�vel.

        if ( media >= 7)
            printf("O aluno %s tem a m�dia %.2f e est� aprovado !", aluno[i].nome ,media);
        else if(media < 7 && media >=4)
            printf("O aluno %s tem a m�dia %.2f e est� de avalia��o final !",aluno[i].nome , media);
        else if(media<4)
            printf("O aluno %s tem a media %.2f e est� reprovado !",aluno[i].nome,media);
    }
    return 0;
}
