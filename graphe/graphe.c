
#include "graphe.h"

// Fonction pour lire un graphe depuis un fichier
Graphe *read_graph(char *nomFichier) {
    Graphe *graphe;
    int ordre;
    FILE * file = fopen(nomFichier,"r");

    if (!file){
        printf("Erreur de lecture fichier\n");
        exit(-1);
    }

    fscanf(file, "%d", &ordre);  // Lecture de l'ordre du graphe

    graphe = createGraph(ordre); // créer le graphe d'ordre sommets
    graphe->order = ordre;

    // Lecture des noms des sommets
    for (int i = 0; i < graphe->order; i++) {
        fscanf(file, " %c", &graphe->vertices[i]);
    }

    // Lecture de la matrice d'adjacence
    for (int i = 0; i < graphe->order; i++) {
        for (int j = 0; j < graphe->order; j++) {
            fscanf(file, "%d", &graphe->capacityMatrix[i][j]);
            if (graphe->capacityMatrix[i][j] != 0){
                graphe->pSommet = createEdge(graphe->pSommet, i, j);
                //graphe->pSommet->capacity = graphe->capacityMatrix[i][j];
                graphe->taille++;
            }
        }
    }

    fclose(file);
    return graphe;
}

// Fonction pour afficher le graphe
void printGraph(const Graphe *graph) {
    printf("Ordre du graphe: %d\n", graph->order);

    printf("Noms des sommets: ");
    for (int i = 0; i < graph->order; i++) {
        printf("%c ", graph->vertices[i]);
    }
    printf("\n");

    printf("Matrice d'adjacence:\n");
    for (int i = 0; i < graph->order; i++) {
        for (int j = 0; j < graph->order; j++) {
            printf("%d ", graph->capacityMatrix[i][j]);
        }
        printf("\n");
    }
}


// Ajouter l'arête entre les sommets s1 et s2 du graphe
pSommet* createEdge(pSommet* sommet,int s1,int s2){
    if(sommet[s1]->arc==NULL){
        pArc Newarc=(pArc)malloc(sizeof(struct Arc));
        Newarc->sommet=s2;
        Newarc->arc_suivant=NULL;
        sommet[s1]->arc=Newarc;
        return sommet;
    }

    else{
        pArc temp=sommet[s1]->arc;
        while(temp->arc_suivant !=NULL)
        {
            temp=temp->arc_suivant;
        }
        pArc Newarc=(pArc)malloc(sizeof(struct Arc));
        Newarc->sommet=s2;
        Newarc->arc_suivant=NULL;

        if(temp->sommet>s2)
        {
            Newarc->arc_suivant=temp->arc_suivant;
            Newarc->sommet=temp->sommet;
            temp->sommet=s2;
            temp->arc_suivant=Newarc;
            return sommet;
        }

        temp->arc_suivant=Newarc;
        return sommet;
    }
}

// créer le graphe
Graphe* createGraph(int ordre){
    Graphe * Newgraphe=(Graphe*)malloc(sizeof(Graphe));
    Newgraphe->pSommet = (pSommet*)malloc(ordre*sizeof(pSommet));

    for(int i=0; i<ordre; i++){
        Newgraphe->pSommet[i]=(pSommet)malloc(sizeof(struct Sommet));
        Newgraphe->pSommet[i]->name = '0';
        Newgraphe->pSommet[i]->arc = NULL;
    }
    return Newgraphe;
}


