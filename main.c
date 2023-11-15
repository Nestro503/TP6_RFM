
#include "graphe/graphe.h"

int main() {
    Graphe * g;
    char nom_fichier[50];

    printf("Entrer le nom du fichier du labyrinthe : ");
    scanf("%s", nom_fichier);

    g = read_graph(nom_fichier);
    printGraph(g);

}
