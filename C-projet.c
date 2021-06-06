/* réalisé par:
  ikram aitbrahim (G4-a)

marieme raboua (G2-b)
*/




#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<dos.h>

//prototype des fonctions


int menu_principal();

int recherche(int);

void ajoutevoiture();

void afficher();

void modifiervoiture();

void suppvoiture();

int rechercheclient(int);

void ajouter_un_client(int);

void ajouteclient();

void afficherclient();

void modifierclient();

void suppclient();

int recherchecontrat(float);

void visualiser_contrat();

void verification_v();

void louer_voiture();

void suppression_contract(float);

void modifiercontrat();

void supp_contract();

          // declaration des structures

typedef struct Voiture
{
 int idVoiture;
 char marque[15];
 char nomVoiture[15];
 char couleur[7];
 int nbplaces;
 int prixJour;
 char EnLocation[4];
} voiture;
typedef struct Client
{
 int idClient;
 char nom[20];
 char prenom[20];
 int cin;
 char adresse[15];
 int telephone;
}client;
typedef struct date
 {

 int jj;
 int mm;
 int yy;
}date;
typedef struct contratLocation
{
 float numContrat;
 int idVoiture;
 int idClient;
 date debut;
 date fin;
 int cout;
} contrat;


int main(){
    menu_principal();

    return 0;
}
   // declaration des fonctions

int recherche(int idrech){
	int v_idVoiture;
	char v_string[1024];
	int valide=0;
	FILE *fichier=NULL;
	fichier=fopen("Voitures","r");
	if(fichier!=NULL){
		while(fscanf(fichier,"%d;%s",&v_idVoiture,&v_string)!=EOF){
            if(idrech==v_idVoiture){
                fclose(fichier);
                return 1;
            }
        }
        fclose(fichier);
    }
	return 0;
}

void ajoutevoiture(){
	int N,i;
	voiture v;
    FILE*fichier = NULL;
	fichier = fopen("Voitures","a");
	int idrech;
	if(fichier != NULL){
        printf("\t saisir le nombre de voiture\t");
        scanf("%d",&N);
        for(i=0;i<N;i++){
            printf("\n\ntaper Id de voiture:\t");
            scanf("%d",&idrech);
            fflush(stdin);
            while(recherche(idrech)==1){
                printf(" Ce ID existe deja . ");
                printf(" taper id de Voiture :\t ");
                scanf("%d",&idrech);
                fflush(stdin);
            }
            v.idVoiture=idrech;
            printf("taper la marque de voiture :\t");
            scanf("%s",v.marque);
            printf("taper le nom de voitiure :\t");
            scanf("%s",v.nomVoiture);
            printf("taper la coulour de voiture :\t");
            scanf("%s",v.couleur);
            printf("taper nombre de place :\t\t");
            scanf("%d",&v.nbplaces);
            fflush(stdin);
            printf("taper le prix par jour :\t");
            scanf("%d",&v.prixJour);
            fflush(stdin);
            printf("taper si en location ou non :\t");
            scanf("%s",v.EnLocation);
            fprintf(fichier,"%d;%s;%s;%s;%d;%d;%s\n",v.idVoiture,v.marque,v.nomVoiture,v.couleur,v.nbplaces,v.prixJour,v.EnLocation);
        }
    }
	fclose(fichier);
}

void afficher(){
	voiture v;
	char c;
	FILE*fichier=NULL;
	fichier=fopen("Voitures","r");
	char buf[1024];
	if(fichier!=NULL){
        while(fgets(buf, 1024, fichier)){
            printf("%s",buf);
        }
    }
    fclose(fichier);
}

