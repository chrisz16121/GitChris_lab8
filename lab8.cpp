#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

class Message{
	private:
		int stringSize;
	public:
		//static string letters = "abcdefghijklmnopqrstuvwxyz";
		//string morseLetters[26] =  {
		//			".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",
		//			".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."
		//			};
		string message;
		Message();
		Message(string);
	//	~Message();
		virtual void print();
};
Message::Message(){
	cout << "hello user, please enter a message\n" << endl;
	cin >> message;
	stringSize = message.length();
	cout << "Size of the string is "<< stringSize << " bytes\n" << endl;
	
}
Message::Message(string message1){
	message = message1;
	stringSize = message.length();
	cout << "Size of the string is "<< message.length() << " bytes\n" << endl;
}
//Message::~Message(){
//	delete message[];	
//}

class morseMessage : public Message{
	private: 
	public:	
		string  *morseMsg;	
		morseMessage();
		//~morseMessage();
		void translate();
		void print();
};
//morseMessage::morseMessage(){
	
//class stackMessage : public Message{
//	public: 
//		Message *stackPtr[10];
//		stackMessage();
//		~stackMessage();
//		void printStack();
//}
		 

void Message::print(void)
{
	cout << "Message: " << message << endl;
}
void morseMessage::print()
{
	cout << "Message:\n" << message << endl;
	cout << "Morse Message:\n" << morseMsg << endl;
} 
int main(void)
{
	Message msg1;
	msg1.print();
	Message msg2("test string for Method two");
	msg2.print();
	return 1;
}

