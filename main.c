#include <stdio.h>
#include <string.h>

struct funcionarios{
	char nome[36];
	char cargo[16];
	float diaria;
	int id;
	char nome_cardapio[16];
};
int separaNomeDeCargo(char *nome, char *cargo){

	//verificar se tem no nome (chefe, recepcionista, garcom)
	char *ponteiro;
	ponteiro = strstr(nome, "chefe");
	int tamanhoChar;
	if(ponteiro != NULL){
		//chefe foi encontrado

		//tratar nome
		tamanhoChar = strlen(nome);
		nome[tamanhoChar-7] = '\0';
		strcpy(cargo, "chefe");
		return 1;
	}

	ponteiro = strstr(nome, "recepcionista");
	if(ponteiro != NULL){
		//recepcionista foi encontrado

		//tratar nome
		tamanhoChar = strlen(nome);
		nome[tamanhoChar-15] = '\0';
		strcpy(cargo, "recepcionista");
		return 1;
	}

	ponteiro = strstr(nome, "garcom");
	if(ponteiro != NULL){
		//garcom foi encontrado

		//tratar nome
		tamanhoChar = strlen(nome);
		nome[tamanhoChar-8] = '\0';
		strcpy(cargo, "garcom");
		return 1;
	}
	return 0;

	
}
int main(){

	struct funcionarios f1[10];

	//*****************************************************************Entrada de arquivos
	FILE *file = NULL;
	file = fopen("funcionarios.txt", "r");

	if (file == NULL) {
        printf("Erro ao abrir o arquivo funcionarios.\n");
        return 1;
    }
    int qtd_func = 0;
    int in = fscanf(file, " %[^1-9]", f1[qtd_func].nome);
    while(in != EOF){

    	
    	separaNomeDeCargo(f1[qtd_func].nome, f1[qtd_func].cargo);
    	if(strcmp(f1[qtd_func].cargo, "chefe")==0)
    	{
    		fscanf(file, "%f %d %s",&f1[qtd_func].diaria, &f1[qtd_func].id, f1[qtd_func].nome_cardapio);
    	}else{
    		fscanf(file, "%f %d", &f1[qtd_func].diaria, &f1[qtd_func].id);
    	}
    	qtd_func++;
    	in = fscanf(file, " %[^1-9]", f1[qtd_func].nome);

    }

    for(int i = 0; i < qtd_func; i++){
    	printf("nome:%s\tcargo:%19s\tdiaria:%.2f\tid:%d\tcardapio:%s\n",f1[i].nome, f1[i].cargo, f1[i].diaria, f1[i].id, f1[i].nome_cardapio);
    }



	//*****************************************************************Menu Login



	//*****************************************************************Menu funcionarios






    fclose(file);
	return 0;
}