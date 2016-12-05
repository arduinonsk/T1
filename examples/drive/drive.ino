// подключаем библиотеку
#include <t1.h>

// создаем объект класса Т1 и называем его telega
T1 telega = T1();

void setup(){ 
	// пока не нажата кнопка - стоим тупим, 
	// ничего не делаем.
	// (восклицательный знак - это логическая инверсия )
	while(!telega.buttonPressed()); 
} 

void loop(){
	// едем вперед обоими моторами
	// на максимальной скорости в течение 1 секунды
	telega.drive(255,255);
	delay(1000); 
	// едем назад обоими моторами
	// на половинной скорости в течение 2 секунд
	telega.drive(-127,-127);
	delay(2000); 
	// крутимся влево в течение 1 секунды
	telega.drive(-200,200);
	delay(1000); 
	// крутимся вправо в течение 1 секунды
	telega.drive(200,-200);
	delay(1000); 
}