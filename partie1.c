#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct DateNaisRepere{
	int jour;
	int mois;
	int annee;
}dateNais;

typedef struct EtudiantRepere {
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

void afficherEtudiant(etudiant *etu) {
    printf("Nom: %s\n", etu->nom );
    printf("Age: %d\n", etu->age );
    printf("Note: %.2f\n", etu->note );
    printf("Date de naissance: %d/%d/%d\n", etu->dNaissance.jour, etu->dNaissance.mois, etu->dNaissance.annee );
    printf("Done......\n");
}

void lireEtudiant(){
	etudiant etu;
	char dateString[20];
	int dateArr[3];
	
	
	printf("Entrez le nom de l'etudiant: ");
	scanf("%s", &etu.nom);
	
	printf("Entrez l'age de l'etudiant: ");
	scanf("%d", &etu.age);
	
	printf("Entrez la note de Maths de l'etudiant: ");
	scanf("%f", &etu.note);
	
	printf("Entrez la date de naissance de l'etudiant: [jour],[mois],[annee] : ");
	scanf("%s", &dateString);
	
	delimiterDate(dateString, dateArr);	
	etu.dNaissance.annee = dateArr[2];
	etu.dNaissance.mois = dateArr[1];
	etu.dNaissance.jour = dateArr[0];
	
	afficherEtudiant(&etu);
}



int main(){
	
	lireEtudiant();
	return 0;
}