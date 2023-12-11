#include"time.cpp"
#include"station.h"

class Event
{
protected:
	char event_type;
	time_def event_time;
	int ID;
public:
	char get_event_type() { return event_type; }
	Event(string time_string, int identity)
	{
		event_time.set_time(time_string);
		ID = identity;
	}
	time_def get_event_time_class()
	{
		return event_time;
	}

	int get_ID()
	{
		return ID;
	}

	virtual void execute();
};

class Arrival_event:protected Event
{
private:
	
	int start_station, end_station;
	string direction;
	string passenger_type;
	string special_description;
public:
	Arrival_event(int start_station, int end_station, string passenger_type, string special_description, string time_string, int identity) :Event(time_string, identity)
	{
		this->start_station = start_station;
		this->end_station = end_station;
		this->passenger_type = passenger_type;
		this->special_description = special_description;
		if ((this->end_station - this->start_station > 0)) direction = "FWD";
		else direction = "BCK";

	}
	
	int get_start_station() { return start_station; }
	int get_end_station() { return end_station; }
	string get_direction() { return direction; }
	string get_passenger_type()
	{
		return passenger_type;
	}

	string get_special_description()
	{
		return special_description;
	}

	void execute(Stations &stationlist)
	{
		passengers NewPassenger(ID,passenger_type,special_description,direction,event_time);
		LinkedList<passengers> current_waiting = stationlist.getWaitingPassengers();
		if (current_waiting.gethead() == nullptr) {
			current_waiting.insertAtBeginning(NewPassenger, NewPassenger.getPriorityNo());
		}
		else current_waiting.insertAfterBeginning(NewPassenger, NewPassenger.getPriorityNo());
	}
};

class Leave_event :public Event
{
private:
	int leave_station;
public:
	Leave_event(int y, string time_string, int identity) :Event(time_string, identity)
	{
		leave_station = y;
	}
	int get_leave_station() { return leave_station; }
	void execute(Stations& stationlist)
	{
		LinkedList<passengers> current_waiting = stationlist.getWaitingPassengers();
		Delete(current_waiting,ID);
	}

};







/*
int main()
{
	Leave_event first(1, "4:40",3);
	cout << "The event time: " << first.get_event_time_class().get_time() << endl;
	cout << "Passenger type: " << first.get_leave_station() << endl;
	cout << "ID: " << first.get_ID();
	
}*/
