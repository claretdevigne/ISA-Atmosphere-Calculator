#include <iostream>
#include <string>
#include <windows.h>

typedef void (*FuncionDisplay)(float);

int main(int argc, char* argv[]) {

  HINSTANCE hDLL = LoadLibrary("atmosfera.dll");

  FuncionDisplay display = (FuncionDisplay)GetProcAddress(hDLL, "display");

  float altura;

  if (argc == 1) {
    std::string h;
    std::cout << "Ingresa la altura en metros: " << std::endl;
    std::cin >> h;
    altura = std::stof(h);
    std::cout << std::endl;
    std::cin.get();
    display(altura);
    
  } else {
    std::cout << std::endl;
    altura = atof(argv[1]);
    display(altura);
  }

  
  

  std::cout << "\n--------------------------------------" << std::endl;
  std::cout << "Calculo finalizado. Presion ENTER para cerrar..." << std::endl;
  std::cin.get();

  FreeLibrary(hDLL);

  return 0;
}