
#include<iostream>
#include<signal.h>
#include<unistd.h>
class Signal
{
public :
	//CTRL + C
	void sigintHandler();
	//CTRL + Z
	void sigstpHandler();


};

