#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() 
{
  List* lista = (List*)malloc(sizeof(List));
  lista->head = NULL;
  lista->tail = NULL;
  lista->current = NULL;
  
  return lista;
}

void* firstList(List * list) 
{
  list->current = list->head;
  if(list->head == NULL)
  {
    return NULL;
  }
  
  return list->head->data;
}

void * nextList(List * list) 
{ 
  if(list->current != NULL && list->current->next!= NULL)
  {
    list->current = list->current->next;
    
  }
  else return NULL;

  return list->current->data;
}

void * lastList(List * list) 
{
  list->current = list->tail;
  if(list->tail == NULL)  
    return NULL;
  
  return list->tail->data;
}

void * prevList(List * list) 
{
  if(list->current != NULL && list->current->prev!= NULL)
    {
      list->current = list->current->prev;

    }
    else return NULL;

    return list->current->data;
}

void pushFront(List * list, void * data) 
{
  Node* nodo = createNode(data);
  
  if (list->head == NULL)
  {
    list->head = nodo;
    list->tail = nodo;
    
  }
  else
  {
    nodo->next = list->head;
    list->head->prev = nodo;
    list->head = nodo;
  }
  
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) 
{
  Node* nodo = createNode(data);

  if(list->current == NULL)
  {
    pushFront(list,data);
  }
  else
  {
    nodo->next = list->current->next;
    nodo->prev = list->current;
    list->current->next = nodo;
    if(nodo->next != NULL)
    {
      nodo->next->prev = nodo;
    }
    else
    {
      list->tail = nodo;
    }
  }
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) 
{
  if(list->current == NULL)
  {
    return NULL;
  }
  else
  {
    Node* aux = list->current;
    if(list->current->prev != NULL)
    {
      list->current->prev->next = list->current->next;
      
    }
    else
    {
      list->head = list->current->next;
      
    }
    if(list->current->next != NULL)
    {
      list->current->next->prev = list->current->prev;
    }
    else
    {
      list->tail = list->current->prev;
    }
  }
  return aux->data;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}