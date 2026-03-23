#include <stdio.h>

//Implement strCopy function
void str_copy(char *s, char *d){     //takes inputs null-terminated string s and string d, copies string s to string d
    while(*s != '\0'){  //while current character of s is not null-terminated   
        *d = *s;        //add current character to d
        s++;            //increment s
        d++;            //increment d
    }
    *d = '\0';      //null-terminate string d at the end
    return;
}

int main(void){
    char s[8] = "ABCDEFG";       //define string s in a stored array
    char d[8];                   //define string d as an empty array of size 7 (if we define it as anything less than 7, we receive a buffer overflow)
    str_copy(s, d);               //call function
    printf("%s \n", d);          //print out destination d
    return 0;
}