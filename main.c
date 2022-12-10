#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "etudiant.h"

int main()
{
    char stop[10] = "C";
    while((strcmp(stop, "S") != 0) && (strcmp(stop, "s") != 0)){

        int choix;
        printf("\n\n");
        printf("Veuillez choisir une tache.\n\n");
        printf("(1) Ajouter un etudiant\n");
        printf("(2) Lire les donnees d'un etudiant\n");
        printf("(3) Extraire les etudiants d'une classe\n");
        printf("(4) Afficher tout les etudiants\n");
        printf("(5) Quitter le programme\n");
        printf("\n");
        scanf("%d", &choix);
        printf("\n");

        if(choix==1){
            ajouterEtudiant();
            printf("\n\n");
            do{
                printf("Taper C pour continuer et S pour sortir --> ");
                scanf("%s", &stop);
            } while ((strcmp(stop, "s")!=0 ) && (strcmp(stop, "S")!=0 ) &&  (strcmp(stop, "c")!=0 ) &&  (strcmp(stop, "C")!=0 ));
        }else if(choix == 2){
            char matriculeE[10];
            printf("Entrer le matricule de l'etudiant que vous recherchez: ");
            scanf("%s", &matriculeE);
            lireDonneeEtudiant(matriculeE);
            printf("\n\n");
            do{
                printf("Taper C pour continuer et S pour sortir --> ");
                scanf("%s", &stop);
            } while ((strcmp(stop, "s")!=0 ) && (strcmp(stop, "S")!=0 ) &&  (strcmp(stop, "c")!=0 ) &&  (strcmp(stop, "C")!=0 ));
        }else if(choix == 3){
            char niveau[8];
            printf("Quelle niveau voulez vous extraire  ?\n");
            scanf("%s", niveau);
            extraireSalle(niveau);
            printf("\n\n");
            do{
                printf("Taper C pour continuer et S pour sortir --> ");
                scanf("%s", &stop);
            } while ((strcmp(stop, "s")!=0 ) && (strcmp(stop, "S")!=0 ) &&  (strcmp(stop, "c")!=0 ) &&  (strcmp(stop, "C")!=0 ));
        }else if(choix == 4){
            classerParOrdreAlphabetique();
            printf("\n\n");
            do{
                printf("Taper C pour continuer et S pour sortir --> ");
                scanf("%s", &stop);
            } while ((strcmp(stop, "s")!=0 ) && (strcmp(stop, "S")!=0 ) &&  (strcmp(stop, "c")!=0 ) &&  (strcmp(stop, "C")!=0 ));
        }else if(choix == 5){
            printf("Voulez vous vraiment sortir ?");
            printf("\n\n");
            do{
                printf("Taper A pour annuler ou S pour confirmer la sortie --> ");
                scanf("%s", &stop);
            } while ((strcmp(stop, "s")!=0 ) && (strcmp(stop, "S")!=0 ) &&  (strcmp(stop, "a")!=0 ) &&  (strcmp(stop, "A")!=0 ));
            printf("\n***** Good Bye! :( *****");
        }else{
            printf("Choix invalide\n");
        }

    }
    return 0;
}