void modifiervoiture(){
	voiture v;
 	int numrech;
 	char k;
 	printf("entrez id de voiture a modifier :\t ");
 	scanf("%d",&numrech);
 	fflush(stdin);
 	if(recherche(numrech)==1){
 		printf("voulez-vous vraiment modifier o/n? ");
 		scanf("%c",&k);
 		fflush(stdin);
 		if(k=='o' || k=='O'){
 			FILE *fichier,*fich;
        	fichier=fopen("Voitures","r");
        	fich=fopen("ne.txt","w");
            char buf[1024];
            while(fgets(buf, 1024, fichier)){
              	char *field = strtok(buf, ";");
                v.idVoiture=atoi(field);
                field = strtok(NULL, ";");
                strcpy(v.marque,field);
                field = strtok(NULL, ";");
                strcpy(v.nomVoiture,field);
                field = strtok(NULL, ";");
                strcpy(v.couleur,field);
                field = strtok(NULL, ";");
                v.nbplaces=atoi(field);
                field = strtok(NULL, ";");
                v.prixJour=atoi(field);
                field = strtok(NULL, "\n");
                strcpy(v.EnLocation,field);
                if(numrech==v.idVoiture){
                    v.idVoiture=numrech;

                    printf("entrez la nouvelle marque de voiture :\t");
                    scanf("%s",v.marque);
                    printf("entrez le nouveau nom de voiture :\t");
                    scanf("%s",v.nomVoiture);
                    printf("entrez la nouvelle couleur de voiture :\t");
                    scanf("%s",v.couleur);
                    printf("entrez le nouveau nombre de place :\t");
                    scanf("%d",&v.nbplaces);
                    fflush(stdin);
                    printf("entrez le nouveau prix par jour :\t");
                    scanf("%d",&v.prixJour);
                    fflush(stdin);
                    printf("entre si en location ou non :\t");
                    scanf("%s",v.EnLocation);
                    fflush(stdin);
                }
                fprintf(fich,"%d;%s;%s;%s;%d;%d;%s\n",v.idVoiture,v.marque,v.nomVoiture,v.couleur,v.nbplaces,v.prixJour,v.EnLocation);
            }

			fclose(fichier);
			fclose(fich);
			remove("Voitures");
			rename("ne.txt","Voitures");

			printf("la modification a reussi");
		 }
		else{
			printf("voiture non modifier");
		}
	 }
	 else printf("Ce Id de voiture n'existe pas");
}

 void suppvoiture(){
 	voiture v;
 	int numrech;
 	char k;
 	printf("entrez id de voiture a supperime : ");
 	scanf("%d",&numrech);
 	fflush(stdin);
 	if(recherche(numrech)==1){
 		printf("voulez-vous vraiment supperime o/n? ");
 		scanf("%c",&k);
 		fflush(stdin);
 		if(k=='o' || k=='O'){
 			FILE *fichier,*fich;
        	fichier=fopen("Voitures","r");
        	fich=fopen("newfich.txt","w");
        	//while(!feof(fichier)){

            char buf[1024];
            while(fgets(buf, 1024, fichier)){

                    char *field = strtok(buf, ";");
                    v.idVoiture=atoi(field);
                    field = strtok(NULL, ";");
                    strcpy(v.marque,field);
                    field = strtok(NULL, ";");
                    strcpy(v.nomVoiture,field);
                    field = strtok(NULL, ";");
                    strcpy(v.couleur,field);
                    field = strtok(NULL, ";");
                    v.nbplaces=atoi(field);
                    field = strtok(NULL, ";");
                    v.prixJour=atoi(field);
                    field = strtok(NULL, "\n");
                    strcpy(v.EnLocation,field);

                    if(numrech!=v.idVoiture){
                        fprintf(fich,"%d;%s;%s;%s;%d;%d;%s\n",v.idVoiture,v.marque,v.nomVoiture,v.couleur,v.nbplaces,v.prixJour,v.EnLocation);
                    }
			}
			fclose(fichier);
			fclose(fich);
			remove("Voitures");
			rename("newfich.txt","Voitures");
			printf("suppression effectuee avec success");
		 }
		else{
			printf("voiture non supprimée");
		}
	 }
	 else printf("Ce Id de voiture n'existe pas");
}

//////////*************gestion clients*******************

int rechercheclient(int idrech){
	int c_idclient;
	char c_string[1024];
	FILE *fichier=NULL;
	fichier=fopen("Clients","r");
	if(fichier!=NULL){
		while(fscanf(fichier,"%d;%s",&c_idclient,&c_string)!=EOF){
            if(idrech==c_idclient){
                fclose(fichier);
                return 1;
            }
        }
        fclose(fichier);
    }
	return 0;
}

