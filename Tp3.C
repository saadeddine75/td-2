#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Product {
    int ID;
    char Name[20];
    int Price;
} Product;

typedef struct Node {
    Product Prod;
    struct Node* next;
} Node;


Node* empty() {
    return NULL;
}


int IsEmpty(Node* head) {
    return (head == NULL);
}


Node* addBeginning(Node* head, Product P) {
    Node* new =  malloc(sizeof(Node));
    new->Prod = P;

    if (head == NULL) {
        new->next = new;
        return new;
    }

    Node* t = head;
    while (t->next != head)
        t = t->next;

    t->next = new;
    new->next = head;

    return new;
}


Node* addEnd(Node* head, Product P) {
    Node* new = malloc(sizeof(Node));
    new->Prod = P;

    if (head == NULL) {
        new->next = new;
        return new;
    }

    Node* t= head;
    while (t->next != head)
        t= t->next;

    t->next = new;
    new->next = head;

    return head;
}


void Display(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* t = head;
    do {
        printf("ID: %d  Name: %s  Price: %d\n",t->Prod.ID,t->Prod.Name,t->Prod.Price);
        t = t->next;
    } while (t != head);
}


int main() {
    Node* head = empty();
    Product P;

    
    P.ID = 1;
    strcpy(P.Name,"A");
    P.Price = 120;
    head = addBeginning(head, P);

    
    P.ID = 2;
    strcpy(P.Name,"j");
    P.Price = 50;
    head = addEnd(head, P);

    
    Display(head);

    return 0;
}
