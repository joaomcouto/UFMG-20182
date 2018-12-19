#include <iomanip>
#include <iostream>
#include <string>
#include <map>
#include <sstream>
using namespace std ;

int main(){
    
    std::cout.precision(2);
    string linha;
    string palavra ;
    
    std::map<std::string, int> m ;
    int numpalavras = 0 ;
    
    while (getline(std::cin, linha)) {
      std::istringstream linha_stream(linha);
      while (getline(linha_stream, palavra, ' ')) {
        numpalavras++ ;
        m[palavra]++ ;
      }
    }
   std::map<string,int>::iterator it;
    for (it = m.begin(); it != m.end(); it++) {
       cout << it->first << " "<< it->second << " " << (float)(it->second)/numpalavras << endl;
    }
}

