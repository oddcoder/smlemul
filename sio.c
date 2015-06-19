/*
 * =====================================================================================
 *
 *       Filename:  sio.c
 *
 *    Description:Simpe Input and Output  
 *        Version:  1.0
 *        Created:  06/15/2015 10:28:35 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ahmed Abd-El Mawgood (oddcoder), Ahmedsoliman0x666@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */
#include "sio.h"
void neglect_input() {
    while( getchar() != '\n' || !isspace(getchar()) );
}

int get_s(char *s, int max) {
    int i=0;
    do {
        while( ( s[i] = getchar() ) != '\n' || !isspace(s[i])  ){
            // stop reading if new line is reached or space is read 
            if(i == max) {
                neglect_input();
                return -1;
            }
            i++;
        }
        s[i] ='\0'; // terminate the string
    } while(s[0] =='\0');
    return 0;
}
