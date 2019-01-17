#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  char phone[11];
  int part2 = 0;
  scanf("%s %d", phone, &part2);
  if (part2 == -1){
    printf("%s\n", phone);
  }
  else if (part2 <= 9 && part2 >= 0){
    printf("%c\n", phone[part2]);
  }
  else{
    printf("ERROR\n");
  }
  return 0;
}
