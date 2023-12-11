#include "passengers.h"


passengers::passengers(/*int priority_no, */ int passenger_id, std::string passenger_type)
    : /*priority_no(priority_no), */ passenger_id(passenger_id), passenger_type(passenger_type) {}


int passengers::getPriorityNo() const {
    return priority_no;
}

int passengers::getPassengerId() const {
    return passenger_id;
}

std::string passengers::getPassengerType() const {
    return passenger_type;
}

int passengers::getArrivalHours() const {
    return arrival_hours;
}

int passengers::getArrivalMinutes() const {
    return arrival_minutes;
}

int passengers::getFinishHours() const {
    return finish_hours;
}

int passengers::getFinishMinutes() const {
    return finish_minutes;
}

int passengers::getWaitingHours() const {
    return waiting_hours;
}

int passengers::getWaitingMinutes() const {
    return waiting_minutes;
}

int passengers::getTripHours() const {
    return trip_hours;
}

int passengers::getTripMinutes() const {
    return trip_minutes;
}

void passengers::setPriorityNo()
{
    if (passenger_type == "NP") priority_no = 0;
    else priority_no = 1;
}

void passengers::setArrivalTime(int minutes) {

    arrival_minutes = minutes;
}

void passengers::setFinishTime(int minutes) {
    finish_minutes = minutes;
}

// Start the trip
void passengers::start_trip() {
    waiting_hours = 0;
    waiting_minutes = 0;
}


void passengers::finish_trip() {
    trip_hours = finish_hours - (arrival_hours + waiting_hours);
    trip_minutes = finish_minutes - (arrival_minutes + waiting_minutes);
}


void passengers::display() const {
    cout << "Passenger " << passenger_id << " - Type: " << passenger_type
        << ", Priority: " << priority_no << ", Arrival Time: " << arrival_hours << ":" << arrival_minutes
        << ", Finish Time: " << finish_hours << ":" << finish_minutes
        << ", Waiting Time: " << waiting_hours << ":" << waiting_minutes
        << ", Trip Time: " << trip_hours << ":" << trip_minutes << endl;
}

