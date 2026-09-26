#include <stdio.h>
#include <stdlib.h>

void PreencheMatriz(float mat[50][50], int n);

void MostraMatriz(float mat[50][50], int n);

//void Resposta(float mat[50][50], int n);

void Resposta2(float mat[50][50], int n);

void Pivoteamento(float mat[50][50], int n);

char Menu();

void EliminacaoGauss(float mat[50][50],int n);

void GaussSeidel(float mat[50][50], int n);

void seidel(float mat[50][50], int n);

void TesteMatriz(float mat [50][50], int n);

int main()
{
    float a[50][50];//={2.0,3.0,-1.0,-1.0,1.0,4.0,1.0,-8.0,-1.0};
    int n;
    char op;
    //scanf("%c",&op);
    op = 'x';
    //printf("\n");
    while(op!='s')
    {
        op=Menu();
//    }
        switch(op)
        {
            case 'a':
                printf("Entre com o numero de variaveis  do sistema:");
                scanf("%d",&n);
                EliminacaoGauss(a,n);

                break;
            case 'b':
                printf("Entre com o numero de variaveis  do sistema:");
                scanf("%d",&n);
                GaussSeidel(a,n);
                break;
            case 's':
                printf("Saindo do programa...\n");
                break;
                //Sistem("Pause");
                //return 0;
        }


//    printf("Entre com o numero de variaveis  do sistema:");
//    scanf("%d",&n);
//    PreencheMatriz(a,n);
//    printf("A matriz a aumentada eh:\n");
//    MostraMatriz(a,n);
//    printf("\n\n");
//    Pivoteamento(a,n);
//    printf("\n");
//    //Resposta(a,n);
//    Resposta2(a,n);
    }
    system("PAUSE");
    return 0;
}

void PreencheMatriz(float mat[50][50], int n)
{
    int i, j;
    //int mat[n][n];
    for(i=0; i<n; i++) // Neste bloco insere-se os termos das linhas e colunas da matriz
    {
        for(j=0; j<n; j++)
        {
            printf("coloque o termo (%d)(%d):", i+1, j+1);
            scanf("%f",&mat[i][j]);
            //mat[i][j]=d;
            //printf("\n");
        }

    }
    printf("\n");
    for(i=0;i<n;i++) //Inser-se os termos independentes, ou seja, as respostas do sistema
    {
        printf("coloque o termo indepente (%d): ", i+1);
        scanf("%f",&mat[i][j]); //os termos independentes sao colocados na mesma matriz em que se emcontra o sistema linear
    }
    printf("\n");
}

void MostraMatriz(float mat[50][50], int n)
{

    int i,j;
    //printf("\nA matriz eh:\n");
    //i=0;
    //j=0;
    for(i=0; i<n; i++)//o indice 'i' é a variaçao da linha
    {
        for(j=0; j<=n; j++)// o indice 'j' é a variaçao da coluna para se mostrar cada termo da matriz
        {
            printf("  %2.3f", mat[i][j]);
        //    scanf("%d",&mat[i][j]);
            //mat[i][j]=d;
        }
        printf("\n");
    }
    //Pivoteamento(mat,n);
   // int j,i;
//    float m;
//    i=0;
//    j=0;
//   // m=mat[i+1][j]/mat[i][j];
//    for(i; i<n-1 ;i++)
//    {
//        m=mat[i+1][j]/mat[j][j];
////        for(j;j<n;j++)
////        {
////            mat[i+1][j]=mat[i+1][j] - m*mat[i][j];
////            printf("\n %2.3f \n",mat[i+1][j]);
////        }
//        printf("\nO valor de m eh: %f",m);
////        m=mat[i+1][j]/mat[i][j];
//    }
}

//void Resposta(float mat[50][50], int n)//nao esta sendo usado, serviu somente como teste
//{
//    int i, j;
//    float x[3];
//    x[2]=mat[2][3]/mat[2][2];
//    //x[2]=0.96875;
//    x[1]=(mat[1][3] - (mat[1][2]*x[2]))/mat[1][1];
//    x[0]=(mat[0][3] - (mat[0][1]*x[1]) - (mat[0][2]*x[2]))/mat[0][0];
//    for(i=0;i<=2;i++)
//        printf("x[%d]= %f\n", i+1,x[i] );
//    printf("\n");
//}


void Resposta2(float mat[50][50], int n)
{
    int i,j,a;
    float x[10];
    float k,c;
    k=0;
    c=0;
    a=1;
    for(i=n-1;i>=0;i--)
    {
        if(i==n-1)
        {

            x[i]=mat[i][n]/mat[i][i];
            //printf("x[%d]= %f\n", i+1,x[i] );
        }
        else
        {
            j=n-1;
            k=0;
            while(j>i)
            {
                c=mat[i][j]*x[j]/mat[i][i];
                k=c+k;  // 'c' e 'k' sao variaveis auxiliares qque servirao pra ajudar pra se obter a resposta x[i]
                j--;
            }
            x[i]=(mat[i][n]/mat[i][i])-k;
        }
    }
    printf("As respostas sao:\n");
    for(i=0;i<=n-1;i++)
        printf("x[%d]= %f\n", i+1,x[i] );

}

