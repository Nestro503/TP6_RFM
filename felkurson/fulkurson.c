#include "fulkurson.h"


bool BFS(Graphe graphe, int source, int puit, int pred[]){
    int s;
    File fifo = fileVide();
    bool marque[graphe.order];
    for (int i = 0; i < graphe.order; ++i) {
        marque[i] = 0;
    }
    marque[source] = true;
    pred[source] = -1;
    enfiler(fifo, source);
    while(!fileEstVide(fifo)){
        s = defilement(fifo);
        for (int i = 0; i < graphe.order; ++i) {
            if(!marque[i] && graphe.capacityMatrix[s][i] > 0){
                enfiler(fifo, i);
                marque[i] = true;
                pred[i] = s;
                if(i == puit){
                    return true;
                }
            }
        }
    }
    return false;
}

void algo_fulkerson(Graphe graphe){
    int tab_pred[graphe.order];
    for (int i = 0; i < graphe.order; ++i) {
        tab_pred[i] = 0;
    }
    int flotMax = 0;
    while(BFS(graphe, graphe.source, graphe.puit, tab_pred)){
        int flotTemp = INT_MAX;
        int pred = graphe.puit;
        while(tab_pred[pred] != graphe.source){
            if(flotTemp > graphe.capacityMatrix[tab_pred[pred]][pred]){
                flotTemp = graphe.capacityMatrix[tab_pred[pred]][pred];
            }
            pred = tab_pred[pred];
        }
        pred = graphe.puit;
        while(tab_pred[pred] != graphe.source){
            graphe.capacityMatrix[tab_pred[pred]][pred] = graphe.capacityMatrix[tab_pred[pred]][pred] - flotTemp;
            pred = tab_pred[pred];
        }

        flotMax += flotTemp;
    }

    printf("\nflot max = %d", flotMax);
}