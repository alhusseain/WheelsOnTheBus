
template <typename StationNumberType, typename PassengerType >
class Stations {
private:
	StationNumberType stationNumber;
	StationNumberType nextStation;
	ContainerType<PassengerType> passengers;

public:
	// Constructor
	Stations(StationNumberType stationNo, NextStationType nextSt, const ContainerType<PassengerType>& passengerList)
		: stationNumber(stationNo), nextStation(nextSt), passengers(passengerList) {}

	// Getter methods
	StationNumberType getStationNumber() const {
		return stationNumber;
	}

	NextStationType getNextStation() const {
		return nextStation;
	}

	const ContainerType<PassengerType>& getPassengers() const {
		return passengers;
	}

	// Setter methods
	void setStationNumber(StationNumberType newStationNo) {
		stationNumber = newStationNo;
	}

	void setNextStation(NextStationType newNextStation) {
		nextStation = newNextStation;
	}

	void setPassengers(const ContainerType<PassengerType>& newPassengerList) {
		passengers = newPassengerList;
	}
};