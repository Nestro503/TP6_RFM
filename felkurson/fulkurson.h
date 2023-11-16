#ifndef TP6_RFM_FULKURSON_H
#define TP6_RFM_FULKURSON_H

#include "../graphe/graphe.h"
#include "../fifo/fifo.h"

void init_arc(Graphe graphe);
bool BFS(Graphe graphe, int source, int puit, int pred[]);
void algo_fulkerson(Graphe graphe);

#endif
