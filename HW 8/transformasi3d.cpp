#include <GL/glut.h>


float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;
float translateX = 0.0f;
float translateY = 0.0f;
float translateZ = 0.0f;
float scaleValue = 1.0f;

void drawCube() {
    glPushMatrix();
    glTranslatef(translateX, translateY, translateZ);
    glRotatef(angleX, 1.0f, 0.0f, 0.0f);
    glRotatef(angleY, 0.0f, 1.0f, 0.0f);
    glRotatef(angleZ, 0.0f, 0.0f, 1.0f);
    glScalef(scaleValue, scaleValue, scaleValue);

    glColor3f(0.0f, 1.0f, 0.0f);
    // Gambar kubus di sini
    //glutWireCube(1.0f);
    glutSolidCube(1.0f);

    glPopMatrix();
    
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);

    drawCube();

    glutSwapBuffers();
}

void reset() {
    angleX = 0.0f;
    angleY = 0.0f;
    angleZ = 0.0f;
    translateX = 0.0f;
    translateY = 0.0f;
    translateZ = 0.0f;
    scaleValue = 1.0f;
}

void keyboard(unsigned char key, int x, int y) {
    switch (key)
    {
    case 'w':
        translateY += 0.1f;
        break;
    case 's':
        translateY -= 0.1f;
        break;
    case 'a':
        translateX -= 0.1f;
        break;
    case 'd':
        translateX += 0.1f;
        break; 
    case 'z':
        translateZ += 0.1f;
        break;
    case 'x':
        translateZ -= 0.1f;
        break;
    case 'u':
        angleY += 5.0f;
        break;
    case 'i':
        angleY -= 5.0f;
        break;
    case 'j':
        angleX += 5.0f;
        break;
    case 'k':
        angleX -= 5.0f;
        break;
    case 'o':
        angleZ += 5.0f;
        break;
    case 'p':
        angleZ -= 5.0f;
        break;
    case 'm':
        scaleValue += 0.1f;
        break;
    case 'n':
        scaleValue -= 0.1f;
        break;
    case 'r':
        reset();
        break;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Transformasi 3D");

    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(45.0, 1.0, 1.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;
}
