#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define Lon 16
#define lar 16
#define VIDE 0
#define PJ1 1
#define PJ2 2
#define PJ3 3
#define PJ4 4
#define dJ 10
#define qJ 11
#define JvE 12
#define EvE 13
#define NoJ 0
#define JHum 1
#define JOrd 2

void Jeu(int NbJ,int NbE);
void initialiser_Damier(int Damier[Lon][lar],int NombreJoueurHumain,int NombreJoueurEnvironnement);
int menu_jeu_Halma();
void color(int t,int f);
int paire(int Nombre);

int main()
{
    /// Declarations des variables
    int damier[Lon][lar] = {VIDE};
    int NbJ;
    int NbE;
    int joueur[4] = {0};
    int i = 0;
    int j = 0;
    int partie = 1;
    int case_x;
    int case_y;

    NbJ = menu_jeu_Halma();
    if(NbJ == dJ)
    {
        NbE = 0;
        NbJ = 2;
    }
    else if(NbJ == qJ)
    {
        NbE = 0;
        NbJ = 4;
    }
    else if(NbJ == JvE)
    {
        NbE = 1;
        NbJ = 1;
    }
    else if(NbJ == EvE)
    {
        NbE = 2;
        NbJ = 0;
    }
    else
    {
        NbE = 4-NbJ;
    }

    initialiser_Damier(damier,NbJ,NbE);
    afficher_Damier(damier);

    switch(NbJ+NbE)
    {
    case 2:
        switch(NbJ)
        {
        case 0:
            joueur[0] = JOrd;
            joueur[1] = JOrd;
            joueur[2] = NoJ;
            joueur[3] = NoJ;
            break;
        case 1:
            joueur[0] = JHum;
            joueur[1] = JOrd;
            joueur[2] = NoJ;
            joueur[3] = NoJ;
            break;
        case 2:
            joueur[0] = JHum;
            joueur[1] = JHum;
            joueur[2] = NoJ;
            joueur[3] = NoJ;
            break;
        }
        break;
    case 4:
        switch(NbJ)
        {
        case 0:
            joueur[0] = JOrd;
            joueur[1] = JOrd;
            joueur[2] = JOrd;
            joueur[3] = JOrd;
            break;
        case 1:
            joueur[0] = JHum;
            joueur[1] = JOrd;
            joueur[2] = JOrd;
            joueur[3] = JOrd;
            break;
        case 2:
            joueur[0] = JHum;
            joueur[1] = JHum;
            joueur[2] = JOrd;
            joueur[3] = JOrd;
            break;
        case 3:
            joueur[0] = JHum;
            joueur[1] = JHum;
            joueur[2] = JHum;
            joueur[3] = JOrd;
            break;
        case 4:
            joueur[0] = JHum;
            joueur[1] = JHum;
            joueur[2] = JHum;
            joueur[3] = JHum;
            break;
        }
        break;
    }
    while(partie)
    {
        int max;
        if(joueur[2] == NoJ)
            max = 2;
        else
            max = 4;

        for(i = 0;i<max;i++)
        {
            color(7,0);
            printf("\nJoueur %d, a vous de jouer !",i+1);
            do
            {
                printf("\nSelectionner la case de depart :\nCoordonnee en x :");
                fflush(stdin);
                case_x = getchar() - 48;
                printf("\nCoordonee en y :");
                fflush(stdin);
                case_y = getchar() - 48;
                if(case_x < 0 || case_x > 15 || case_y < 0 || case_y > 15)
                    printf("La case rentrer est invalide");
                else if(damier[case_x][case_y] != PJ1 && i == 1)
                    printf("\nCette case ne contient pas un de vos pions");
                else if(damier[case_x][case_y] != PJ2 && i == 2)
                    printf("\nCette case ne contient pas un de vos pions");
                else if(damier[case_x][case_y] != PJ3 && i == 3)
                    printf("\nCette case ne contient pas un de vos pions");
                else if(damier[case_x][case_y] != PJ4 && i == 4)
                    printf("\nCette case ne contient pas un de vos pions");
            }
            while(case_x < 0 || case_x > 15 || case_y < 0 || case_y > 15 || (damier[case_x][case_y] != PJ1 && i == 0) || (damier[case_x][case_y] != PJ2 && i == 1) || (damier[case_x][case_y] != PJ3 && i == 2) || (damier[case_x][case_y] != PJ4 && i == 3) );
            afficher_Damier(damier);
        }
    }
    return 0;
}

void afficher_Damier(int damier[Lon][lar])
{
    int i,j = 0;
    //system("cls"); // Nettoie l'écran
    color(15,0);
    printf("\n   ");
    for(i=0;i<16;i++)
        if(i<9)
            printf(" %d ",i);
        else
            printf(" %d",i);
    printf("\n");
    /// Affichage damier départ
    for(i = 0;i<lar;i++)
    {
        color(15,0);
        if(i < 10)
            printf("%d  ",i);
        else
            printf("%d ",i);
        for(j=0;j<Lon;j++)
        {
            switch(damier[j][i])
            {
            case VIDE:
                if((paire(j) && paire(i)) || (!paire(j) && !paire(i)))
                {
                    color(0,0);
                    printf("   ");
                }
                else
                {
                    color(0,15);
                    printf("   ");
                }
                break;
            case PJ1:
                color(0,3);
                printf("   ");
                break;
            case PJ2:
                color(0,5);
                printf("   ");
                break;
            case PJ3:
                color(0,7);
                printf("   ");
                break;
            case PJ4:
                color(0,10);
                printf("   ");
                break;
            }
        }
        printf("\n");
    }
}
int paire(int nombre)
{
    if(nombre%2 == 0)
        return 1;
    else
        return 0;
}