void seidel(float mat[50][50], int dim)
{
    int i,j,a;
    float x[10];
    float k,c;
    k=0;
    c=0;
    //a=50;
    for(i=0;i<=dim-1;i++)//atrubuir valor zero a todos os elementos do vetor x[i] 
    {                    //para se inciar a iteraçao
        x[i]=0;
    }

    for(a=0;a<=100;a++) // laço que fara 100 iteraçoes com os valores de x[i]
    {
        for(i=0;i<=dim-1;i++)//calcular o x[] de indice i
        {
            x[i]=mat[i][dim]/mat[i][i];//termo independente dividido pelo coeficiente de x[i]
            if(i==dim-1)//se i for o ultimo termo da diagonal principal
            {
                for(j=0;j<=i-1;j++)//para que nao se calcule x[i] dentro de si mesma e j nao seja igual a i
                {
                    c=x[j]*mat[i][j]/mat[i][i];//c é variavel auxiliar
                    k=c+k;//recebe a soma de todos os valores que serao colocados em 'c'
                }
                x[i]=x[i]-k;//resposta final de x[i] apos a iteraçao 'i'
                k=0;//tem que ser zerado pra nao ocorrer de pegar valores da iteraçao anterior  
            }
            else//caso contrario...
            {
                for(j=0;j<=dim-1;j++)//j ira ate o termo
                {
                    if(j==i)
                        j++;
                    c=x[j]*mat[i][j]/mat[i][i];
                    k=c+k;
                }
                x[i]=x[i]-k;
                k=0;
                //printf("\n x[%d]=%4.1f\n",i,x[i]);
            }


        }
    }
    printf("\nApos 100 iteracoes:\n"); 
    for(i=0;i<=dim-1;i++)
        printf("x[%d]= %f\n", i+1,x[i] );
}

void Pivoteamento(float mat[50][50], int n)
{
    int j,i,a,b;
    float m;
    i=1;
    b=1;
    //j=0;
    a=0;
    //m=mat[i+1][j]/mat[i][j];
    for(a;a<=n-2;a++)
    {
        j=a;//o indice referente a coluna recebe o valor de 'a'
        //if(i>n)
        //    i--;
        for(i;i<=n-1;i++)
        {

            m=mat[i][a]/mat[a][a];  //este é o fator multiplicador que sera usado pra zerar os termos das colunas abaixo da diagonal principal
           // printf("\no valor de m eh : %f\n",m);
            for(j;j<=n;j++)
            {
                mat[i][j]=mat[i][j]-m*mat[a][j]; //o novo valor que cada elemento da linha 'i' vai receber

            //   printf("\n %2.3f \n",mat[i+1][j]);
            }
            j=a;

        }
       // MostraMatriz(mat,n);
        b++; // variavel auxiliar que sera usada na variavel 'i' para poder mudar o valor das linhas
        //j=a;
        //if(a>=n-3)
        //    i++;
        i=b;
    }
    printf("A nova matriz eh:\n");
    MostraMatriz(mat,n);
    printf("\n\n");
}

char Menu()
{
    char op;
    printf("\n******************************************\n");
    printf("***** Resolucao de Sistemas Lineares *****\n");
    printf("******************************************\n\n");
    printf("Escolha uma opcao:\n\n");
    printf("A - Metodo Eliminacao Gaussiana\n\n");
    printf("B - Metodo Gauus Seidel\n\n");
    printf("S - Sair do Programa\n\n");
    op=getche();
    //flush(stdin);
    printf("\n");
    return op;
//    while (op !='a'|| op != 'b')
//    {
//        switch(op)
//        {
//            case 'a':
//            {
//
//            }
//
//
//
//
//        }
//    }
}
void TesteMatriz(float mat [50][50], int n)
{
    float c,k,aux;
    int i,j;
    c=0;
    k=0;
    for(i=0;i<=n-1;i++)
    {
        aux=mat[i][i];
        if (aux<0)
            aux=(-1)*aux;
        if(i==n-1)
        {
            for(j=0;j<=i-1;j++)
            {
                c=mat[i][j];
                if(c<0)
                    c=(-1)*c;
                k=c+k;
            }
            //if(aux>=k)
//                printf("\nOs resultados podem nao convergirem \n");
//            else
//                printf("\nOs resultados nao convergem!\n");
            k=0;

        }
        else
        {

            for(j=0;j<=n-1;j++)
            {
                if(j==i)
                    j++;
                c=mat[i][j];
                if(c<0)
                    c=(-1)*c;
                k=c+k;
            }
         //   if(aux>=k)
//                printf("\nOs resultados convergem!\n");
//            else
//                printf("\nOs resultados nao convergem!\n");
                  k=0;
        }




    }
}

void EliminacaoGauss(float mat[50][50], int n)
{
    PreencheMatriz(mat,n);
    printf("A matriz a aumentada eh:\n");
    MostraMatriz(mat,n);
    printf("\n\n");
    Pivoteamento(mat,n);
    printf("\n");
    Resposta2(mat,n);
}

void GaussSeidel(float mat[50][50], int n)
{
    PreencheMatriz(mat,n);
    printf("\nOs coeficientes do sistema e seus termos independentes sao:\n");
    MostraMatriz(mat,n);
    printf("\n\n");
    TesteMatriz(mat,n);
    seidel(mat,n);
}
