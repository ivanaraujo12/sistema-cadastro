#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <locale.h>
#include <conio.h>


typedef struct Produto{

    char nomeProduto[100];
    double valorProduto;
    int codigoProduto;

}PRODUTO;


PRODUTO produtos[3];
void cadastrar();
void buscar();
void manual();
int escolhaDoMenu(int a);
void MenuPrincipal();
int code=0;
int opcoes=0;
int codigo=0;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    //printf("Antes de começarmos! Gostaria de apagar as informaçoes da tela a cada nova interaçao? Y//N");
   // char limpa[3];
   // fgets(limpa,3,stdin);

    MenuPrincipal();






return 0;
}

void MenuPrincipal(){

    while(opcoes!=3){


        printf("\n\tESCOLHA UMA OPÇÃO \n");
        printf("\n\t1. Cadastrar Produto: ");
        printf("\n\t2. Buscar Produto : ");
        printf("\n\t3. Sair do Sistema: ");
        printf("\n\t4. Manual de Uso: \n");
        printf("\t*cadastros = %d \n", code);
        printf("\n");
        scanf("%d", &opcoes);
        getchar();
        printf("\n" );


        escolhaDoMenu(opcoes);



   }






}

int escolhaDoMenu(int a){

    switch(a){
        case 1:
            cadastrar();
            break;
        case 2:
            buscar();
            break;
        case 3:
            opcoes =3;
            printf("\nVoce saiu do sistema!");
            break;
        case 4:
            manual();
            break;
        default:
            printf("\a");
            printf("Opcao invalida. Tente novamente.\n");
            break;

    }

return 0;
}


void cadastrar( ){
     PRODUTO p;

    if(code>=3){
        printf("\a");
        printf("Nao e possivel cadastrar novos produtos.\n");

        return;
    }


        printf("\nNome do Produto: ");
        fgets(p.nomeProduto,100,stdin);
        printf("valor do Produto: ");
        scanf("%lf", &p.valorProduto);
        printf("Codigo do Produto: ");
        scanf("%d", &p.codigoProduto);
        getchar();

    for(int i=0; i<code; i++){

        if(produtos[i].codigoProduto == p.codigoProduto){
            printf("\a");
            printf("Ja existe um produto com este codigo.\n");
            return;
        }
    }


    produtos[code] = p;
    code++;


}

void buscar(){

    printf("\nDigite o codigo do produto: ");
    scanf("%d", &codigo);
    getchar();
    int encontrado = 0;

    for(int j=0; j<3; j++){

        if(produtos[j].codigoProduto==codigo){

            printf("\nNome: %s", produtos[j].nomeProduto);
            printf("Valor: %.2lf", produtos[j].valorProduto);
            printf("\nCodigo: %d\n", produtos[j].codigoProduto);
            encontrado=1;
            break;
        }




}
    if(!encontrado){
    printf("\a");
    printf("\nCodigo nao cadastrado.\n");

}

    opcoes=0;

}

void manual(){

int b =0;
    system("cls");

    printf("MANUAL DE USO\n");
    printf("\n");
    printf("1.Ao entrar no menu de opções digite o numero referente a opção a ser selecionada e tecle (Enter) \n");
    printf("2.Os valores dos produtos seguem a formataçao, exemplo: 5,5.\nCom a virgula separando as casas decimais\n");

    printf("\nPressione 5 para voltar ao menu inicial.\n");
    b =getch();

    if(b==5){
        MenuPrincipal();
    }


}







