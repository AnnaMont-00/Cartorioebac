#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h>//biblioteca de aloca��o em memoria 
#include <locale.h>  //biblioteca de aloca��o de texto em regi�o 
#include <string.h> //biblioteca responsavel por cuidar das strings 

int Registro()// fun��o responsavel por cadastrar 
{
    char arquivo[40];
	char cpf [40];
    char nome [40];
    char sobrenome [40];
    char cargo [40];
    
    printf ("Digite o cpf a ser cadastrado:");// coletando informa��o 
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
    	printf ("N�o foi possivel abrir o arquivo, n�o localizado!. \n ");
	}
	
	while (fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas s�o as informa��es do usuario: ");
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
    	printf ("O usuario n�o se encontra no sistema!. \n ");
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
	
	printf("### cart�rio da EBAC ###\n\n");// Inicio do menu 
	printf("Escolha a op��o desejada do menu: \n\n ");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n");
	printf("Op��o");// Fim do menu 
	
	scanf ("%d", &opcao );// Armazenando a escolha do usuario 
	
	system("cls");// responsavel por limpar a tela 
	
	
	switch (opcao)// inicio sele��o
	{
	   case 1:
	   Registro();// chamada de fun�oes 
	   break;
	   
	   case 2:
       Consulta();
	   break;
	   
	   case 3:
	   Deletar();
	   break;
	 
	   default:
	   	printf ("Essa op��o n�o esta disponivel!\n");
    	system("pause");
    	break;
	   
	}// fim sele��o 
	
    }
}
