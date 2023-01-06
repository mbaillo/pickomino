#include "jeu.h"
//la fonction de creation d une pile prend un pickomino en parametre
PILE_PICKO * creerPile(PICKOMINO pic) {
 PILE_PICKO *p;
 p=(PILE_PICKO*)malloc(sizeof (PILE_PICKO));
 p->picko=pic;
 p->suiv=NULL;
 return p;
}
/*----------------------------------------------------*/
//la fonction empiler ajoute un picko a la tete de la pile des pickos

PILE_PICKO * empiler(PILE_PICKO * listP,PICKOMINO picko) {
  PILE_PICKO *newPicko;
      newPicko=creerPile(picko);
      if(listP==NULL) {
      	  listP=newPicko;
      }
      else {
      newPicko->suiv=listP;
      listP=newPicko;
       }
       return listP;

}
/*----------------------------------------------------*/

//depiler c'est pour supprimer le picko en tete de la liste des pickominos
PILE_PICKO *  depiler(PILE_PICKO * listP) {
    if(listP==NULL)
    	return NULL;

    return listP->suiv;

}
/*----------------------------------------------------*/
//pour liberer les espaces  aloues
PILE_PICKO * detruirePile(PILE_PICKO * p) {
	PILE_PICKO * c,*q;
	c=p;
	while(c!=NULL) {
		q=c;
		c=c->suiv;
		free(q);

	}
	return NULL;
}
/*----------------------------------------------------*/
void afficher_Picko(PICKOMINO p) {
	printf(" |%d|\n |%d| \n",p.val ,p.nbPoint);
}
/*----------------------------------------------------*/
//un pickomino a une valeur v et point n  
PICKOMINO picko(int v,int n) {
	PICKOMINO p;
	p.val=v;
	p.nbPoint=n;
	return p;
}

/*----------------------------------------------------*/

//pour lancer n dés  
void lancer_de(int n,int *c,int *tab) {
	srand(time(NULL));//cette fonction pour dire qu on utilise les aleas(nombres choisis par hasard)
	int a,i=0;
	*c=0;
	int max=1,count=0;//la valeur maximale 

	for ( i = 0; i < n; i++)
	{
      a=rand()%6 + 1;//choix d un nombre aleatoire entre 1 et 6(6 pour V)
      tab[i]=a;//on garde les valeurs de chaque de afin de savoir l apparution du plus grand
      if(a!=6)
      	printf("[%d]", a);
      else
      	printf("[V]");
	}
	(*c)=i;

}
/*----------------------------------------------------*/

//rechercher un pickomono dans la table de pickomino
int recherche_picko(PICKOMINO tab[],int n,int val) {
	int i=0;
	while(i<n&&(tab[i].val!=val))
		i++;
	if(i<n)
		return i;
	return -1;
}
/*----------------------------------------------------*/

//supprimer un pickomino de la table
void supprimer_Picko(PICKOMINO tab[],int *n,int val) {
	int pos=recherche_picko(tab,*n,val);
	if(pos!=-1)
		for (int i = pos; i < *n -1; i++)
		{
			tab[i]=tab[i+1];
		}
     (*n)--;
 
}
/*----------------------------------------------------*/

//ajouter un pickomino a la table
void ajouter_PickoTable(PICKOMINO tab[],int* n,int val,int point) {
	(*n)++;//augmentation de la taille du tableau des picko
	PICKOMINO p=picko(val,point);
	tab[*n -1]=p;

}
/*----------------------------------------------------*/
//elle charge la table des pickominos qui comprend 16 pickos
void chargerTable_picko(PICKOMINO tab[],int n) {
   int i;
	for (i = 0; i < 4; ++i)
	{
		tab[i]=picko(21+i,1);
	}
	for ( i =4; i <8 ;i++)
	{
		tab[i]=picko(21+i,2);
		
	}
	for ( i =8; i <12 ;i++)
	{
		tab[i]=picko(21+i,3);
		
	}
	for ( i =12; i <16 ;i++)
	{
		tab[i]=picko(21+i,4);
		
	}
}
/*----------------------------------------------------*/
//
void afficherLesPickos(PICKOMINO tab[],int n) {
	for (int i = 0; i < n; ++i)
	{
       afficher_Picko(tab[i]);
       printf(" \n");
   	}
} 
/*----------------------------------------------------*/

//nouveau joueur
JOUEUR newPlayer(char * nom) {
	JOUEUR j;
	strcpy(j.nom,nom);
	j.score=0;
	return j;
}
/*----------------------------------------------------*/

