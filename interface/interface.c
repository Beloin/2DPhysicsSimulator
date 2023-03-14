//
// Created by beloin on 12/03/23.
//

#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "interface.h"
#include "../particle_utils.h"

const char *clear = "\x1b[2J";

char started = 0;
int t_width;
int t_height;
char *terminal;

void setupConsole(int width, int height) {
    printf("%s", clear);

    t_width = width;
    t_height = height;

    if (!started) { // Buffer unused for now;
        terminal = (char *) malloc(sizeof(char) * width * height);
        started = 1;
    }
}


void printParticle(Particle *p) {
    double d_x = p->position.x;
    double d_y = p->position.y;

    // TODO: Lower the resolution x / 10
    // In order to print, we need a way to keep it between a console window size
    int x = (int) round(d_x) / 10;
    int y = (int) round(d_y) / 10;

    // For now, we will not use any buffer to draw, we will do it later
    printf("%s%i;%i%s", "\x1b[", y, x, "H"); // ANSI Matrix style
    printf("%c", particle_ui);
}

void ShowParticles(int width, int height, Particle *p_arr, int particles_length) {
    setupConsole(width, height);

    for (int i = 0; i < particles_length; ++i) {
        Particle *p = &p_arr[i];
        printParticle(p);
    }
}