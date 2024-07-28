#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h>//biblioteca de alocação em memoria 
#include <locale.h>  //biblioteca de alocação de texto em região 
#include <string.h> //biblioteca responsavel por cuidar das strings 

int Registro()// função responsavel por cadastrar 
{
    char arquivo[40];
	char cpf [40];
    char nome [40];
    char sobrenome [40];
    char cargo [40];
    
    printf ("Digite o cpf a ser cadastrado:");// coletando informação 
    scanf ("%s", cpf );// %s refere-se a string 
    
    strcpy(arquivo, cpf);// responsavel por copiar os valores das strings 
    
	FILE *file;// cria o arquivo 
	file = fopen(arquivo, "w");
	fprintf (file,cpf);// salva o valor da variavel 
	fclose (file);// fecha o arquivo 
	
	file=fopen(arquivo,"a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:");
	scanf ("%s", nome);
	
	file=fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file=fopen(arquivo,"a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:");
	scanf ("%s", sobrenome);
	
	file=fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	
	file=fopen(arquivo,"a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:");
	scanf("%s", cargo);
	
	file=fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
}

int Consulta()
{
     setlocale (LC_ALL, "portuguese");//definindo a linguagem 
	
	char cpf[40];
    char conteudo[200];
    
    printf("igite o cpf a ser consultado: ");
    scanf("%s", cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if(file== NULL)
    {
    	printf ("Não foi possivel abrir o arquivo, não localizado!. \n ");
	}
	
	while (fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas são as informações do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	system("pause");
	
		
}

int Deletar()
{
    char cpf[40];
    
    printf ("Digite o cpf a ser deletado: ");
    scanf ("%s", cpf);
    
    remove(cpf);
    
    FILE *file;
    file =fopen(cpf, "r");
    
    if(file == NULL)
    {
    	printf ("O usuario não se encontra no sistema!. \n ");
    	system ("pause");
	}
    
}


int main ()
{
	int opcao=0;
	int x=1;
    
	
	for (x=1;x=1;)
	{
	
	system("cls");
	
    setlocale (LC_ALL, "portuguese");//definindo a linguagem 
	
	printf("### cartório da EBAC ###\n\n");// Inicio do menu 
	printf("Escolha a opção desejada do menu: \n\n ");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n");
	printf("Opção");// Fim do menu 
	
	scanf ("%d", &opcao );// Armazenando a escolha do usuario 
	
	system("cls");// responsavel por limpar a tela 
	
	
	switch (opcao)// inicio seleção
	{
	   case 1:
	   Registro();// chamada de funçoes 
	   break;
	   
	   case 2:
       Consulta();
	   break;
	   
	   case 3:
	   Deletar();
	   break;
	 
	   default:
	   	printf ("Essa opção não esta disponivel!\n");
    	system("pause");
    	break;
	   
	}// fim seleção 
	
    }
}
