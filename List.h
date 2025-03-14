//
// Created by Samadjon Sayfullayev on 14/03/25.
//

#ifndef LIST_H
#define LIST_H
#include <exception>
using namespace std;
template <typename T>
class List {
    private:
    class Node {
    public:
        T val;
        Node* next;
        Node *prev;
        Node(T val) {
            this->val=val;
            next=nullptr;
            prev=nullptr;
        }

    };
    Node* head;
    Node* tail;

    public:
    List() {
        head =nullptr;
        tail =nullptr;
    }
    void addFront(T val) {
        Node * newNode = new Node(val);
        if (head==nullptr) {
            head=newNode;
            tail=newNode;
        } else {
            newNode->next=head;
            head->prev=newNode;
            head=newNode;
        }
    }
    void addTail(T val) {
        Node * newNode = new Node(val);
        if (head==nullptr) {
            head=newNode;
            tail=newNode;
        } else {
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;

        }
    }
    T getFront() {
        if (head==nullptr) throw std::runtime_error("List is empty. Cannot get front.");
        return head->val;
    }
    T getTail() {
        if (tail==nullptr) throw std::runtime_error("List is empty. Cannot get tail.");
        return tail->val;
    }
    void displayForwards() {
        Node * temp=head;
        while (temp!=nullptr) {
            std::cout<<temp->val<<"->";
            temp=temp->next;
        }
        std::cout<<"NULL"<<std::endl;
    }
    void displayBackwards() {
        Node * temp=tail;
        while (temp!=nullptr) {
            std::cout<<temp->val<<"->";
            temp=temp->prev;
        }
        std::cout<<"NULL"<<std::endl;
    }
    void removeFront() {
        if (head==nullptr) throw std::runtime_error("List is empty. Cannot delete front.");
        Node *temp=head;
        head=head->next;
        head->prev=nullptr;
        delete temp;
    }
    void removeTail() {
        if (head==nullptr) throw std::runtime_error("List is empty. Cannot delete tail.");
        Node * temp=tail;
        tail=tail->prev;
        tail->next=nullptr;
        delete temp;
    }
    T getAt(int index) {
        if (index < 0) throw runtime_error("Index cannot be negative.");
        Node* current = head;
        int currentIndex = 0;
        while (current != nullptr && currentIndex < index) {
            current = current->next;
            currentIndex++;
        }
        if (current == nullptr) throw runtime_error("Index out of range.");
        return current->val;
    }



    void insertAt(T val, int index) {
        if (index < 0) throw std::runtime_error("Index cannot be negative.");
        if (head == nullptr) throw std::runtime_error("List is empty. Cannot remove.");
        Node * current = head;
        int currentIndex=0;
        while (current!=nullptr && currentIndex<index) {
            current=current->next;
            currentIndex++;
        }
     if (current==nullptr) throw std::runtime_error("Index out of range.");
    }
    void removeAt(int index) {
        if (index < 0) throw std::runtime_error("Index cannot be negative.");
        if (head==nullptr) throw std::runtime_error("List is empty. Cannot remove tail.");
        Node * current = head;
        int currentIndex=0;
        if (current==head) {
            head=current->next;
        }
        if (current==tail) {
            tail=current->prev;
        }
        delete current;
    }
};
#endif //LIST_H
