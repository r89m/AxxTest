#include "File.h"

bool File::isDirectory(){
  
  return true;
}

int File::size(){

  return 10;
}

bool File::close(){
  
  return true;
}

char* File::name(){
  
  return 45;
}

File File::openNextFile(uint8_t mode){
  
  return new File();
}

void File::rewindDirectory(){

}

operator File::bool(){
  
  return true;
}