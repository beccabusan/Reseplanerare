#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "graph.h"




/*
void options(){
  Node nodeList = NULL; //Creates empty nodelist
  char stationString[128]; 
  int choice = -1;
  while(choice != 0){
  puts("Choose an operation: ");
  puts("1: Create a new node. ");
  puts("2: Print nodes");
  scanf("%d", &choice);
  switch(choice){
  case 1:
    puts("Enter a station name");
    scanf("%s", stationString);
    createNode(nodeList, stationString); 
      
    break;

  case 2:

    displayNodes(nodeList);

    break;

  }

  }


}

*/

Adjacent addToList(char* station, char* station2, char* busNumber, int* time, Adjacent stationList){
  Node station1 = createNode(station);
  stationList = createAdj(station1, *time, busNumber, stationList);
  stationList->station->connections = createAdj((createNode(station2)), *time, busNumber, stationList);
  //puts(stationList->station->connections->station->station);
  //printf("Station %s is connected with %s\n",station1->station, station1->connections->station->station);
  return stationList;
}



Adjacent addToArray(FILE *network, char *buffer, Adjacent stationList){
  char *busNumber = malloc(sizeof(char)*120);
  char *station1 = malloc(sizeof(char)*120);
  char *station2 = malloc(sizeof(char)*120);
  int *time = malloc(sizeof(int));
  int countCommas = 0;
  int i = 0;
  fgets(buffer, 100, network);
  int lineLength = strlen(buffer);

  


  int j = 0;
  for(i = 0; i < lineLength-1; ++i){

    switch(countCommas){
    case 0:
      *(busNumber + j) = buffer[i];
      break;
      
    case 1:
      *(station1 + j) = buffer[i];
      break;
      
    case 2:
      *(station2 + j) = buffer[i];
      break;
      
    case 3:
      *(time + j) = atoi(&buffer[i]);
      break;
        
    }
    
    j++;
     if(',' == buffer[i + 1]){
       j=0;
       i+=2;
       ++countCommas;
       
     }
     
    

  }
  //printf("%s\n", busNumber);
  //printf("%s\n", station1);
  //printf("%s\n", station2);
  //printf("%i\n", *time);
  
  //addToNodes(station1, station2, time, busNumber);
  //for(int i = 0; station1 != NULL; i++){
  //Node x = createNode(station1);
  //printf("%c\n", station1[0]);
    
    //}

  //Node node = malloc(sizeof(struct node));
  //createNode(station1);
  //puts(*x);
  
  //Node allNodes[200];
  //if()
  //allNodes[0] = createNode(station1);
  //printf("%s\n", station1[5]);
  stationList = addToList(station1, station2, busNumber, time, stationList);
  return stationList;
}



void openFile(){
  
  FILE *network;
  network = fopen("nätverk.txt", "r");
  char *buffer = malloc(2048);
  Adjacent stationList = NULL;
  while (!(feof(network))){
    stationList = addToArray(network, buffer, stationList);
     }


  // puts(stationList->station);
}




int main(int argc, char *argv[]){
  if (argc < 1){
    puts("Error");
    return -1;
  }

  //test();
  openFile();
  //options();
  return 0;
}
