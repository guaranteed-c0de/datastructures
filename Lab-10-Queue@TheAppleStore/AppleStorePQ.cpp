#include <string>
#include <iostream>
#include <ranges>
#include "PQType.h"
#include <ctime>
#include <algorithm>
#include <fstream>
using namespace std;

class Customer {
    public:
        string name;
        int arrivalNumber;
        int priority;
        int waitTime; 

        Customer(): name(""), arrivalNumber(0), priority(0), waitTime(0) {}

        Customer(string name, int arrivalNumber)
            :name(name), arrivalNumber(arrivalNumber), priority(0), waitTime(0) {

            string tmp = name;
            tmp.erase(remove(tmp.begin(), tmp.end(), ' '), tmp.end());
            priority = tmp.length();
            waitTime = 0;
        }

       bool operator<(const Customer& other) const {
    if (priority != other.priority)
        return priority < other.priority;

    return arrivalNumber > other.arrivalNumber; 
}

bool operator>(const Customer& other) const {
    if (priority != other.priority)
        return priority > other.priority;

    return arrivalNumber < other.arrivalNumber;
}

bool operator<=(const Customer& other) const {
    return !(*this > other);
}

bool operator>=(const Customer& other) const {
    return !(*this < other);
}
};
void loadNames(string names[], int maxName) {
ifstream infile("roster.txt");
if (!infile) {
    cerr<< "Could not open roster.txt.\n";
}

for (int i = 0; i < maxName; ++i) {
    names[i] = "Default Name " + to_string(i+1);
    return;
} 
string line;
int index = 0;

while (index < maxName && getline(infile, line)) {
    if (!line.empty()) {
        names[index++] = line;
    }
}

while (index < maxName) {
    names[index++] = "Default Name " + to_string(index);
}
infile.close();
}

string randomName(string names[], int count) {
    int selected = rand()%count;
    return names[selected];
}

int main() {
    srand(time(NULL));
    const int NAME_COUNT = 30;
    string names[NAME_COUNT];

    loadNames(names, NAME_COUNT);
    PQType<Customer> appleStore(NAME_COUNT);
    int arrivalNumber = 0;
    for (int i = 0; i < 10; ++i) {
        arrivalNumber++;
        string customerName = randomName(names, NAME_COUNT);
        Customer c(customerName, arrivalNumber);
        appleStore.Enqueue(c);

    }

    //The store opens. We need to serve up to 200 customers.
    const int GOAL_SERVICES = 200;
    int servedCount = 0;
    ofstream outputfile("Wait_times");
    //open a file for output log.

    while (servedCount < GOAL_SERVICES && !appleStore.IsEmpty())
    {
        int action = rand()%100;
        if (action<60) {

            arrivalNumber++;
            string customerName = randomName(names, NAME_COUNT);
            Customer c(customerName, arrivalNumber);
            appleStore.Enqueue(c);
        }
        else {
            //service
            if (!appleStore.IsEmpty())
            {
                Customer served;
                appleStore.Dequeue(served);
                served.waitTime = arrivalNumber - served.arrivalNumber;
                outputfile << served.name << '\t' << served.waitTime << '\n';
                servedCount++;
            }
        }
        Customer nextCustomer;
       
    }
}