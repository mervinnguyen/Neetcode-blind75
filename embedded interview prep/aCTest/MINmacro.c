//Write the "standard" MIN macro. That is, a macro that takes two arguments and returns the smaller of the two arguments.

#define MIN(A,B)    (((A) < (B)) ? (A) : (B))     //if A is less than B is true, then output A,else output B
//small note: ake sure to paranthesize each argument