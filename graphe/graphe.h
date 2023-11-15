
#ifndef TP6_RFM_GRAPHE_H
#define TP6_RFM_GRAPHE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_SIZE 100

/// SOURCES : Le travail realise dans ce fichier a ete elabore sur la base de la propriete intelectuelle de Mr DEBIZE.

/* Structure d'un arc*/
struct Arc
{
    char sommet; // numéro de sommet d'un arc adjacent au sommet initial
    int capacity;
    int flot;
    struct Arc* arc_suivant;
};

/* Alias de pointeur sur un Arc */
typedef struct Arc* pArc;

/* Structure d'un sommet*/
struct Sommet{
    struct Arc* arc;
    char name;
};

/* Alias de pointeur sur un Sommet */
typedef struct Sommet* pSommet;

/* Alias d'un Graphe */
typedef struct Graphe{
    int taille;
    int order;  // Ordre du graphe
    char vertices[MAX_SIZE];
    int capacityMatrix[MAX_SIZE][MAX_SIZE];  // Matrice d'adjacence
    pSommet* pSommet;
} Graphe;

Graphe* createGraph(int ordre);
pSommet* createEdge(pSommet* sommet,int s1,int s2);
Graphe *read_graph(char *filename);
void printGraph(const Graphe *graph);


#endif //TP6_RFM_GRAPHE_H
