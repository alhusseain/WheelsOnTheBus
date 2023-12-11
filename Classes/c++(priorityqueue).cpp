#include <iostream>
#include "Passengers.h"

using namespace std;

template<class t>
class Node {
public:
    t data;
    int priority;

    Node<t>* next; 

    // Constructor to initialize the node with data and a null next pointer
    Node(t value, int priorityvalue) : data(value), next(nullptr), priority(priorityvalue) {}
    
    void setNext(Node<t>* nextNodePtr)
	{
		next = nextNodePtr;
	}

	t getItem() const
	{
		return data;
	} 

	Node<t>* getNext() const
	{
		return next;
	}
};

template<class t>
class LinkedList {
private:
    Node<t>* head; // Pointer to the head node in the list

public:
    // constructor for an empty list
    LinkedList() : head(nullptr) {}


    ~LinkedList() {
        // clear nodes 
        clear();
    }

    Node<t>* gethead() {
        return head;
     }
    void insertAtBeginning(t value, int priority) {
        Node<t>* newNode = new Node<t>(value, priority); // Create a new node with the given data,and give it a priority
        newNode->next = head; // Set the next pointer of the new node to the current head
        head = newNode; // Update the head to the new node
    } void insertAfterBeginning(t value, int priority) {
        Node<t>* newNode = new Node<t>(value, priority); // Create a new node with the given data,and give it a priority
        newNode->next = head->next; // Set the next pointer of the new node to the current head
        head->next = newNode; // Update the head to the new node
    }

    // Function to insert a new node with the given data at the end of the list
    void insertAtEnd(t value, int priority) {
        Node<t>* newNode = new Node<t>(value, priority); // Create a new node with the given data

        // If the list is empty, make the new node the head
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node<t>* current = head;

            // Traverse the list to the last node
            while (current->next != nullptr) {
                current = current->next;
            }

            // Set the next pointer of the last node to the new node
            current->next = newNode;
        }
    }

    // Function to display the elements of the linked list
  

    // Function to delete all nodes in the linked list and free memory
    void clear() {
        while (head != nullptr) {
            Node<t>* temp = head; // Save the current head
            head = head->next; // Move to the next node
            delete temp; // Delete the saved node
        }
    }
    int getHeadPriority() const {
        if (head != nullptr) {
            return head->priority;
        }
        else {

            return -1;
        }
    }
    void getpostionofequalpriority(t value, int priorityentered)
    {
        while (head != nullptr)
        {
            Node<t>* current = head;
            Node<t>* newNode = new Node<t>(value, priorityentered);
            while (current->next != nullptr)
            {
                if (current->next->priority != priorityentered)
                {

                    current = current->next;
                }
                else {
                    newNode->next = current->next;
                    current->next = newNode;
                    return;
                }
            }
            newNode->next = current->next;
            current->next = newNode;
            return;


        }
    }

    void dequeue(t value) {
        Node<t>* current = head;
        Node<t>* previous = nullptr;

        while (current != nullptr && current->data != value) {
            previous = current;
            current = current->next;
        }

        if (current == head) {
            head = head->next;
            delete current;
        }
        else if (current != nullptr) {
            previous->next = current->next;
            delete current;
        }
    }
    
int getLength()
{
    Node<t> *p = head;
    int count = 0;
    while(p)
    {
        count++;
        p = p->getNext();
    }
    return count;
}


void displaypassengers(Node<passengers>*  head) {
	Node<passengers>* current = head; // Start at the head of the list
	while (current != nullptr) { // Traverse the list until the end
		std::cout << "(" << current->data.getPassengerId() << ", " << current->priority << ") ";
		current = current->next; // Move to the next node
	}
	std::cout << std::endl;
}

void deletepassengers(Node<passengers>* head,int targetid){
		Node<passengers>* previous = nullptr;
		Node<passengers>* current = head; // Start at the head of the list
		while (current->data.getPassengerId() != targetid) { // Traverse the list l8ayt ama alaA2Y
			previous = current;
			current = current->next; // Move to the next node
			if (current->data.getPassengerId() == targetid) {
				previous->next = current->next;
			
				return;
			}

		
		}
		
		
	
	
	
}
};

template<class t>
class Queue {
private:
    LinkedList<t> list;
public:

    void enqueue(t value, int priority) {
        if (priority < list.getHeadPriority() || list.getHeadPriority() == -1)
            list.insertAtBeginning(value, priority);
         else if (priority == list.getHeadPriority()) {

            list.insertAfterBeginning(value,priority);
                
        }
        else 
            list.getpostionofequalpriority(value, priority);
    }

    // Function to dequeue (remove) an element from the front of the queue
    void dequeue() {
        list.dequeue();
    }

    // Function to display the elements of the queue
    void display() {
        list.display(); // Display the linked list elements made specifically for the queues
    }
    LinkedList<t> getlinkedlist() {
        return list;
    }
};
