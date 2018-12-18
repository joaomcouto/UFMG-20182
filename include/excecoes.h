#ifndef PDS2_EXCECOES_H
#define PDS2_EXCECOES_H

#include <stdexcept>

class InvalidCharacterException : public std::exception{
 public:
  virtual const char* what() const noexcept override;
};

class TimeTurnerException : public std::exception{
  public:
    virtual const char* what() const noexcept override;
};


class NULL_Pointer_Exception : public std::exception{
  public:
    virtual const char* what() const noexcept override;
};

class InvalidStringException : public std::exception{
  public:
    virtual const char* what() const noexcept override;
};

#endif
