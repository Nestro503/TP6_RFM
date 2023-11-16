#include "fulkerson.h"


bool BFS(Graphe graphe, int source, int puit, int pred[]){
    int s;
    File fifo = fileVide(); // creation d'une file fifo
    bool marque[graphe.order]; // initialisation du tableau de marquage // different du BSF classique('B','G','N')
    for (int i = 0; i < graphe.order; ++i) { // initialisation des marqueurs à faux
        marque[i] = false;
    }
    marque[source] = true; // marquer le sommet source
    pred[source] = -1; // mettre son prédécesseur à -1 pour ne pas avoir de problème
    enfiler(fifo, source); // enfiler le sommet source dans la file
    while(!fileEstVide(fifo)){ // tant que la file n'est pas vide
        s = defilement(fifo);
        for (int i = 0; i < graphe.order; ++i) {
            if(!marque[i] && graphe.capacityMatrix[s][i] > 0){ // si i n'est pas marqué et le poids de l'arc s-i est supérieur à 0
                enfiler(fifo, i);
                marque[i] = true;
                pred[i] = s;
                if(i == puit){
                    return true; // condition pour rester dans la boucle de l'algorithme de fulkerson
                }
            }
        }
    }
    return false; // condition pour sortir dans la boucle de l'algorithme de fulkerson
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
        while(tab_pred[pred] != graphe.source){ // boucle while qui permet de détecter le flot minimal
            if(flotTemp > graphe.capacityMatrix[tab_pred[pred]][pred]){
                flotTemp = graphe.capacityMatrix[tab_pred[pred]][pred];
            }
            pred = tab_pred[pred];
        }
        pred = graphe.puit; //remet le precedent a la valeur du sommet puit
        while(tab_pred[pred] != graphe.source){ // boucle while qui permet de soustraire le poid des arc pour trouvé le flot de l'arc
            graphe.capacityMatrix[tab_pred[pred]][pred] = graphe.capacityMatrix[tab_pred[pred]][pred] - flotTemp;
            pred = tab_pred[pred];
        }

        flotMax += flotTemp;
    }

    printf("\nflot max = %d", flotMax);
}