void ajouter_un_client(int idrech){
    client c;
    FILE *fichier = NULL;
    fichier = fopen("Clients","a");
    c.idClient=idrech;
    printf("taper le  nom de client :\t");
    scanf("%s",c.nom);
    fflush(stdin);
    printf("taper le prenom de client :\t");
    scanf("%s",c.prenom);
    fflush(stdin);
    printf("taper CIN de client :\t");
    scanf("%d",&c.cin);
    fflush(stdin);
    printf("taper l'adresse de client :\t");
    scanf("%s",c.adresse);
    fflush(stdin);
    printf("taper le numero tel de client :\t");
    scanf("%d",&c.telephone);
    fflush(stdin);
    fprintf(fichier,"%d;%s;%s;%d;%s;%d\n",c.idClient,c.nom,c.prenom,c.cin,c.adresse,c.telephone);
	fclose(fichier);
}

void ajouteclient(){
 	int N,i,idrech;
 	FILE *fichier = NULL;
	fichier = fopen("Clients","r");
	if(fichier != NULL){
        printf("\t saisir le nombre de clients\t");
        scanf("%d",&N);
        for(i=0;i<N;i++){
            printf("\ntapez Id de client:\t");
            scanf("%d",&idrech);
            fflush(stdin);
            while(rechercheclient(idrech)==1){
                printf(" Ce ID existe deja . ");
                printf(" taper id de client :\t ");
                scanf("%d",&idrech);
                fflush(stdin);
            }
            ajouter_un_client(idrech);
        }
    }
    else{
        fichier = fopen("Clients","w");
        fclose(fichier);
        ajouteclient();
    }
    fclose(fichier);
}

void afficherclient(){
    char k;
    FILE*fichier=NULL;
    fichier=fopen("Clients","r");
    char buf[1024];
    if(fichier!=NULL){
        while(fgets(buf, 1024, fichier)){
            printf("%s",buf);
        }
    }
    fclose(fichier);
}

void modifierclient(){
	client c;
 	int numrech;
 	char k;
 	printf("entrez id de client a modifier :\t ");
 	scanf("%d",&numrech);
 	fflush(stdin);
 	if(rechercheclient(numrech)==1){
 		printf("voulez-vous vraiment modifier o/n? ");
 		scanf("%c",&k);
 		fflush(stdin);
 		if(k=='o' || k=='O'){
 			FILE *fichier,*fich;
        	fichier=fopen("Clients","r");
        	fich=fopen("nc.txt","w");
            char buf[1024];
            while(fgets(buf, 1024, fichier)){
              	char *field = strtok(buf, ";");
                c.idClient=atoi(field);
                field = strtok(NULL, ";");
                strcpy(c.nom,field);
                field = strtok(NULL, ";");
                strcpy(c.prenom,field);
                field = strtok(NULL, ";");
                c.cin=atoi(field);
                field = strtok(NULL, ";");
                strcpy(c.adresse,field);
                field = strtok(NULL, "\n");
                c.telephone=atoi(field);
                if(numrech==c.idClient){
                    c.idClient=numrech;
                    printf("entrez le nouveau nom de client:\t");
                    scanf("%s",c.nom);
                    printf("entrez le nouveau prenom de client :\t");
                    scanf("%s",c.prenom);
                    printf("entrez la nouvelle CIN :\t");
                    scanf("%s",&c.cin);
                    fflush(stdin);
                    printf("entrez le nouveau adresse :\t");
                    scanf("%s",c.adresse);
                    printf("entrez le nouveau numero de tel :\t");
                    scanf("%d",&c.telephone);
                    fflush(stdin);

                }
                fprintf(fich,"%d;%s;%s;%d;%s;%d\n",c.idClient,c.nom,c.prenom,c.cin,c.adresse,c.telephone);
            }
			fclose(fichier);
			fclose(fich);
			remove("Clients");
			rename("nc.txt","Clients");
			printf("la modification a reussi");
		 }
		else{
			printf("client non modifier");
		}
	 }
	 else printf("Ce Id de client n'existe pas\n");
}

