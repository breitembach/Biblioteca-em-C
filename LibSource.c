//AUTHOR  lucas Breitembach

//Compara duas String se são iguais
int equals(char *string1, char *string2) {
//	char *st = string1;
//	char *st2 = string2;
	if (string1[0] != string2[0])
		return -1;
	if (string1[0] == '\0' && string2[0] == '\0')
		return 1;

	return equals(++string1, ++string2);
}

//Ignora a String maiúscula
int equalsIgnoreCase(char *string1, char *string2) {
	if (string1[0] >= 'A' && string1[0] <= 'Z')
		if (string2[0] >= 'a' && string2[0] <= 'z')
			if (string1[0] != string2[0] - 32)
				return -1;
	else
		if (string2[0] >= 'A' && string2[0] <= 'Z')
			if (string1[0] - 32 != string2[0])
				return -1;

		if(string1[0]  == '\0' && string2[0] == '\0')
			return 1;

	return equalsIgnoreCase(string1 + 1, string2 + 1);
}


char substring(char *string, int inic, int fim, char *result){

	if (inic > fim)
		return *result;

	if (inic <= fim)
		result[0] = string[inic];


	return substring(string, inic + 1, fim, result+1);
}

int toUpperCase(char *string){

       if ( *string >= 'a' && *string <= 'z' )
          *string = *string - 32;

       if(string[0] == '\0')
    	   return 1;

       return toUpperCase(++string);


}

int toLowerCase(char *string){
	if ( *string >= 'A' && *string <= 'Z' )
          *string = *string + 32;

       if(string[0] == '\0')
    	   return 1;

       return toLowerCase(++string);
    }

int length(char* string) {

	if(string[0] == '\0') {
		return 0;
	}

	return length(++string) +1;
}

int replace(char *string,char *caracterOld,char *caracterNews) {
	if(string[0] == '\0' )
		return string;
	if(string[0] == caracterOld[0]) {
		string[0] = caracterNews[0];
	}else {
		--caracterOld;
		--caracterNews;
	}


	return replace(++string,++caracterOld,++caracterNews);
}


