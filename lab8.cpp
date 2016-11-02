#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;
int getIndex(char c);

class Message{
	private:
		
	public:
		int truthVal;
		int stringSize;
		string message;
		Message();
		Message(string);
		//~Message();
		virtual void print();
};
Message::Message(){
	cout << "hello user, please enter a message\n" << endl;
	cin >> message;
	stringSize = message.length();
	//cout << "Size of the string is "<< stringSize << " bytes\n" << endl;
	truthVal = 0;
	
}
Message::Message(string message1){
	message = message1;
	stringSize = message.length();
	//cout << "Size of the string is "<< stringSize << endl;
	truthVal = 0;
}

class morseMessage : public Message{
	private: 
	public:	
		string* morseMsg;	
		morseMessage();
		~morseMessage();
		void translate(string);
		void print();
};
morseMessage::morseMessage(){
	stringSize = message.length();
	cout << "size of morse string is " << stringSize << endl;
	translate(message);
	truthVal = 1;
}	
morseMessage::~morseMessage(){
	//delete[] morseMessage;
}
class stackMessage{
	public: 
		int numStackElements;;
		Message *stackPtr[10];
		Message *startPtr;
		stackMessage();
		//~stackMessage();
		void pushMsg(Message);
		void pushMsg(morseMessage);
		void popMsg();
		void printStack(stackMessage);
		int i;
};
void stackMessage::printStack(stackMessage msg){
	int j = 0;
	cout << "\n\t\tSTACK\n" << endl;
	while(j < i)
	{
		cout << "Eleement " << j+1 << ":" << endl;
		stackPtr[j]->print();
		j++;
	}
	cout << "\n\n" << endl;
}
stackMessage::stackMessage(){
	i = 0;
	startPtr = NULL;
}
void stackMessage::pushMsg(Message message){//two different pushMsg methods, depends on if it is a regular message or a morse message
	if(startPtr == NULL);
	else{
		startPtr = &message;
	}
	if(numStackElements >= 10) return;
	else{
		stackPtr[i] = new Message(message);
		i++;
	}
}
void stackMessage::pushMsg(morseMessage message){
	if(startPtr == NULL);
	else{
		startPtr = &message;
	}
	if(numStackElements >= 10) return;
	else{
		stackPtr[i] = new morseMessage(message);
		i++;
	}
}
void stackMessage::popMsg(){
	if(i == 0){
		cout << "Theres nothing to pop!" << endl;
		return;
	}
	delete stackPtr[i-1];
	i--;
}
void Message::print(void)
{
	cout << "\tMessage: " << message << endl;
}
void morseMessage::print()
{
	int i =0;
	string* startPtr = morseMsg;
	cout << "\tMessage:" << message << endl;
	cout << "\tMorse Message:" << endl;
	while (i < stringSize){
		cout  << *morseMsg << "\t";
		morseMsg++;
		i++;
	}
	morseMsg = startPtr;
	cout << endl;
} 
int main(void)
{
	//Message msg1;//these tests go fine, i can translate effectively and print it out 
	//msg1.print();
	//Message msg2("test string for Method two");
	//msg2.print();
	//morseMessage msg3;
	//msg3.print();
	cout << "\nOKAY; now we built three different types of classes time to stack shit up" << endl;
	int userInput = 1000;
	int regORmorse;
	int i = 0;
	stackMessage msg4;
	while (userInput != 0)//where the user menu begins
	{
		cout << "What do you want to do?\n0: Exit the program\n1:Push a message onto the stack\n2:POP a message off of the stack\n3: DISPLAY the current stack" << endl;
		cin >> userInput;
		while(userInput < 0 || userInput > 3){
			cout <<"Try that again, user" << endl;
			cin >> userInput;
		}
		switch(userInput)
		{
			case 0:
				return 1;
				break;
			case 1:
				cout << "Regular (1) message or morse message (2)?" << endl;
				cin >> regORmorse;
				if(regORmorse == 1) 
				{	
					Message tempMessage;//trying to make a new message here, and then push it onto the stack, by making the stackpointer point to each of these messages created
					msg4.pushMsg(tempMessage);
				}
				else 
				{
					morseMessage tempMessage;//in case the user wanted to use a morse message
					msg4.pushMsg(tempMessage);
				}
				break;
			case 2:
				msg4.popMsg();
				break;
			case 3: 
				msg4.printStack(msg4);//print stack used to work in a way, however i could only get the first element of the stack into memory
				break;
			default:
				break;
		}
	}
	return 1;
}
void morseMessage::translate(string message1)
{
	morseMsg = new string[stringSize];
	char c;
	int index;
	int i;
	cout << "translating..\n" << endl;
	string* startPtr = morseMsg;
	string letters = "abcdefghijklmnopqrstuvwxyz";
	string morseLetters[26] =  {
	".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",
	".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};	
	for(i=0;i<stringSize;i++)
	{
		c = message[i];
		if(isupper(c)==1) c = tolower(c);//converts to lowercase if it is uppercase
		index = getIndex(c);
		*morseMsg = morseLetters[index];//sets the actual morse string
		//cout << *morseMsg << endl;
		morseMsg++;
		//message++;
	}	
	morseMsg = startPtr;	
}
int getIndex(char c)//function to find the index of the letter 
{
	int index;	
	index = c -97;//subtract 97 because lowercase letters begin at 97 on ASCII table..
	return index;
}

