// подключаем библиотеку
#include <t1.h>

// создаем объект класса Т1 и называем его telega
T1 telega = T1();

void setup(){ 
	// стартуем последовательное соединение с ПК 
	// на скорости 19200
	Serial.begin(19200); 
} 

void loop(){
	// читаем значение с левого сенсора и печатаем
	// без переноса строки
	Serial.print("Left = "); 
	Serial.print(telega.readSensorL()); 
	// читаем значение с правого сенсора и печатаем
	// без переноса строки
	Serial.print(" Right = "); 
	Serial.print(telega.readSensorR()); 
	// читаем значение с сонара и печатаем
	// с переносом строки
	Serial.print(" RF = "); 
	Serial.println(telega.readSonar()); 
	// задержка 100 миллисекунд
	delay(100);
}