void suppclient(){
    client c;
 	int numrech;
 	char k;
 	printf("entrez id de client a supperime : ");
 	scanf("%d",&numrech);
 	fflush(stdin);
 	if(rechercheclient(numrech)==1){
 		printf("voulez-vous vraiment supperime o/n? ");
 		scanf("%c",&k);
 		fflush(stdin);
 		if(k=='o' || k=='O'){
 			FILE *fichier,*fich;
        	fichier=fopen("Clients","r");
        	fich=fopen("nc.txt","w");
            char buf[1024];
            while(fgets(buf, 1024, fichier)){
                char *field = strtok(buf, ";");
                c.idClient=atoi(field);
                field = strtok(NULL, ";");
                strcpy(c.nom,field);
                field = strtok(NULL, ";");
                strcpy(c.prenom,field);
                field = strtok(NULL, ";");
                c.cin=atoi(field);
                field = strtok(NULL, ";");
                strcpy(c.adresse,field);
                field = strtok(NULL, "\n");
                c.telephone=atoi(field);
                if(numrech!=c.idClient){
                    fprintf(fich,"%d;%s;%s;%d;%s;%d\n",c.idClient,c.nom,c.prenom,c.cin,c.adresse,c.telephone);
                }
			}
			fclose(fichier);
			fclose(fich);
			remove("Clients");
			rename("nc.txt","Clients");
			printf("suppression effectuee avec success");
		 }
		else{
			printf("client non supprimée");
		}
	 }
	 else printf("Ce Id de client n'existe pas");
}

///////////*********Location d'une voiture*********
int recherchecontrat(float idrech){
	float ct_numcontrat;
	int ct_string[1024];
	FILE *fichier=NULL;
	fichier=fopen("ContratsLocations","r");
	if(fichier!=NULL){
		while(fscanf(fichier,"%f;%s",&ct_numcontrat,&ct_string)!=EOF){
            if(idrech==ct_numcontrat){
                fclose(fichier);
                return 1;
            }
        }
        fclose(fichier);
    }
	return 0;
}
void visualiser_contrat(){
	FILE*fichier=NULL;
	float numContract;
	char debut[9],fin[9],buf[1024];
	fichier=fopen("ContratsLocations","r");
	printf("donnez le numero de contract à voire :\t");
    scanf("%f",&numContract);
    if (recherchecontrat(numContract)==1){
        if(fichier!=NULL){
            while(fgets(buf, 1024, fichier)){
                char *field = strtok(buf, ";");
                if (numContract==atof(field)){
                    printf("Numero de contract : \t\t%f\n",atof(field));
                    field = strtok(NULL, ";");
                    printf("L'Id de la voiture est : \t%d\n",atoi(field));
                    field = strtok(NULL, ";");
                    printf("l'Id du client est : \t\t%d\n",atoi(field));
                    field = strtok(NULL, ";");
                    printf("La date de début est : \t\t%s\n",field);
                    field = strtok(NULL, ";");
                    printf("La date de fin est : \t\t%s\n",field);
                    field = strtok(NULL, "\n");
                    printf("le Cout est : \t\t\t%d\n",atoi(field));
                }
            }
        }
    }
    fclose(fichier);
}

void verification_v(){
  	voiture v;

  	FILE*fichier=NULL;
  	fichier=fopen("Voitures","r");
  	if(fichier!=NULL){
  	//	while(!feof(fichier)){
            char buf[1024];
            printf("idVoiture\tmarque\tnom Voiture\tcouleur\tnbplaces\tprixJour\tEnLocation\n");
            while(fgets(buf, 1024, fichier)){
                char *field = strtok(buf, ";");
                v.idVoiture=atoi(field);
                field = strtok(NULL, ";");
                strcpy(v.marque,field);
                field = strtok(NULL, ";");
                strcpy(v.nomVoiture,field);
                field = strtok(NULL, ";");
                strcpy(v.couleur,field);
                field = strtok(NULL, ";");
                v.nbplaces=atoi(field);
                field = strtok(NULL, ";");
                v.prixJour=atoi(field);
                field = strtok(NULL, "\n");
                strcpy(v.EnLocation,field);
                if(strcmp(v.EnLocation,"oui")!=0 && strcmp(v.EnLocation,"OUI")!=0 && strcmp(v.EnLocation,"Oui")!=0){
                    printf("%d\t\t%s\t%s\t\t%s\t%d\t\t%d\t\t%s\n",v.idVoiture,v.marque,v.nomVoiture,v.couleur,v.nbplaces,v.prixJour,v.EnLocation);
                }
		  }
		  fclose(fichier);
	  }
}

