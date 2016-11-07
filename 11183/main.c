#include<stdio.h>
#include<string.h>
#include"function.h"


int main(){
  char input[1000];
  char temp[1000];
  int longest_length;
  int candidate_position;

  /* 
   * This condition get the string and put into the input array 
   * on success, scanf returns 1;
   * we may expect that after the last line of the test case,
   * scanf reads nothing but a EOF so it returns 0,
   * which will break the loop.
   */
  while(scanf("%s", input) == 1){

    /*
     * Initialize the two variables for each input:
     *     longest_length: the length of the longest palindrome,
     *                     initialized to 0.
     *     candidate_position: the starting position of the longest palindrome,
     *                         which is a substring of the input.
     */
    longest_length = 0;
    candidate_position = 0;

    /*
     * str_start: the starting position of the substring
     */
    for(int str_start = 0; str_start < strlen(input); str_start++){

      /*
       * str_end: the ending position of the substring
       */
      for(int str_end = str_start; str_end < strlen(input); str_end++){

        /*
         * You should provide the implementaiton of 
         * ispal() ONLY.
         *
         * Given the string, the front and the end,
         * determine if the substring is a palindrome:
         * if it is, it must be the longest and first
         */
        if(ispal(input, str_start, str_end)){

          /*
           * Now we are sure the substring starting from input[str_start]
           * to input[str_end] is a palindrome, but we have to check if
           * this is longer than the previously found one.
           */
          if(longest_length < str_end-str_start+1){
            longest_length = str_end-str_start+1;
            candidate_position = str_start;
          }
        }
      } /* the str_end loop*/
    } /* the str_start loop */

    /*
     * print out the result
     */
    for(int i = candidate_position; i < candidate_position+longest_length; i++)
      printf("%c", input[i]);
    printf("\n");

    /*
     * continue the loop to start a new input string
     */
  } /* while loop */
}