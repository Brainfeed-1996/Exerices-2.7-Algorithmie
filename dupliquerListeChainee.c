#include <stdio.h>
#include <stdlib.h>

// Définition de la structure d'un nœud
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Fonction pour dupliquer une liste chaînée
Node* dupliquerListe(Node* head) {
    if (head == NULL) return NULL;

    Node* newHead = (Node*)malloc(sizeof(Node));
    newHead->data = head->data;
    newHead->next = dupliquerListe(head->next);

    return newHead;
}

// Fonction pour ajouter un nœud à la liste
void ajouterNoeud(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Fonction pour afficher la liste
void afficherListe(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;

    // Ajouter des nœuds à la liste
    ajouterNoeud(&head, 5);
    ajouterNoeud(&head, 4);
    ajouterNoeud(&head, 3);
    ajouterNoeud(&head, 2);
    ajouterNoeud(&head, 1);

    printf("Liste originale : ");
    afficherListe(head);

    // Dupliquer la liste
    Node* copie = dupliquerListe(head);

    printf("Liste dupliquée : ");
    afficherListe(copie);

    return 0;
}
