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

    passengers(/*int priority_no, */ int passenger_id, string passenger_type);


    int getPriorityNo() const;
    int getPassengerId() const;
    std::string getPassengerType() const;
    int getArrivalHours() const;
    int getArrivalMinutes() const;
    int getFinishHours() const;
    int getFinishMinutes() const;
    int getWaitingHours() const;
    int getWaitingMinutes() const;
    int getTripHours() const;
    int getTripMinutes() const;

    void setPriorityNo();
    void setArrivalTime(int minutes);
    void setFinishTime(int minutes);


    void start_trip();
    void finish_trip();


    void display() const;
};
