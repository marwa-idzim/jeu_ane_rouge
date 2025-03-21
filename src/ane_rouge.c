#include <libTableauNoir.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct { int l1; int c1; int l2; int c2; }piece_t;
typedef struct { piece_t p[10];int ps;}etat_t;
typedef struct { int p; piece_t f; int direction;}deplacement_t;
typedef struct { int l; int c;}case_t;
//direction:(vers la droite=0; vers le haut=1; vers la gauche=2; vers le bas=3)


etat_t init_aleatoire(int n)
{//tracer le cadre et definir les positions initales:
  etat_t etat;
  choisirTypeStylo(10,108,2,119);
  tracerSegment(-208,259,208,259);
  tracerSegment(-208,259,-208,-259);
  tracerSegment(208,-259,208,259);
  tracerSegment(-208,-259,-108,-259);
  tracerSegment(208,-259,108,-259);
  choisirTypeStylo(2,254, 191, 210);
  choisirCouleurPinceau(254, 191, 210);
  tracerRectangle(-202,253,202,-253);
  //classic:
  if(n==0)
    {
      etat=(etat_t){
	.p={{0,1,1,2},{0,0,1,0},{0,3,1,3},{2,0,3,0},{2,1,2,2},{2,3,3,3},{3,1,3,1},{3,2,3,2},{4,0,4,0},{4,3,4,3}},
	.ps=-1,
      };
    }
  if(n==1)
    {
      etat=(etat_t){
	.p={{0,1,1,2},{0,0,0,0},{0,3,0,3},{1,0,1,0},{1,3,1,3},{2,1,2,2},{3,0,4,0},{3,1,4,1},{3,2,4,2},{3,3,4,3}},
	.ps=-1,
      };
    }
  //facile:
  if(n==2)
    {
      etat=(etat_t){
	.p={{2,2,3,3},{0,0,1,0},{0,1,1,1},{0,2,0,2},{0,3,0,3},{1,2,1,3},{3,0,4,0},{3,1,4,1},{4,2,4,2},{4,3,4,3}},
	.ps=-1,
      };
    }
  if(n==3)
    {
      etat=(etat_t){
	.p={{3,2,4,3},{0,0,0,0},{0,1,0,2},{0,3,0,3},{1,0,2,0},{1,1,1,2},{1,3,1,3},{3,0,3,0},{2,1,3,1},{4,0,4,1}},
	.ps=-1,
      };
    }
  if(n==4)
    {
      etat=(etat_t){
	.p={{0,2,1,3},{0,0,0,1},{1,0,1,1},{2,0,2,1},{3,0,4,0},{3,1,4,1},{3,2,3,2},{3,3,3,3},{4,2,4,2},{4,3,4,3}},
	.ps=-1,
      };
    }
  if(n==5)
    {
      etat=(etat_t){
	.p={{0,0,1,1},{0,2,0,2},{0,3,0,3},{1,2,1,3},{2,2,2,3},{3,0,4,0},{3,1,4,1},{3,2,3,3},{4,2,4,2},{4,3,4,3}},
	.ps=-1,
      };
    }
  if(n==6)
    {
      etat=(etat_t){
	.p={{0,0,1,1},{0,2,0,2},{0,3,0,3},{1,2,1,3},{2,2,2,3},{3,0,4,0},{3,1,4,1},{3,2,3,3},{4,2,4,2},{4,3,4,3}},
	.ps=-1,
      };
    }
  //moyen:
  if(n==7)
    {
      etat=(etat_t){
	.p={{0,0,1,1},{0,2,0,2},{0,3,0,3},{1,2,1,2},{1,3,1,3},{2,2,2,3},{3,0,4,0},{3,1,4,1},{3,2,3,3},{4,2,4,3}},
	.ps=-1,
      };
    }
  if(n==9)
    {
      etat=(etat_t){
	.p={{0,2,1,3},{0,0,0,1},{2,0,2,0},{2,1,2,1},{2,2,2,2},{2,3,2,3},{3,0,4,0},{3,1,4,1},{3,2,4,2},{3,3,4,3}},
	.ps=-1,
      };
    }
  if(n==8)
    {
      etat=(etat_t){
	.p={{0,2,1,3},{0,0,1,0},{0,1,1,1},{2,0,2,1},{3,0,3,1},{3,2,3,2},{3,3,3,3},{4,0,4,1},{4,2,4,2},{4,3,4,3}},
	.ps=-1,
      };
    }
  if(n==10)
    {
      etat=(etat_t){
	.p={{0,1,1,2},{0,0,1,0},{0,3,0,3},{1,3,1,3},{2,1,2,2},{3,0,3,0},{3,1,4,1},{3,2,4,2},{3,3,4,3},{4,0,4,0}},
	.ps=-1,
      };
    }
  if(n==11)
    {
      etat=(etat_t){
	.p={{3,2,4,3},{0,0,1,0},{0,1,1,1},{0,2,1,2},{0,3,0,3},{1,3,1,3},{2,2,2,2,},{2,3,2,3},{3,0,3,1},{4,0,4,1}},
	.ps=-1,
      };
    }
  //difficile:
  if(n==12)
    {
      etat=(etat_t){
	.p={{3,0,4,1},{0,0,0,0},{0,1,1,1},{0,2,1,2},{0,3,1,3},{1,0,1,0},{2,0,2,0},{2,1,2,1},{3,2,3,3},{4,2,4,3}},
	.ps=-1,
      };
    }
  if(n==13)
    {
      etat=(etat_t){
	.p={{3,2,4,3},{0,0,0,0},{0,1,0,1},{0,2,0,2},{0,3,0,3},{1,0,2,0},{1,1,1,2},{1,3,2,3},{3,0,3,1},{4,0,4,1}},
	.ps=-1,
      };
    }
  if(n==14)
    {
      etat=(etat_t){
	.p={{0,1,1,2},{0,0,0,0},{0,3,0,3},{1,0,1,0},{1,3,1,3},{2,1,2,2},{3,0,4,0},{3,1,4,1},{3,2,3,3},{4,2,4,3}},
	.ps=-1,
      };
    }
  if(n==15)
    {
      etat=(etat_t){
	.p={{2,1,3,2},{0,0,1,0},{0,1,0,1},{0,2,0,2},{0,3,1,3},{1,1,1,1},{1,2,1,2},{2,0,3,0},{4,0,4,1},{4,2,4,3}},
	.ps=-1,
      };
    }
  if(n==16)
    {
      etat=(etat_t){
	.p={{2,1,3,2},{0,0,1,0},{0,1,0,1},{0,2,0,2},{0,3,1,3},{1,1,1,1},{1,2,1,2},{2,3,3,3},{4,0,4,1},{4,2,4,3}},
	.ps=-1,
      };
    }
  return etat;
}

