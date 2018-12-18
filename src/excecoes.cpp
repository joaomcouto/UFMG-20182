#include "excecoes.h"

const char* InvalidCharacterException::what() const noexcept{
  return "Character can't be created, there is some bugs at his constructor!";
}

const char* TimeTurnerException::what() const noexcept {
  return "You cannot go back in time in the first round! Try again";
}


const char* NULL_Pointer_Exception::what() const noexcept {
  return "You're trying to acess a NULL Pointer";
}

const char*  InvalidStringException::what() const noexcept {
  return "You're trying to put invalid characteres!";
}
