#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o de mem�ria 
#include <locale.h> // Biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das strings

int Registro()
{
	char arquivo [40];
	char cpf[40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];   
	
	printf ("Digite o CPF a ser cadastrado: ");
	scanf ("%s", cpf); // Scanf salva informa��es
		
	strcpy(arquivo, cpf); // respons�vel por copiar os valores das strings
	
	FILE *file; // Acessa um file e cria um file
	file = fopen(arquivo, "w"); // cria o arquivo. "w" � para escrever no arquivo
	fprintf(file,cpf); // salvo valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // "a" � pra atulizar os dados
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:  ");
	scanf ("%s", nome); // %s � referente as strings
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite sobrenome a ser cadastrado:  ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}
int Consultar()
{
	setlocale(LC_ALL, "Portuguese");
	char cpf[40];
	char conteudo [200];
	
	printf ("digite o CPF a ser consultado:  ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file== NULL)
	{
		printf ("N�o foi poss�vel abrir o arquivo, n�o localizado! \n");
	}
	
	while(fgets(conteudo,200, file)!= NULL)

	{
	printf("\nEssas s�o as informa��es do usu�rio: ");
	printf("%s",conteudo);
	printf("\n\n");
	}

	system("pause");
}
int Deletar ()
{
	char cpf [40];
	printf("Digite o CPF a ser deletado:  ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen (cpf,"r");
	
	if (file == NULL);
	{
		printf("O usu�rio n�o se encontra no sistema! \n");
		system ("pause");
	}
}

int main () // int main � a fun��o principal para ponto de partida da execu�ao do programa

{
	int opcao=0; 
	int laco=1;
	
	for (laco=1;laco=1;)
	{

		system ("cls"); //Respons�vel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); // idioma
	
		printf("###Cart�rio da EBAC###\n\n"); // inicio do menu
		printf("Escolha a op��o desejada do Menu: \n \n"); 
		printf ("\t 1 - Registrar nomes \n");
		printf ("\t 2 - Consultar os nomes\n");
		printf ("\t 3 - Deletar nomes \n ");
		printf ("Op��o: "); // fim do menu
	
		 
		scanf("%d", &opcao);
	
		system("cls"); //Respons�vel por limpar a tela
		
		switch (opcao)
		{
			case 1:
			Registro ();
			system ("pause");
			break;
			
			case 2:
			Consultar ();
			system ("pause");
			break;
		
			case 3:
			Deletar ();
			system ("pause");
			break;
		
			default:
			printf ("Op��o n�o est� dispon�vel\n");
			system ("pause"); 
		}
	}
}
