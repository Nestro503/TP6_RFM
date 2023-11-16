
#include "graphe/graphe.h"
#include "felkurson/fulkurson.h"

int main() {
    Graphe * g;
    char nom_fichier[50];
    char source, puit;
    int intsource, intpuit;

    printf("Entrer le nom du fichier : ");
    scanf("%s", nom_fichier);


    g = read_graph(nom_fichier);

    printGraph(g);
    algo_fulkerson(*g);


}
