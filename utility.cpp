#include "utility.h"
#include <iostream>
using namespace std;

gameMap::gameMap(int size) {
    gridSize = size;
    grid = new char*[gridSize];
    for (int i = 0; i < gridSize; i++){
        grid[i] = new char[gridSize];
    }
    cout << "New Map Created!" << endl;
}

void gameMap::generateMap(const char* diff) {
    for (int i = 0; i < gridSize; i++){
        for (int j = 0; j < gridSize; j++){
            grid[i][j] = '0';
        }
    }
    grid[0][gridSize-1] = 'B';
    grid[gridSize-1][0] = 'C';
}

void gameMap::displayMap() {
    for (int i = 0; i < gridSize; i++){
        for (int j = 0; j < gridSize; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

gameMap::~gameMap() {

}

template <class T> List<T>::List(){
    head = NULL;
}

template <class T> void List<T>::insertNode(T* key) {
    ListNode<T>* newNode = new ListNode<T>();
    newNode->data = key;
    newNode->next = NULL;
    ListNode<T>* tmp = head;
    while (tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = newNode;
}

template <class T> void List<T>::deleteNode(T* key) {
    ListNode<T>* del = head;
    if (head->data == key){
        head = head->next;
        delete del;
        return;
    }
    ListNode<T>* tmp = head;
    del = del->next;
    while(del->next != NULL){
        if (del->data == key){
            tmp->next = tmp->next->next;
            delete del;
            return;
        }
        del = del->next;
        tmp = tmp->next;
    }
    cout << "Item not found in the list." << endl;
}

template <class T> void List<T>::printList() {
    ListNode<T>* tmp = head;
    cout << "List contains the following items:" << endl;
    while (tmp->next!=NULL){
        cout << tmp->data << endl;
    }
}

template <class T> List<T>::~List(){

}