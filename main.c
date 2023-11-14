
#include "graphe/graphe.h"

int main() {
    Graphe * g;
    char nom_fichier[MAX_SIZE];

    printf("Entrer le nom du fichier du labyrinthe :");
    gets(nom_fichier);

    g = read_graph(nom_fichier);
    printGraph(g);

}
