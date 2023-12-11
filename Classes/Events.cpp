#include"f_handler.cpp"
#include"time.cpp"
class Event
{
private:
	time_def event_time;
	string passenger_type;
	string special_description;
	int ID;
public:
	Event(string time_string, string p_type, string SP_description, int identity)
	{
		event_time.set_time(time_string);
		passenger_type = p_type;
		special_description = SP_description;
		ID = identity;
	}
	time_def get_event_time_class()
	{
		return event_time;
	}
	string get_passenger_type()
	{
		return passenger_type;
	}
	string get_special_description()
	{
		return special_description;
	}
	int get_ID()
	{
		return ID;
	}


};

/*
int main()
{
	Event first("4:3", "SP", "Pregnant", 1);
	cout << "The event time: " << first.get_event_time_class().get_time() << endl;
	cout << "Passenger type: " << first.get_passenger_type() << endl;
	cout << "Passenger description: " << first.get_special_description()<<endl;
	cout << "ID: " << first.get_ID();
}
*/
