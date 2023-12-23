#include <stdio.h>
#include <stdlib.h>

#define MAX_LIBRI 10

typedef struct s_libro {
    long long int id;
    int count;
    struct s_libro *next;
    struct s_libro *prev;
} libro;

static libro *head = NULL;

libro *cerca(long long int id) {
    libro *current = head;
    
    while(current != NULL) {
        if(current->id == id)
            return current;
        current = current->next;
    }

    return NULL; 
}

void aggiungi(long long int id) {
    libro *current = cerca(id);

    if(current != NULL)
        current->count += 1;
    else {
        current = (libro *)malloc(sizeof(libro));
        current->id = id;
        current->count = 1;
        current->next = head;
        if(head != NULL)
            current->next->prev = current;
        current->prev = NULL;
        head = current;
    }
}

void togli(long long int id) {
    libro *current = cerca(id);

    if(current != NULL) {
        current->count -= 1;
    }
}


int conta(long long int id) {
    libro *current = cerca(id);
    
    if(current != NULL)
        return current->count;

    return 0;
}
