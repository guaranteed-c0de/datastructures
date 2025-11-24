#include <string>
#include <iostream>
#include <ranges>
#include "PQType.h"
#include <ctime>
#include <algorithm>
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
    bool operator<(const)

};
void loadNames(string names[], int maxName) {

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

    //open a file for output log.

    while (servedCount < GOAL_SERVICES && !appleStore.IsEmpty())
    {
        int action = rand()%100;
        if (action<60) {

            arrivalNumber++;
            //get a random name
            //create a customer.
            //Enqueue
        }
        else {
            //service
            if (!appleStore.IsEmpty())
            {
                //Dequeue
                //Calculate the wait time.
                //log the wait time.
                servedCount++;
            }
        }
        Customer nextCustomer;
        appleStore.Dequeue(nextCustomer);
    }
}