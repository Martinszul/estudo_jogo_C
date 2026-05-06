#include <GL/freeglut.h>
#include <GL/glut.h>

// JOGADOR
int moveEsq, moveDir, moveCima, moveBaixo;
float xPOS, yPOS;

// MAPA
float descerMapa = 0.0;
float tamanhoX = 0.056;
float tamanhoY = 0.08;

//IMAGEM DO CARRO JOGADORORR
int carrinho[20][10] = {
    {0, 0, 0, 2, 2, 2, 2, 0, 0, 0},
    {0, 0, 2, 2, 2, 2, 2, 2, 0, 0},
    {0, 2, 3, 3, 2, 2, 3, 3, 2, 0},
    {1, 2, 2, 2, 2, 2, 2, 2, 2, 1},
    {1, 2, 2, 1, 1, 1, 1, 2, 2, 1},
    {1, 2, 1, 1, 1, 1, 1, 1, 2, 1},
    {0, 2, 1, 1, 1, 1, 1, 1, 2, 0},
    {0, 2, 1, 3, 2, 2, 3, 1, 2, 0},
    {0, 2, 2, 3, 2, 2, 3, 2, 2, 0},
    {0, 2, 2, 3, 2, 2, 3, 2, 2, 0},
    {0, 2, 2, 3, 2, 2, 3, 2, 2, 0},
    {0, 2, 2, 3, 2, 2, 3, 2, 2, 0},
    {0, 2, 2, 3, 2, 2, 3, 2, 2, 0},
    {0, 2, 2, 3, 2, 2, 3, 2, 2, 0},
    {1, 2, 2, 3, 2, 2, 3, 2, 2, 1},
    {1, 2, 2, 1, 1, 1, 1, 2, 2, 1},
    {1, 2, 2, 2, 1, 1, 2, 2, 2, 1},
    {0, 2, 2, 2, 2, 2, 2, 2, 2, 0},
    {0, 2, 2, 2, 2, 2, 2, 2, 2, 0},

};

//COR DO CARRO JOGADOR
void carrinhoRodar(){
     for(int l = 0; l < 20; l++){
        for(int c = 0; c < 10; c++){
              if(carrinho[l][c] != 0){
                 if(carrinho[l][c] == 1) glColor3ub(0, 0, 0); if(carrinho[l][c] == 2) glColor3ub(255,0,0); if(carrinho[l][c] == 3) glColor3ub(255,255,255);
            
                 float x = c * 0.0090 - 0.09; float y = -l * 0.0090 - 0.011;

                glBegin(GL_QUADS);
                    glVertex2f(x, y);
                    glVertex2f(x + 0.0090, y);
                    glVertex2f(x + 0.0090, y + 0.0090);
                    glVertex2f(x, y + 0.0090);
                glEnd();
            }
        }
    }
}

int estrada1[25][25] = {
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
};

void estrada1Rodar(){

    for(int l = 0; l < 25; l++){
        for(int c = 0; c  < 25; c++){
            if(estrada1[l][c] != 10){
                if(estrada1[l][c] == 0) glColor3ub(128, 128, 128); if(estrada1[l][c] == 1) glColor3ub(255, 255, 255);
                if(estrada1[l][c] == 3) glColor3ub(255, 0, 0);

                float x = -0.7 + c * tamanhoX; float y = -1.0 + l * tamanhoY;

                glBegin(GL_QUADS);
                    glVertex2f(x, y);
                    glVertex2f(x + tamanhoX, y);
                    glVertex2f(x + tamanhoX, y + tamanhoY);
                    glVertex2f(x, y + tamanhoY);
                glEnd();

                
            }
        }
    }
}






void teclaMovendo(unsigned char key, int a, int b){
    if(key == 'a') moveEsq = 1;
    if(key == 'd') moveDir = 1;
    if(key == 'w') moveCima = 1;
    if(key == 's') moveBaixo = 1;
}

void teclaSolta(unsigned char key, int a, int b){
    if(key == 'a') moveEsq = 0;
    if(key == 'd') moveDir = 0;
    if(key == 'w') moveCima = 0;
    if(key == 's') moveBaixo = 0;
}

void caminhar(int valor){
    float velocidadeCaminhar = 0.0050;
    if(moveEsq) xPOS -= velocidadeCaminhar;
    if(moveDir) xPOS += velocidadeCaminhar; 
    if(moveCima) yPOS += velocidadeCaminhar;
    if(moveBaixo) yPOS -= velocidadeCaminhar;
    
    glutTimerFunc(2, caminhar, 0);
    glutPostRedisplay();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    estrada1Rodar();
    glPushMatrix();
    glTranslated(xPOS, yPOS,0);
    carrinhoRodar();
    glPopMatrix();
    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutCreateWindow("Jogo Dois");
    glClearColor(0.2, 0.2, 0.2, 1.0);
    glutKeyboardFunc(teclaMovendo);
    glutKeyboardUpFunc(teclaSolta);
    glutTimerFunc(16, caminhar, 0);
    glutDisplayFunc(display);
    glutMainLoop();
}
