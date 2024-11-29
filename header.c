#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//les structures 
typedef struct {
    int jour,annee;
    char mois[10];
}Date;


typedef struct {
    float montant ,consommation ;
    int num_facture,num_contrat;
    Date date_facture,date_echeance;
}Facture ;

struct client {
char nom[20],prenom[20],id_client[20],num_compteur[20];
char mot_de_passe[ 20];
Date date_naissance;
struct adresse adresse_client; 
};

 struct administrateur{
char email[20],mot_de_passe[20];
 };

struct carte_bancaire {
char num_carte[17], nom_complet[25],code_veri[4];
Date date_expi;
};

struct adresse {
char ville[20],quartier[20],compteur[20],num_residence[20];

};
FILE *fp;


void ajouter_clients( ){
  struct client A;
  FILE *fichier;
  printf("entrer le ID_CLIENT\n\n");
  scanf("%s",A.id_client);
  printf("entrer le nom du client\n\n");
  scanf("%s",A.nom);
  printf("entrer le prenom du client\n\n");
  scanf("%s",A.prenom);
  printf("entrer le num_compteur du client\n\n");
  scanf("%s",A.num_compteur);
  fichier = fopen("client.txt","a");
  fwrite (&A,sizeof(struct client),1,fichier);
  if(fwrite != 0)
    printf("clients ajoute avec succes ");
  else if (printf("erreur lors de l'ajout du client"));
  fclose(fichier );
}
void afficher_clients( ){
  struct client A;
  struct client clients [100];
  FILE *fichier;
  fichier=fopen("client.txt","r");
  int nbclients=0;
  while(fread(&A,sizeof(struct client),1,fichier)!=0){
      clients[nbclients]=A;
       nbclients++; 
  }
  fclose(fichier );
  for(int i=0;i<nbclients;i++){
    printf("ID_CLIENT:%s\n",clients[i].id_client);
    printf("nom:%s\n",clients[i].nom);
    printf("prenom:%s\n",clients[i].prenom);
    printf("num_compteur:%s\n",clients[i].num_compteur);
    printf("l'adresse du clientest:%s\n",clients[i].adresse_client);
    printf("\n");
    
  }
  
  
}

