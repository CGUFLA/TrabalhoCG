#include "main.h"

#include <assert.h>


static void testeIniciarPrograma() {
    assert(iniciarPrograma("RU UFLA")==0 && "testeIniciarPrograma()");
}

int main(int argc, char const *argv[]) {
    //assert(false && "Teste Inicial");

    testeIniciarPrograma();

    return 0;
}
