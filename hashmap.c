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
    long size; //cantidad de datos/pairs en la tabla
    long capacity; //capacidad de la tabla
    long current; //indice del ultimo dato accedido
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

void insertMap(HashMap * map, char * key, void * value) {
    if (!map || !key || map->capacity <= 0) return;

    long idx = hash(key, map->capacity);
    long start = idx;
    while (map->buckets[idx] != NULL) {
        Pair *p = map->buckets[idx];
        if (p->key != NULL && is_equal(p->key, key)) {
            return;
        }
        idx = (idx + 1) % map->capacity;
        if (idx == start) break;
    }

    idx = hash(key, map->capacity);
    start = idx;
    long first_tombstone = -1;

    while (map->buckets[idx] != NULL) {
        if (map->buckets[idx]->key == NULL && first_tombstone == -1) {
            first_tombstone = idx;
        }
        idx = (idx + 1) % map->capacity;
        if (idx == start) break;
    }

    long pos = (first_tombstone != -1) ? first_tombstone : idx;

    if (map->buckets[pos] == NULL) {
        map->buckets[pos] = createPair(key, value);
    } else {
        map->buckets[pos]->key = key;
        map->buckets[pos]->value = value;
    }

    map->size += 1;
    map->current = pos;
}

void enlarge(HashMap * map) {
    enlarge_called = 1; //no borrar (testing purposes)


}

void eraseMap(HashMap * map,  char * key) {    


}

Pair * searchMap(HashMap * map,  char * key) {   


    return NULL;
}

Pair * firstMap(HashMap * map) {

    return NULL;
}

Pair * nextMap(HashMap * map) {

    return NULL;
}
