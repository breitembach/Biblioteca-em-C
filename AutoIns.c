/*
 ============================================================================
 Name        : AutoIns.c
 Author      : lucas Breitembach
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LibHeader.h"

//PROTOTIPO
void readNomeCompleto(char *frase);
void readEndereco(char *frase);
void readData(char *data);
int criarCodigo(Alunos *listaAlunos);
void cadastrarAlunos(Alunos *listaAlunos,int index);
void Pesquisar(Alunos *listaAlunos);
void listarAlunos(Alunos *aluno,int i);
void criarCodigoMatricula(int index, char *nomeCompleto, char *data, int codigoAluno,char *codigoMatricula);
void alterar(Alunos *aluno);
void getSobrenome(char *string,char *result);
void menu();
void getNome(char *string,char *result);

//MAIN
int main(void) {
	setbuf(stdout, NULL);

	menu();

	return 0;
}

void menu() {
	int op ;
	int index;
	int tamanhoLista;
	Alunos *listaAlunos;
	do{
			printf("\n1 – Cadastro de alunos\n"
					"\n2 – Pesquisar\n"
					"\n3 – Alterar\n"
					"\n4 – Finalizar\n"
					"\nDigite sua opção: \n");
			fflush(stdin);
			scanf("%d", &op);

			switch(op) {
			case 1:
				if(tamanhoLista == 0){
					listaAlunos = (Alunos*)calloc(10, sizeof(Alunos));
					tamanhoLista++;
				}
				cadastrarAlunos(listaAlunos, index);
				printf("Aluno Cadastrado com Sucesso!");
				index++;

				break;

			case 2:
				if(!tamanhoLista == 0) {
					Pesquisar(listaAlunos);
				}else {
					printf("Não Existem Alunos Cadastrados!");
				}
				break;
			case 3:
				if(!tamanhoLista == 0){
				alterar(listaAlunos);

				}else {
					printf("Não Existem Alunos Cadastrados!");
				}
				break;
			case 4:
				printf("\nPrograma finalizado\n");

				free(listaAlunos);
				break;
			default:
				printf("\nOpção inválida.\n");
			}



		} while (op != 4);

}

void cadastrarAlunos(Alunos *listaAlunos,int index) {

	readNomeCompleto(listaAlunos[index].nomeCompleto);
	readEndereco(listaAlunos[index].endereco);
	readData(listaAlunos[index].data);
	listaAlunos[index].codigo = criarCodigo(listaAlunos) +1;
	//funcão pra criar Matrícula
	criarCodigoMatricula(index, listaAlunos[index].nomeCompleto,
			listaAlunos[index].data, listaAlunos[index].codigo, listaAlunos[index].codigoMatricula);



}


void readNomeCompleto(char *frase){
	char valid = 'n';
	int i;
	do{

		printf("Digite seu (nome e sobrenome): ");
		fflush(stdin);
		gets(frase);


		char first = frase[0];
		toLowerCase(frase);

		toUpperCase(&first);

		for (i = 0; i < Util.length(frase); ++i) {
			frase[0] = first;
			if(frase[i] == ' ') {
				printf("\n %c",frase[i]);
				valid = 's';
				char up = frase[++i];

				toUpperCase(&up);

				frase[i] = up;


			}
		}


		if (Util.length(frase) == '\0' || valid == 'n'){
			printf("\n Nome inválido\n");
		}
	} while (Util.length(frase) == '\0' || valid == 'n');


}


void readEndereco(char *frase){
	char valid = 'n';
	int i;
	do{

		printf("\nDigite o Endereço(rua,400): ");
		fflush(stdin);
		gets(frase);
		char first = frase[0];
		toLowerCase(frase);

		toUpperCase(&first);

		for (i = 0; i < Util.length(frase); ++i) {
			frase[0] = first;
			if(frase[i] == ' ') {
				printf("\n %c",frase[i]);

				char up = frase[++i];

				toUpperCase(&up);

				frase[i] = up;
				valid = 's';

			}

			if(frase[i] == ',') {
				valid = 's';
			}else if(frase[i] >= 48 && frase[i] <= 57) {
				valid ='s';
			}else valid ='n';

			if(frase[Util.length(frase)-2] >= 48 && frase[Util.length(frase)-1] <= 57) {
				valid ='s';
			}else valid = 'n';
		}

		if (Util.length(frase) == '\0' || valid == 'n'){
			printf("\n Endereço inválido, Sugestão: cruzeiro,200\n");
		}
	} while (Util.length(frase) == '\0' || valid == 'n');


}

void readData(char *frase) {
	char valid = 'n';

	char dia[2];
	char mes[2];
	char ano[4];

	do{
		printf("Digite a Data (dd/mm/yyyy):");
		fflush(stdin);
		gets(frase);

		Util.substring(frase,0,1,dia);
		Util.substring(frase,3,4,mes);
		Util.substring(frase,6,10,ano);

		if((dia[1] >= 48 && dia[1] <= 57) &&
			(mes[1] >= 48 && mes[1] <= 57) &&
			(ano[1] >= 48 && ano[1] <= 57) &&
			(ano[2] >= 48 && ano[2] <= 57) &&
			(ano[3] >= 48 && ano[3] <= 57) &&
			(frase[5] == '/' && frase[2] == '/') &&
			(dia[0] >= 48 && dia[0] <= 57) &&
			(mes[0] >= 48 && mes[0] <= 57) &&
			(ano[0] >= 48 && ano[0] <= 57)) {

			valid = 's';
		}else valid = 'n';

		if (Util.length(frase) == '\0' || valid == 'n' || Util.length(frase) < 10){
			printf("\n Data inválida \n");
		}

		} while (Util.length(frase) == '\0' || valid == 'n' || Util.length(frase) < 10);

}


int criarCodigo(Alunos *alunos) {
	int tam = 0;
	int i =0;

	for (i = 0; i < 10; ++i) {
		tam += alunos[i].codigo;
	}

	return tam;
}

void Pesquisar(Alunos *listaAlunos) {
	int i;
	int j;
	char encontrou = 'n';
	int op;
	char pesquisa[20];
	char numeroCasa[20];
	char sobrenome[100];
	char ano[4];
	char mes[2];

	do {
		printf("\n1 – Buscar pelo Número da casa\n"
						"\n2 – Buscar pelo sobrenome\n"
						"\n3 – Buscar pelo Ano de nascimento\n"
						"\n4 – Buscar pelo Mes de nascimento\n"
						"\n5 – Buscar pela Matrícula\n"
						"\n0 – Voltar Menu Inicial\n"
						"\nDigite sua opção: \n");

		fflush(stdin);
		scanf("%d",&op);

			switch (op) {
				case 1:

					printf("Digite o Numero da casa: ");
					fflush(stdin);
					gets(pesquisa);

					for (i = 0; i < 10; ++i) {
						for (j = 0; j < Util.length(listaAlunos[i].endereco); ++j) {
							if(listaAlunos[i].endereco[j] == ',') {

								Util.substring(listaAlunos[i].endereco,j+1,10 ,numeroCasa);

								if(Util.equals(numeroCasa,pesquisa) == 1) {
									encontrou = 's';
									listarAlunos(listaAlunos,i);
									break;

								}
							}

						}



					}

					if(encontrou == 'n')
					printf("não existem Alunos com esse ano!");


					break;
				case 2:

					printf("Digite o Sobrenome: ");
						fflush(stdin);
						gets(pesquisa);
						char first = pesquisa[0];
							toLowerCase(pesquisa);
							toUpperCase(&first);
							pesquisa[0] = first;

						for (i = 0; i < 10; ++i) {
							for (j = 0; j < Util.length(listaAlunos[i].nomeCompleto); ++j) {
								if(listaAlunos[i].nomeCompleto[j] == ' ') {

									Util.substring(listaAlunos[i].nomeCompleto, j+1, 50 ,sobrenome);

									if(Util.equals(sobrenome,pesquisa) == 1) {

										listarAlunos(listaAlunos,i);
										break;

									}else {
										printf("Não Encontrou Sobrenome");

									}

								}

							}


						}

					break;

				case 3:
					printf("Digite o Ano de nascimento: ");
					fflush(stdin);
					gets(pesquisa);

					for (i = 0; i < 10; ++i) {

						Util.substring(listaAlunos[i].data,6,10,ano);

						if(Util.equals(ano,pesquisa) == 1) {
							encontrou = 's';
							listarAlunos(listaAlunos,i);
							break;

						}


					}
					if(encontrou == 'n')
					printf("não existem Alunos com esse ano!");

					break;
				case 4:
					printf("Digite o Mês de Nascimento: ");
					fflush(stdin);
					gets(pesquisa);


					for (i = 0; i < 10; ++i) {

						Util.substring(listaAlunos[i].data,3,4,mes);
						if(Util.equals(mes,pesquisa) == 1) {
							encontrou = 's';
							listarAlunos(listaAlunos,i);
							break;

						}

					}

					if(encontrou == 'n')
					printf("não existem Alunos com esse MES!");
					break;
				case 5:
					printf("Digite A Matrícula: ");
					fflush(stdin);
					gets(pesquisa);


					for (i = 0; i < 10; ++i) {

						if(Util.equals(listaAlunos[i].codigoMatricula,pesquisa) == 1) {
							encontrou = 's';
							listarAlunos(listaAlunos,i);
							break;

						}
					}

					if(encontrou == 'n')
					printf("não existem Alunos com Essa matrícula!");

					break;
				case 0:

					break;
				default:
					printf("\nOpção Inválida");
			}

		}while(op != 0);


}
void listarAlunos(Alunos *aluno,int i) {


//		if(!aluno[i].codigo == 0)
		printf("\n Nome :%s \n Endereço: %s \n Data: %s \n Codigo: %d\n codigoMatricula: %s \n",
				aluno[i].nomeCompleto,
				aluno[i].endereco,
				aluno[i].data,
				aluno[i].codigo,
				aluno[i].codigoMatricula);

}

void criarCodigoMatricula(int index, char *nomeCompleto, char *data, int codigoAluno,char *codigoMatricula) {

	char ano[4];
	Util.substring(data,6,10,ano);
	char first = nomeCompleto[0];
	char last = nomeCompleto[Util.length(nomeCompleto)-1];
	char codigoAlunoToChar[2];

	//int to char
	itoa(codigoAluno,codigoAlunoToChar,10);


	codigoMatricula[0] = first;
	codigoMatricula[1] = last;
	codigoMatricula[2] = ano[0];
	codigoMatricula[3] = ano[1];
	codigoMatricula[4] = ano[2];
	codigoMatricula[5] = ano[3];
	codigoMatricula[6] = codigoAlunoToChar[0];



}

void alterar(Alunos *aluno) {
	int op;
	int i;
	char pesquisa[50];
	char pesquisaAlterar[100];
	char encontrou = 'n';

	do{
		printf("\n1 – Alterar Nome\n"
				"\n2 – Alterar Sobrenome\n"
				"\n3 – Alterar ano de nascimento\n"
				"\n4 – Voltar Ao menu Anterior\n"
				"\nDigite sua opção: \n");
		fflush(stdin);
		scanf("%d", &op);

		switch(op) {
		case 1:
			printf("\nDigite sua Data de nascimento:");
			fflush(stdin);
			gets(pesquisa);

			printf("\nDigite seu NOVO nome para Alterar:");
			fflush(stdin);
			gets(pesquisaAlterar);

			char first = pesquisaAlterar[0];
			toLowerCase(pesquisaAlterar);
			toUpperCase(&first);

			printf("pesuqisa:%s",pesquisaAlterar);
			for (i = 0; i < 10; ++i) {

				if(Util.equals(aluno[i].data, pesquisa) == 1) {
					encontrou = 's';
					char nomeAluno[100];

					getNome(aluno[i].nomeCompleto,nomeAluno);
					replace(aluno[i].nomeCompleto,nomeAluno,pesquisaAlterar);
					criarCodigoMatricula(i,aluno[i].nomeCompleto,aluno[i].data,aluno[i].codigo, aluno[i].codigoMatricula);

					break;

				}

			}

			if(encontrou == 'n')
			printf("não existem Alunos com esse ano!");



			break;

		case 2:
			printf("\nDigite sua Data de nascimento:");
			fflush(stdin);
			gets(pesquisa);

			printf("\nDigite seu NOVO Sobrenome para Alterar:");
			fflush(stdin);
			gets(pesquisaAlterar);

			for (i = 0; i < 10; ++i) {

				if(Util.equals(aluno[i].data, pesquisa) == 1) {
					encontrou = 's';
					char sobrenomeAluno[100];

					getSobrenome(aluno[i].nomeCompleto,sobrenomeAluno);
					replace(aluno[i].nomeCompleto,sobrenomeAluno,pesquisaAlterar);
					criarCodigoMatricula(i,aluno[i].nomeCompleto,aluno[i].data,aluno[i].codigo, aluno[i].codigoMatricula);
					printf("\nSobrenome Alterado com Sucesso!");
					break;

				}

			}

			if(encontrou == 'n')
			printf("não existem Alunos com esse ano!");


			break;
		case 3:

			printf("\nDigite sua Data de nascimento:");
			fflush(stdin);
			gets(pesquisa);

			printf("\nDigite seu NOVO ano de Nascimento para Alterar:");
			fflush(stdin);
			gets(pesquisaAlterar);

			for (i = 0; i < 10; ++i) {

				if(Util.equals(aluno[i].data, pesquisa) == 1) {
					encontrou = 's';
					char ano[4];
					Util.substring(aluno[i].data,6,10,ano);

					replace(aluno[i].data,ano,pesquisaAlterar);
					criarCodigoMatricula(i,aluno[i].nomeCompleto,aluno[i].data,aluno[i].codigo, aluno[i].codigoMatricula);
					printf("\nAno alterado com Sucesso!");
					break;

				}

			}

			if(encontrou == 'n')
			printf("não existem Alunos com esse ano!");


			break;
		case 4:
			printf("\n voltando\n");
			break;

		default:
			printf("\nOpção inválida.\n");
		}



	} while (op != 4);
}

void getNome(char *string,char *result) {

	while(*string) {
		if(string[0] == ' '){
			break;
		}
		result[0] = string[0];
		++string;
		++result;
	}
}

void getSobrenome(char *string,char *result) {
	char init = 'n';
	while(*string) {

		if(string[0] == ' ' || init == 's'){

			if(init == 's'){
			result[0] = string[0];

			++result;
			}
			init = 's';
		}
		++string;
	}

}



