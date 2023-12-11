#pragma once
#include <string>
#include <iostream>
using namespace std;


class passengers {
private:
    int priority_no;
    int passenger_id;
    std::string passenger_type;
    int arrival_hours;
    int arrival_minutes;
    int finish_hours;
    int finish_minutes;
    int waiting_hours;
    int waiting_minutes;
    int trip_hours;
    int trip_minutes;

public:

    passengers(/*int priority_no, */ int passenger_id1, string passenger_type1) {
        passenger_id = passenger_id1;
        passenger_type = passenger_type1;



    }


    int getPriorityNo() const {
        return priority_no;
    }
    int getPassengerId() const {
        return passenger_id;
    }

    std::string getPassengerType() const {
        return passenger_type;
    }

    int getArrivalHours() const {
        return arrival_hours;
    }

    int getArrivalMinutes() const {
        return arrival_minutes;
    }

    int getFinishHours() const {
        return finish_hours;
    }

    int getFinishMinutes() const {
        return finish_minutes;
    }

    int getWaitingHours() const {
        return waiting_hours;
    }

    int getWaitingMinutes() const {
        return waiting_minutes;
    }

    int getTripHours() const {
        return trip_hours;
    }

    int getTripMinutes() const {
        return trip_minutes;
    }

    void setPriorityNo(int priority_no1) {
        priority_no = priority_no1;
    }


    void setArrivalTime(int minutes) {

        arrival_minutes = minutes;
    }

    void setFinishTime(int minutes) {
        finish_minutes = minutes;
    }

    // Start the trip
    void start_trip() {
        waiting_hours = 0;
        waiting_minutes = 0;
    }


    void finish_trip() {
        trip_hours = finish_hours - (arrival_hours + waiting_hours);
        trip_minutes = finish_minutes - (arrival_minutes + waiting_minutes);
    }
    void setPassengerID(int passenger_id1) {
        passenger_id = passenger_id1;
    }

    void display() const {
        cout << "Passenger " << passenger_id << " - Type: " << passenger_type
            << ", Priority: " << priority_no << ", Arrival Time: " << arrival_hours << ":" << arrival_minutes
            << ", Finish Time: " << finish_hours << ":" << finish_minutes
            << ", Waiting Time: " << waiting_hours << ":" << waiting_minutes
            << ", Trip Time: " << trip_hours << ":" << trip_minutes << endl;
    }
};