int verifier(double x , double y)
//retourne 1 si (x,y) est a l'interieur du cadre et retourne 0 sinon:
{
  if(x<202 && x>-202 && y<253 && y>-253)
    return 1;
  else
    return 0;
}
int verifier_si_vide(etat_t etat, int l, int c)
/*retourne -1 si la case l c est vide et retourne l'indice i de la piece qui occupe cette case sinon*/
{
  int n=-1;
  for(int i=0;i<10;i=i+1)
    {
      if(l>=etat.p[i].l1 && l<=etat.p[i].l2 && c>=etat.p[i].c1 && c<=etat.p[i].c2)
	{
	  n=i;
	}
    }
  return n;
}
case_t chercher(double x, double y)
/*cherche la case qui contient les coord x et y et retourne la ligne et la colonne de cette case*/
{
  int l=-1;
  int c=-1;
  for(int i=0;i<5;i=i+1)
    {
      for(int j=0;j<4;j=j+1)
	{
	  if(x>102*j-202 && x<102*j-202+98 && y<253-102*i && y>253-98-102*i )
	    {
	      l=i;
	      c=j;
	    }
	}
    }
  case_t cas ={l,c};
  return cas;
}

deplacement_t donneesdudeplacement(etat_t* etat)
{
  EtatSourisClavier esc = lireEtatSourisClavier();
  deplacement_t dep;
  //save l'indice de la piece selectionnee dans ps ( si la case est vide ps=-1)
  if(esc.sourisBoutonGauche && verifier(esc.sourisX ,esc.sourisY))
    {
      int lg=chercher(esc.sourisX ,esc.sourisY).l;
      int cg=chercher(esc.sourisX ,esc.sourisY).c;
      (*etat).ps=verifier_si_vide(*etat ,lg,cg);
    }
  
  
  //verifier si la case lg cg n'est pas vide:(si vide ps=-1 sinon ps=indice de la piece qui l'occupe):
  int ld;
  int cd;
  
  if(esc.sourisBoutonDroit && verifier(esc.sourisX ,esc.sourisY))
    {
      //chercher la colonne et la ligne du clic droit et le mettre dans ld et cd:
      ld=chercher(esc.sourisX ,esc.sourisY).l;
      cd=chercher(esc.sourisX ,esc.sourisY).c;
      
      //verifier si la case ld cd est vide:(si vide n=-1 sinon n=indice de la piece qui l'occupe)
      int n=verifier_si_vide(*etat,ld, cd);
      
      if(n==-1 && (*etat).ps!=-1)
	{
	  int ps=(*etat).ps;
	  //verifier si le deplacement est permis:
	  //si la case vide se trouve juste en dessous de la piece selectionnee:on verifie que toutes les cases qui se trouvent juste en dessous de la piece sont vides:
	  if((*etat).p[ps].l2-ld==-1  &&  (*etat).p[ps].c1<=cd && (*etat).p[ps].c2>=cd
	     && verifier_si_vide(*etat, ld, (*etat).p[ps].c1)==-1 && verifier_si_vide(*etat, ld,(*etat).p[ps].c2)==-1  )
	    {
	      //deplacement possible
	      dep=(deplacement_t){ps,{ (*etat).p[ps].l1+1 ,(*etat).p[ps].c1, (*etat).p[ps].l2+1 ,(*etat).p[ps].c2},3};
	      return dep;
	    }
	  //si la case vide se trouve juste en dessus de la piece selectionnee:on verifie que toutes les cases qui se trouvent juste en dessus de la piece sont vides:
	  if((*etat).p[ps].l1-ld==1  &&  (*etat).p[ps].c1<=cd && (*etat).p[ps].c2>=cd
	     && verifier_si_vide(*etat, ld, (*etat).p[ps].c1)==-1 && verifier_si_vide(*etat, ld,(*etat).p[ps].c2)==-1  )
	    {
	      //deplacement possible
	      dep=(deplacement_t){ps,{ (*etat).p[ps].l1-1 ,(*etat).p[ps].c1, (*etat).p[ps].l2-1 ,(*etat).p[ps].c2},1};
	      return dep;
	    }
	  //si la case vide se trouve juste a droite de la piece selectionnee:on verifie que toutes les cases qui se trouvent juste a droite de la piece sont vides:
	  if((*etat).p[ps].c2-cd==-1  && (*etat).p[ps].l1<=ld && (*etat).p[ps].l2>=ld
	     && verifier_si_vide(*etat, (*etat).p[ps].l1 , cd )==-1 && verifier_si_vide(*etat,(*etat).p[ps].l2 , cd)==-1  )
	    {
	      //deplacement possible
	      dep=(deplacement_t){ps,{ (*etat).p[ps].l1 ,(*etat).p[ps].c1+1, (*etat).p[ps].l2 ,(*etat).p[ps].c2+1},0};
	      return dep;
	    }
	  //si la case vide se trouve juste a gauche de la piece selectionnee:on verifie que toutes les cases qui se trouvent juste a gauche de la piece sont vides:
	  if((*etat).p[ps].c1-cd==1  && (*etat).p[ps].l1<=ld && (*etat).p[ps].l2>=ld
	     && verifier_si_vide(*etat, (*etat).p[ps].l1 , cd )==-1 && verifier_si_vide(*etat,(*etat).p[ps].l2 , cd) ==-1  )
	    {
	      //deplacement possible
	      dep=(deplacement_t){ps,{ (*etat).p[ps].l1 ,(*etat).p[ps].c1-1, (*etat).p[ps].l2 ,(*etat).p[ps].c2-1},2};
	      return dep;
	    }
	  else
	    {
	      dep=(deplacement_t){-1,{-1,-1,-1},-1};
	      return dep;
	    }
	}
      else
	{
	  dep=(deplacement_t){-1,{-1,-1,-1},-1};
	  return dep;
	}
    }
  else
    {
      dep=(deplacement_t){-1,{-1,-1,-1},-1};
      return dep;
    }
}
void afficher(etat_t etat)
{
  choisirCouleurPinceau(255,0,0);//couleur de l'ane en rouge( piece d'indice 0)
  choisirTypeStylo(2,129, 20, 83);
  for(int i=0; i<10; i=i+1)
    {
      tracerRectangle(etat.p[i].c1*102-202, 253-etat.p[i].l1*102,
		      etat.p[i].c2*102-202+98,253-etat.p[i].l2*102-98);
      choisirCouleurPinceau(223,115,255);//couleur des autres pieces (les pieces en mauve) 
    }
  
  if(etat.ps!=-1)//si le joueur selectionne une piece, il y aura un changement de couleur de la piece selectionnee
    {
      if(etat.ps==0)
	choisirCouleurPinceau(187, 11, 11);
      else
	choisirCouleurPinceau(128, 0, 128);
      choisirTypeStylo(2,129, 20, 83);
      tracerRectangle(etat.p[etat.ps].c1*102-202, 253-etat.p[etat.ps].l1*102,
		      etat.p[etat.ps].c2*102-202+98,253-etat.p[etat.ps].l2*102-98);
    }
}
void effacer()
{
  choisirTypeStylo(10,108,2,119);
  tracerSegment(-208,259,208,259);
  tracerSegment(-208,259,-208,-259);
  tracerSegment(208,-259,208,259);
  tracerSegment(-208,-259,-108,-259);
  tracerSegment(208,-259,108,-259);
  choisirTypeStylo(2,254, 191, 210);
  choisirCouleurPinceau(254, 191, 210);
  tracerRectangle(-202,253,202,-253);
}
void deplacement(deplacement_t dep, etat_t* etat)
{
  double dt;
  Son pop=chargerAudio ("../data/dep.wav");
  if(dep.p!=-1)//deplacement possible
    {
      if(dep.direction==0)//deplacement vers la droite
	{
	  double y1=(*etat).p[dep.p].c1;
	  double y2=(*etat).p[dep.p].c2;
	  dt = delta_temps();
	  while( y1<dep.f.c1 && y2<dep.f.c2)
	    {
	      dt = delta_temps();
	      choisirTypeStylo(2,254, 191, 210);
	      choisirCouleurPinceau(254, 191, 210);
	      tracerRectangle(y1*102-202, 253-(*etat).p[dep.p].l1*102,
			      y2*102-202+98,253-(*etat).p[dep.p].l2*102-98);
	      y1=10*dt+y1;
	      y2=10*dt+y2;
	      if( y1<dep.f.c1 && y2<dep.f.c2)
		{
		  if(dep.p==0)
		    choisirCouleurPinceau(255,0,0);
		  else
		    choisirCouleurPinceau(223,115,255);
		  choisirTypeStylo(2,129, 20, 83);
		  tracerRectangle(y1*102-202, 253-(*etat).p[dep.p].l1*102,
				  y2*102-202+98,253-(*etat).p[dep.p].l2*102-98);
		  tamponner();
		}
	    }
	  (*etat).p[dep.p].c1=dep.f.c1;
	  (*etat).p[dep.p].c2=dep.f.c2;
	  jouerSon(pop,0);
	  effacer();
	  afficher(*etat);
	  tamponner();
	  printf("la piece numero %d s'est deplacee une case vers la droite\n",dep.p);
	  dep.p=-1;
	  etat->ps=-1;
	}
      if(dep.direction==1)//deplacement vers le haut
	{
	  double x1=(*etat).p[dep.p].l1;
	  double x2=(*etat).p[dep.p].l2;
	  dt = delta_temps();
	  while( x1>dep.f.l1 && x2>dep.f.l2)
	    {
	      dt = delta_temps();
	      choisirTypeStylo(2,254, 191, 210);
	      choisirCouleurPinceau(254, 191, 210);
	      tracerRectangle((*etat).p[dep.p].c1*102-202, 253-x1*102,
			      (*etat).p[dep.p].c2*102-202+98,253-x2*102-98);
	      x1=-10*dt+x1;
	      x2=-10*dt+x2;
	      if( x1>dep.f.l1 && x2>dep.f.l2)
		{
		  if(dep.p==0)
		    choisirCouleurPinceau(255,0,0);
		  else
		    choisirCouleurPinceau(223,115,255);
		  choisirTypeStylo(2,129, 20, 83);
		  tracerRectangle((*etat).p[dep.p].c1*102-202, 253-x1*102,
				  (*etat).p[dep.p].c2*102-202+98,253-x2*102-98);
		  tamponner();
		}
	    }
	  (*etat).p[dep.p].l1=dep.f.l1;
	  (*etat).p[dep.p].l2=dep.f.l2;
	  jouerSon(pop,0);
	  effacer();
	  afficher(*etat);
	  tamponner();
	  printf("la piece numero %d s'est deplacee une case vers le haut\n",dep.p);
	  dep.p=-1;
	   etat->ps=-1;
	}
      if(dep.direction==2)//deplacement vers la gauche
	{
	  double y1=(*etat).p[dep.p].c1;
	  double y2=(*etat).p[dep.p].c2;
	  dt = delta_temps();
	  while( y1>dep.f.c1 && y2>dep.f.c2)
	    {
	      dt = delta_temps();
	      choisirTypeStylo(2,254, 191, 210);
	      choisirCouleurPinceau(254, 191, 210);
	      tracerRectangle(y1*102-202, 253-(*etat).p[dep.p].l1*102,
			      y2*102-202+98,253-(*etat).p[dep.p].l2*102-98);
	      y1=-10*dt+y1;
	      y2=-10*dt+y2;
	      if(y1>dep.f.c1 && y2>dep.f.c2)
		{
		  if(dep.p==0)
		    choisirCouleurPinceau(255,0,0);
		  else
		    choisirCouleurPinceau(223,115,255);
		  choisirTypeStylo(2,129, 20, 83);
		  tracerRectangle(y1*102-202, 253-(*etat).p[dep.p].l1*102,
				  y2*102-202+98,253-(*etat).p[dep.p].l2*102-98);
		  tamponner();
		}
	    }
	  (*etat).p[dep.p].c1=dep.f.c1;
	  (*etat).p[dep.p].c2=dep.f.c2;
	  jouerSon(pop,0);
	  effacer();
	  afficher(*etat);
	  tamponner();
	  printf("la piece numero %d s'est deplacee une case vers la gauche\n",dep.p);
	  dep.p=-1;
	   etat->ps=-1;
	}
      if(dep.direction==3)//deplacement vers le bas
	{
	  double x1=(*etat).p[dep.p].l1;
	  double x2=(*etat).p[dep.p].l2;
	  dt = delta_temps();
	  while( x1<dep.f.l1 && x2<dep.f.l2)
	    {
	      dt = delta_temps();
	      choisirTypeStylo(2,254, 191, 210);
	      choisirCouleurPinceau(254, 191, 210);
	      tracerRectangle((*etat).p[dep.p].c1*102-202, 253-x1*102,
			      (*etat).p[dep.p].c2*102-202+98,253-x2*102-98);
	      x1=10*dt+x1;
	      x2=10*dt+x2;
	      if( x1<dep.f.l1 && x2<dep.f.l2)
		{
		  if(dep.p==0)
		    choisirCouleurPinceau(255,0,0);
		  else
		    choisirCouleurPinceau(223,115,255);
		  choisirTypeStylo(2,129, 20, 83);
		  tracerRectangle((*etat).p[dep.p].c1*102-202, 253-x1*102,
				  (*etat).p[dep.p].c2*102-202+98,253-x2*102-98); 
		  tamponner();
		}
	    }
	  (*etat).p[dep.p].l1=dep.f.l1;
	  (*etat).p[dep.p].l2=dep.f.l2;
	  jouerSon(pop,0);
	  effacer();
	  afficher(*etat);
	  printf("la piece numero %d s'est deplacee une case vers le bas\n",dep.p);
	  dep.p=-1;
	   etat->ps=-1;
	}
    }
}
int glisse_ane(etat_t* etat)
{
  if((*etat).p[0].l1==3 && (*etat).p[0].c1==1 && (*etat).p[0].l2==4 && (*etat).p[0].c2==2 && !fermetureDemandee())//si l'ane se trouve a la sortie
    {
      Son wiw=chargerAudio ("../data/anesorti.wav");
      Son winner=chargerAudio ("../data/winner.wav");
      //glisser l'ane vers le bas
      double y1=253-(*etat).p[0].l1*102;
      double y2=253-(*etat).p[0].l2*102-98;
      double dt = delta_temps();
      jouerSon(wiw,0);//son de la chute de l'ane
      while(y2>-350 && !fermetureDemandee())
	{
	  dt = delta_temps();
	  choisirTypeStylo(2,254, 191, 210);
	  choisirCouleurPinceau(254, 191, 210);
	  tracerRectangle((*etat).p[0].c1*102-202,y1,
			  (*etat).p[0].c2*102-202+98,y2);
	  y1=-5*dt*dt-20*dt+y1;
	  y2=-5*dt*dt-20*dt+y2;
	  choisirCouleurPinceau(255,0,0);
	  choisirTypeStylo(2,129, 20, 83);
	  tracerRectangle((*etat).p[0].c1*102-202, y1,
			  (*etat).p[0].c2*102-202+98,y2);
	  tamponner();	
	}
      if(fermetureDemandee())
	return 1;
      effacerTableau();
      printf("winner!!" );
      Image winner1=chargerImage("../data/winner.jpeg");
      jouerSon(winner,0);
      afficherImage(winner1,-400,143);
      tamponner();
      attendreNms(6000);
      libererImage(winner1);
      return 1;
    }
  return 0;
}

