#include <iostream>

// Node class represents a node in the linked list
class Node {
public:
    int data;
    int priority;

    Node* next; // Pointer to the next node in the list

    // Constructor to initialize the node with data and a null next pointer
    Node(int value, int priorityvalue) : data(value), next(nullptr), priority(priorityvalue) {}
};

class LinkedList {
private:
    Node* head; // Pointer to the head node in the list

public:
    // constructor for an empty list
    LinkedList() : head(nullptr) {}


    ~LinkedList() {
        // clear nodes 
        clear();
    }


    void insertAtBeginning(int value, int priority) {
        Node* newNode = new Node(value, priority); // Create a new node with the given data,and give it a priority
        newNode->next = head; // Set the next pointer of the new node to the current head
        head = newNode; // Update the head to the new node
    }

    // Function to insert a new node with the given data at the end of the list
    void insertAtEnd(int value, int priority) {
        Node* newNode = new Node(value, priority); // Create a new node with the given data

        // If the list is empty, make the new node the head
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* current = head;

            // Traverse the list to the last node
            while (current->next != nullptr) {
                current = current->next;
            }

            // Set the next pointer of the last node to the new node
            current->next = newNode;
        }
    }

    // Function to display the elements of the linked list
    void display() {
        Node* current = head; // Start at the head of the list
        while (current != nullptr) { // Traverse the list until the end
            std::cout << "(" << current->data << ", " << current->priority << ") ";
            current = current->next; // Move to the next node
        }
        std::cout << std::endl;
    }

    // Function to delete all nodes in the linked list and free memory
    void clear() {
        while (head != nullptr) {
            Node* temp = head; // Save the current head
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
    void getpostionofequalpriority(int value, int priorityentered)
    {
        while (head != nullptr)
        {
            Node* current = head;
            Node* newNode = new Node(value, priorityentered);
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

    void dequeue() {
        if (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};


class Queue {
private:
    LinkedList list;
public:

    void enqueue(int value, int priority) {
        if (priority < list.getHeadPriority() || priority == list.getHeadPriority() || list.getHeadPriority() == -1)
            list.insertAtBeginning(value, priority);
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
};

int main() {
    Queue myQueue;

    // Enqueue elements
    myQueue.enqueue(5, 2);
    std::cout << "Queue: ";
    myQueue.display();


    myQueue.enqueue(3, 1);
    std::cout << "Queue: ";
    myQueue.display();
    myQueue.enqueue(7, 3);
    std::cout << "Queue: ";
    myQueue.display();
    myQueue.enqueue(8, 4);
    myQueue.enqueue(8, 3);
    // Display the queue
    std::cout << "Queue: ";
    myQueue.display();

    // Dequeue an element
    myQueue.dequeue();

    // Display the modified queue
    std::cout << "Queue after dequeue: ";
    myQueue.display();

    return 0;
}