#include "topic.h"
#include <iostream>
#include <vector>

using namespace std;

void Guess(vector<char>& abcd, int times)
{
	cout << endl << "Guess 4 letter" << endl << endl;

	if (times == 0)
	{
		cout << "ex:A(enter)"    << endl 
			 << "   B(enter)"    << endl 
			 << "   C(enter)"    << endl 
			 << "   D(enter)"    << endl
			 << ":";
	}

	char letter;
	for (int i = 0; i < 4; ++i)
	{
		cin >> letter;
		abcd.push_back(letter);
	}
}

int findB(vector<char> abcd, vector<Topic> topic, vector<char>& B)
{
	for (int i = 0; i < 4; ++i)
	for (int j = 0; j < 4; ++j)
	{
		if (abcd[i] == topic[j].getTopic() && !topic[j].IsRepet())
		{
			B.push_back(topic[j].getTopic());
			topic[j].Repet();
			break;
		}
	}

	return B.size();
}

int findA(vector<char> abcd, vector<Topic> topic, vector<char>& A)
{
	for (int i = 0; i < 4; ++i)
		if (abcd[i] == topic[i].getTopic() && !topic[i].IsRepet())
		{
			A.push_back(topic[i].getTopic());
			topic[i].Repet();
		}

	return A.size();
}

void InitTopic(vector<Topic>& topic, const char* argv)
{
	//cout << "answer is:" << *argv[1] << endl;
	Topic oneLetter;
	for (int i = 0; i < 4; ++i)
	{
		oneLetter.setTopic(argv[i]);
		topic.push_back(oneLetter);
		oneLetter.clear();
	}
}

int Result(int A, int B)
{
	int isAgain;
	cout << A << "A" << B-A << "B" << endl;
	cout << endl;

	if (A == 4 && B-A == 0)
	{
		cout << "Congratulation!! you are right" << endl;
		return 3;  //game over
	}
	else
	{
		do
		{
			cout << "is Continue?? (OK = 1, NO = 0):";
			cin >> isAgain;
		}while(isAgain != 0 && isAgain != 1);
		//}while((isAgain != 0 && isAgain) != 1); //原本有一個括號忘記拿掉了
		return isAgain;
	}
}

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		cout << "error: the number of topic is not right" << endl;
		cout << endl << "\tright format: main <topic>" << endl;
		cout << "\tex: main aabc" << "\t (aabc is topic)" << endl;
		return 0;
	}

	vector<Topic> topic;
	InitTopic(topic, argv[1]);
	
	
	vector<char> abcd;
	vector<char> B, A;
	int times = 0;
	
	do
	{
		abcd.clear();
		B.clear();
		A.clear();

		Guess(abcd, times);
		findB(abcd, topic, B);
		findA(abcd, topic, A);
		times++;
	}
	while(Result(A.size(), B.size()) == 1);
	
	topic.clear();

	return 0;
}