void louer_voiture(){
    contrat ct;
    voiture v;
  	int idC,idV,du,p=0;
  	char k;
  	printf("donner l'ID du client :\t");
  	scanf("%d",&idC);
  	fflush(stdin);
  	if(rechercheclient(idC)==0) {
        printf(" Ce client n'existe pas. \n\n Voulez-vous l'ajouter (o/n)?\t");
        scanf("%c",&k);
 		fflush(stdin);
 		if(k=='o' || k=='O'){
            ajouter_un_client(idC);
  		}
    }
    else{
        printf("Voila les voitures qui ne sont pas louer :\n");
        verification_v();
        printf("\ndonner l'ID de voiture que vous veuillez louer a partir de la liste affichee :\t");
        scanf("%d",&idV);
        FILE *fichier,*fich;
        fichier=fopen("Voitures","r");
        fich=fopen("ne.txt","w");
        char buf[1024];
        while(fgets(buf, 1024, fichier)){
            char *field = strtok(buf, ";");
            v.idVoiture=atoi(field);
            field = strtok(NULL, ";");
            strcpy(v.marque,field);
            field = strtok(NULL, ";");
            strcpy(v.nomVoiture,field);
            field = strtok(NULL, ";");
            strcpy(v.couleur,field);
            field = strtok(NULL, ";");
            v.nbplaces=atoi(field);
            field = strtok(NULL, ";");
            v.prixJour=atoi(field);
            field = strtok(NULL, "\n");
            strcpy(v.EnLocation,field);
            if(idV==v.idVoiture){
                    if(strcmp(v.EnLocation,"non")==0 || strcmp(v.EnLocation,"NON")==0 || strcmp(v.EnLocation,"Non")==0){
                        strcpy(v.EnLocation,"oui");
                        p=v.prixJour;
                    }
                    else{
                        printf("La voitures est déjà réserver\n");
                        p=-1;
                    }
            }
            fprintf(fich,"%d;%s;%s;%s;%d;%d;%s\n",v.idVoiture,v.marque,v.nomVoiture,v.couleur,v.nbplaces,v.prixJour,v.EnLocation);
        }
        fclose(fichier);
        fclose(fich);
        remove("Voitures");
        rename("ne.txt","Voitures");
        if (p!=-1){
            printf("taper la durée(jours) de location  :");
            scanf("%d",&du);
            p= p*du;
            printf("le prix de location est : %d\n",p);
            FILE * fichier=NULL;
            fichier=fopen("ContratsLocations","a");
            if(fichier!=NULL){
                printf("Le numero de contrat :\t");
                scanf("%2f",&ct.numContrat);
                fflush(stdin);
                while(recherchecontrat(ct.numContrat)){
                    printf("Ce numero existe deja !! \n");
                    printf("Le numero de contrat :\t ");
                    scanf("%2f",&ct.numContrat);
                    fflush(stdin);
                }
                printf("ID de voiture : %d\n",idV);

                ct.idVoiture=idV;

                printf("ID de client :%d\n",idC);

                ct.idClient=idC;

                printf("la date de debut :\n");
                printf("jour :\t");
                scanf("%d",&ct.debut.jj);
                fflush(stdin);
                printf("mois :\t");
                scanf("%d",&ct.debut.mm);
                fflush(stdin);
                printf("annee :\t");
                scanf("%d",&ct.debut.yy);
                fflush(stdin);
                printf("la date de fin :\n");
                printf("jour :\t");
                scanf("%d",&ct.fin.jj);
                fflush(stdin);
                printf("mois :\t");
                scanf("%d",&ct.fin.mm);
                fflush(stdin);
                printf("annee :\t");
                scanf("%d",&ct.fin.yy);
                fflush(stdin);
                printf("le cout : %d\t",p);

                ct.cout=p;

                fprintf(fichier,"%f;%d;%d;%d/%d/%d;%d/%d/%d;%d\n",ct.numContrat,ct.idVoiture,ct.idClient,ct.debut.jj,ct.debut.mm,ct.debut.yy,ct.fin.jj,ct.fin.mm,ct.fin.yy,ct.cout);

              }
              fclose(fichier);
        }
    }
}

