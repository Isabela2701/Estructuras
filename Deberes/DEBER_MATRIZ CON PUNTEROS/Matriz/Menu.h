/***********************************************************************
 * Module:  Menu.h
 * Author:  danys
 * Modified: jueves, 8 de mayo de 2025 19:14:57
 * Purpose: Declaration of the class Menu
 ***********************************************************************/

#if !defined(__Programa_Matriz_Menu_h)
#define __Programa_Matriz_Menu_h

class Menu {
public:
  int getFilas(void);
  void setFilas(int newFilas);
  int getColumnas(void);
  void setColumnas(int newColumnas);
  Menu();
  ~Menu();
  int getFlag(void);
  void setFlag(int newFlag);
  void setFlag();
  void setDim(char *string);

protected:
private:
  int filas;
  int columnas;
  int flag;
};

#endif
