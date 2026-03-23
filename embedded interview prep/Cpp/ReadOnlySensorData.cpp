//Read-only sensordata reference
//You are given a struct sensor_data containing three integer fields: x, y, z
//You are also given a global pointer : const int *ptr = null ptr;
//Write a function print_data that:
//Accepts a SensorData object without copying it
//Enforces read-only access at compile time
//Ensure that attempting to modify the object inside the function results in compilation error
//Prints the values in the format: x y z (single line, space)
//Stores the address of x in ptr without violating const-correctness
//You must write only the correct function paraemter and implementation
//Input: 3 4 5

#include <iostream>
using namespace std;

const int *ptr = nullptr;

typedef struct SensorData{
    int x;
    int y;
    int z;
}sensor_data;

void print_data(const sensor_data &sd){

    cout << sd.x << " " << sd.y << " " << sd.z << "\n";

    //store address of x safely 
    ptr = &sd.x;
}

int main(){
    sensor_data sd;
    cin >> sd.x >> sd.y >> sd.z;
    print_data(sd);

    if (&sd.x != ptr){
        cout << "Failed\n";
    }
    return 0;
}