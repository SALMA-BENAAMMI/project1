#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//les structures 
typedef struct {
    int jour,annee;
    char mois[10];
}Date;

typedef struct {

    char nom[20],prenom[20],ID_client[20],num_compteur[20],mot_de_pass[20],quartier[20],residence[20],ville[20];
    Date date_naissance;

}Client ;

typedef struct {
    float montant ,consommation ;
    int num_facture,num_contrat;
    Date date_facture,date_echeance;
}Facture ;

FILE *fp;


void Ajouter_facture()
{
    Client C;
    Facture F1;
    int n,n1;
    int tr,tr1;
    n=RechercherClient();
    n1=Rechercher_Facture();
     if(n==0)
          exit(1);
     if (n == 1 && n1 != 1){
             fp=fopen("Factures.txt","a+");
              if(fp==NULL){
               printf("Echec d'ouverture !! ");
               exit(1);
             }
   
            printf("Saisir le numero de la facture : ");
            scanf("%d",&F1.num_facture);
            printf("Saisir le numero du contrat : ");
            scanf("%d",&F1.num_contrat);
            printf("Saisir le montant a payer en DH : ");
            scanf("%f",&F1.montant);
            printf("Saisir la consommation en Kwh : ");
            scanf("%f",&F1.montant);
            printf("Saisir le montant a payer en DH : ");
            scanf("%f",&F1.montant);
            printf("Entrer La Date Limite: J/M/A:   ");
            scanf("%d",&F1.date_echeance.jour);
            scanf("%d",&F1.date_echeance.mois);
            scanf("%d",&F1.date_echeance.annee);
            printf("Entrer La Date de la facture: J/M/A: ");
            scanf("%d",&F1.date_facture.jour);
            scanf("%d",&F1.date_facture.mois);
            scanf("%d",&F1.date_facture.annee);
            fprintf(fp,"%d  %d  %s  %f  %f  %d  %d  %d  %d  %d  %d \n",F1.num_facture,F1.num_contrat,C.ID_client,F1.montant,F1.consommation,F1.date_facture.jour,F1.date_facture.mois,F1.date_facture.annee,F1.date_echeance.jour,F1.date_echeance.mois,F1.date_echeance.annee);

          fclose(fp)
        } 


}

