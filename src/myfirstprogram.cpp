#include <iostream>
using namespace std;
#include <Windows.h>

int main() {
    //comentario foase
    /*
    afa
    */
    cout << "Hello World!" << "\n" << "fi0hwqoifnwq";
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 12); // Define a cor vermelha
    std::cout << "Hello, world!\n";
    SetConsoleTextAttribute(hConsole, 7); // Define a cor padrão (branco)
    return 0;
}
