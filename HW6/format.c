//
//  main.c
//  HW6
//
//  Created by Drew Gotbaum, Pablo Horth, and Prakash Paudel on 11/4/13.
//  Copyright (c) 2013 Drew Gotbaum, Pablo Horth, and Prakash Paudel. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int width = 72;
char align = 'l';
int spacing = 0;
char str[5000];
void widthFormatting() {
    char ch;
    int count = 0;
    int lastspace = 0;
    int wasLine = 0;
    int index = 0;
    while ( EOF !=(ch = getchar())) {
        if (count >= width && ch == ' ' ) {
            printf("\n");
            str[index]= '\n';
            index++;
            count = 0;
            lastspace = 1;
        }
        if (ch == ' ' && lastspace !=1){
            lastspace = 1;
            putchar(ch);
            str[index] = ch;
            index++;
            count++;
            wasLine = 0;
        }
        else if (ch == ' ' && lastspace == 1) {
            continue;
        }
        else if (ch == '\n') {
            if (wasLine == 0) {
                wasLine = 1;
                continue;
            }
            else if (wasLine == 1) {
                wasLine = 0;
                putchar(ch);
                str[index] = ch;
                index++;
                putchar(ch);
                str[index] = ch;
                index++;
                count = 0;
                lastspace = 1;
            }
        }
        else {
            putchar(ch);
            str[index] = ch;
            index++;
            lastspace = 0;
            count++;
            wasLine = 0;
        }
    }
}
int main(int argc, const char * argv[]){
    for (int i = 1; i < argc ; i++){
        if (argv[i][0] == '-' && argv[i][1] == 'w') {
            i++;
            width = atoi(argv[i]);
            printf("width changed to %d \n", width);
        }
        else if (argv[i][0] == '-' && (argv[i][1] == 'r'|| argv[i][1] == 'j')) {
            align = argv[i][1];
            printf("alignment is now %c \n",align );
        }
        else if (argv[i][0] == '-' && argv[i][1] == 's') {
            spacing = 1;
            printf("Spacing is on \n");
        }
        else if (argv[i][0] == '-') {
            printf("Please use only the options from the man page.\n");
            exit(1);
        }
    }
    

    widthFormatting();
    printf("\n");
    for (int i = 0; i < 5000; i++) {
        if (str[i] == '\0') {
            break;
        }
        printf("%c",str[i]);
    }
    
    printf("\n");
    return 0;
}

