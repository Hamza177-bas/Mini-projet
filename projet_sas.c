#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{

    int coude_prod[100];
    char nome_prod[100][100];
    int quantite[100];
    float prix[100];

} produit;
produit pherma;
int c = 0;
struct ventu
{
    float total_prix;
    float moyen_prix;
    float min_prix;
    float max_prix;
    int qonti;
} pri;

void choix1()
{
    printf("\nAjouter un nouveau produit : \n");
    printf("- Entrez le code produit : ");
    scanf("%d", &pherma.coude_prod[c]);
    printf("Entrez le nom produit : ");
    scanf(" %[^\n]s", pherma.nome_prod[c]);
    printf("Entrez le quantite : ");
    scanf("%d", &pherma.quantite[c]);
    printf("Entrez le prix : ");
    scanf("%f", &pherma.prix[c]);
    c++;
    printf("\n[ Le produit a ete ajoute avec succes ]\n");
}

void choix2()
{

    char yesno;
    do
    {
        choix1();
        printf("Voulez-vous ajouter un autre produit ?(Y OR N ) :");
        scanf(" %c", &yesno);

    } while (yesno == 'Y' || yesno == 'y');
}

void choix3()
{

    printf("\nListe de tous les produits : \n");
    for (int i = 0; i < c; i++)
    {
        printf("%d - %s : \tle prix : %.2f \t le prix TTC : %.2f \n", i + 1, pherma.nome_prod[i], pherma.prix[i], pherma.prix[i] + pherma.prix[i] * 0.15);
    }
}

void choix4()
{
    printf("\nListe des produits par ordre alphabetique : \n");
    char t[100];
    int t2[100];
    int tm;
    float tmp;
    for (int i = 0; i < c; i++)
    {
        for (int j = i + 1; j < c; j++)
        {
            if (strcmp(pherma.nome_prod[i], pherma.nome_prod[j]) > 0)
            {
                strcpy(t, pherma.nome_prod[i]);
                strcpy(pherma.nome_prod[i], pherma.nome_prod[j]);
                strcpy(pherma.nome_prod[j], t);
                t2[i] = pherma.coude_prod[i];
                pherma.coude_prod[i] = pherma.coude_prod[j];
                pherma.coude_prod[j] = t2[i];
                tm = pherma.quantite[i];
                pherma.quantite[i] = pherma.quantite[j];
                pherma.quantite[j] = tm;
                tmp = pherma.prix[i];
                pherma.prix[i] = pherma.prix[j];
                pherma.prix[j] = tmp;
            }
        }
        printf("%d - %s : \tle prix : %.2f \tle prix TTC : %.2f \n", i + 1, pherma.nome_prod[i], pherma.prix[i], pherma.prix[i] + pherma.prix[i] * 0.15);
    }
}

void choix5()
{

    printf("\nListe des produits par ordre decroissant de prix:\n");
    char t[100];
    int t2[100];
    int tm;
    float tmp;
    for (int i = 0; i < c; i++)
    {
        for (int j = i + 1; j < c; j++)
        {
            if (pherma.prix[i] < pherma.prix[j])
            {
                strcpy(t, pherma.nome_prod[i]);
                strcpy(pherma.nome_prod[i], pherma.nome_prod[j]);
                strcpy(pherma.nome_prod[j], t);
                t2[i] = pherma.coude_prod[i];
                pherma.coude_prod[i] = pherma.coude_prod[j];
                pherma.coude_prod[j] = t2[i];
                tm = pherma.quantite[i];
                pherma.quantite[i] = pherma.quantite[j];
                pherma.quantite[j] = tm;
                tmp = pherma.prix[i];
                pherma.prix[i] = pherma.prix[j];
                pherma.prix[j] = tmp;
            }
        }
        printf("%d - %s : \tle prix : %.2f \tle prix TTC : %.2f \n", i + 1, pherma.nome_prod[i], pherma.prix[i], pherma.prix[i] + pherma.prix[i] * 0.15);
    }
}

void choix6()
{

    int t, r;
    int quan, i, x = 0;
    float min = 0, max;
    printf("\nAcheter le produit :\n");
    printf("Entrer le code produit : ");
    scanf("%d", &t);

    printf("Entrer la quantite que vous shohaitez acheter : ");
    scanf("%d", &quan);
    for (i = 0; i < c; i++)
    {

        if (t == pherma.coude_prod[i])
        {
            x = 1;
            if (quan < pherma.quantite[i])
            {
                pherma.quantite[i] -= quan;
                pri.qonti += quan;
                printf("\n[ Achat termine avec succes ]\n");
                pri.total_prix += (pherma.prix[i] * quan);
                pri.moyen_prix = (pri.total_prix / pri.qonti);
                min = pherma.prix[i];
                if (pri.min_prix < min)
                {
                    if (pri.min_prix == 0)
                    {
                        pri.min_prix = min;
                    }
                }
                else
                {
                    pri.min_prix = min;
                }
                max = pherma.prix[i];
                if (pri.max_prix < max)
                {
                    pri.max_prix = max;
                }
            }
            else
            {
                printf("Le stock disponible est inferieur a la quntite requise \n");
            }
        }
    }
    if (x == 0)
    {
        printf("Le code que vous avez entre n'existe pas \n");
    }
}

