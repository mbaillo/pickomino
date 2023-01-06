#ifndef JEU_H
#define JEU_H  
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct pickomino
{
  int val;//la valeur du pickomino
  int nbPoint;//le nombre de point 
} PICKOMINO;
typedef struct joueur {
	char nom[45] ;
	int score;
} JOUEUR;

//declaration de la pile de pickomino
typedef struct pilePicko {
	//int val;//valeur de picko
	//int nbP;//nombre de point
	PICKOMINO picko;//le pickomino
	struct pilePicko *suiv;
} PILE_PICKO;
PILE_PICKO * empiler(PILE_PICKO * listP,PICKOMINO p);
PILE_PICKO *  depiler(PILE_PICKO * listP);
PILE_PICKO * creerPile(PICKOMINO p);
PILE_PICKO *  detruirePile(PILE_PICKO * p);
PICKOMINO picko(int v,int n);
void afficher_Picko(PICKOMINO p);
void afficher_pilePico(PILE_PICKO * p);
void ajouter_Picko(PILE_PICKO *lp,PICKOMINO p );
void lancer_de(int ,int *,int *);
void supprimer_Picko(PICKOMINO tab[],int* n,int);
void ajouter_PickoTable(PICKOMINO tab[],int* n,int,int);
int recherche_picko(PICKOMINO tab[],int n,int val);
void chargerTable_picko(PICKOMINO tab[],int n) ;
void afficherLesPickos(PICKOMINO tab[],int n);
JOUEUR newPlayer(char * nom);

void showPlayer(JOUEUR );
int occurenceDes(int *tab,int n,int);
void ajoutDes(int *tab,int *taille,int);
int calculTotalPoint(int *tab,int taille,int *);
int recherche_De(int *tab,int n,int val);
int compterPoints(PILE_PICKO *lp);
void supprimerDe(int *tab,int *n,int val);
PICKOMINO sommet(PILE_PICKO *p) ;
int indiceInferieur(PICKOMINO *tab,int n,int val);
PICKOMINO  maxPicko(PILE_PICKO *p);
PICKOMINO maxPickoTable(PICKOMINO *,int );
PILE_PICKO * supprimerPickoDansPile(PILE_PICKO *p,int  val);
void vainceur(JOUEUR j1,JOUEUR j2) ;
void jouer(PILE_PICKO **,PILE_PICKO **,PICKOMINO *,int *,int) ;


#endif //JEU_H