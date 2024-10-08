#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int sommeNotes = 0;

typedef struct DateNaisRepere{
	int jour;
	int mois;
	int annee;
}dateNais;

typedef struct EtudiantRepere {
	char prenom[50];
	char nom[50];
	int age;
	float note;
	dateNais dNaissance;
} etudiant;

void delimiterDate(char *dateString, int dateArr[3]) {
    char *delim = ",";
    char *token;
    int i = 0;

    
    token = strtok(dateString, delim);
    
    
    while (token != NULL && i < 3) { 
        dateArr[i] = atoi(token);  
        token = strtok(NULL, delim); 
        i++;
    }
}


void lireTableauEtudiants(int taille, etudiant *ptr)
{
	int i = 0;
	char dateString[20];
	int dateArr[3];
	
	for (i = 0; i < taille; i++) {
		printf("Entrez le nom de l'etudiant: ");
		scanf("%s", &ptr[i].nom);
		printf("Entrez le prenom de l'etudiant: ");
		scanf("%s", &ptr[i].prenom);
		
		printf("Entrez l'age de l'etudiant: ");
		scanf("%d", &ptr[i].age);
		
		printf("Entrez la note de l'etudiant: ");
		scanf("%f", &ptr[i].note);
		
		printf("Entrez la date de naissance de l'etudiant: [jour],[mois],[annee]: ");
		scanf("%s", &dateString);
		
		delimiterDate(dateString, dateArr);	
		ptr[i].dNaissance.annee = dateArr[2];
		ptr[i].dNaissance.mois = dateArr[1];
		ptr[i].dNaissance.jour = dateArr[0];
		
		printf("--------------------------------------------\n");
		
		printf("Lecture de l'etudiant %d terminee....\n", i + 1);
	}
	printf("==================================================================\n");
}



int sommeNotesRecursif(int A[], int N) 
{ 
    if (N <= 0) 
        return 0; 
    return (sommeNotesRecursif(A, N - 1) + A[N - 1]); 
}

float calculerMoyenne(int taille){
	float moy = 0;
	if(taille == 0){
		return -1;
	}else{
		moy = sommeNotes / taille;
	}
	
	return moy;
}


void afficherTableauEtudiants(int taille ,etudiant *ptr, int notes[]){
	int i = 0;
	for (i = 0; i < taille; i++) {
		notes[i] = ptr[i].note;
		printf("Informations pour l'étudiant %d :\n", i + 1);
		printf("%s %s, %d ans, %.1f/20, ne le  %d/%d/%d \n", ptr[i].nom, ptr[i].prenom,  ptr[i].age, ptr[i].note, ptr[i].dNaissance.jour, ptr[i].dNaissance.mois, ptr[i].dNaissance.annee );
	}
	
	sommeNotes = sommeNotesRecursif(notes, taille);
	printf("--------------------------------------------\n");
}





int main(){
	int taille;
	etudiant *ptr;
	
	printf("Combien d'etudiants voulez-vous entrer? '");
	scanf("%d", &taille);
	
	if(taille > 0){
		ptr = (etudiant*)malloc(taille * sizeof(etudiant));
	
		if (ptr == NULL) {
			printf("Échec de l'allocation memoire\n");
			return 1;
		}
	
		int notes[taille];
		lireTableauEtudiants(taille, ptr);
		afficherTableauEtudiants(taille, ptr, notes);
		printf("La moyenne des notes est : %.2f", calculerMoyenne(taille));
		free(ptr);
	}else {
	 printf("La taille doit etre une valuer strictement positive.");
	}
		

	return 0;
}