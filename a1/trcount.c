#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Constants that determine that address ranges of different memory regions

#define GLOBALS_START 0x400000
#define GLOBALS_END   0x700000
#define HEAP_START   0x4000000
#define HEAP_END     0x8000000
#define STACK_START 0xfff000000

int main(int argc, char **argv) {

    FILE *fp = NULL;

    if(argc == 1) {
        fp = stdin;

    } else if(argc == 2) {
        fp = fopen(argv[1], "r");
        if(fp == NULL){
            perror("fopen");
            exit(1);
        }
    } else {
        fprintf(stderr, "Usage: %s [tracefile]\n", argv[0]);
        exit(1);
    }

    /* Complete the implementation */
    int instr = 0;
    int mods = 0;
    int loads = 0;
    int stores = 0;
    int globs = 0;
    int heap = 0;
    int stack = 0;
    char name = 'F';
    unsigned long hex = 0;
    int loop = 2;
    while(loop == 2){
      if(name == 'I'){
        instr++;
      }
      else if(name == 'M'){
        mods++;
      }
      else if(name == 'L'){
        loads++;
      }
      else if(name == 'S'){
        stores++;
      }
      if (hex >= GLOBALS_START && hex <= GLOBALS_END && name != 'I'){
        globs++;
      }
      else if (hex >= HEAP_START && hex <= HEAP_END && name != 'I'){
        heap++;
      }
      else if (hex >= STACK_START && name != 'I'){
        stack++;
      }
      loop = fscanf(fp, "%c,%lx\n", &name, &hex);
    }
    fclose(fp);

    /* Use these print statements to print the ouput. It is important that
     * the output match precisely for testing purposes.
     * Fill in the relevant variables in each print statement.
     * The print statements are commented out so that the program compiles.
     * Uncomment them as you get each piece working.
     */

    printf("Reference Counts by Type:\n");
    printf("    Instructions: %d\n", instr);
    printf("    Modifications: %d\n", mods);
    printf("    Loads: %d\n", loads);
    printf("    Stores: %d\n", stores);
    printf("Data Reference Counts by Location:\n");
    printf("    Globals: %d\n", globs);
    printf("    Heap: %d\n", heap);
    printf("    Stack: %d\n", stack);


    return 0;
}
