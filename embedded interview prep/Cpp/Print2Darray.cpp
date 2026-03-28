/**
 * @file Print2Darray.cpp
 * @brief Program to print a 2D array in matrix format
 * @author Author
 * @date 2024-12-19
 * @version 1.0.0
 */

#include <iostream>

/**
 * @brief Main function that demonstrates 2D array printing
 * @return 0 on successful execution
 */
int main(){
    const int a = 3;    /**< Number of rows */
    const int b = 3;    /**< Number of columns */
    int array[a][b] = {{1, 2, 3},       /**< Initialize 2D array with sample data */
                        {4, 5, 6},
                        {7, 8, 9}};

    for (int i = 0; i < a; i++){
        for (int j = 0; j < b; j++){
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}