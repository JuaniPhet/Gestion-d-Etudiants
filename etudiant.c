#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "etudiant.h"

int counter = 0;
groupe_d_etudiant groupe;

void ajouterEtudiant(){
    ETUDIANT newE;
    printf("-> Nom: ");
    scanf("%s", &newE.nom);
    printf("-> Prenom: ");
    scanf("%s", &newE.prenom);
    printf("-> Matricule: ");
    scanf("%s", &newE.matricule);
    printf("-> Sexe('M' ou 'F'): ");
    scanf("%s", &newE.sexe);
    printf("-> Niveau(Exemple: INF1): ");
    scanf("%s", &newE.niveau);

    groupe[counter] = newE;
    counter++;
    rangerEtudiant(newE);

    printf("\n***** Ajout reussi! :) *****");
}

void lireEtudiant(ETUDIANT EtudiantA){
    printf("->Nom: %s, Prenom: %s, Matricule: %s, Sexe: %s, Niveau: %s \n",
        EtudiantA.nom, EtudiantA.prenom, EtudiantA.matricule, EtudiantA.sexe, EtudiantA.niveau);
}

void lireDonneeEtudiant(char* identifiant){
    groupe_d_etudiant tab;
    int nbrEtu = 0;

    FILE *fic = fopen("etudiant.txt", "r+");
    if(fic == NULL)
        exit(1);

    while(fscanf(fic, "%s\t %s\t %s\t %s\t %s\t", &tab[nbrEtu].nom, &tab[nbrEtu].prenom, &tab[nbrEtu].matricule, &tab[nbrEtu].sexe, &tab[nbrEtu].niveau) != EOF)
        nbrEtu++;

    fclose(fic);

    for (int i = 0; i < nbrEtu; i++){
        if(strcmp(tab[i].matricule, identifiant) == 0){
            lireEtudiant(tab[i]);
            break;
        }
    }
}

void rangerEtudiant(ETUDIANT EtudiantB){
    FILE *fic = fopen("etudiant.txt", "a");

    if(fic == NULL)
        exit(1);

    fprintf(fic,"%s\t %s\t %s\t %s\t %s\t\n", EtudiantB.nom, EtudiantB.prenom, EtudiantB.matricule, EtudiantB.sexe, EtudiantB.niveau);

    fclose(fic);
}

void extraireSalle(char* salle){
    char destination[15];
    strcpy(destination, salle);
    strcat(destination, ".txt");

    groupe_d_etudiant tab;
    int nbrEtu = 0;
    FILE *fic = fopen("etudiant.txt", "r+");
    if(fic == NULL)
        exit(1);

    while(fscanf(fic, "%s\t %s\t %s\t %s\t %s\t", &tab[nbrEtu].nom, &tab[nbrEtu].prenom, &tab[nbrEtu].matricule, &tab[nbrEtu].sexe, &tab[nbrEtu].niveau) != EOF)
        nbrEtu++;

    fclose(fic);

    for(int i=0; i<nbrEtu; i++) {
        if(strcmp(tab[i].niveau, salle) == 0){
            FILE *fic = fopen(destination, "a+");
            if(fic == NULL)
                exit(1);

            fprintf(fic,"->Nom: %s, Prenom: %s, Matricule: %s, Sexe: %s, Niveau: %s \n",
            tab[i].nom, tab[i].prenom, tab[i].matricule, tab[i].sexe, tab[i].niveau);
            fclose(fic);
        }
    }
} 

void classerParOrdreAlphabetique(){
    groupe_d_etudiant tab;
    int nbrEtu = 0;
    int min;
    ETUDIANT temp;

    FILE *fic = fopen("etudiant.txt", "r+");
    if(fic == NULL)
        exit(1);

    while(fscanf(fic, "%s\t %s\t %s\t %s\t %s\t", &tab[nbrEtu].nom, &tab[nbrEtu].prenom, &tab[nbrEtu].matricule, &tab[nbrEtu].sexe, &tab[nbrEtu].niveau) != EOF)
        nbrEtu++;

    fclose(fic);

    for(int i = 0; i < nbrEtu-1; i++){
        min = i;
        for (int j = i+1; j < nbrEtu; j++){
            if(strcmp(tab[j].nom, tab[min].nom) < 0)
                min = j;
            else if(strcmp(tab[j].nom, tab[min].nom) == 0 && strcmp(tab[j].prenom, tab[min].prenom) < 0)
                min = j;
            else if(strcmp(tab[j].prenom, tab[min].prenom) == 0 && strcmp(tab[j].matricule, tab[min].matricule) < 0)
                min = j;
        }
        if(min != i){
            temp = tab[i];
            tab[i] = tab[min];
            tab[min] = temp;
        }
    }

    printf("\nListe des etudiants");
    printf("\nNom\t Prenom\t Matricule\t Sexe\t Niveau");
    for (int k = 0; k < nbrEtu; k++){
        printf("\n%s\t %s\t %s\t %s\t %s\t", tab[k].nom, tab[k].prenom, tab[k].matricule, tab[k].sexe, tab[k].niveau);
    }
}
