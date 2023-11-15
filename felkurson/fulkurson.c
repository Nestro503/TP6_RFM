#include "fulkurson.h"

void init_arc(Graphe graphe){
    for (int i = 0; i < graphe.order; ++i) {
        pArc arc=graphe.pSommet[i]->arc;
        printf(" sommet %d :\n",i );
        while(arc!=NULL){
            printf("%d ",arc->sommet);
            arc=arc->arc_suivant;
        }
    }
}

void algo_fulkerson(Graphe graphe){
    init_arc(graphe);
}