#include <stdio.h>
#include <string.h>

int end(char str[]){
	int i = 1, check = 1;
	char con[] = "FIN";
	
	if(strlen(str) == 4){
		check = 0;
		while(str[i] != '\0' && !check){
			if(str[i] != con[i - 1]) check = 1;
			else i++;
		}
	}
	
	return !check;
}

void cifer(char str[]){
	int des = 'p' - str[0], i = 1, aux;
	
	while(str[i] != '\0'){
		if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')){
			if(str[i] >= 'a' && str[i] <= 'z') aux = str[i] - 'a';
			else if(str[i] >= 'A' && str[i] <= 'Z') aux = str[i] - 'A';
			aux += des;
			if(aux > 25) aux -= 26;
			else if(aux < 0) aux += 26;
		}
		if(str[i] >= 'a' && str[i] <= 'z') str[i] = 'a' + aux;
		else if(str[i] >= 'A' && str[i] <= 'Z') str[i] = 'A' + aux;
		i++;
	}
}

int isVowel(char c){
	int i, is = 0;
	char vowel[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
	
	for(i = 0; i < 10; i++){
		if(c == vowel[i]) is = 1;
	}
	
	return is;
}


int countVowels(char str[]){
	int i=0, count = 0;
	
	while(str[i++] != '\0') if(isVowel(str[i])) count++;
	
	return count;
}

int main(void) {
	char str[80];
	int i;
	
	gets(str);
	cifer(str);
	while(!end(str)){
		printf("%d\n", countVowels(str));
		gets(str);
		cifer(str);
	}
	
	return 0;
}