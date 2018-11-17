#include "excecoes.h"

const char* InvalidCharacterException::what() const noexcept{
  return "Character can't be created, there is some bugs at his constructor!";
}
