#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct DateNaisRepere{
	int jour;
	int mois;
	int annee;
}dateNais;

typedef struct EtudiantRepere {
	char prenom[20];
	char nom[20];
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

void afficherTableauEtudiants(int taille ,etudiant *ptr){
	int i = 0;
	for (i = 0; i < taille; i++) {
		printf("Nom: %s  Prenom: %s\n", ptr[i].nom, ptr[i].prenom);
		printf("Age: %d\n", ptr[i].age);
		printf("Note Module: %f\n", ptr[i].note);
		printf("Date de Nassaince: %d/%d/%d\n",ptr[i].dNaissance.jour, ptr[i].dNaissance.mois, ptr[i].dNaissance.annee );
		printf("Impression de l'etudiant %d terminee.....\n", i + 1);
		printf("--------------------------------------------\n");
	}
}




int main(){
	int taille;
	etudiant *ptr;
	
	printf("Combien d'etudiants voulez-vous entrer? '");
	scanf("%d", &taille);
	
	ptr = (etudiant*)malloc(taille * sizeof(etudiant));
	
	if (ptr == NULL) {
		printf("Échec de l'allocation memoire\n");
		return 1;
	}
	
	lireTableauEtudiants(taille, ptr);
	afficherTableauEtudiants(taille, ptr);
	free(ptr);
	return 0;
}