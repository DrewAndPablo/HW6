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
char align = 'L';
int spacing = 0;

int main(int argc, const char * argv[])
{
    for (int i = 1; i < argc ; i++){
        if (argv[i][0] == '-' && argv[i][1] == 'w') {
            i++;
            width = atoi(argv[i]);
        }
        else if (argv[i][0] == '-' && (argv[i][1] == 'w'|| argv[i][1] == 'j')) {
            align = argv[i][1];
        }
        else if (argv[i][0] == '-' && argv[i][1] == 's') {
            spacing = 1;
        }
        else if (argv[i][0] == '-') {
            printf("Please use only the options from the man page.");
            exit(1);
        }
    }
    return 0;
}

