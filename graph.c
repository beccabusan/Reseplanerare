#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

typedef struct node{
  char *station;
  struct adjacent *connections;
  //char connected;
}*Node;

/*
typedef struct list{
  struct node *station;
  struct list *next;
} *List;
*/
/*
typedef struct edge{
  int travelTime;
  int busLine;
  struct node *station1;
  struct node *station2;
} *Edge;
*/
typedef struct adjacent{
  struct node *station;
  int travelTime;
  char *busLine;
  struct adjacent *next;
}*Adjacent;


/*
List createList(Node station, List list){
  List newList = (malloc(sizeof(struct list)));
  newList->station = station;
  newList->next = list;
  list = newList;
  return list;
}
*/

Node createNode(char *station_name){
  Node newNode = malloc(sizeof(struct node));
  newNode->station = malloc(strlen(station_name) + 1);
  strcpy(newNode->station, station_name);
  newNode->connections = NULL;
  return newNode;
}

Adjacent createAdj(Node station, int time, char *bus_line, Adjacent list){
  Adjacent adj = malloc(sizeof(struct adjacent));
  adj->station = station;
  adj->travelTime = time;
  adj->busLine = bus_line;
  adj->next = list;
  list = adj;
  return list;
}

/*
void addToNodes(char *station1, char *station2, int *time, char *bus_line){
  
  while(station1 != '\n'){
    char *temp = 
    printf("%s\n", station1);
}


  //for(int i = 0; station1 != NULL; *(station1 + i)){
  // createNode(&station1[i]);
    

  //}



}
*/
/*
void test(){
  Node x = createNode("Hello");
  Node y = createNode("Hej");
  Adjacent z = createAdj(x, 10, 5);
  printf("%d\n", z->travelTime);

}
*/
/*
void createNetwork(char *station_name, char *nextStation, int time, int bus_line, Adjacent nextAdj){

  newNode->connections->station = nextStation;
  newNode->connections->travelTime = time;
  newNode->connections->busLine = bus_line;

  if(nextAdj != NULL){
    newNode->connections->next = nextAdj;
  }
}


*/






/*
Node createNode(char *station_name, Edge next[]){
  Node newNode = malloc(sizeof(struct node));
  newNode->station = malloc(strlen(station_name) +1);
  strcpy(newNode->station, station_name);
  newNode->next = next[];
  return newNode;
}


Edge connectNodes(Node node1, Node node2, int travel_time, char bus_line){
  Edge newEdge = malloc(sizeof(struct edge));
  newEdge->station1->station = node1;
  newEdge->station2->station = node2; 
  newEdge->travelTime = travel_time;
  newEdge->busLine = bus_line;

  return newEdge;
}

*/



