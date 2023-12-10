
template <typename StationNumberType, typename PassengerType >
class Stations {
private:
	StationNumberType stationNumber;
	StationNumberType nextStation;
	ContainerType<PassengerType> waitingPassengers;

public:
	// Constructor
	Stations(StationNumberType stationNo, NextStationType nextSt, const ContainerType<PassengerType>& passengerList)
		: stationNumber(stationNo), nextStation(nextSt), waitingPassengers(passengerList) {}

	// Getter methods
	StationNumberType getStationNumber() const {
		return stationNumber;
	}

	NextStationType getNextStation() const {
		return nextStation;
	}

	const ContainerType<PassengerType>& getWaitingPassengers() const {
		return waitingPassengers;
	}

	// Setter methods
	void setStationNumber(StationNumberType newStationNo) {
		stationNumber = newStationNo;
	}

	void setNextStation(NextStationType newNextStation) {
		nextStation = newNextStation;
	}

	void setWaitingPassengers(const ContainerType<PassengerType>& newPassengerList) {
		waitingPassengers = newPassengerList;
	}
};
