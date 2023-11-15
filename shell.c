#include "main.h"

/**
 * main - main
 * Return: 0
 */
int main(void)
{
    int exit_status = 0;
    
    while (exit_status == 0) {
        exit_status = prompt_display();
    }

    return 0;
}
