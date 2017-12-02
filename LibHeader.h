/*
 * LibHeader.h
 *
 *  Created on: 24 de nov de 2017
 *      Author: lucas Breitembach
 */

#ifndef LIBHEADER_H_
#define LIBHEADER_H_


//Estruturas

struct Funcoes{
    int (*equals)(char*, char*);
    int (*equalsIgnoreCase)(char*, char*);
    int (*toUpperCase)(char*);
    int (*toLowerCase)(char*);
    int (*length)(char*);
    char (*substring)(char*, int, int ,char* );
    int (*replace)(char*,char,char);

};
typedef struct Funcoes Funcoes;

struct Alunos {
	char codigoMatricula[50];
	char nomeCompleto[100];
	char endereco[100];
	char data[15];
	int codigo;
};
typedef struct Alunos Alunos;

//prototipos
int equals(char *string1, char *string2);
int equalsIgnoreCase(char *string1, char *string2);
char substring(char *string, int inic, int fim, char *result);
int toUpperCase(char *string);
int toLowerCase(char *string);
int length(char *string);
int replace(char *string, char *caracterOld, char *caracterNews);

//Para Chamar as funcoes use Func

Funcoes Util = {.equals = equals,.equalsIgnoreCase = equalsIgnoreCase,.toUpperCase = toUpperCase,
		.toLowerCase = toLowerCase,.length = length,.substring = substring,.replace = replace};




#endif /* LIBHEADER_H_ */