void modifier_clients( ){
   struct client clients [100];
  struct client A;
  struct client nvA;
  FILE *fichier;
  printf("entrer le nouveau  ID_CLIENT\n\n");
  scanf("%s",nvA.id_client);
  printf("entrer le nouveau nom du client\n");
  scanf("%s",nvA.nom);
  printf("entrer le nouveau prenom du client\n");
  scanf("%s",nvA.prenom);
  printf("entrer le nouveau num_compteur\n");
  scanf("%s",nvA.num_compteur);
  printf("entrer le nouveau adresse du client\n_n ");
  scanf("%s %s %s %s",nvA.adresse_client.ville,nvA.adresse_client.quartier,nvA.adresse_client.compteur,nvA.adresse_client.num_residence);
  fichier=fopen("cient.txt","r");
    int nbclients=0;
    while(fread(&A,sizeof(struct client),1,fichier)!=0){
       clients[nbclients]=A;
       nbclients++;
    }
  fclose(fichier);
    remove("cient.txt");
    FILE *nfichier;
    nfichier=fopen("nv.txt","a");
    for(int i=0;i<nbclients;i++){
      if(clients[i].id_client==nvA.id_client)
        fwrite(&nvA,sizeof(struct client),1,nfichier);
      else 
        fwrite(&clients[i],sizeof(struct client),1,nfichier);
         
    }
    fclose(nfichier);
    rename("nv.txt","client.txt");
    
}
int rechercher_clients( client A ,int tr){
  struct client clients [100];
  FILE *fichier;
  fichier=fopen("client.txt","r");
  int nbclients=0;
  while(fread(&A,sizeof(struct client),1,fichier)!=0){
       clients[nbclients]=A;
       nbclients++;
  }
  for(int i=0;i < nbclients ;i++){
    if(A.id_client==clients[i].id_client){
      printf("ce client existe est son id est :%s\n",clients[i].id_client);
      tr=1;}
    else{
      printf("ce client n'existe pas");
      tr=0;
    }
      return tr;

      
}
}
void supprimer_clients( struct client A){
  struct client clients [100];
  struct client  nvA ;
  FILE *fichier;
  printf("  ID_CLIENT a supprimer\n\n");
  scanf("%s",A.id_client);
  printf(" nom de ce  client\n");
  scanf("%s",A.nom);
  printf(" prenom de ce client\n");
  scanf("%s",A.prenom);
  printf(" num_compteur de ce client\n");
  scanf("%s",A.num_compteur);

  fichier=fopen("cient.txt","r");
    int nbclients=0;
    while(fread(&A,sizeof(struct client),1,fichier)!=0){
       clients[nbclients]=A;
       nbclients++;
    }
  fclose(fichier);
    remove("cient.txt");
    FILE *nfichier;
    nfichier=fopen("nv.txt","a");
    for(int i=0;i<nbclients;i++){
      if(clients[i].id_client!=A.id_client)
        fwrite(&nvA,sizeof(struct client),1,nfichier);

    }
    fclose(nfichier);
    rename("nv.txt","client.txt");


}
void Ajouter_facture()
{
    struct client C;
    Facture F1;
    int n,n1;
    int tr,tr1;
    n=rechercher_clients(C,tr);
    n1=Rechercher_Facture(tr);
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
            fprintf(fp,"%d  %d  %s  %f  %f  %d  %d  %d  %d  %d  %d \n",F1.num_facture,F1.num_contrat,C.id_client,F1.montant,F1.consommation,F1.date_facture.jour,F1.date_facture.mois,F1.date_facture.annee,F1.date_echeance.jour,F1.date_echeance.mois,F1.date_echeance.annee);

          fclose(fp);
        } 


}

 void afficher_facture(){
    struct client C;
    Facture F1;
    int n,n1;
    int tr,tr1;
    n=rechercher_clients(C,tr);
    n1=Rechercher_Facture(tr1);
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
                  fscanf(fp,"%d  %d  %s  %f  %f  %d  %d  %d  %d  %d  %d \n",&F1.num_facture,&F1.num_contrat,&C.id_client,&F1.montant,&F1.consommation,&F1.date_facture.jour,&F1.date_facture.mois,&F1.date_facture.annee,&F1.date_echeance.jour,&F1.date_echeance.mois,&F1.date_echeance.annee);
                  printf("\n\t\t\t Numero de Facture :    %d\n\t\t\t Numero de contrat : %d\n\t\t\t Id de client :    %s\n\t\t\t Montant:     %.3f DH\n\t\t\t Consommation  :    %.3f(W)\n\t\t\tDate de la facture  :  %d/%d/%d\n \t\t\tDate limité de facture :   %d/%d/%d\n",F1.num_facture,C.id_client,F1.montant,F1.consommation,F1.date_facture.jour,F1.date_facture.mois,F1.date_facture.annee,F1.date_echeance.jour,F1.date_echeance.mois,F1.date_echeance);
               }
             fclose(fp);
               

   
}
  }
