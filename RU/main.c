#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <string.h>

static int retorno = 0;

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glFlush();
}


int iniciarPrograma(char *nome) {
    int argc;
    char **argv;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowPosition(400, 400);
    glutInitWindowSize(300, 300);
    glutCreateWindow(nome);

    glutDisplayFunc(display);

    glutMainLoop();

    return retorno;
}
