
#include "graphe.h"


// Fonction pour lire un graphe depuis un fichier
Graphe *read_graph(char *filename) {
    Graphe *graphe = malloc(sizeof(Graphe));
    FILE * file = fopen("graphe.txt","r");

    if (!file){
        printf("Erreur de lecture fichier\n");
        exit(-1);
    }

    fscanf(file, "%d", &graphe->order);  // Lecture de l'ordre du graphe

    // Lecture des noms des sommets
    for (int i = 0; i < graphe->order; i++) {
        fscanf(file, " %c", &graphe->vertices[i]);
    }

    // Lecture de la matrice d'adjacence
    for (int i = 0; i < graphe->order; i++) {
        for (int j = 0; j < graphe->order; j++) {
            fscanf(file, "%d", &graphe->capacityMatrix[i][j]);
        }
    }

    fclose(file);
    return graphe;
}

// Fonction pour afficher le graphe
void printGraph(const Graphe *graph) {
    printf("Ordre du graphe: %d\n", graph->order);

    printf("Noms des sommets: ");
    for (int i = 0; i < graph->order; i++) {
        printf("%c ", graph->vertices[i]);
    }
    printf("\n");

    printf("Matrice d'adjacence:\n");
    for (int i = 0; i < graph->order; i++) {
        for (int j = 0; j < graph->order; j++) {
            printf("%d ", graph->capacityMatrix[i][j]);
        }
        printf("\n");
    }
}
