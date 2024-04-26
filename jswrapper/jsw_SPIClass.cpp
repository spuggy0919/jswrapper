//C++ wrapper auto generator jswmgen.js ver.0.9.0
//https://github.com/spuggy0919/jswrapper.git
//**WARNING**You should examine and fix the code to meet your requirements!
//Wed Apr 17 2024 23:20:49 GMT+0800
//Json:./json/SPIClass.json
//File:./jswrapper/jsw_SPIClass.cpp
//className:SPIClass
//classObj:spiclass
//constructorPrototype:SPIClass::SPIClass(uint8_t spi_bus)
//prototypesArray:
//   void begin(int8_t sck, int8_t miso, int8_t mosi, int8_t ss)
//   void end()
//   void setHwCs(bool use)
//   void setBitOrder(uint8_t bitOrder)
//   void setDataMode(uint8_t dataMode)
//   void setFrequency(uint32_t freq)
//   void setClockDivider(uint32_t clockDiv)
//   uint32_t getClockDivider()
//   void beginTransaction(uint32_t clock, uint8_t bitOrder, uint8_t dataMode)
//   void endTransaction()
//   void transfer(void* data, uint32_t size)
//   uint8_t transfer(uint8_t data)
//   uint16_t transfer16(uint16_t data)
//   uint32_t transfer32(uint32_t data)
//   void transferBytes(uint8_t* data, uint8_t* out, uint32_t size)
//   void transferBits(uint32_t data, uint32_t* out, uint8_t bits)
//   void write(uint8_t data)
//   void write16(uint16_t data)
//   void write32(uint32_t data)
//   void writeBytes(uint8_t* data, uint32_t size)
//   void writePixels(void* data, uint32_t size)
//   void writePattern(uint8_t* data, uint8_t size, uint32_t repeat)
//   spi_t* bus() 
//   int8_t pinSS() 