void suppression_contract(float numrech){
    FILE *fichier,*fich;
    char buf[1024];
    float(numContrat);
    fichier=fopen("ContratsLocations","r");
    fich=fopen("ncontrat.txt","w");
    if(fichier!=NULL){
        while(fscanf(fichier,"%f;%s",&numContrat,&buf)!=EOF){
            if(numrech!=numContrat){
                fprintf(fich,"%f;%s\n",numContrat,buf);
            }
        }
    }
    fclose(fichier);
    fclose(fich);
    remove("ContratsLocations");
    rename("ncontrat.txt","ContratsLocations");
}

void Retourner_voiture(){

 	float numrech;
 	char k;
 	printf("entrez numero de contrat à retourner :\t ");
 	scanf("%f",&numrech);
 	fflush(stdin);
 	if(recherchecontrat(numrech)==1){
 		printf("voulez-vous vraiment retourner o/n? ");
 		scanf("%c",&k);
 		fflush(stdin);
 		if(k=='o' || k=='O'){
            suppression_contract(numrech);
 			FILE *fichier,*fich;
        	fichier=fopen("Voitures","r");
        	fich=fopen("ne.txt","w");
            char buf[1024];
            while(fgets(buf, 1024, fichier)){
                voiture v;
              	char *field = strtok(buf, ";");
                v.idVoiture=atoi(field);
                field = strtok(NULL, ";");
                strcpy(v.marque,field);
                field = strtok(NULL, ";");
                strcpy(v.nomVoiture,field);
                field = strtok(NULL, ";");
                strcpy(v.couleur,field);
                field = strtok(NULL, ";");
                v.nbplaces=atoi(field);
                field = strtok(NULL, ";");
                v.prixJour=atoi(field);
                field = strtok(NULL, "\n");
                strcpy(v.EnLocation,field);
                if(numrech==v.idVoiture){
                    strcpy(v.EnLocation,"non");
                }
                fprintf(fich,"%d;%s;%s;%s;%d;%d;%s\n",v.idVoiture,v.marque,v.nomVoiture,v.couleur,v.nbplaces,v.prixJour,v.EnLocation);
            }

			fclose(fichier);
			fclose(fich);
			remove("Voitures");
			rename("ne.txt","Voitures");

			printf("Voitures est retournée");
		 }
		else{
			printf("contrat non supprimée");
		}
	 }
	 else printf("Ce numero de contrat n'existe pas");
}
void modifiercontrat(){
contrat ct;
int nbrjours,prixjour;
 	float numrech;
 	char k;
 	printf("entrez numero de contrat a modifier :\t ");
 	scanf("%f",&numrech);
 	fflush(stdin);
 	if(recherchecontrat(numrech)==1){
 		printf("voulez-vous vraiment modifier o/n? ");
 		scanf("%c",&k);
 		fflush(stdin);
 		if(k=='o' || k=='O'){
 			FILE *fichier,*fich;
        	fichier=fopen("ContratsLocations","r");
        	fich=fopen("ncontrat.txt","w");
        	char buf[1024];
            while(fgets(buf, 1024, fichier)){

                    char *field = strtok(buf, ";");
                    ct.numContrat=atof(field);
                    field = strtok(NULL, ";");
                    ct.idVoiture=atoi(field);
                    field = strtok(NULL, ";");
                    ct.idClient=atoi(field);
                    field = strtok(NULL, "/");
                    ct.debut.jj=atoi(field);
                    field = strtok(NULL, "/");
                    ct.debut.mm=atoi(field);
                    field = strtok(NULL, ";");
                    ct.debut.yy=atoi(field);
                    field = strtok(NULL, "/");
                    ct.fin.jj=atoi(field);
                    field = strtok(NULL, "/");
                    ct.fin.mm=atoi(field);
                    field = strtok(NULL, ";");
                    ct.fin.yy=atoi(field);
                    field = strtok(NULL, "\n");
                    ct.cout =atoi(field);
                    if(numrech==ct.numContrat){

                            printf("la nouvelle date de fin :\n");
                            printf("jour :\t");
                            scanf("%d",&ct.fin.jj);
                            fflush(stdin);
                            printf("mois :\t");
                            scanf("%d",&ct.fin.mm);
                            fflush(stdin);
                            printf("annee :\t");
                            scanf("%d",&ct.fin.yy);
                            fflush(stdin);
                             printf(" le nombre de jour ajoute dont la voiture sera louer :");
					scanf("%d",&nbrjours);
					fflush(stdin);
					printf("le prix par jour du voirure :");
					scanf("%d",&prixjour);
					fflush(stdin);
					ct.cout=ct.cout+(nbrjours*prixjour);


                }
                fprintf(fich,"%f;%d;%d;%02d/%02d/%4d;%02d/%02d/%4d;%d\n",ct.numContrat,ct.idVoiture,ct.idClient,ct.debut.jj,ct.debut.mm,ct.debut.yy,ct.fin.jj,ct.fin.mm,ct.fin.yy,ct.cout);
            }

			fclose(fichier);
			fclose(fich);
			remove("ContratsLocations");
			rename("ncontrat.txt","ContratsLocations");
			printf("la modification a reussi");
		 }
		else{
			printf("contrat non modifier");
		}
	 }
	 else printf("Ce numero de contrat n'existe pas");
}
void supp_contract(){
  	float numrech;
 	char k;
 	printf("entrez numero de contrat a supperime :\t ");
 	scanf("%f",&numrech);
 	fflush(stdin);
 	if(recherchecontrat(numrech)==1){
 		printf("voulez-vous vraiment supperime o/n? ");
 		scanf("%c",&k);
 		fflush(stdin);
 		if(k=='o' || k=='O'){
 			suppression_contract(numrech);
            printf("suppression effectuee avec success");
		 }
		else{
			printf("contrat non supprimée");
		}
	 }
	 else printf("Ce numero de contrat n'existe pas");
}

