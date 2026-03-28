/**
 * @brief Example of incorrect interrupt service routine (ISR) declaration and best practices for ISRs in embedded systems.
 *
 * - ISRs cannot return a value.
 * - ISRs should not take parameters.
 * - Floating point operations are generally not safe or re-entrant in ISRs.
 * - ISRs should be short and avoid complex operations.
 */
__interrupt double compute_area(double radius){
    double area = PI * radius * radius;
    printf("\nArea = %f", area);
    return area;
}

