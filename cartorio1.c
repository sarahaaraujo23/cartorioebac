#include <stdio.h> //biblioteca de comunicação com o usuário 
#include <stdlib.h> //biblioteca de alocação de espaço em memória 
#include <locale.h> //biblioteca de alocação de texto por regição (define acentos e etc, próprio da ortografia do país)
#include <string.h> // biblioteca responsável por cuidar das strings

int registro () //função responsável por cadastrar os usuários no sistema
{
	//Início criação de variáveis/string
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//Final criação de variáveis/string

	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário 
	scanf ("%s", cpf); //%s refere-se a strings - armazenamento de string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file, cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //"fopen" é a função responsável por abrir o arquivo (esse arquivo ja deve existir antes de ser aberto). "a" é identificador de archive 
	fprintf(file, ","); 
	fclose(file); // fechar arquivo
	
	printf ("Digite o nome a ser cadastrado: "); // "printf" é o comando que se dá para que o sistema apresente um texto para o usuário
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

int consulta () //função responsável por consultar registros já cadastrados no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40]; // Definindo o tipo de variável char (caractere) e quantos caracteres o CPF suportará
	char conteudo[100]; // Definindo o tipo de variável char do conteúdo, que poderá receber 100 caracteres para consulta
	
	printf("Digite o CPF a ser consultado: "); // mensagem a ser apresentada em tela para o usuário
	scanf("%s",cpf); //%s refere-se a strings - armazenamento de string
	
	FILE *file; //comando de criação de arquivo no banco
	file = fopen(cpf,"r"); //comando de abertura (fopen) e leitura ("r") do arquivo no banco
	
	if(file == NULL) //caso o valor a ser consultado não retorne com nenhum resultado (NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado!.\n"); // "\n" é para pular linha
	}
	
	while(fgets(conteudo, 100, file) != NULL) //while é quando a primeira condição não é atendida. Então  a busca apresenta resultados (!= NULL)
	{
		printf("\nEssas são as informações do usuário: "); //mensagem apresentada em tela para o usuário
		printf("%s",conteudo); // comando para busca das informações na string e a apresentação do conteúdo em tela para o usuário
		printf("\n\n");
	}
	
	system("pause"); // sistema apresenta informação, até usuário dar o comando de retorno de tela
	
}

int deletar () //função responsável por excluir registros ja cadastrados no sistema
{
	char cpf[40]; //criando a variável de caractere de CPF, com limitação de 40 caracteres
	
	printf("Digite o CPF do usuário a ser deletado: "); //mensagem apresentada em tela para o usuário
	scanf("%s", cpf); ////%s refere-se a strings - armazenamento de string
	
	remove(cpf); //comando para remover o CPF informado
	
	FILE *file; //criar o arquivo
	file = fopen(cpf,"r"); // abrir o arquivo e ler "r" o conteúdo existente no banco de dados. Depois, deletar conforme comando de remoção
	
	if(file == NULL) //caso o usuário busque CPF para deletar que não exista no banco de dados
	{
		printf("O usuário não se encontra no sistema!\n"); // mensagem apresentada em tela para o usuário
		system("pause"); //sistema permanece na mesma tela até o usuário dar o comando de retorno
	}
	
}

int main () //função principal do sistema
	{
	//Definindo variáveis
	int opcao=0; 
	int laco=1;
	//Fim da definição de variáveis
	
	for(laco=1;laco=1;)
	{

		system("cls"); //responsável por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //Início do menu
		printf ("Escolha a opção desejada do menu:\n\n");
		printf ("\t1 - Registrar nomes\n");
		printf ("\t2 - Consultar nomes\n");
		printf ("\t3 - Deletar nomes\n\n");
		printf ("Opção: "); //Fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuário
	
		system("cls"); //responsável por limpar a tela
		
		switch(opcao) //início da seleção dos menus
		{
			case 1:
			registro(); //chamada de funções
			break;
			
			case 2:
			consulta(); //chamada de funções
			break;
			
			case 3:	
			deletar(); //chamada de funções
			break;
			
			default:
			printf ("Essa opção não está disponível!\n"); //chamada de funções
			system("pause");	
			break;
		}
	
	
	}
}
