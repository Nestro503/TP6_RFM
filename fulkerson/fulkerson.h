#ifndef TP6_RFM_FULKERSON_H
#define TP6_RFM_FULKERSON_H

#include "../graphe/graphe.h"
#include "../fifo/fifo.h"
#include <limits.h>

bool BFS(Graphe graphe, int source, int puit, int pred[]);
void algo_fulkerson(Graphe graphe);

#endif
