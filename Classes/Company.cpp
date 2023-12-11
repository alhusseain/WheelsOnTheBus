#include<iostream>
#include<fstream>
#include<string>
#include"passengers.h"
#include"station.h"
#include"Events.cpp"
#include"priorityqueue.h"
using namespace std;
class company
{
	private:
		int S; 		// number of stations
		int ST; 	//time between each two successive stations
		int WBus_count;
		int MBus_count;
		int WBus_capacity;
		int MBus_capacity;
		int J; 			//number of trips the bus completes before performing a checkup
		int C_WBus;		// the check up duration in minutes for WBus
		int C_MBus;		//the checkup duration in minutes for MBus
		int maxW;		//maximum waiting time
		int on_off_time;//get on/off time in seconds
		int E; 			//number of events
		/*char event_type;
		string passenger_type;
		string string_time;
		time_def event_time;
		int id;
		int start_station, end_station;
		string special_description;*/
		//--------------------------------------------------------------------
		Queue<Arrival_event> Arrival_events_list;
		Queue<Leave_event> Leave_events_list;
		char* event_types;

	public:
		company()
		{
			ifstream randomizer("random_file.txt");
			randomizer>>S>>ST;
			randomizer>>WBus_count>>MBus_count;
			randomizer>>WBus_capacity>>MBus_capacity;
			randomizer>>J>>C_WBus>>C_MBus;
			randomizer>>maxW>>on_off_time;
			randomizer>>E;
			
	/*		event_types = new char[E];
			for (int i = 0; i < E; i++)
			{
				randomizer >> event_type >> passenger_type >> string_time >> id;
				if (event_type == 'A') {
					randomizer >> start_station >> end_station;
					if (passenger_type == "SP") randomizer >> special_description;
				}
				else randomizer >> start_station;
				if (event_type == 'A')
				{
					Arrival_event new_event (start_station, end_station, passenger_type, special_description, string_time, id);
					Arrival_events_list.enqueue(new_event, 0);
				}
				else {
					Leave_event new_event(end_station,string_time, id);
					Leave_events_list.enqueue(new_event, 0);
				}
				event_types[i] = event_type;
				
			}
			
		}
		 void display()
		{
			cout<<S<<" "<<ST<<endl;
			cout<<WBus_count<<" "<<MBus_count<<endl;
			cout<<WBus_capacity<<" "<<MBus_capacity<<endl;
			cout<<J<<" "<<C_WBus<<" "<<C_MBus<<endl;
			cout<<maxW<<" "<<on_off_time<<endl;
			cout<<E<<endl<<endl;
			for (int i; i < E; i++)
			{
				if (event_types[i] == 'A')
				{
					Arrival_events_list.dequeue(new_event)
				}
			}
		}
		 */
			
		int num_of_stations() { return S;}
		int time_between_stations(){return ST;}
		int W_count(){return WBus_count;}
		int M_count(){return MBus_count;}
		int W_capacity(){return WBus_capacity;}
		int M_capacity(){return MBus_capacity;}
		int num_before_checkup(){return J;}
		int W_checkup_duration(){return C_WBus;}
		int M_checkup_duration(){return C_MBus;}
		int maximum_waiting_time(){return maxW;}
		int get_on_off_time(){return on_off_time;}
		void events_set_up()
		{

		}

		
};
//NOT FINISHED, ELHUSSEAIN'S WORK