void afficher_facture(){
    Client C;
    Facture F1;
    int n,n1;
    int tr,tr1;
    n=RechercherClient();
    n1=RechercherFacture();
     if(n==0)
          exit(1);
     if (n == 1 && n1 != 1){
             fp=fopen("Factures.txt","r");
              if(fp==NULL){
               printf("Echec d'ouverture !! ");
               exit(1);
             }
               printf("\t\t        ----------------------------------------------Les factures qui existent sont : ----------------------------------------------\n");
               while (!feof(fp))
               {
                  fscanf(fp,"%d  %d  %s  %f  %f  %d  %d  %d  %d  %d  %d \n",&F1.num_facture,&F1.num_contrat,&C.ID_client,&F1.montant,&F1.consommation,&F1.date_facture.jour,&F1.date_facture.mois,&F1.date_facture.annee,&F1.date_echeance.jour,&F1.date_echeance.mois,&F1.date_echeance.annee);
                  printf("\n\t\t\t Numero de Facture :    %d\n\t\t\t Numero de contrat : %d\n\t\t\t Id de client :    %s\n\t\t\t Montant:     %.3f DH\n\t\t\t Consommation  :    %.3f(W)\n\t\t\tDate de la facture  :  %d/%d/%d\n \t\t\tDate limité de facture :   %d/%d/%d\n",F1.num_facture,C.ID_client,F1.montant,F1.consommation,F1.date_facture.jour,F1.date_facture.mois,F1.date_facture.annee,F1.date_echeance.jour,F1.date_echeance.mois,F1.date_echeanceee);
               }
             fclose(fp);
               

   
}
}
void Modifier_facture(){
    FILE *f;
    int tr=0;
    Client C;
    Facture F1;
    int NF; // numéro de facture saisie par l'administarteur 
    
     fp=fopen("Factures.txt","r");
              if(fp==NULL){
               printf("Echec d'ouverture !! ");
               exit(1);
             }
     f=fopen("nouveaux_factures.txt","w");
             if(f==NULL){
                printf("Echec d'ouverture !! ");
                exit(1);
             }
             printf("Veuillez saisir le numéro da la facture que vous voulez la modifier : ");
             scanf("%d",&NF);
             while(!feof(fp))
             {
                fscanf(fp,"%d  %d  %s  %f  %f  %d  %d  %d  %d  %d  %d \n",&F1.num_facture,&F1.num_contrat,&C.ID_client,&F1.montant,&F1.consommation,&F1.date_facture.jour,&F1.date_facture.mois,&F1.date_facture.annee,&F1.date_echeance.jour,&F1.date_echeance.mois,&F1.date_echeance.annee);
                 if (NF == F1.num_facture){
                    tr=1;
                   printf("Donner le nouveau montant mensuel : \n");
                   scanf("%f",&F1.montant);
                   printf("Donner la nouvelle consommation mensuelle: \n");
                   scanf("%f",&F1.consommation);
                   printf("Donner la nouvelle date d'echeance :\n");
                   scanf("%d",&F1.date_echeance.jour);
                   scanf("%d",&F1.date_echeance.mois);
                   scanf("%d",&F1.date_echeance.annee);
                   printf("Donner la nouvelle date de la Facture:\n");
                   scanf("%d",&F1.date_facture.jour);
                   scanf("%d",&F1.date_facture.mois);
                   scanf("%d",&F1.date_facture.annee);
        }
        fprintf(f,"%d  %d  %s %.3f  %.3f  %d  %d  %d  %d  %d  %d\n",F1.num_facture,F1.num_contrat,C.ID_client,F1.montant,F1.consommation,F1.date_facture.jour,F1.date_facture.mois,F1.date_facture.annee,F1.date_echeance.jour,F1.date_echeance.mois,F1.date_echeance.annee);

                 }
                 fclose(f);
                 fclose(fp);
             
             remove("Factures.txt");
             rename("nouveaux_factures.txt","Factures.txt");
             if(tr==0)
                   printf("Facture n'existe pas !!!!'");
    else
        printf("modification enregistrée");
             


}

int Rechercher_Facture(){
    int NF;
    Client  C;
    Facture F1;
    int tr=0;
     fp=fopen("Factures.txt","r");
              if(fp==NULL){
               printf("Echec d'ouverture !! ");
               exit(1);
             }
             printf("Entrer le numero de la facture que vous chercher : ");
             scanf("%d",NF);
             while(!feof(fp))
             {
                fscanf(fp,"%d  %d  %s  %f  %f  %d  %d  %d  %d  %d  %d \n",&F1.num_facture,&F1.num_contrat,&C.ID_client,&F1.montant,&F1.consommation,&F1.date_facture.jour,&F1.date_facture.mois,&F1.date_facture.annee,&F1.date_echeance.jour,&F1.date_echeance.mois,&F1.date_echeance.annee);
                 if (NF == F1.num_facture){
                   tr=1;
                   printf("ID du client est : %s \n ",C.ID_client);
                   printf("Le numero de la facture est : %d \n ",F1.num_facture);
                   printf("Le numero de contrat  est : %d \n ",F1.num_contrat);
                   printf("Le montant a payer est  : %.3f \n ",F1.montant);
                   printf("La cosmmation en  : %d  Kwh \n ",F1.consommation);
                   printf("La date de la facture est : %d/%s/%d \n ",F1.date_facture.jour,F1.date_facture.mois,F1.date_facture.annee);
                   printf("La date d'echeance  est : %d/%s/%d \n ",F1.date_echeance.jour,F1.date_echeance.mois,F1.date_echeance.annee);
                 }
                }
                if(tr==0)
                 printf("Cette facture n'existe pas !! ");
                 fclose(fp);
                 return tr;
}


