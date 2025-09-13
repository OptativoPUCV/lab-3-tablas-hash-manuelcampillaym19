#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "hashmap.h"

typedef struct HashMap HashMap;
int enlarge_called=0;

struct HashMap {
    Pair ** buckets;
    long size;      // cantidad de datos/pairs en la tabla
    long capacity;  // capacidad de la tabla
    long current;   // indice del ultimo dato accedido
};

Pair * createPair( char * key,  void * value) {
    Pair * new = (Pair *)malloc(sizeof(Pair));
    new->key = key;
    new->value = value;
    return new;
}

long hash( char * key, long capacity) {
    unsigned long hash = 0;
    char * ptr;
    for (ptr = key; *ptr != '\0'; ptr++) {
        hash += hash*32 + tolower(*ptr);
    }
    return hash%capacity;
}

int is_equal(void* key1, void* key2){
    if(key1==NULL || key2==NULL) return 0;
    if(strcmp((char*)key1,(char*)key2) == 0) return 1;
    return 0;
}

/* =========================
   1) createMap (IMPLEMENTADA)
   ========================= */
HashMap * createMap(long capacity) {
    if (capacity <= 0) capacity = 2;

    HashMap *map = (HashMap*) malloc(sizeof(HashMap));
    if (!map) return NULL;

    map->buckets  = (Pair**) calloc((size_t)capacity, sizeof(Pair*));
    map->size     = 0;
    map->capacity = capacity;
    map->current  = -1;

    return map;
}

/* =========================
   2) insertMap (stub)
   ========================= */
void insertMap(HashMap * map, char * key, void * value) {
    (void)map; (void)key; (void)value;
    /* implementar después */
}

/* =========================
   3) searchMap (stub)
   ========================= */
Pair * searchMap(HashMap * map,  char * key) {
    (void)map; (void)key;
    /* implementar después */
    return NULL;
}

/* =========================
   4) eraseMap (stub)
   ========================= */
void eraseMap(HashMap * map,  char * key) {
    (void)map; (void)key;
    /* implementar después */
}

/* =========================
   5) firstMap / nextMap (stubs)
   ========================= */
Pair * firstMap(HashMap * map) {
    (void)map;
    /* implementar después */
    return NULL;
}

Pair * nextMap(HashMap * map) {
    (void)map;
    /* implementar después */
    return NULL;
}

/* =========================
   6) enlarge (stub)
   ========================= */
void enlarge(HashMap * map) {
    (void)map;
    enlarge_called = 1; // no borrar (testing purposes)
    /* implementar después */
}
