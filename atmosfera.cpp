#include <iostream>
#include <cmath>

float pres_0{101325};
float dens_0{1.225};

float calcular_temp(float altura) {
  
  float temp{0.0};

  if (altura > 0 && altura < 11000) {
    temp = 288.16 + (-0.0065 * altura);
  } else if (altura >= 11000 && altura <= 20000 ) {
    temp = 216.16; 
  } else if (altura > 20000 && altura <= 32000){
    temp = 216.16 + (0.001 * (altura - 20000));
  } else if (altura > 32000 && altura <= 47000) {
    temp = 228.16 + (0.0028 * (altura - 32000));
  } else if (altura > 47000 && altura <= 51000) {
    temp = 270.16;
  }

  return temp;
}

float calcular_presion(float altura, float temp) {
  
  float pres;
  float g = 9.80665;
  float R = 287.05;
  float pres_0 = 101325;

  if ((altura >= 0 && altura <= 11000)) {
    pres = pow((temp / 288.16), (-g / (-0.0065 * R))) * pres_0;
  } else if ((altura > 11000 && altura <= 20000)) {
    float dh = altura - 11000;
    float exponente = ((-g * dh) / (R * temp));
    pres = exp(exponente) * 22632.1;
  } else if ((altura > 20000 && altura <= 32000)) {
    pres = pow((temp / 216.16), (-g / (0.001 * R))) * 5455.5;
  } else if ((altura > 32000 && altura <= 47000)) {
    pres = pow((temp / 228.16), (-g / (0.0028 * R))) * 858.5; 
  } else if (altura > 47000 && altura <= 51000) {
    float dh = (altura - 47000);
    float num = (-g * dh);
    float den = (R * temp);
    float division = num / den;
    float exponente = exp(division);
    pres = exponente * 108.9;
  }

  return pres;
}

float calcular_densidad(float press, float temp) {
  float R = 287.05;

  float densidad = press / (R * temp);

  return densidad;
}

extern "C" __declspec(dllexport) void display(float altura) {
  float temp;
  float pres;
  float densidad;

  temp = calcular_temp(altura);
  pres = calcular_presion(altura, temp);
  densidad = calcular_densidad(pres, temp); 

  std::cout << "La temperatura es de " << temp << "K." << std::endl;
  std::cout << "La presion es de " << pres << " pa." << std::endl;
  std::cout << "La densidad es de " << densidad << " kg/m3." << std::endl;
}