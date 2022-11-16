#include "trem.h"
#include <QtCore>
#include "globals.h"
//Construtor
Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 100;
}

//Função a ser executada após executar trem->START
void Trem::run(){
    while(true){
        switch(ID){
        case 1:     //Trem 1
            if(velocidade != 201){
                if (y == 30 && x <330){
                    //RC 1 entrada
                    if(x == 310){
                        pthread_mutex_lock(&rc[0]);
                    }
                    x+=10;
                }
                else if (x == 330 && y < 150){
                    //RC 3 entrada
                    if(y == 130){
                        pthread_mutex_lock(&rc[2]);
                    }
                    y+=10;
                }
                else if (x > 60 && y == 150){
                    //RC 1 SAÍDA
                    if(x == 310){
                        pthread_mutex_unlock(&rc[0]);
                    }
                    //RC 3 saída
                    if(x == 240){
                        pthread_mutex_unlock(&rc[2]);
                    }
                    x-=10;
                }
                else
                    y-=10;
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 2: //Trem 2
            if(velocidade != 201){
                if (y == 30 && x <600){
                    //RC1 - SAÍDA
                    if(x == 350){
                        pthread_mutex_unlock(&rc[0]);
                    }
                    //RC 2 - ENTRADA
                    if(x == 580){
                        pthread_mutex_lock(&rc[1]);
                    }
                    x+=10;
                }
                else if (x == 600 && y < 150){
                    //RC6 - ENTRADA
                    //RC5 - ENTRADA
                    if(y == 130){
                        pthread_mutex_lock(&rc[4]);
                        pthread_mutex_lock(&rc[5]);
                    }
                    y+=10;
                }
                else if (x > 330 && y == 150){
                    //RC1 - ENTRADA
                    if(x == 350){
                        pthread_mutex_lock(&rc[0]);
                    }
                    //RC2 - SAÍDA
                    //RC6 - SAÍDA
                    if(x == 580){
                        pthread_mutex_unlock(&rc[1]);
                        pthread_mutex_unlock(&rc[5]);
                    }
                    //RC4 - ENTRADA

                    if(x == 480){
                        pthread_mutex_lock(&rc[3]);
                    }
                    //RC5 - SAÍDA
                    if(x == 450){
                        pthread_mutex_unlock(&rc[4]);
                    }
                    x-=10;
                }
                else{
                    //RC3 - SAÍDA
                    //RC4 - SAÍDA
                    if(y == 130){
                        pthread_mutex_unlock(&rc[2]);
                        pthread_mutex_unlock(&rc[3]);
                    }
                    y-=10;
                }
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 3: //Trem 3
            if(velocidade != 201){
                if (y == 30 && x <870){
                    //RC2 - SAÍDA
                    if(x == 620){
                        pthread_mutex_unlock(&rc[1]);
                    }
                    x+=10;
                }
                else if (x == 870 && y < 150)
                    y+=10;
                else if (x > 600 && y == 150){
                    //RC2 - ENTRADA
                    //RC6 - ENTRADA
                    if(x == 690){
                        pthread_mutex_lock(&rc[1]);
                        pthread_mutex_lock(&rc[5]);
                    }
                    x-=10;
                }
                else{
                    //RC6 - SAÍDA
                    if(y == 130){
                        pthread_mutex_unlock(&rc[5]);
                    }
                    y-=10;
                }
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 4: //Trem 4
            if(velocidade != 201){
                if (y == 150 && x <460){
                    //RC7 - ENTRADA
                    if(x == 440){
                        pthread_mutex_lock(&rc[6]);
                    }
                    //RC3 - SAÍDA
                    if(x == 350){
                        pthread_mutex_unlock(&rc[2]);
                    }
                    x+=10;
                }
                else if (x == 460 && y < 390){
                    //RC4 - SAÍDA
                    if(y == 170){
                        pthread_mutex_unlock(&rc[3]);
                    }
                    //RC 7
                    y+=10;
                }
                else if (x > 260 && y == 390){
                    //RC7 - SAÍDA
                    if(x == 440){
                        pthread_mutex_unlock(&rc[6]);
                    }
                    x-=10;
                }
                else{
                    //RC3 - ENTRADA
                    //RC4 - ENTRADA
                    if(y == 170){
                        pthread_mutex_lock(&rc[3]);
                        pthread_mutex_lock(&rc[2]);

                    }
                    y-=10;
                }
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 5: //Trem 5
            if(velocidade != 201){
                if (y == 150 && x < 667){
                    //RC7 - SAÍDA
                    if(x == 480){
                        pthread_mutex_unlock(&rc[6]);
                        pthread_mutex_unlock(&rc[3]);
                    }
                    //RC6 - ENTRADA
                    if(x == 580){
                        pthread_mutex_lock(&rc[5]);
                    }
                    //RC5 - SAÍDA
                    if(x == 620){
                        pthread_mutex_unlock(&rc[4]);
                    }
                    x+=10;
                }
                else if (x == 670 && y < 390){
                    //RC6 - SAÍDA
                    if(y == 170){
                        pthread_mutex_unlock(&rc[5]);
                    }
                    y+=10;
                }
                else if (x > 460 && y == 390){
                    //RC7 - ENTRADA
                    if(x == 480){
                        pthread_mutex_lock(&rc[4]);
                        pthread_mutex_lock(&rc[3]);
                        pthread_mutex_lock(&rc[6]);
                    }
                    x-=10;
                }
                else{
                    //RC5 - ENTRADA
                    if(y == 170){
//                        pthread_mutex_lock(&rc[4]);
                    }
                    y-=10;
                }
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        default:
            break;
        }
        msleep(velocidade);
    }
}

void Trem::setVelocidade(int velocidade){
    this->velocidade = velocidade;
}



