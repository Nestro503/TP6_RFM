
#include "graphe/graphe.h"
#include "fulkerson/fulkerson.h"

int main() {
    Graphe * g;
    char nom_fichier[50];

    printf("Entrer le nom du fichier : ");
    scanf("%s", nom_fichier);
    g = read_graph(nom_fichier);

    printGraph(g);
    algo_fulkerson(*g);
}