void choix7()
{

    int code, i, x;
    x = 0;
    printf("\nRecherche d'un produit : \n");
    printf("Entrer le code produit : ");
    scanf("%d", &code);
    printf("\nResultats de la recherche : \n");
    for (i = 0; i < c; i++)
    {
        if (code == pherma.coude_prod[i])
        {
            printf("%d - %s :\t prix : %.2f\t quantite : %d \n", i + 1, pherma.nome_prod[i], pherma.prix[i], pherma.quantite[i]);
            x = 1;
        }
    }
    if (x == 0)
    {
        printf("Produit introuvable .\n");
    }
}

void choix8()
{
    printf("\nEtat des stocks : \n");
    int i, x;
    x = 0;
    for (i = 0; i < c; i++)
    {
        if (pherma.quantite[i] < 3)
        {
            printf("Produit : %s\t code : %d \nLe stock doit etre expedie pour ce produit \n", pherma.nome_prod[i], pherma.coude_prod[i]);
            x = 1;
        }
    }
    if (x == 0)
    {
        printf("Aucun produit ne necessite d'expedition \n");
    }
}

void choix9()
{

    int code, quantet, i, x;
    x = 0;

    printf("\nAjouter un inventaire : \n");
    printf("Entrer le code produit : ");
    scanf("%d", &code);
    printf("Entrer la quantite que vous souhaitez ajouter : ");
    scanf("%d", &quantet);
    for (i = 0; i < c; i++)
    {
        if (code == pherma.coude_prod[i])
        {
            pherma.quantite[i] += quantet;
            x = 1;
            printf("\n[ Quantite ajoutee avec succes ]\n");
        }
    }
    if (x == 0)
        printf("\nCode produit invalide\n");
}

void choix10()
{

    int code, i, x, j;
    printf("\nSupprimer des produits : \n");
    printf("Entrer le code produit : ");
    scanf("%d", &code);
    x = 0;
    for (i = 0; i < c; i++)
    {
        if (code == pherma.coude_prod[i])
        {

            for (j = i + 1; j < c; j++)
            {
                pherma.coude_prod[i] = pherma.coude_prod[j];
                strcpy(pherma.nome_prod[i], pherma.nome_prod[j]);
                pherma.prix[i] = pherma.prix[j];
                pherma.quantite[i] = pherma.quantite[j];
            }
            x = 1;
            c--;
            printf("[ Le produit a ete supprime avec succes ]\n");
        }
    }
    if (x == 0)
        printf("Le code n'existe pas \n");
}

void choix11()
{
    printf("\nStatistiques de ventes : \n");
    printf("Prix totaux des produit vendus aujourd'hui : %.2f\n", pri.total_prix);
    printf("Prix moyen de produit vendus aujourd'hui : %.2f\n", pri.moyen_prix);
    printf("Prix maximum des produit vendus aujourd'hui : %.2f\n", pri.max_prix);
    printf("Prix minumum pour les produits vendus aujourd'hui : %.2f\n", pri.min_prix);
}

void Meunu_principal()
{
    printf("========== GESTION DU PHARMACINEN ==========\n");
    printf("1 : Ajouter un nouveau produit .\n");
    printf("2 : Ajouter plusieurs produits .\n");
    printf("3 : Lste de tous les produits (Nom , Prix et prix TTC).\n");
    printf("4 : Liste de tous les produits par ordre croissant de nom .\n");
    printf("5 : Liste de tous les produits par ordre decroissant de prix.\n");
    printf("6 : Acheter un produit .\n");
    printf("7 : Rechercher un produit .\n");
    printf("8 : Etat des stocks .\n");
    printf("9 : Ajouter un inventaire .\n");
    printf("10 : Supprimer des produits.\n");
    printf("11 : Statistiques de vents . \n");
    printf("12 : Quitter le programme .\n\n");
    printf("REMARQUE IMPORTANTE : (Oui = Y or y) (Nou = N or n)");
}

void printprogramm()
{
     Meunu_principal();
    char yesno;
    do
    {
        int opr;
        pri.total_prix = 0;
        pri.max_prix = 0;
        pri.min_prix = 0;
        pri.moyen_prix = 0;
        pri.qonti = 0;
        printf("\nChoisissez une operetion : ");
        scanf("%d", &opr);

        switch (opr)
        {
        case 1:
            choix1();
            break;
        case 2:
            choix2();
            break;
        case 3:
            choix3();
            break;
        case 4:
            choix4();
            break;
        case 5:
            choix5();
            break;
        case 6:
            choix6();
            break;
        case 7:
            choix7();
            break;
        case 8:
            choix8();
            break;
        case 9:
            choix9();
            break;
        case 10:
            choix10();
            break;
        case 11:
            choix11();
            break;
        case 12:
        {
            printf("\n*** Merci d'utiliser l'application de gestionde pharmacie Au revoir :) ***\n");
            return;
        }
        break;

        default:
            printf("Le numero que vous aves entre n'est pas dans la liste \n");
            break;
        }
        printf("Retour au menu principal (Y OR N ) : ");
        scanf(" %c", &yesno);

    } while (yesno == 'Y' || yesno == 'y');
}

int main()
{
    printprogramm();

    return 0;
}