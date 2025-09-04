#include <stdio.h>
#include <string.h>
int trouve = 0;
int main() {
    char noms[200][200];     
    float prix[200];         
    int quantite[200];       
    char auteur[200][200];   
    
    int choix, n = 0, i;
    char recherche[200];
    
    do {
        printf("\n--- Menu Gestion de Stock ---\n");
        printf("1. Ajouter un article\n");
        printf("2. Afficher le stock\n");
        printf("3. Rechercher un article\n");
        printf("4. Supprimer un article\n");
        printf("5. Modifier un article\n");
        printf("6. Afficher le nombre total de livres\n");
        printf("7. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                if (n < 200) {
                    printf("Nom de l'article : ");
                    scanf(" %s", noms[n]);
                    printf("Prix : ");
                    scanf("%f", &prix[n]);
                    printf("Quantite : ");
                    scanf("%d", &quantite[n]);
                    printf("Auteur : ");
                    scanf(" %s", auteur[n]);
                    n++;
                } else {
                    printf("Stock plein !\n");
                }
                break;

            case 2:
                printf("\n--- Liste des Articles ---\n");
                for (i = 0; i < n; i++) {
                    printf("%d. %s | Prix: %.2f | Quantite: %d | Auteur: %s\n",
                           i+1, noms[i], prix[i], quantite[i], auteur[i]);
                }
                break;

            case 3:
                printf("Entrer le nom de l'article a rechercher : ");
                scanf(" %s", recherche);
                {
                    
                    for (i = 0; i < n; i++) {
                        if (strcmp(noms[i], recherche) == 0) {
                            printf("Trouve : %s | Prix: %.2f | Quantite: %d | Auteur: %s\n",
                                   noms[i], prix[i], quantite[i], auteur[i]);
                            trouve = 1;
                            break;
                        }
                    }
                    if (!trouve) {
                        printf("Article non trouve.\n");
                    }
                }
                break;

            case 4: {
                printf("Entrer le nom de l'article a supprimer : ");
                scanf(" %s", recherche);
                trouve=0;
                for (i = 0; i < n; i++) {
                    if (strcmp(noms[i], recherche) == 0) {
                        for (int j = i; j < n - 1; j++) {
                            strcpy(noms[j], noms[j+1]);
                            strcpy(auteur[j], auteur[j+1]);
                            prix[j] = prix[j+1];
                            quantite[j] = quantite[j+1];
                        }
                        n--;  
                        printf("Article supprime avec succes.\n");
                        trouve = 1;
                        break;
                    }
                }
                if (!trouve) {
                    printf("Article non trouve.\n");
                }
                }
                break;

            case 5: {
                printf("Entrer le nom d'article a modifier: ");
                scanf("%s", recherche);
                
                int trouve = 0;
                for(i = 0; i < n; i++) {
                    if (strcmp(noms[i], recherche) == 0) {
                        printf("Entrer la nouvelle quantite: ");
                        scanf("%d", &quantite[i]);
                        printf("Quantite modifiee avec succes.\n");
                        trouve = 1;
                        break;
                    }
                }

                if (!trouve) {
                    printf("Article non trouve.\n");
                }
                }
                break;

            case 6: {
                int total = 0;
                for(i = 0; i < n; i++) {
                    total += quantite[i];
                }
                printf("Le total des livres est: %d\n", total);
                }
                break;
                
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 7);

    return 0;
}