void space()//taper espace pour commencer
{
  effacerTableau();
  Image start=chargerImage("../data/start.png");
  Image ane=chargerImage("../data/ane.png");
  EtatSourisClavier esc ;
  while(1)
    {
      esc = lireEtatSourisClavier();
      if(esc.touchesClavier[44]==0 && !fermetureDemandee())
	{
	  afficherImage(start,-303.5,-180 );
	  afficherImage(ane,-250,320 );
	  tamponner();
	}
      else
	break;
    }
  libererImage(start);
  libererImage(ane);
}
int tuto()//instructions
{
  effacerTableau();
  Image tuto=chargerImage("../data/tuto.png");
  Son click=chargerAudio("../data/click.mp3");
  EtatSourisClavier esc;
  afficherImage(tuto,-1*tn_largeur(tuto)/2,tn_hauteur(tuto)/2 );
  tamponner();
  while(!fermetureDemandee())
    {
      esc = lireEtatSourisClavier();
      if(esc.sourisBoutonGauche && esc.sourisX<=557.5 && esc.sourisX>=338.5 && esc.sourisY<=306.5 && esc.sourisY>=248.5)//next
	break;
    }
  if(fermetureDemandee())
    return 0;
     	
  jouerSon(click,0);
  attendreNms(300);
  effacerTableau();
  libererImage(tuto);
  Image gauche=chargerImage("../data/clickgauche.png");
  afficherImage(gauche,-1*tn_largeur(gauche)/2,tn_hauteur(gauche)/2 );
  tamponner();
  while(!fermetureDemandee())
    {
      esc = lireEtatSourisClavier();
      if(esc.sourisBoutonGauche && esc.sourisX<=557.5 && esc.sourisX>=338.5 && esc.sourisY<=306.5 && esc.sourisY>=248.5)//next
	break;
    }
  if(fermetureDemandee())
    return 0;
  jouerSon(click,0);
  attendreNms(300);
  effacerTableau();
  libererImage(gauche);
  Image droit=chargerImage("../data/clickdroit.png");
  afficherImage(droit,-1*tn_largeur(droit)/2,tn_hauteur(droit)/2 );
  tamponner();
  while(!fermetureDemandee())
    {
      esc = lireEtatSourisClavier();
      if(esc.sourisBoutonGauche &&  esc.sourisX<=557.5 && esc.sourisX>=338.5 && esc.sourisY<=306.5 && esc.sourisY>=248.5)//next
	break;
    }
  if(fermetureDemandee())
    return 0;
  jouerSon(click,0);
  attendreNms(300);
  effacerTableau();
  libererImage(droit);
  return 0;
  
}
int fin()//replay or exit?(retourne 0 si exit et retourne 1 si replay)
{
  effacerTableau();
  Son click=chargerAudio("../data/click.mp3");
  Image exit=chargerImage("../data/exit.png");
  Image replay=chargerImage("../data/replay.png");
  Image ane1=chargerImage("../data/ane.png");
  EtatSourisClavier esc ;
  afficherImage(ane1,-250,320 );
  afficherImage(replay,22,-230);
  afficherImage(exit,-372, -230);
  tamponner();
  while(!fermetureDemandee())
    {
      esc = lireEtatSourisClavier();
      if( esc.sourisBoutonGauche && esc.sourisX>=22 && esc.sourisX<=342 && esc.sourisY<=-230 && esc.sourisY>=-300)//replay
	{
	  /*son click + attendreNms*/
	  jouerSon(click,0);
	  attendreNms(300);
	  libererImage(ane1);
	  libererImage(exit);
	  libererImage(replay); 
	  return 1;//replay
	}
      if( esc.sourisBoutonGauche && esc.sourisX>=-372 && esc.sourisX<=-22 && esc.sourisY<=-230 && esc.sourisY>=-300)//exit
	{
	  /*son click + attendreNms*/
	  jouerSon(click,0);
	  attendreNms(300);
	  libererImage(ane1);
	  libererImage(exit);
	  libererImage(replay);
	  return 0;//exit
	}
    }
}
int difficulte()//il existe 17 positions initiales qui admettent une solution (2 positions classic, 5 positions de niveau facile, 5 positions de niveau moyen, 5 positions de niveau difficile)
{
  effacerTableau();
  Son click=chargerAudio("../data/click.mp3");
  Image choose=chargerImage("../data/choose_diff.png");
  EtatSourisClavier esc ;
  afficherImage(choose,-597 ,335);
  tamponner();
  int n;
  while(!fermetureDemandee())
    {
      esc = lireEtatSourisClavier();
      if( esc.sourisBoutonGauche && esc.sourisX>=81 && esc.sourisX<=313 && esc.sourisY<=293 && esc.sourisY>=232)//si le joueur clique sur classic
	{
	  jouerSon(click,0);
	  attendreNms(300);
	  effacerTableau();
	  libererImage(choose);
	  Image levelclassic=chargerImage("../data/levelclassic.png");
	  afficherImage(levelclassic,-597 ,335);
	  tamponner();
	  attendreNms(300);
	  while(!fermetureDemandee())
	    {
	      esc = lireEtatSourisClavier();
	      if( esc.sourisBoutonGauche && esc.sourisX>=66 && esc.sourisX<=301 && esc.sourisY<=190 && esc.sourisY>=130)//si le joueur clique sur 1
		{
		  jouerSon(click,0);
		  attendreNms(300);
		  libererImage(levelclassic);
		  return 0;
		}
	      if( esc.sourisBoutonGauche && esc.sourisX>=66 && esc.sourisX<=301 && esc.sourisY<=52 && esc.sourisY>=-9)//si le joueur clique sur 2
		{
		  jouerSon(click,0);
		  attendreNms(300);
		  libererImage(levelclassic);
		  return 1;
		}
	      if( esc.sourisBoutonGauche && esc.sourisX>=66 && esc.sourisX<=301 && esc.sourisY<=-89 && esc.sourisY>=-150)//si le joueur clique sur randclassic (retourner une position classic aleatoirement)
		{
		  jouerSon(click,0);
		  attendreNms(300);
		  libererImage(levelclassic);
		  return rand()%2;
		}
	    }
	}
      if( esc.sourisBoutonGauche && esc.sourisX>=81 && esc.sourisX<=313 && esc.sourisY<=-243 && esc.sourisY>=-304)//si le joueur clique sur random(retourner l'indice d'une position quelconque aleatoirement)
	{
	  jouerSon(click,0);
	  attendreNms(300);
	  libererImage(choose);
	  return rand()%17;
	}
      if( esc.sourisBoutonGauche && esc.sourisX>=81 && esc.sourisX<=313 && esc.sourisY<=159 && esc.sourisY>=98 //si le joueur clique sur easy
	  || esc.sourisBoutonGauche && esc.sourisX>=81 && esc.sourisX<=313 && esc.sourisY<=25 && esc.sourisY>=-37 //si le joueur clique sur medium
	  ||esc.sourisBoutonGauche && esc.sourisX>=81 && esc.sourisX<=313 && esc.sourisY<=-108 && esc.sourisY>=-170 //si le joueur clique sur hard
	  )
	{
	  if( esc.sourisBoutonGauche && esc.sourisX>=81 && esc.sourisX<=313 && esc.sourisY<=159 && esc.sourisY>=98)
	    n=0;
	  if( esc.sourisBoutonGauche && esc.sourisX>=81 && esc.sourisX<=313 && esc.sourisY<=25 && esc.sourisY>=-37)
	    n=1;
	  if(esc.sourisBoutonGauche && esc.sourisX>=81 && esc.sourisX<=313 && esc.sourisY<=-108 && esc.sourisY>=-170)
	    n=2;
	  jouerSon(click,0);
	  attendreNms(300);
	  effacerTableau();
	  libererImage(choose);
	  Image level5=chargerImage("../data/level5.png");
	  afficherImage(level5, -597 ,335);
	  tamponner();
	  attendreNms(300);
	  while(!fermetureDemandee())
	    {
	      esc = lireEtatSourisClavier();
	      if( esc.sourisBoutonGauche && esc.sourisX>=70 && esc.sourisX<=303 && esc.sourisY<=298 && esc.sourisY>=235)//si le joueur clique sur 1
		{
		  jouerSon(click,0);
		  attendreNms(300);
		  libererImage(level5);
		  return 2+5*n;
		}
	      if( esc.sourisBoutonGauche && esc.sourisX>=70 && esc.sourisX<=303 && esc.sourisY<=182 && esc.sourisY>=120)//si le joueur clique sur 2
		{
		  jouerSon(click,0);
		  attendreNms(300);
		  libererImage(level5);
		  return 3+5*n;
		}
	      if( esc.sourisBoutonGauche && esc.sourisX>=70 && esc.sourisX<=303 && esc.sourisY<=70 && esc.sourisY>=6)//si le joueur clique sur 3
		{
		  jouerSon(click,0);
		  attendreNms(300);
		  libererImage(level5);
		  return 4+5*n;
		}
	      if( esc.sourisBoutonGauche && esc.sourisX>=70 && esc.sourisX<=303 && esc.sourisY<=-41 && esc.sourisY>=-104)//si le joueur clique sur 4
		{
		  jouerSon(click,0);
		  attendreNms(300);
		  libererImage(level5);
		  return 5+5*n;
		}
	      if( esc.sourisBoutonGauche && esc.sourisX>=70 && esc.sourisX<=303 && esc.sourisY<=-153 && esc.sourisY>=-217)//si le joueur clique sur 5
		{
		  jouerSon(click,0);
		  attendreNms(300);
		  libererImage(level5);
		  return 6+5*n;
		}
	      if( esc.sourisBoutonGauche && esc.sourisX>=70 && esc.sourisX<=303 && esc.sourisY<=-265 && esc.sourisY>=-327)//si le joueur clique sur randclassic(retourner l'indice d'une position de nv facile aleatoirement)
		{
		  jouerSon(click,0);
		  attendreNms(300);
		  libererImage(level5);
		  return (rand()%5)+2+5*n;
		}
	    }
	}
    }
}
//********************************************************************************************************************************
int main()
{

  srand(time(NULL));
  creerTableau();
  fixerModeBufferisation(1);
  fixerTaille(1920,1080);
  etat_t etat;
  deplacement_t dep;
  Son pop1=chargerAudio ("../data/pop1.mp3");
  jouerSon(pop1,0);
  while(!fermetureDemandee())
    {
      space();
      if(fermetureDemandee())
	return EXIT_SUCCESS;
      tuto();
      if(fermetureDemandee())
	return EXIT_SUCCESS;
      int n=difficulte();
      if(fermetureDemandee())
	return EXIT_SUCCESS;
      effacerTableau();
      etat=init_aleatoire(n);
      while(!fermetureDemandee())
	{
	  afficher(etat);
	  tamponner();
	  dep=donneesdudeplacement(&etat);
	  deplacement(dep,&etat);
	  dep.p=-1;
	  int k=glisse_ane(&etat);
	  if(fermetureDemandee())
	    return EXIT_SUCCESS;
	  if(k)
	    {
	      int f=fin();
	      if(f)
		break;
	      else
		return EXIT_SUCCESS;
	    }
	}
    }

  return EXIT_SUCCESS;
}
