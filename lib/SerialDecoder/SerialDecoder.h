#ifndef SerialDecoder_H
#define SerialDecoder_H

#include <arduino.h>


class SerialDecoder {

  private:
    static int const bufferDelay = 300;
    int bautrate;

  public:
    SerialDecoder(int bautrate);
    void open();
    void readCommand();

};

#endif
