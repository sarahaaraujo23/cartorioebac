#include <stdio.h> //biblioteca de comunica��o com o usu�rio 
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria 
#include <locale.h> //biblioteca de aloca��o de texto por regi��o (define acentos e etc, pr�prio da ortografia do pa�s)
#include <string.h> // biblioteca respons�vel por cuidar das strings

int registro () //fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//In�cio cria��o de vari�veis/string
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//Final cria��o de vari�veis/string

	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio 
	scanf ("%s", cpf); //%s refere-se a strings - armazenamento de string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file, cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //"fopen" � a fun��o respons�vel por abrir o arquivo (esse arquivo ja deve existir antes de ser aberto). "a" � identificador de archive 
	fprintf(file, ","); 
	fclose(file); // fechar arquivo
	
	printf ("Digite o nome a ser cadastrado: "); // "printf" � o comando que se d� para que o sistema apresente um texto para o usu�rio
	scanf("%s", nome); //%s refere-se a strings - armazenamento de string
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta () //fun��o respons�vel por consultar registros j� cadastrados no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40]; // Definindo o tipo de vari�vel char (caractere) e quantos caracteres o CPF suportar�
	char conteudo[100]; // Definindo o tipo de vari�vel char do conte�do, que poder� receber 100 caracteres para consulta
	
	printf("Digite o CPF a ser consultado: "); // mensagem a ser apresentada em tela para o usu�rio
	scanf("%s",cpf); //%s refere-se a strings - armazenamento de string
	
	FILE *file; //comando de cria��o de arquivo no banco
	file = fopen(cpf,"r"); //comando de abertura (fopen) e leitura ("r") do arquivo no banco
	
	if(file == NULL) //caso o valor a ser consultado n�o retorne com nenhum resultado (NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n"); // "\n" � para pular linha
	}
	
	while(fgets(conteudo, 100, file) != NULL) //while � quando a primeira condi��o n�o � atendida. Ent�o  a busca apresenta resultados (!= NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); //mensagem apresentada em tela para o usu�rio
		printf("%s",conteudo); // comando para busca das informa��es na string e a apresenta��o do conte�do em tela para o usu�rio
		printf("\n\n");
	}
	
	system("pause"); // sistema apresenta informa��o, at� usu�rio dar o comando de retorno de tela
	
}

int deletar () //fun��o respons�vel por excluir registros ja cadastrados no sistema
{
	char cpf[40]; //criando a vari�vel de caractere de CPF, com limita��o de 40 caracteres
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //mensagem apresentada em tela para o usu�rio
	scanf("%s", cpf); ////%s refere-se a strings - armazenamento de string
	
	remove(cpf); //comando para remover o CPF informado
	
	FILE *file; //criar o arquivo
	file = fopen(cpf,"r"); // abrir o arquivo e ler "r" o conte�do existente no banco de dados. Depois, deletar conforme comando de remo��o
	
	if(file == NULL) //caso o usu�rio busque CPF para deletar que n�o exista no banco de dados
	{
		printf("O usu�rio n�o se encontra no sistema!\n"); // mensagem apresentada em tela para o usu�rio
		system("pause"); //sistema permanece na mesma tela at� o usu�rio dar o comando de retorno
	}
	
}

int main () //fun��o principal do sistema
	{
	//Definindo vari�veis
	int opcao=0; 
	int laco=1;
	//Fim da defini��o de vari�veis
	
	for(laco=1;laco=1;)
	{

		system("cls"); //respons�vel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //In�cio do menu
		printf ("Escolha a op��o desejada do menu:\n\n");
		printf ("\t1 - Registrar nomes\n");
		printf ("\t2 - Consultar nomes\n");
		printf ("\t3 - Deletar nomes\n\n");
		printf ("Op��o: "); //Fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
		system("cls"); //respons�vel por limpar a tela
		
		switch(opcao) //in�cio da sele��o dos menus
		{
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consulta(); //chamada de fun��es
			break;
			
			case 3:	
			deletar(); //chamada de fun��es
			break;
			
			default:
			printf ("Essa op��o n�o est� dispon�vel!\n"); //chamada de fun��es
			system("pause");	
			break;
		}
	
	
	}
}
