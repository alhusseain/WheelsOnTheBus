#include <iostream>
#include "LinkedList.h"
using namespace std;

// remove template when station and passenegrs are implemented
template <typename T>
class bus{
    private:
        int id;
        int capacity;
        int numberOfJourneysDone;
        int busyTime;
        // replace t of the station to be a pointer to the station
        T station;
        int totalNumberOfPassengers;
        // replace t of the currentPassengers to be a pointer to the passengers
        LinkedList<T> currentPassengers;
        int checkUpDuration;
        bool isBusy;
    public:
        bus(int id, int capacity, int numberOfJourneys, int checkUpDuration){
            this->id = id;
            this->capacity = capacity;
            this->numberOfJourneysDone = numberOfJourneys;
            this->checkUpDuration = checkUpDuration;
        }
        int getId(){
            return id;
        }
        int getCapacity(){
            return capacity;
        }
        int getNumberOfJourneys(){
            return numberOfJourneysDone;
        }
        int getCheckUpDuration(){
            return checkUpDuration;
        }
        void setId(int id){
            this->id = id;
        }
        void setCapacity(int capacity){
            this->capacity = capacity;
        }
        void setNumberOfJourneys(int numberOfJourneys){
            this->numberOfJourneys = numberOfJourneys;
        }
        void setCheckUpDuration(int checkUpDuration){
            this->checkUpDuration = checkUpDuration;
        }
        void addPassenger(int passengerId){
            currentPassengers.Insert(passengerId);
        }
        void removePassenger(int passengerId){
            currentPassengers.DeleteNode(passengerId);
        }
        void printPassengers(){
            currentPassengers.PrintList();
        }
        int getNumberOfPassengers(){
            return currentPassengers.getLength();
        }
        bool isFull(){
            return currentPassengers.getLength() == capacity;
        }
        bool isEmpty(){
            return currentPassengers.getLength() == 0;
        }
        void setBusy(bool isBusy){
            this->isBusy = isBusy;
        }
        bool getBusyStatus(){
            return isBusy;
        }
        ~bus(){
            currentPassengers.DeleteAll();
        }
};

template <typename T>
class Wbus : public bus<T> {
    private:
        bus<T> bus; 
    public:
        Wbus(int id, int capacity, int numberOfJourneys, int checkUpDuration) : bus<T>(id, capacity, numberOfJourneys, checkUpDuration){
        }
        ~Wbus(){
            ~Wbus();
        }
};


template <typename T>
class Mbus: public bus<T>{
    public:
        Mbus(int id, int capacity, int numberOfJourneys, int checkUpDuration) : bus<T>(id, capacity, numberOfJourneys, checkUpDuration){
        }
        ~Mbus(){
            ~Mbus();
        }
};


int main(){
    bus<int> b(1, 10, 5, 10);
    b.addPassenger(1);
    b.addPassenger(2);
    b.addPassenger(3);
    b.addPassenger(4);
    b.addPassenger(5);
    b.printPassengers();
    b.removePassenger(1);
    b.removePassenger(2);
    b.removePassenger(3);
    b.removePassenger(4);
    b.removePassenger(5);
    b.printPassengers();
    cout << b.getNumberOfPassengers() << endl;
    cout << b.isFull() << endl;
    cout << b.isEmpty() << endl;
    return 0;
}
