#include <fstream>
#include <iostream>
#include <vector>

using namespace::std;


//This is a class that holds the time and minute. Should be implemented in order to track start and end time for an event.
class Time {
    public:
    int hour, min;
};
//A separate class that is designed to hold the start and end date for an event. Inherits hours and minutes from Time.
class Date: public Time {
    private:
        int day, month, year;
    public:
        void setDate(int d, int m, int y);
        Date(int d, int m, int y);
};
//Constructor for date.
Date::Date(int d, int m, int y){
    day = d;
    month = m;
    year = y;
};

void 
Date::setDate(int d = 0, int m = 0, int y = 0){
    day = d;
    month = m;
    year = y;
}

class Event {
    private:
        string name;
        Date start;
    public:
        Event(string n, Date s){
            name = n;
            start = s;
        }
        string getName(){
            return name;
        }
        Date getDate(){
            return start;
        }
};

class Calendar {
    private:
        vector<Event> dailyEvents;
    public:
        void addEvent(Event event){
            dailyEvents.push_back(event);
        }
        void printEvents(Date date);
};

void
Calendar::printEvents(Date date){
    for (int i = 0; i < dailyEvents.size(); i++){

        cout << "EVENT " << i << ": " << dailyEvents.at(i).getName() << endl << endl;  
    }
}


int main() {
    Calendar cal;
    Date currentDate(30, 11, 2022);
    currentDate.hour = 5;
    currentDate.min = 30;

    Event scheduleEvent("Class", currentDate);
    cal.addEvent(scheduleEvent);
    cal.printEvents();

    return 0;

}