
/* 	Simple Scytale Encryption script in C language.
	Author: Valdecir Junior
	Class: Análise e Desenvolvimento de Sistema - Fatec Lins
	Segurança da Informação
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void decrypt(){
	char mensagem[100];
	int key;
	
	printf("Digite a mensagem: ");
	fflush(stdin);gets(mensagem);
	printf("Digite a chave: ");
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
	
	printf("\n\nMensagem descriptografada: ");
	puts(matriz);
	printf("\n\n");
    system("pause");
}


void encrypt(){
	char mensagem[100];
	int key, i, j, y;
	
	printf("Digite a mensagem: ");
	fflush(stdin); gets(mensagem);
	printf("Digite a chave: ");
	fflush(stdin);scanf("%i",&key);
	
	int msg = strlen(mensagem), tam = msg/key;
	
	if((msg%key) > 0)
		tam++;
	srand((unsigned)time(NULL));
	
	int ness = tam*key;
	char newMensagem[ness], matriz[key][tam];;
	for(i=0; i<ness; i++){
		if(i<msg)
			newMensagem[i] = mensagem[i];
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
    printf("MENSAGEM CRIPTOGRAFADA: ");
    puts(newMensagem);
    printf("\n\n");
    system("pause");
}


int main(void){
	int op;
	do {
		system("cls");
	    printf("\n-----------------------------------");
		printf("\n------- BASTAO DE LICURGO ---------");
		printf("\n-----------------------------------");
	    printf("\n--- M E N U   P R I N C I P A L ---");
		printf("\n-----------------------------------");
	    printf("\n");
	    printf("\n- 1 - Criptografar");
	    printf("\n- 2 - Descriptografar");
	    printf("\n- 0 - Sair");
	    printf("\n\nOpcao-> ");
	    fflush(stdin); scanf("%i",&op); //recebe a opção do usuário
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
