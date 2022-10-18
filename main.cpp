// =================================================================
//
// File: main.cpp
// Author: Ian Joab Padrón Corona - A01708940
// Date: 17-10-2022
// 
// =================================================================
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "header.h"

using namespace std;

int main(int argc, char *argv[]) {
	ifstream inputFile;
  ofstream outputFile;

  int firstNumber;         // Numero de registros a buscar
  string tempLine, search1; // Para pasar del archivo a leer a un vector
  vector<string> datos, line1;

  inputFile.open(argv[1], ios::in);
  outputFile.open(argv[2], ios::out);

  inputFile >> firstNumber;

  for (int i = 0; i <= firstNumber; i++) {
    getline(inputFile, tempLine);
    datos.push_back(tempLine);
  }

  tempLine = datos[0];
  stringstream tempLine1(tempLine);

  while (getline(tempLine1,tempLine,' ')) {
    line1.push_back(tempLine);
  }

  search1 = line1[1];
  vector<string> datos1;


  for (int i = 1; i < datos.size(); i++) {
    datos1.push_back(datos[i]);
  }

  vector<string> datosFiltrados = search(datos1,search1);
	vector<int> dayValue = line2string(datosFiltrados);
	vector<string> sorted = selectionSort(dayValue,datosFiltrados);

	vector<string> divided = divide(sorted);
	/*
	for (int i = 0; i < divided.size(); i++) {
		cout << divided[i];
		}
	*/
  for (int i = 0; i < divided.size(); i++) {
  	outputFile << divided[i];
		}

  inputFile.close();
  outputFile.close();



  return 0;
}
