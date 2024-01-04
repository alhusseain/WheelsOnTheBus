#include <iostream>
#include "station.h"
using namespace std;

template <typename T>
class bus{
    private:
            int maxCapacity;
            int count = 0;
            bool isMoving = false;
            int numberOfJourneysDoneBeforeCheckUp;
            int checkUpDuration;
            Stations currentStation; 
            Stations destinationStation;
            int NumberOfPassengers;
            LinkedList<passengers> currentPassengers;
            public:
                bus(int numberOfJourneysDoneBeforeCheckUp, int checkUpDuration, Stations currentStation, LinkedList<passengers> currentPassengers, int maxCapacity = 10, bool isMoving = false){
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

        Stations getCurrentStation(){
            return currentStation;
        }

        void setIsMoving(bool isMoving){
            this->isMoving = isMoving;
        }

        void IncrementNumberOfJourneysDone(){
            numberOfJourneysDoneBeforeCheckUp++;
        }

        void setCurrentStation(Stations st)
		{
			currentStation = st;
		}

        Stations getDestinationStation()
		{
			destinationStation.setStationNumber(currentStation.getStationNumber() + 1);
            return destinationStation;
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

}