int menu_principal(){
	int i,j,k,l,break_=0;
	printf("\n                               \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                               \xb3 Menu Principal  \xb3");
	printf("\n                               \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
	printf("\n\n");
	printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
    printf("\n               \xba                                              \xba");
	printf("\n               \xba       Location..........................1    \xba");
	printf("\n               \xba       Gestion voitures..................2    \xba");
	printf("\n               \xba       Gestion clients...................3    \xba");
	printf("\n               \xba       Quitter...........................4    \xba");
	printf("\n               \xba                                              \xba");
	printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
	printf("\n\n       \t\tVotre choix :  ");
	scanf("%d",&i);
	system("cls");
	switch(i){
		case 1:
            do{
                printf("\n                               \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
                printf("\n                               \xb3 Location  d'une voiture   \xb3");
                printf("\n                               \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
                printf("\n\n");
                printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
                printf("\n               \xba                                                      \xba");
                printf("\n               \xba   Visualiser contrat............................1    \xba");
                printf("\n               \xba   Louer voiture.................................2    \xba");
                printf("\n               \xba   Retourner voiture.............................3    \xba");
                printf("\n               \xba   Modifier contrat..............................4    \xba");
                printf("\n               \xba   Suppprimer contrat............................5    \xba");
                printf("\n               \xba   Retour........................................6    \xba");
                printf("\n               \xba                                                      \xba");
                printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
                printf("\n\n               Votre choix :  ");
                fflush(stdin);
                scanf("%d",&j);
                system("cls");
                switch(j){
                    case 1:
                        visualiser_contrat();
                        printf("\nAppuyez sur entrer pour continuer \n");
                        getch();
                        system("cls");
                        break;
                    case 2:
                        louer_voiture();
                        printf("\nAppuyez sur entrer pour continuer \n");
                        getch();
                        system("cls");
                        break;
                    case 3:
                        Retourner_voiture();
                        printf("\nAppuyez sur entrer pour continuer \n");
                        getch();
                        system("cls");
                        break;
                    case 4:
                        modifiercontrat();
                        printf("\nAppuyez sur entrer pour continuer \n");
                        getch();
                        system("cls");
                        break;
                    case 5:
                        supp_contract();
                        printf("\nAppuyez sur entrer pour continuer \n");
                        getch();
                        system("cls");
                        break;
                    case 6:
                        break_=1;
                        break;
                }
            }while(break_==0);
            break_=0;
            menu_principal();
			break;
		case 2:
            do{
                printf("\n                               \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
                printf("\n                               \xb3   Gestion des Voitures   \xb3 ");
                printf("\n                               \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
                printf("\n\n");
                printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
                printf("\n               \xba                                                     \xba");
                printf("\n               \xba   Liste des voitures..........................1     \xba");
                printf("\n               \xba   Ajouter voiture.............................2     \xba");
                printf("\n               \xba   Modifier voiture............................3     \xba");
                printf("\n               \xba   Supprimer voiture...........................4     \xba");
                printf("\n               \xba   Retour......................................5     \xba");
                printf("\n               \xba                                                     \xba");
                printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
                printf("\n\n               \t\tVotre choix :   ");
                scanf("%d",&k);
                system("cls");
                int b=1;
                switch(k){
                    case 1:
                        afficher();
                        printf("\nAppuyez sur entrer pour continuer \n");
                        getch();
                        system("cls");
                        break;
                    case 2:
                        ajoutevoiture();
                        printf("\nAppuyez sur entrer pour continuer \n");
                        getch();
                        system("cls");
                        break;
                    case 3:
                        modifiervoiture();
                        printf("\nAppuyez sur entrer pour continuer \n");
                        getch();
                        system("cls");
                        break;
                    case 4:
                        suppvoiture();
                        printf("\nAppuyez sur entrer pour continuer \n");
                        getch();
                        system("cls");
                        break;
                    case 5:
                        break_=1;
                        break;
                }
			}while(break_==0);
            break_=0;
            menu_principal();
			break;

		case 3:
            do{
                printf("\n                               \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
                printf("\n                               \xb3 Gestion des Clients \xb3           ");
                printf("\n                               \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
                printf("\n\n");
                printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
                printf("\n               \xba                                              \xba");
                printf("\n               \xba   Liste des clients.....................1    \xba");
                printf("\n               \xba   Ajouter client........................2    \xba");
                printf("\n               \xba   Modifier client.......................3    \xba");
                printf("\n               \xba   Suprimer client.......................4    \xba");
                printf("\n               \xba   Retour................................5    \xba");
                printf("\n               \xba                                              \xba");
                printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
                printf("\n\n               Votre choix :  ");
                scanf("%d",&l);
                system("cls");
                switch(l){
                    case 1:
                        afficherclient();
                        printf("\nAppuyez sur entrer pour continuer \n");
                        getch();
                        system("cls");
                        break;
                    case 2:
                        ajouteclient();
                        printf("\nAppuyez sur entrer pour continuer \n");
                        getch();
                        system("cls");
                        break;
                    case 3:
                        modifierclient();
                        printf("\nAppuyez sur entrer pour continuer \n");
                        getch();
                        system("cls");
                        break;
                    case 4:
                        suppclient();
                        printf("\nAppuyez sur entrer pour continuer \n");
                        getch();
                        system("cls");
                        break;
                    case 5:
                        break_=1;
                        break;
                }
			}while(break_==0);
            break_=0;
            menu_principal();
			break;
		case 4:
		exit(0);

        }
}



