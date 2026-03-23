//Print a 2D array
//input: {{1,2,3}, {4,5,6}, {7,8,9}}
//

#include <iostream>

//implement function to print the 2D array

int main(){
    const int a = 3;    //row
    const int b = 3;    //column
    int array[a][b] = {{1, 2, 3},       //Define 2D array
                        {4, 5, 6},
                        {7, 8, 9}};

    for (int i = 0; i < a; i++){        //loop through row
        for (int j = 0; j < b; j++){    //loop through column       (start from top left, span right, skip to the next line)
            std::cout << array[i][j] << " ";        //use standard library to output current cell of array and skip a line
        }
        std::cout << std::endl;      //after iterating through each column, skip a line
    }
    return 0;
}