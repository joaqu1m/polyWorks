#include <iostream>
#include <Windows.h>

using namespace std;

int main() {

    // Obt�m o identificador do console de entrada padr�o (teclado)
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);

    // Configura o modo de entrada para capturar pressionamentos de tecla
    DWORD mode = 0;
    GetConsoleMode(hStdin, &mode);
    SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));

    // Exibe uma mensagem de instru��o para o usu�rio
    cout << "Digite algumas teclas (pressione ESC para sair): " << endl;

    // Loop para detectar e exibir as teclas pressionadas
    while (true) {
        // Aguarda at� que ocorra um evento de entrada
        INPUT_RECORD inputRec;
        DWORD numEvents;
            //cout << "opa1" << endl;
        ReadConsoleInput(hStdin, &inputRec, 1, &numEvents);
            //cout << "opa2" << endl;

        // Verifica se o evento � um pressionamento de tecla
        if (inputRec.EventType == KEY_EVENT && inputRec.Event.KeyEvent.bKeyDown) {
            // Exibe o c�digo ASCII da tecla pressionada
            cout << "Tecla pressionada: " << (int)inputRec.Event.KeyEvent.uChar.AsciiChar << endl;

            // Verifica se a tecla ESC foi pressionada para sair do loop
            if (inputRec.Event.KeyEvent.uChar.AsciiChar == 27) {
                break;
            }
        }
    }

    // Restaura o modo de entrada original
    SetConsoleMode(hStdin, mode);

    return 0;
}