void color(int t,int f)
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,f*16+t);
}

int menu_jeu_Halma()
{
    char lettre_selection; /// lettre qui définie le mode de jeu
    int nbr_joueur; /// utilisé pour le cas e du menu

    printf("a) partie a 2 joueurs\n\n");
    printf("b) partie a 4 joueurs\n\n");
    printf("c) partie 1 joueur contre l'ordinateur\n\n");
    printf("d) partie ordinateur contre ordinateur\n\n");
    printf("e) partie de 0 a 3 humain contre une a 4 machines\n\n");
    printf("appuyer sur la touche clavier du monde de jeu que vous souhaitez:\n\n");

    while(!kbhit())
    {
        lettre_selection=getch();

        switch(lettre_selection)
        {
        case 'a':
            return dJ;
            break;

        case 'b':
            return qJ;
            break;

        case 'c':
            return JvE;
            break;

        case 'd':
            return EvE;
            break;

        case 'e':
            printf("Entrer le nombre de joueur que vous souhaitez:");
            fflush(stdin);
            nbr_joueur = fgetchar()-48;

            while(nbr_joueur>3 || nbr_joueur < 0)
            {
                printf("Le nombre de joueur entré est incorect, resaisissez le nombre de joueur:");
                fflush(stdin);
                nbr_joueur = fgetchar() - 48;
            }

            if(nbr_joueur > 1)
                printf("Vous serez donc %d joueurs contre %d ordinateurs\n\n",nbr_joueur,4-nbr_joueur);
            else if(nbr_joueur == 1)
                printf("Tu es donc tout seul face a 3 ordinateurs\n\n");
            else
                printf("Il y aura donc 4 ordinateurs\n\n");

            return nbr_joueur;
            break;
        }
    }
}
void initialiser_Damier(int Damier[Lon][lar],int NbJ,int NbE)
{
    int NbJTT = NbJ + NbE;
    int x = 0;
    int y = 0;

    switch(NbJTT)
    {
    case 4:
        /// On donne la valeur PJ1 à tous les pions situés en haut à gauche selon la répartition du jeu
        for(y=0; y<lar; y++)
            for(x=0; x<Lon; x++)
                if(x<4 && y < 4 && (x+y < 5))
                    Damier[x][y] = PJ1;
                else if((x == 0 && y == 4) || (x == 4 && y == 0) )
                    Damier[x][y] = VIDE;

        /// On donne la valeur PJ2 à tous les pions situés en bas à droite selon la répartition du jeu
        for(y=0; y<lar; y++)
            for(x=0; x<Lon; x++)
                if(x>11 && y>11 && (x+y > 25))
                    Damier[x][y] = PJ2;
                else if((x == 11 && y == 15) || (x == 15 && y == 11) )
                    Damier[x][y] = VIDE;

        /// On donne la valeur PJ3 à tous les pions situés en bas à gauche selon la répartition du jeu
        for(y=0; y<lar; y++)
            for(x=0; x<Lon; x++)
            {
                if(x<4 && y > 10)
                    Damier[x][y] = PJ3;
                if((x == 0 && y == 11) || (x == 1 && y == 11) || (x == 2 && y == 11) || (x == 3 && y == 11) || (x == 2 && y == 12) || (x == 3 && y == 12) || (x == 3 && y == 13))
                    Damier[x][y] = VIDE;
            }

        /// On donne la valeur PJ4 à tous les pions situés en bas à gauche selon la répartition du jeu
        for(y=0; y<lar; y++)
            for(x=0; x<Lon; x++)
            {
                if(x>10 && y < 4)
                    Damier[x][y] = PJ4;
                if((x == 11 && y == 0) || (x == 11 && y == 1) || (x == 11 && y == 2) || (x == 11 && y == 3) ||(x == 12 && y == 2) || (x == 12 && y == 3) || (x == 13 && y == 3))
                    Damier[x][y] = VIDE;
            }
        break;
    case 2:
        /// On donne la valeur PJ1 à tous les pions situés en haut à gauche selon la répartition du jeu
        for(y=0; y<lar; y++)
            for(x=0; x<Lon; x++)
                if(x<5 && y < 5 && (x+y < 6))
                    Damier[x][y] = PJ1;
                else if((x == 0 && y == 5) || (x == 5 && y == 0) )
                    Damier[x][y] = VIDE;

        /// On donne la valeur PJ2 à tous les pions situés en bas à droite selon la répartition du jeu
        for(y=0; y<lar; y++)
            for(x=0; x<Lon; x++)
                if(x>10 && y>10 && (x+y > 24))
                    Damier[x][y] = PJ2;
                else if((x == 10 && y == 15) || (x == 15 && y == 10) )
                    Damier[x][y] = VIDE;
        break;
    default:
        printf("Error, program stops");
        return EXIT_FAILURE;
    }
}
