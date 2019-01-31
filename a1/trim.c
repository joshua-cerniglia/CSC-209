#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Reads a trace file produced by valgrind and an address marker file produced
 * by the program being traced. Outputs only the memory reference lines in
 * between the two markers
 */

int main(int argc, char **argv) {

    if(argc != 3) {
         fprintf(stderr, "Usage: %s tracefile markerfile\n", argv[0]);
         exit(1);
    }

    // Addresses should be stored in unsigned long variables
    // unsigned long start_marker, end_marker;
    unsigned long start_marker = 0;
    unsigned long end_marker = 0;
    fscanf(argv[2], "%lu,%lu", start_marker, end_marker);


    /* For printing output, use this exact formatting string where the
     * first conversion is for the type of memory reference, and the second
     * is the address
     */
    // printf("%c,%#lx\n", VARIABLES TO PRINT GO HERE);
    int bool = 0;
    char name = 'F';
    unsigned long hex = 0;
    while(fscanf(argv[1], "%c,%lu", name, hex) == 1){
      if(hex == start_marker){
        bool = 1;
      }
      if(bool == 1){
        printf("%c,%#lx\n", name, hex);
      }
      if(hex == end_marker){
        bool = 0;
      }
    }
    return 0;
}