void Modifier_facture(){
    FILE *f;
    int tr=0;
    struct client C;
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
                fscanf(fp,"%d  %d  %s  %f  %f  %d  %d  %d  %d  %d  %d \n",&F1.num_facture,&F1.num_contrat,&C.id_client,&F1.montant,&F1.consommation,&F1.date_facture.jour,&F1.date_facture.mois,&F1.date_facture.annee,&F1.date_echeance.jour,&F1.date_echeance.mois,&F1.date_echeance.annee);
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
        fprintf(f,"%d  %d  %s %.3f  %.3f  %d  %d  %d  %d  %d  %d\n",F1.num_facture,F1.num_contrat,C.id_client,F1.montant,F1.consommation,F1.date_facture.jour,F1.date_facture.mois,F1.date_facture.annee,F1.date_echeance.jour,F1.date_echeance.mois,F1.date_echeance.annee);

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

int Rechercher_Facture( int tr ){
    int NF;
    struct client  C;
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
                fscanf(fp,"%d  %d  %s  %f  %f  %d  %d  %d  %d  %d  %d \n",&F1.num_facture,&F1.num_contrat,&C.id_client,&F1.montant,&F1.consommation,&F1.date_facture.jour,&F1.date_facture.mois,&F1.date_facture.annee,&F1.date_echeance.jour,&F1.date_echeance.mois,&F1.date_echeance.annee);
                 if (NF == F1.num_facture){
                   tr=1;
                   printf("ID du client est : %s \n ",C.id_client);
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
    int NF,tr;
    FILE *fs;
    Facture F1;
    struct client  C;

        fp=fopen("Factures.txt","r");
              if(fp==NULL){
               printf("Echec d'ouverture !! ");
               exit(1);
             }
     fs=fopen("temp.txt","w");
             if(fs==NULL){
                printf("Echec d'ouverture !! ");
                exit(1);
             }
             printf("Veuillez saisir le numéro da la facture que vous voulez supprimer : ");
             scanf("%d",&NF);
             while(!feof(fp)){
                     fscanf(fp,"%d  %d  %s  %f  %f  %d  %d  %d  %d  %d  %d \n",&F1.num_facture,&F1.num_contrat,&C.id_client,&F1.montant,&F1.consommation,&F1.date_facture.jour,&F1.date_facture.mois,&F1.date_facture.annee,&F1.date_echeance.jour,&F1.date_echeance.mois,&F1.date_echeance.annee);
                    if(NF==F1.num_facture)
                        fprintf(fs,"%d  %d  %s %.3f  %.3f  %d  %d  %d  %d  %d  %d\n",F1.num_facture,F1.num_contrat,C.id_client,F1.montant,F1.consommation,F1.date_facture.jour,F1.date_facture.mois,F1.date_facture.annee,F1.date_echeance.jour,F1.date_echeance.mois,F1.date_echeance.annee);
                     else tr=1;
             }

             fclose(fp);
             fclose(fs);
             remove("Factures.txt");
             rename("temp.txt","Factures.txt");
             if(tr==0)
             printf("Le client n'existe pas !! ");
             else
             printf("La modification est bien éffectuée ");


}

void Valider_Payement(){
    int NF;
    Facture F1;
    struct client C;
    FILE *fpp,*fp,*temp;
    int tr=0;
    printf(" veuiller saisir le numéro de la facture : ");
    scanf("%d",&NF);
    fp=fopen("Factures.txt","r");
              if(fp==NULL){
               printf("Echec d'ouverture !! ");
               exit(1);
             }
     fpp=fopen("Factures_payees.txt","a+");
              if(fpp==NULL){
               printf("Echec d'ouverture !! ");
               exit(1);
             }
     temp=fopen("temp.txt","w");
      if(temp==NULL){
               printf("Echec d'ouverture !! ");
               exit(1);
              }
             while (!feof(fp))
             {
               fscanf(fp,"%d  %d  %s  %f  %f  %d  %d  %d  %d  %d  %d \n",&F1.num_facture,&F1.num_contrat,&C.id_client,&F1.montant,&F1.consommation,&F1.date_facture.jour,&F1.date_facture.mois,&F1.date_facture.annee,&F1.date_echeance.jour,&F1.date_echeance.mois,&F1.date_echeance.annee);
               if(NF==F1.num_facture){
                // ajouter la facture 
                   fprintf(fpp,"%d  %d  %s %.3f  %.3f  %d  %d  %d  %d  %d  %d\n",F1.num_facture,F1.num_contrat,C.id_client,F1.montant,F1.consommation,F1.date_facture.jour,F1.date_facture.mois,F1.date_facture.annee,F1.date_echeance.jour,F1.date_echeance.mois,F1.date_echeance.annee);   
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

void Affichier_facture_payees(){
    FILE *fpp;
    Facture F1;
    struct client  C;
    fpp=fopen("Factures_payees.txt","a");
              if(fp==NULL){
               printf("Echec d'ouverture !! ");
               exit(1);
             }
             else {
                printf("\n\n------------------------------les Factures Payees :-----------------------\n\n");   
             while (!feof(fp))
             {
               fscanf(fpp,"%d  %d  %s  %f  %f  %d  %d  %d  %d  %d  %d \n",&F1.num_facture,&F1.num_contrat,&C.id_client,&F1.montant,&F1.consommation,&F1.date_facture.jour,&F1.date_facture.mois,&F1.date_facture.annee,&F1.date_echeance.jour,&F1.date_echeance.mois,&F1.date_echeance.annee);
                printf("\n\t\t\t Numero de Facture :    %d\n\t\t\t Numero de contrat : %d\n\t\t\t Id de client :    %s\n\t\t\t Montant:     %.3f DH\n\t\t\t Consommation  :    %.3f(W)\n\t\t\tDate de la facture  :  %d/%d/%d\n \t\t\tDate limité de facture :   %d/%d/%d\n",F1.num_facture,C.id_client,F1.montant,F1.consommation,F1.date_facture.jour,F1.date_facture.mois,F1.date_facture.annee,F1.date_echeance.jour,F1.date_echeance.mois,F1.date_echeance);
           
             }
}
    fclose(fpp);
}







