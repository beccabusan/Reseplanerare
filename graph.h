#ifdef GRAPH_H
#define GRAPH_H

typedef struct node *Node;

typedef struct adjacent *Adjacent;


Node createNode(char*);
Adjacent createAdj(Node, int, char*, Adjacent);


#endif