//afficher un joueur
void showPlayer(JOUEUR j) {
	printf("Le joueur %s a pour score:%d\n",j.nom,j.score);
} 
/*----------------------------------------------------*/
//elle cherche le nombre d apparution d un entier dans un tableau
int occurenceDes(int *tab,int n,int val) {
	int count=0;
	for (int i = 0; i < n; ++i)
	{
		if(tab[i]==val)
			count++;
	}
	return count;
}
/*----------------------------------------------------*/

//pour conserver les des que le joueur veut garder
void ajoutDes(int *tab,int *taille,int val){
	tab[*taille]=val;
	(*taille)++;
}
/*----------------------------------------------------*/

//la fonction qui calcule le totale des points
int calculTotalPoint(int *tabDe,int taille,int *tabOc) {
	int somme=0,i;
	for (i = 0; i < taille; ++i)
	{  
		if(tabDe[i]==6)
         somme+=5*tabOc[i];
      else
        somme+=tabDe[i]*tabOc[i];
	}
	return somme;
}
/*----------------------------------------------------*/

int recherche_De(int *tab,int n,int val) //la fonction recherche un dé parmis les des gardes du joueur
{
	int i=0;
	while(i<n && tab[i]!=val)
		i++;
	if(i<n)
		return i;
	return -1;

}
/*----------------------------------------------------*/
//pour afficher la pile de picko d un joueur
void afficher_pilePico(PILE_PICKO * p) {
   PILE_PICKO *c;
   c=p;
   while(c!=NULL) {
   	afficher_Picko(c->picko);
   	c=c->suiv;
   }	

}
/*----------------------------------------------------*/
//elle suprime un entier dans un tab d entiers
void supprimerDe(int *tab,int *n,int val)
 {
	int i=0,pos;
	pos=recherche_De(tab,*n,val);
	for (i = pos; i <*n-1 ; i++)
	{
     tab[i]=tab[i+1];
	}
	(*n)--;
}
/*----------------------------------------------------*/

//compter le nombre des points d un joueur pour trouver le nombre de points cumules a la fin du jeu
int compterPoints(PILE_PICKO *lp) {
 int count=0;
 PILE_PICKO *p;
 p=lp;
 while(p!=NULL) {
 	count+=(p->picko).nbPoint;
 	p=p->suiv;
 }
 return count;
}
/*------------------- ---------------------------------*/
//retourne le picko au sommet de la pile
PICKOMINO sommet(PILE_PICKO *p) 
{
	return p->picko;
}
/*----------------------------------------------------*/
//pour trouver l indice du pickomino qui vient apres un nombre val quelconque,dans la table des pickos
int indiceInferieur(PICKOMINO *tabPic ,int n,int val) {
	int i=0;
	while(i<n&&tabPic[i].val<val)
		i++;
	return i-1;

}
/*----------------------------------------------------*/

