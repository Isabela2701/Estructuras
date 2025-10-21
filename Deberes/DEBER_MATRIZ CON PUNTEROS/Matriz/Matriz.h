/***********************************************************************
 * Module:  Matriz.h
 * Author:  danys
 * Modified: s�bado, 10 de mayo de 2025 17:11:39
 * Purpose: Declaration of the class Matriz
 ***********************************************************************/

#if !defined(__Programa_Matriz_Matriz_h)
#define __Programa_Matriz_Matriz_h

class Matriz {
public:
  int getFilas(void);
  void setFilas(int newFilas);
  int getColumnas(void);
  void setColumnas(int newColumnas);
  char **getMatrizChar(void);
  void setMatrizChar(char **newMatrizChar);
  double **getMatrizDouble(void);
  void setMatrizDouble(double **newMatrizDouble);
  Matriz(int deFilas, int defColumnas, int flag); /*CONSTRUCTOR*/
  void setValues(int flag, char *string); /*TIPO DE MATRIZ*/
  void imprimirMatriz(int flag, char *string); /*IMPRIMIR DATOS*/
  ~Matriz(); /*DESTRUCTOR*/

protected:
private:
  int filas;
  int columnas;
  char **matrizChar;
  double **matrizDouble;
};

#endif
