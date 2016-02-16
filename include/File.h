#ifndef TEST_FILE_H_
#define TEST_FILE_H_

class File{

  public:
    bool isDirectory();
    int size();
    bool close();
    char* name();
    File openNextFile(uint8_t);
    void rewindDirectory();
    operator bool();


};


#endif // TEST_FILE_H_