/*retourner le picko de valeur maximale dans la pile,elle sera utile lorsque le joueur
 ratera son tour ,il metera le picko de plus grande valeur dans sa pile
*/
PICKOMINO  maxPicko(PILE_PICKO *p) {
	int max;
	PICKOMINO pic;
	PILE_PICKO *c;//courant
	c=p->suiv;
	max=(p->picko).val;
     while(c!=NULL) {
      if((c->picko).val>max)
      {
      	max=(c->picko).val;
      	pic=c->picko;
      }
      c=c->suiv;
     }
     return pic;
}
/*----------------------------------------------------*/
//retourner le picko de valeur maximale dans la table des pickos,utile dans le cas le joueur a un total qui
//depase la valeur de picko le plus grand sur la table 
PICKOMINO maxPickoTable(PICKOMINO *tab,int n ) {
	int i=1;
	PICKOMINO p;
	p=tab[0];
    while(i<n) {
    	if(tab[i].val>p.val)
    		p=tab[i];
    	i++;
    }
	return p;//
}
/*----------------------------------------------------*/
//supprimer un picko dans la pile du joueur
//apres la suppression une nouvelle pile sans le picko supprime
PILE_PICKO * supprimerPickoDansPile(PILE_PICKO *p,int  val) {
	PILE_PICKO *newPile=NULL;
      while(p!=NULL) {
      	if((p->picko).val!=val)
      		newPile=empiler(newPile,p->picko);
      	p=p->suiv;
      }
      return newPile;

}
/*----------------------------------------------------*/
//pour faire le statistique du jeu a la fin
void vainceur(JOUEUR j1,JOUEUR j2) {
	if(j1.score==j2.score)
		printf("VOUS AVEZ FAIT UN MATCH NUL %d-%d PAR TOUT\n",j1.score,j1.score);
	 else {
	 	if(j1.score>j2.score)
	 		printf("BRAVO %s VOUS AVEZ GAGNE AVEC DIFFERENCE DE %d!!!!\n ",j1.nom,j1.score-j2.score );
	 		else
	 		 printf("BRAVO %s VOUS AVEZ GAGNE AVEC DIFFERENCE DE %d!!!!\n ",j2.nom ,j2.score-j1.score);
	 }
}
/*------------------------------------------------------------------------------------------------*/
//cette fonction demare le  jeu,elle prend deux piles de joueurs ,un tableau de pickominos et sa taille
//et le numero du joueur (1 ou 2)
void jouer(PILE_PICKO **pileJ1,PILE_PICKO **pileJ2,PICKOMINO *tabPicko,int *taillePickos,int numJ) {
	PICKOMINO somet,picMax;//picMax prendra le picko max du tableau
    char repJ1[5];
	int i,b, continuer,a,deGarde,k,*c,nbDes,*tailleOc1;
	int *tabOcJ1=malloc(8*sizeof(int));//tableau des occurences des des du joueur 
	int *tab=malloc(8*sizeof(int));//tableau des des
	 tailleOc1=malloc(sizeof(int));
	int *n1,tourRate,*desJ1=malloc(8*sizeof(int));//on garde les des que le joueur 1 decide de garder et son occurence
	c=malloc(sizeof(int));
	n1=malloc(sizeof(int));
	nbDes=8;*n1=0;
     tourRate=0;continuer=1;*tailleOc1=0;//taille du tableau des occurences de des
     b=1;
	while(continuer) {
     	 printf("Voulez vous continuer a jouer le %d lance oui ou non ?\n",b++);
     	 scanf("%s",repJ1);
     	 if(strcmp(repJ1,"oui")==0){
     	 	 lancer_de(nbDes,c,tab);//afficher les dés au debut 8 chance 
           printf("\nChoisir le de a garder V=6\n");
           scanf(" %d",&deGarde);//recuperer la valeur saisi par le joueur
           a=occurenceDes(tab,*c,deGarde);//prendre son nombre d apparution dans le tableau de des
          k=recherche_De(desJ1,*n1,deGarde);//rechercher si le nombre est deja present dans le tableau de des
          if(k==-1)
          for (i = 0; i < a; i++)
          	nbDes--;
         if(k==-1){
           	    ajoutDes(tabOcJ1,tailleOc1,a);//ajouter l occurence du nombre dans le tableau
                ajoutDes(desJ1,n1,deGarde);//mettre le dé a coté
                if(deGarde==6)
                printf("la valeur garde :V et le nombre d apparution :%d \n",a );
                else
                printf("la valeur garde :%d et le nombre d apparution :%d \n",deGarde,a );

               }
           else//TOUR RATE,lorsque le joueur rate son tour
           	{ continuer=0;tourRate=1;
           		printf(" le de de numero %d  est deja pris (mis de cote)\n",deGarde);
           		if(*pileJ1!=NULL)
           		{
              	  somet=sommet(*pileJ1);//recuper le picko au sommet de la pile de 2e joueur
                  picMax=maxPickoTable(tabPicko,*taillePickos); //le picko de valeur maximal present dans la table
                  if(somet.val==picMax.val)//on compare le picko qui est au sommet de sa pile avec le picko max du table
                  {
                  ajouter_PickoTable(tabPicko,taillePickos,somet.val,somet.nbPoint);
                  *pileJ1=depiler(*pileJ1);
                 }
                 else {//si le picko au sommet n est pas le picko maximal
                         ajouter_PickoTable(tabPicko,taillePickos,somet.val,somet.nbPoint);
                         *pileJ1=depiler(*pileJ1);
                         if(*pileJ1!=NULL)
                         {
                         picMax= maxPicko(*pileJ1);
                         ajouter_PickoTable(tabPicko,taillePickos,picMax.val,picMax.nbPoint);//ajouter le picko dans la table
                         *pileJ1=supprimerPickoDansPile(*pileJ1,picMax.val);//supprimer le picko de valeur maximale dans la table
                         }
                      }
            }
         }
     	}
     	 else//si la reponse est non on arrete la partie
     	 	continuer=0;
      }//sortie du joueur  ok

      //etape pour prendre un pickomino
      b= calculTotalPoint(desJ1,*n1,tabOcJ1);//calcule le total necessaire pour choisir un pickomino
     printf("votre  total pour prendre pickomino est :%d \n",b);
     if(b<21)//TOUR RATE car le joueur ne peut pas prendre un pickomino son total est inferieur
     	{      printf(" Desole votre tour est rate votre total est insuffisant\n" );
           		if(*pileJ1!=NULL)//si la pile du joueur n est pas vide il doit rendre un picko au sommet plus un picko de valeur maximal  
           		{ 
              	  somet=sommet(*pileJ1);//recuper le picko au sommet de la pile de 2e joueur
                  picMax=maxPickoTable(tabPicko,*taillePickos); 
                  if(somet.val==picMax.val)
                  {
                  ajouter_PickoTable(tabPicko,taillePickos,somet.val,somet.nbPoint);
                  *pileJ1=depiler(*pileJ1);
                  }
                 else {
                         ajouter_PickoTable(tabPicko,taillePickos,somet.val,somet.nbPoint);
                         *pileJ1=depiler(*pileJ1);
                         if(*pileJ1!=NULL)
                         {
                         picMax= maxPicko(*pileJ1);
                         ajouter_PickoTable(tabPicko,taillePickos,picMax.val,picMax.nbPoint);
                         *pileJ1=supprimerPickoDansPile(*pileJ1,picMax.val);
                       }
                 }
            }
        }//b<21
      else{//on teste si le tour n es pas raté 
      	 if(tourRate==0) {
          k=recherche_picko(tabPicko,*taillePickos,b);
         if(k!=-1)
     	  {
     	  *pileJ1=empiler(*pileJ1,tabPicko[k]);
          supprimer_Picko(tabPicko,taillePickos,b);//une fois prendre un picko on le  supprime dans la table des pickominos 
     	  }
     else {//si le picko a choisir n est pas dans la table
              if(*pileJ2!=NULL){
              	  somet=sommet(*pileJ2);//recuper le picko au sommet de la pile de 2e joueur
                 if(somet.val==b){
                  *pileJ1=empiler(*pileJ1,somet);
                  *pileJ2=depiler(*pileJ2); 
                 }
                 else{
                 	k=indiceInferieur(tabPicko,*taillePickos,b);//on cherche le picko plus petit que la valeur dans la table
                   *pileJ1=empiler(*pileJ1,tabPicko[k]);
                   supprimer_Picko(tabPicko,taillePickos,tabPicko[k].val);//une prendre un picko on le  supprime dans la table des pickominos 
                   }
                }
              else //si la pile du joueur 2 vide on prend le picko qui a valeur petite que total du point 
              {
              	//printf("cas ou on prend le petit picko que le total\n");
              	k=indiceInferieur(tabPicko,*taillePickos,b);//on cherche le picko plus petit que la valeur dans la table
                 *pileJ1=empiler(*pileJ1,tabPicko[k]);
                 supprimer_Picko(tabPicko,taillePickos,tabPicko[k].val);//une prendre un picko on le  supprime dans la table des pickominos 
              }
         }
        }
        else //le tour est rate le joueur doit mettre un picko sur la table
         {      printf("Votre tour est rate !!!!\n");
        	   	if(*pileJ1!=NULL)
           		{
              	  somet=sommet(*pileJ1);//recuper le picko au sommet de la pile de 2e joueur
                  picMax=maxPickoTable(tabPicko,*taillePickos); 
                  if(somet.val==picMax.val)
                  {
                  ajouter_PickoTable(tabPicko,taillePickos,somet.val,somet.nbPoint);
                  *pileJ1=depiler(*pileJ1);
                 }
                 else {
                         ajouter_PickoTable(tabPicko,taillePickos,somet.val,somet.nbPoint);
                         *pileJ1=depiler(*pileJ1);
                         if(*pileJ1!=NULL)
                         {
                         picMax= maxPicko(*pileJ1);
                         ajouter_PickoTable(tabPicko,taillePickos,picMax.val,picMax.nbPoint);
                         *pileJ1=supprimerPickoDansPile(*pileJ1,picMax.val);
                         }
                      }
            }
           } 
     }
       if(*pileJ1!=NULL){//afficher la pile du joueur
         	printf("pile joueur %d\n",numJ);
           afficher_pilePico(*pileJ1);
         }  
         printf("Les pickominos disponible: \n");
	     afficherLesPickos(tabPicko,*taillePickos);

	    
}
