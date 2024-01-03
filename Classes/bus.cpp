#include <iostream>
#include "station.h"
using namespace std;

template <typename T>
class bus{
    private:
            int maxCapacity;
            bool isMoving = false;
            int numberOfJourneysDoneBeforeCheckUp;
            int checkUpDuration;
            Stations* currentStation; 
            int NumberOfPassengers;
            LinkedList<passengers> currentPassengers;
            public:
                bus(int numberOfJourneysDoneBeforeCheckUp, int checkUpDuration, Stations* currentStation, LinkedList<passengers> currentPassengers, int maxCapacity = 10, bool isMoving = false){
                    this->numberOfJourneysDoneBeforeCheckUp = numberOfJourneysDoneBeforeCheckUp;
                    this->checkUpDuration = checkUpDuration;
                    this->currentStation = currentStation;
                    this->currentPassengers = currentPassengers;
                    this->maxCapacity = maxCapacity;
                    this->isMoving = isMoving;
                }
            int getMaxCapacity(){
                    return maxCapacity;
                }
            int getNumberOfJourneys(){
                return numberOfJourneysDoneBeforeCheckUp;
            }
        int getCheckUpDuration(){
            return checkUpDuration;
        }
        int getNumberOfPassengers(){
            return currentPassengers.getLength();
        }
        bool isFull(){
            return currentPassengers.getLength() == maxCapacity;
        }
        bool isEmpty(){
            return currentPassengers.getLength() == 0;
        }
        void Moving(){
            if (currentStation->waitingPassengers.getLength() == 0){
                isMoving = true;
                currentStation = currentStation->getNextStation();
            }
            else if (currentStation->waitingPassengers.getLength() != 0){
                isMoving = false;
                currentStation->waitingPassengers.insertAtBeginning(currentStation->waitingPassengers.gethead()->getItem(), currentStation->waitingPassengers.gethead()->priority);
                currentStation->waitingPassengers.deleteAtBeginning();
            }
        }
        void Waiting(){
            if (currentPassengers.getLength() == maxCapacity){
                isMoving = true;
                Moving();
            }
            else if (currentPassengers.getLength() < maxCapacity){
                isMoving = false;
                currentPassengers.insertAtBeginning(currentStation->waitingPassengers.gethead()->getItem(), currentStation->waitingPassengers.gethead()->priority);
                currentStation->waitingPassengers.deleteAtBeginning();
            }
        }
        void waitingAndMoving(){
            if (currentPassengers.getLength() == maxCapacity || currentStation->waitingPassengers.getLength() == 0){
                isMoving = true;
                Moving();
            }
            else if (currentPassengers.getLength() < maxCapacity && currentStation->waitingPassengers.getLength() != 0){
                isMoving = false;
                Waiting();
            } 
            else if (currentPassengers.getLength() < maxCapacity && currentStation->waitingPassengers.getLength() == 0){
                isMoving = true;
                Moving();
            }
        }
        ~bus(){
            currentPassengers.clear();
        }
};

template <typename T>
class Wbus : public bus<T> {
    public:
        Wbus(int numberOfJourneysDoneBeforeCheckUp, int checkUpDuration, Stations* currentStation, LinkedList<passengers> currentPassengers, int maxCapacity = 10, bool isMoving = false) : bus<T>(numberOfJourneysDoneBeforeCheckUp, checkUpDuration, currentStation, currentPassengers, maxCapacity = 10, isMoving = false){
        }
        ~Wbus(){
            ~Wbus();
        }
};


template <typename T>
class Mbus: public bus<T>{
    public:
        Mbus(int numberOfJourneysDoneBeforeCheckUp, int checkUpDuration, Stations* currentStation, LinkedList<passengers> currentPassengers, int maxCapacity = 10, bool isMoving = false) : bus<T>(numberOfJourneysDoneBeforeCheckUp, checkUpDuration, currentStation, currentPassengers, maxCapacity = 10, isMoving = false){
        }
        ~Mbus(){
            ~Mbus();
        }
};

int main(){
    LinkedList<passengers> passengersList;
    passengers passenger1(1, "WP");
    passengersList.insertAtEnd(passenger1, passenger1.getPriorityNo());
    passengers passenger2(2, "MP");
    passengersList.insertAtEnd(passenger2, passenger2.getPriorityNo());
    passengers passenger3(3, "WP");
    passengersList.insertAtEnd(passenger3, passenger3.getPriorityNo());
    passengers passenger4(4, "MP");
    passengersList.insertAtEnd(passenger4, passenger4.getPriorityNo());

    Stations* station = new Stations(1, 2, passengersList);
    bus<passengers>* myBus = new bus<passengers>(5, 2, station, passengersList);
    cout << myBus->getMaxCapacity() << endl;
    cout << myBus->getNumberOfJourneys() << endl;
    cout << myBus->getCheckUpDuration() << endl;
    // passengers, priority queue, and station 
    // cout << myBus->getNumberOfPassengers() << endl;
    // cout << myBus->isFull() << endl;
    // cout << myBus->isEmpty() << endl;
    // cout << myBus->getNumberOfPassengers() << endl; // Exception has occurred. Segmentation fault. in priority queue
    // passengersList.displaypassengers(passengersList.gethead()); // Exception has occurred. Segmentation fault. in Passengers in getPassengerId()
    return 0;
}
