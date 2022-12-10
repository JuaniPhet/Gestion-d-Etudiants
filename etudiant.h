#ifndef ETUDIANT_H
#define ETUDIANT_H

#define Nmax 1500


//Definition de la structure Etudiant
typedef struct{
    char nom[25];
    char prenom[25];
    char matricule[10];
    char sexe[10];
    char niveau[10];
}ETUDIANT;

//Definition du type tableau d'etudiant
typedef ETUDIANT groupe_d_etudiant[Nmax];

void ajouterEtudiant(); 

void lireEtudiant(ETUDIANT EtudiantA);

void lireDonneeEtudiant(char* identifiant);

void rangerEtudiant(ETUDIANT EtudiantB);

void parcourirFichierEtudiant();

void extraireSalle(char* salle); 

void classerParOrdreAlphabetique();

#endif // ETUDIANT_H
