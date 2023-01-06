#include "jeu.h"
int main(int argc, char const *argv[])
{
    PICKOMINO tabPicko[16];//la table des pickominos
    PILE_PICKO * pileJ1=NULL;//=creerPile(pick1);//pile du joueur 1
	PILE_PICKO * pileJ2=NULL;//pile du joueur 2
	JOUEUR j1,j2;char nomJ1[50],nomJ2[50];
	printf("BIENVENUE AU JEU PICKOMINO CHAQUE JOUEUR DOIT SAISIR SON NOM\n");
    printf("NOM JOUEUR 1:" );
    scanf("%s",nomJ1);
    printf("NOM JOUEUR 2:" );
    scanf("%s",nomJ2);
	j1=newPlayer(nomJ1);
	j2=newPlayer(nomJ2);
	int finJeu=1,*taillePickos;//la taille de table des pickominos
	   taillePickos=malloc(sizeof(int));//taille du tableau de pickominos
	   *taillePickos=3;
	 chargerTable_picko(tabPicko,4);

while(finJeu) {
	   if(*taillePickos<=0)
	   {
	   	finJeu=0;
	   }
	 printf("Les pickominos disponibles :\n");
	 afficherLesPickos(tabPicko,*taillePickos) ;
     printf(" Joueur 1\n");
       //tourRate=0;continuer=1;
	   if(*taillePickos!=0)
       jouer(&pileJ1,&pileJ2,tabPicko,taillePickos,1);
         else
        	finJeu=0;
         //deuxieme joueur
     	 printf(" Joueur numero 2\n");
     	 if(*taillePickos!=0)
       jouer(&pileJ2,&pileJ1,tabPicko,taillePickos,2);
        else
        	finJeu=0;
      
}
 j1.score=compterPoints(pileJ1);      
j2.score=compterPoints(pileJ2);
 vainceur( j1,j2); 
	 detruirePile(pileJ1);
	 detruirePile(pileJ2);
	return 0;
}