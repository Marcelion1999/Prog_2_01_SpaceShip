#include <iostream>

using namespace std;

class Spaceship
{
public:

	int length;
	int crew_number;
	int speed;
	bool ftl; //faster than light

	void list() 
	{
		cout << length <<" " << crew_number << " " << speed << " " << ftl <<endl;
	}
	Spaceship(int a, int b, int c, bool d)
	{
		this->length= a;
		this->crew_number = b;
		this->speed = c;
		this->ftl = d;
	}
	~Spaceship()
	{

	}
private:

};

void Crew(Spaceship array[], int a, int number)
{
	
	int k = 0;
	for (int i = 0; i < number; i++)
	{
		if (array[i].crew_number > 100)
		{
			k++;
		}
	}
	cout << k << " ships can carry more than " << a <<endl;

}

Spaceship* store(int number) 
{
	Spaceship* ptr;
	ptr = (Spaceship*)malloc(number * sizeof(Spaceship));
	return ptr;
}
Spaceship* FasterThanLight(Spaceship array[], bool _ftl)
{
	Spaceship* ptr = store(1);
	int min = array[0].speed; 
	int space = 0;
	for (int i = 0; i < array->length; i++)
	{
		if (_ftl == true)
		{
			if (array[i].ftl == true)
			{
				if (array[i].speed < min)
				{
					min = array[i].speed;
					space = i;
				}
			}
		}
	}
	*ptr = array[space];
	return ptr;
}
static int spaceships = 0;
int main()
{
	cout << "Task I:" << endl;
	cout << "Give me the number of spaceships, you want to store: !\n";
	int number = 0;
	cin >> number;
	Spaceship* array = store(number);
	int a, b, c; bool d;
	cout << "Task II:";
	for (int i = 0; i < number; i++)
	{
		cout << "\nLength: ";
		cin >> a;
		cout << "\nCrew Number: ";
		cin >> b;
		cout << "\nSpeed: ";
		cin >> c;
		cout << "\nFaster than Light ? (0/1): ";
		cin >> d;
		Spaceship data = Spaceship(a, b, c, d);
		array[i] = data;
	}
	cout << "Task III:" <<endl;
	for (int i = 0; i < number; i++)
	{
		cout << i;
		array[i].list();
	}
	cout << "Task IV:\nGive me a number:\n";
	int asd = 0;
	cin >> asd;
	Crew(array,asd,number);

	bool ftl = false;
	cout << "Task V:\n Faster than Ligth (0/1):";
	cin >> ftl;
	Spaceship* current = FasterThanLight(array, ftl);
	cout << "The Slowest Ship : \n";
	cout << "\nLength: " << current->length << "\nSpeed: " << current->speed << "\nCrew Number: " << current->crew_number << "\nFaster than Light:" << current->ftl;
	return 0;
}