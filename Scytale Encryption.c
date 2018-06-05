
/* 	Simple Scytale Encryption script in C language.
	Author: Valdecir Junior
	Class: Análise e Desenvolvimento de Sistema - Fatec Lins
	Segurança da Informação
	
	Credits:
	strlen and str_replace functions made by github.com/amcsi
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int strlen(char* str) {
	int ret = 0;
	while (str[ret]) {
		ret++;
	}
	return ret;
}

char* str_replace(char* search, char* replace, char* subject) {
	int i, j, k;
	
	int searchSize = strlen(search);
	int replaceSize = strlen(replace);
	int size = strlen(subject);

	char* ret;

	if (!searchSize) {
		ret = malloc(size + 1);
		for (i = 0; i <= size; i++) {
			ret[i] = subject[i];
		}
		return ret;
	}
	
	int retAllocSize = (strlen(subject) + 1) * 2; // Allocation size of the return string.
    // let the allocation size be twice as that of the subject initially
	ret = malloc(retAllocSize);

	int bufferSize = 0; // Found characters buffer counter
	char* foundBuffer = malloc(searchSize); // Found character bugger
	
	for (i = 0, j = 0; i <= size; i++) {
		/**
         * Double the size of the allocated space if it's possible for us to surpass it
		 **/
		if (retAllocSize <= j + replaceSize) {
			retAllocSize *= 2;
			ret = (char*) realloc(ret, retAllocSize);
		}
		/**
         * If there is a hit in characters of the substring, let's add it to the
         * character buffer
		 **/
		else if (subject[i] == search[bufferSize]) {
			foundBuffer[bufferSize] = subject[i];
			bufferSize++;

			/**
             * If the found character's bugger's counter has reached the searched substring's
             * length, then there's a hit. Let's copy the replace substring's characters
             * onto the return string.
			 **/
			if (bufferSize == searchSize) {
				bufferSize = 0;
				for (k = 0; k < replaceSize; k++) {
					ret[j++] = replace[k];
				}
			}
		}
		/**
         * If the character is a miss, let's put everything back from the buffer
         * to the return string, and set the found character buffer counter to 0.
		 **/
		else {
			for (k = 0; k < bufferSize; k++) {
				ret[j++] = foundBuffer[k];
			}
			bufferSize = 0;
			/**
             * Add the current character in the subject string to the return string.
			 **/
			ret[j++] = subject[i];
		}
	}

	/**
	 * Free memory
	 **/
	free(foundBuffer);
	
	return ret;
}

void decrypt(){
	char mensagem[100];
	int key;
	
	printf("Type the encrypted message: ");
	fflush(stdin);gets(mensagem);
	printf("Type the key: ");
	fflush(stdin);scanf("%i",&key);
	
	
	int i, j, y, msg = strlen(mensagem), tam = msg/key;
	char matriz[key][tam], retorno[msg];
	
	y=0;
	for (i=0; i<tam; i++){
    	for (j=0; j<key; j++){
    		matriz[j][i] = mensagem[y];
    		y++;
		}
	}
	
	printf("\n\nDecrypted message: ");
	puts(matriz);
	printf("\n\n");
    system("pause");
}


void encrypt(){
	char mensagem[100];
	int key, i, j, y;
	
	printf("Type the message: ");
	fflush(stdin); gets(mensagem);
	char* new_msg = str_replace(" ", "", mensagem);
	printf("Type the key: ");
	fflush(stdin);scanf("%i",&key);
	
	int msg = strlen(new_msg), tam = msg/key;
	
	if((msg%key) > 0)
		tam++;
	srand((unsigned)time(NULL));
	
	int ness = tam*key;
	char newMensagem[ness], matriz[key][tam];;
	for(i=0; i<ness; i++){
		if(i<msg)
			newMensagem[i] = new_msg[i];
		else
			newMensagem[i] = (char)(65 + rand()%26);
	}
	
	y=0;
	for (i=0; i<key; i++)
    	for (j=0; j<tam; j++,y++)
    		matriz[i][j] = newMensagem[y];

	y=0;
	for (i=0; i<tam; i++)
    	for (j=0; j<key; j++,y++)
    		newMensagem[y] = toupper(matriz[j][i]);
    
		
	printf("\n\n");
    printf("ENCRYPTED MESSAGE: ");
    puts(newMensagem);
    printf("\n\n");
    system("pause");
}


int main(void){
	int op;
	do {
		system("cls");
	    printf("\n-----------------------------------");
		printf("\n------- Scytale Encryption --------");
		printf("\n-----------------------------------");
	    printf("\n--- C H O S E  ONE  O P T I O N ---");
		printf("\n-----------------------------------");
	    printf("\n");
	    printf("\n- 1 - Encript");
	    printf("\n- 2 - Decrypt");
	    printf("\n- 0 - exit");
	    printf("\n\nOption-> ");
	    fflush(stdin); scanf("%i",&op);
	    switch(op){
		  	case 1:
		        encrypt();
		        break;
		    case 2:
		     	decrypt();
		      	break;
		}
	}while(op!=0);

  	getch();
  	return(0);
}
