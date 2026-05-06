#include <GL/glut.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

// JOGADOR
int teclaEsquerda, teclaDireita, teclaCima, teclaAbaixo;
float xJogador, yJogador;
float limiteX = 0.60;
float limiteY = 0.83;

// IMAGEM DO CARRO
int imagemCarro[20][10] = {
    {0,0,0,2,2,2,2,0,0,0},
    {0,0,2,2,2,2,2,2,0,0},
    {0,2,3,3,2,2,3,3,2,0},
    {1,2,2,2,2,2,2,2,2,1},
    {1,2,2,1,1,1,1,2,2,1},
    {1,2,1,1,1,1,1,1,2,1},
    {0,2,1,1,1,1,1,1,2,0},
    {0,2,1,3,2,2,3,1,2,0},
    {0,2,2,3,2,2,3,2,2,0},
    {0,2,2,3,2,2,3,2,2,0},
    {0,2,2,3,2,2,3,2,2,0},
    {0,2,2,3,2,2,3,2,2,0},
    {0,2,2,3,2,2,3,2,2,0},
    {0,2,2,3,2,2,3,2,2,0},
    {1,2,2,3,2,2,3,2,2,1},
    {1,2,2,1,1,1,1,2,2,1},
    {1,2,2,2,1,1,2,2,2,1},
    {0,2,2,2,2,2,2,2,2,0},
    {0,2,2,2,2,2,2,2,2,0},
};

void desenharCarro(){
    for(int l = 0; l < 20; l++){
        for(int c = 0; c < 10; c++){
            if(imagemCarro[l][c] != 0){

                if(imagemCarro[l][c] == 1) glColor3ub(0,0,0);
                else if(imagemCarro[l][c] == 2) glColor3ub(255,0,0);
                else if(imagemCarro[l][c] == 3) glColor3ub(255,255,255);

                float x = c * 0.011 - 0.045;
                float y = -l * 0.011;

                glBegin(GL_QUADS);
                    glVertex2f(x, y);
                    glVertex2f(x+0.011, y);
                    glVertex2f(x+0.011, y+0.011);
                    glVertex2f(x, y+0.011);
                glEnd();
            }
        }
    }
}

int mapa[25][25] = {
    {1, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 2, },
    {2, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 2, },
    {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, },
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, },
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, },
    {2, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 2, },
    {2, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 2, },
    {1, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 1, },
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
    {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, },
    {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, },
    {1, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 1, },
    {1, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 1, },
    {2, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 2, },
    {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, },
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
    {2, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 2, },
    {2, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 2, },
    {1, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 1, },
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
    {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, },
    {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, },
    {1, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 1, },
    {1, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 1, },
};

// DESENHO MAPA

void desenharMapa(){
    float largura = 1.4 / 25.0;  // -0.7 até 0.7
    float altura  = 2.0 / 25.0;  // -1 até 1

    for(int l = 0; l < 25; l++){
        for(int c = 0; c < 25; c++){

            if(mapa[l][c] == 0) glColor3ub(167,167,167); if(mapa[l][c] == 1) glColor3ub(0, 0, 0); if(mapa[l][c] == 2) glColor3ub(255, 255, 255);
            if(mapa[l][c] == 3) glColor3ub(255,255,0);

                float x = -0.7 + c * largura;
                float y =  1.0 - l * altura;

                glBegin(GL_QUADS);
                    glVertex2f(x, y);
                    glVertex2f(x + largura, y);
                    glVertex2f(x + largura, y - altura);
                    glVertex2f(x, y - altura);
                glEnd();
    
        }
    }
}

// TECLAS
void teclaMovendo(unsigned char key, int a, int b){
    if(key=='a') teclaEsquerda=1;
    if(key=='d') teclaDireita=1;
    if(key=='w') teclaCima=1;
    if(key=='s') teclaAbaixo=1;
}

void teclaSolta(unsigned char key, int a, int b){
    if(key=='a') teclaEsquerda=0;
    if(key=='d') teclaDireita=0;
    if(key=='w') teclaCima=0;
    if(key=='s') teclaAbaixo=0;
}

// JOGADOR
void moverJogador(int valor){
    float v = 0.005;

    if(teclaEsquerda) xJogador -= v;
    if(teclaDireita) xJogador += v;
    if(teclaCima) yJogador += v;
    if(teclaAbaixo) yJogador -= v;  

    if(xJogador > limiteX) xJogador = limiteX;
    if(xJogador < -limiteX) xJogador = -limiteX;
    if(yJogador < -limiteY) yJogador = -limiteY;
    
    glutTimerFunc(2, moverJogador, 0);
    glutPostRedisplay();
}

// DISPLAY
void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    desenharMapa();

    glPushMatrix();
        glTranslated(xJogador,yJogador,0);
        desenharCarro();
    glPopMatrix();

    glutSwapBuffers();
}

int main(int argc, char** argv){
    srand(time(NULL));

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutCreateWindow("Jogo");

    glClearColor(0.2,0.2,0.2,1);

    glutKeyboardFunc(teclaMovendo);
    glutKeyboardUpFunc(teclaSolta);

    glutTimerFunc(16, moverJogador, 0);

    glutDisplayFunc(display);
    glutMainLoop();
}
