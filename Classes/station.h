#ifndef STATION
#define STATION


#include "c++(priorityqueue).cpp"

class Stations {
private:
	int  stationNumber;
	int  nextStation;
	LinkedList<passengers> waitingPassengers;

public:
	// Constructor
	Stations(int stationNo, int nextSt, LinkedList<passengers>& passengerList)
		: stationNumber(stationNo), nextStation(nextSt), waitingPassengers(passengerList) {}

	// Getter methods
	int getStationNumber(){
		return stationNumber;
	}

	int getNextStation() {
		return nextStation;
	}

	LinkedList<passengers>& getWaitingPassengers() {
		return waitingPassengers;
	}

	int getNumberOfWaitingPassengers() {
		return waitingPassengers.getLength();
	}

	// Setter methods
	void setStationNumber(int newStationNo) {
		stationNumber = newStationNo;
	}

	void setNextStation(int newNextStation) {
		nextStation = newNextStation;
	}

	void setWaitingPassengers(LinkedList<passengers>& newPassengerList) {
		waitingPassengers = newPassengerList;
	}
};

#endif // !STATION
