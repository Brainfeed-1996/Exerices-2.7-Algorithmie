#include <stdio.h>
#include <stdlib.h>

// Définition de la structure d'un nœud
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Fonction pour ajouter un nœud à la fin de la liste
void ajouterNoeudFin(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Fonction pour construire une liste chaînée à partir d'un tableau
Node* construireListe(int arr[], int taille) {
    Node* head = NULL;
    for (int i = 0; i < taille; i++) {
        ajouterNoeudFin(&head, arr[i]);
    }
    return head;
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
    int arr[] = {1, 2, 3, 4, 5};
    int taille = sizeof(arr) / sizeof(arr[0]);

    Node* liste = construireListe(arr, taille);

    printf("Liste construite à partir du tableau : ");
    afficherListe(liste);

    return 0;
}
