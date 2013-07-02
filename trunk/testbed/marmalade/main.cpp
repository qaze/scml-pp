#include <IwGx.h>
#include "testbed.h"
int main(){
    IwGxInit();
    testSCMLMarmalade();
    IwGxTerminate();
    return 0;
}