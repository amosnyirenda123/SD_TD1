#include <stdlib.h>
#include <stdio.h>
#include <string.h>


float sommeNotes = 0;
int ageState = 0;

typedef struct DateNaisRepere{
	int jour;
	int mois;
	int annee;
}dateNais;

typedef struct Note{
	float math;
	float physique;
	float science;
	int nbrModule;
} note;

typedef struct EtudiantRepere {
	char prenom[50];
	char nom[50];
	int age;
	note noteEtu;
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

void validerDateNaissance(int annee, int age) {
    int difference = 2024 - annee;
    if (difference == age) {
        ageState = 1;  
    } else {
        printf("L'age et l'annee de naissance ne correspondent pas. Veuillez reessayer.\n");
        ageState = 0;  
    }
}


void lireTableauEtudiants(int taille, etudiant *ptr)
{
	char dateString[20];
	int dateArr[3], age, i = 0;
	
	for (i = 0; i < taille; i++) {
		printf("Entrez le nom de l'etudiant: ");
		scanf("%s", ptr[i].nom);
		printf("Entrez le prenom de l'etudiant: ");
		scanf("%s", ptr[i].prenom);
		do {
            printf("Entrez la date de naissance de l'etudiant: [jour],[mois],[annee]: ");
            scanf("%s", dateString);
            delimiterDate(dateString, dateArr); 
            ptr[i].dNaissance.jour = dateArr[0];
            ptr[i].dNaissance.mois = dateArr[1];
            ptr[i].dNaissance.annee = dateArr[2];
            
            printf("Entrez l'age de l'etudiant: ");
            scanf("%d", &age);
            
            validerDateNaissance(dateArr[2], age); 
            
        } while (ageState == 0);  
        
        ptr[i].age = age;

		printf("Entrez la note de Maths de l'etudiant: ");
		scanf("%f", &ptr[i].noteEtu.math);
		printf("Entrez la note de Physique de l'etudiant: ");
		scanf("%f", &ptr[i].noteEtu.physique);
		printf("Entrez la note de Science de l'etudiant: ");
		scanf("%f", &ptr[i].noteEtu.science);
		
		
		
		
		ptr[i].noteEtu.nbrModule = 3;
		
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

void calculerMoyennePonderee(etudiant *ptr, int taille, float moyPond[]){
	int i;
	for(i = 0; i < taille; i++){
		moyPond[i] = (2*ptr[i].noteEtu.math + ptr[i].noteEtu.physique + ptr[i].noteEtu.science) / (2 + 1 + 1);
	}
	
	
}


void afficherTableauEtudiants(int taille ,etudiant *ptr, int notes[]){
	int i = 0;
	float moyPond[taille];
	
	calculerMoyennePonderee(ptr, taille, moyPond);
	
	
	for (i = 0; i < taille; i++) {
		notes[i] = (ptr[i].noteEtu.math + ptr[i].noteEtu.physique + ptr[i].noteEtu.science) / ptr[i].noteEtu.nbrModule;
		printf("Informations pour l'étudiant %d :\n", i + 1);
		printf("%s %s, %d ans, Maths:  %.1f/20, Physique: %.1f/20, Science: %.1f/20, Moyenne Ponderee: %.2f, ne le  %d/%d/%d \n", ptr[i].nom,
		 ptr[i].prenom,  ptr[i].age, ptr[i].noteEtu.math, ptr[i].noteEtu.physique, ptr[i].noteEtu.science, moyPond[i] , 
		 ptr[i].dNaissance.jour, ptr[i].dNaissance.mois, ptr[i].dNaissance.annee );
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