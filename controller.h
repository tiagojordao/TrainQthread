#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "pthread.h"

class Controller
{
public:
    Controller();
    static pthread_mutex_t *rc;
};



#endif // CONTROLLER_H
