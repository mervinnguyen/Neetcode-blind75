/**
 * @file ReadOnlySensorData.cpp
 * @brief Demonstrates read-only sensor data reference handling with const-correctness
 * @author Author
 * @date 2024-12-19
 * @version 1.0.0
 */

#include <iostream>
using namespace std;

/**< Global pointer to store const reference to sensor data x-coordinate */
const int *ptr = nullptr;

/**
 * @brief Structure representing 3D sensor data coordinates
 */
typedef struct SensorData{
    int x; /**< X-coordinate sensor reading */
    int y; /**< Y-coordinate sensor reading */
    int z; /**< Z-coordinate sensor reading */
}sensor_data;

/**
 * @brief Prints sensor data values while enforcing read-only access
 * @param[in] sd Constant reference to sensor data structure (prevents copying and modification)
 * @note Function enforces compile-time read-only access through const reference
 * @note Stores address of x-coordinate in global ptr while maintaining const-correctness
 */
void print_data(const sensor_data &sd){

    cout << sd.x << " " << sd.y << " " << sd.z << "\n";

    ptr = &sd.x;
}

/**
 * @brief Main function demonstrating sensor data input and processing
 * @return Program exit status
 */
int main(){
    sensor_data sd;
    cin >> sd.x >> sd.y >> sd.z;
    print_data(sd);

    if (&sd.x != ptr){
        cout << "Failed\n";
    }
    return 0;
}