void Supprimer_Facture(){
    int NF;
    FILE *fs;
    Facture F1;
    Client C;

        fp=fopen("Factures.txt","r");
              if(fp==NULL){
               printf("Echec d'ouverture !! ");
               exit(1);
             }
     fs=fopen("temp.txt","w");
             if(f==NULL){
                printf("Echec d'ouverture !! ");
                exit(1);
             }
             printf("Veuillez saisir le numéro da la facture que vous voulez supprimer : ");
             scanf("%d",&NF);
             while(!feof(fp)){
                     fscanf(fp,"%d  %d  %s  %f  %f  %d  %d  %d  %d  %d  %d \n",&F1.num_facture,&F1.num_contrat,&C.ID_client,&F1.montant,&F1.consommation,&F1.date_facture.jour,&F1.date_facture.mois,&F1.date_facture.annee,&F1.date_echeance.jour,&F1.date_echeance.mois,&F1.date_echeance.annee);
                    if(NF==F1.num_facture)
                        fprintf(fs,"%d  %d  %s %.3f  %.3f  %d  %d  %d  %d  %d  %d\n",F1.num_facture,F1.num_contrat,C.ID_client,F1.montant,F1.consommation,F1.date_facture.jour,F1.date_facture.mois,F1.date_facture.annee,F1.date_echeance.jour,F1.date_echeance.mois,F1.date_echeance.annee);
                     else tr=1
             }

             fclose(fp);
             fclose(fs);
             remove("Factures.txt");
             rename("temp.txt","Factures.txt");
             if(tr==0);
             printf("Le client n'existe pas !! ");
             else
             printf("La modification est bien éffectuée ");


}

void Valider_Payement(){
    int NF;
    Facture F1;
    Client C;
    FILE *fpp;
    int tr=O;
    fp=fopen("Factures.txt","r");
              if(fp==NULL){
               printf("Echec d'ouverture !! ");
               exit(1);
             }
     fpp=fopen("Factures_payees.txt","r");
              if(fp==NULL){
               printf("Echec d'ouverture !! ");
               exit(1);
             }
             printf(" veuiller saisir le numéro de la facture : ");
             scanf("%d",&NF);
             while (!feof(fp))
             {
               fscanf(fp,"%d  %d  %s  %f  %f  %d  %d  %d  %d  %d  %d \n",&F1.num_facture,&F1.num_contrat,&C.ID_client,&F1.montant,&F1.consommation,&F1.date_facture.jour,&F1.date_facture.mois,&F1.date_facture.annee,&F1.date_echeance.jour,&F1.date_echeance.mois,&F1.date_echeance.annee);
               if(NF==F1.num_facture){
                   fprintf(fpp,"%d  %d  %s %.3f  %.3f  %d  %d  %d  %d  %d  %d\n",F1.num_facture,F1.num_contrat,C.ID_client,F1.montant,F1.consommation,F1.date_facture.jour,F1.date_facture.mois,F1.date_facture.annee,F1.date_echeance.jour,F1.date_echeance.mois,F1.date_echeance.annee);   
                   tr=1;
               }
             }
             if(tr==0)
             printf("Paiement validée");
             else
             printf("Client n'existe pas !!");
             fclose(fp);
             fclose(fpp);
}

void Affichier_facture_payées(){
    FILE *fpp;
    Facture F1;
    Client C;
    fpp=fopen("Factures_payees.txt","r");
              if(fp==NULL){
               printf("Echec d'ouverture !! ");
               exit(1);
             }
             else {
                printf("\n\n------------------------------les Factures Payées :-----------------------\n\n");   
             while (!feof(fp))
             {
               fscanf(fpp,"%d  %d  %s  %f  %f  %d  %d  %d  %d  %d  %d \n",&F1.num_facture,&F1.num_contrat,&C.ID_client,&F1.montant,&F1.consommation,&F1.date_facture.jour,&F1.date_facture.mois,&F1.date_facture.annee,&F1.date_echeance.jour,&F1.date_echeance.mois,&F1.date_echeance.annee);
                printf("\n\t\t\t Numero de Facture :    %d\n\t\t\t Numero de contrat : %d\n\t\t\t Id de client :    %s\n\t\t\t Montant:     %.3f DH\n\t\t\t Consommation  :    %.3f(W)\n\t\t\tDate de la facture  :  %d/%d/%d\n \t\t\tDate limité de facture :   %d/%d/%d\n",F1.num_facture,C.ID_client,F1.montant,F1.consommation,F1.date_facture.jour,F1.date_facture.mois,F1.date_facture.annee,F1.date_echeance.jour,F1.date_echeance.mois,F1.date_echeanceee);
           
             }
}
    fclose(fpp);
}







