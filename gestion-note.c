#include <stdio.h>
#include <string.h>
typedef struct
{
   char nom[20];
   int notes[5];
}etudiant;
typedef struct
{
   char nom[20];
   float moyenne;
}resultat;
int main(){
    int coeff[5]={1,3,2,4,1};
    int sommecoeff=11;
    int i,j,sommepondereer=0,produit;
    etudiant etudiants[5];
    for (i=0;i<5;i++){
        printf("Nom de l'éleve %d :",i+1);
        scanf("%s",etudiants[i].nom);
        for (j=0;j<5;j++){
            printf("note %d : ",j+1);
            scanf("%d",&etudiants[i].notes[j]);
        }
    }
    resultat resultats[5];
    for(i=0;i<5;i++){
        sommepondereer=0;
        for (j=0;j<5;j++){
            produit=etudiants[i].notes[j]*coeff[j];
            sommepondereer += produit;
        }
        resultats[i].moyenne=(float)sommepondereer/sommecoeff;
        strcpy(resultats[i].nom,etudiants[i].nom);
    }
    for (i=0;i<4;i++){
        for (j=i+1;j<5;j++){
            if (resultats[i].moyenne<resultats[j].moyenne){
                resultat temp = resultats[i];
                resultats[i]=resultats[j];
                resultats[j]=temp;
            }
        }
    }
    printf("classement des eleves :\n");
    printf("%-20s| Moyenne | Rang\n","Nom");
    printf("------------------------------------------\n");
    for (i=0;i<5;i++){
        printf("%-20s| %7.2f  | %d\n",resultats[i].nom,resultats[i].moyenne,i+1);
    }
    return 0;
}