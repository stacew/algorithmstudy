#include <iostream>
using namespace std;

class Brain
{
private:
	bool m_bMemory;

public:
	void Copy(Brain &a_rBrain)
	{
		m_bMemory = a_rBrain.m_bMemory;
		cout << "Copy Brain " << endl;
	}
};
class Person
{
private:
	Brain m_oBrain;
	string m_strName;

public:
	Person(string a_strName)
	{
		m_strName = a_strName;
	}
	void Copy(Person &a_rPerson)
	{
		m_strName = a_rPerson.m_strName;
		m_oBrain.Copy(a_rPerson.m_oBrain);
	}
	void PrintName()
	{
		cout << m_strName << endl;
	}
};
void SwapPersonRef3(Person &a_r1, Person &a_r2)
{
	Person temp("temp");
	temp.Copy(a_r1);
	a_r1.Copy(a_r2);
	a_r2.Copy(temp);
}
void SwapPersonPointer3(Person *a_p1, Person *a_p2)
{
	Person temp("temp");
	temp.Copy(*a_p1);
	a_p1->Copy(*a_p2);
	a_p2->Copy(temp);
}

void SwapPersonDoublePointer2(Person **a_p1, Person **a_p2)
{
	Person *pTemp = new Person("temp");
	pTemp->Copy(**a_p1);
	(*a_p1)->Copy(**a_p2);
	delete (*a_p2);
	*a_p2 = pTemp;
}
void SwapPersonPointerRef2(Person *&a_p1, Person *&a_p2)
{
	Person *pTemp = new Person("temp");
	pTemp->Copy(*a_p1);
	a_p1->Copy(*a_p2);
	delete (a_p2);
	a_p2 = pTemp;
}

int main()
{
#if 1 //변경 불가
	Person oMe("My Name Is Owen");
	Person oYou("My Name Is Another");
	oMe.PrintName();		   // My Name Is Owen 출력
	oYou.PrintName();		   // My Name Is Another 출력
	SwapPersonRef3(oMe, oYou); // Copy Brain 3회 출력
	oMe.PrintName();		   // My Name Is Another 출력
	oYou.PrintName();		   // My Name Is Owen 출력
#endif
	cout << "--------------" << endl;
#if 1 //2번 가능한데, 3번 호출
	Person *pMe1 = new Person("My Name Is Owen");
	Person *pYou1 = new Person("My Name Is Another");
	pMe1->PrintName();	// My Name Is Owen 출력
	pYou1->PrintName(); // My Name Is Another 출력

	//SwapPersonPointer3(pMe1, pYou1);// Copy Brain 3회 출력

	//LocalSwapPersonPoint3 // Copy Brain 3회 출력
	Person *pTemp1 = new Person("temp");
	pTemp1->Copy(*pMe1); //pTemp에 현재 시트
	pMe1->Copy(*pYou1);	 //현재 시트에 Undo에 저장된 시트
	pYou1->Copy(*pTemp1);
	delete pTemp1;

	pMe1->PrintName();	// My Name Is Another 출력
	pYou1->PrintName(); // My Name Is Owen 출력
	delete pYou1;
	delete pMe1;
#endif
	cout << "--------------" << endl;
#if 1 //2번 호출
	Person *pMe2 = new Person("My Name Is Owen");
	Person *pYou2 = new Person("My Name Is Another");
	pMe2->PrintName();	// My Name Is Another 출력
	pYou2->PrintName(); // My Name Is Owen 출력

	//SwapPersonDoublePointer2(&pMe2, &pYou2);// Copy Brain 2회 출력

	//SwapPersonPointerRef2(pMe2, pYou2);// Copy Brain 2회 출력

	//LocalSwapPeronPointer2 // Copy Brain 2회 출력
	Person *pTemp2 = new Person("temp");
	pTemp2->Copy(*pMe2);
	pMe2->Copy(*pYou2);
	delete (pYou2);
	pYou2 = pTemp2;

	pMe2->PrintName();	// My Name Is Another 출력
	pYou2->PrintName(); // My Name Is Owen 출력
	delete pYou2;
	delete pMe2;
#endif
	cout << "--------------" << endl;
#if 1 //0 번 호출
	Person *pMe3 = new Person("My Name Is Owen");
	Person *pYou3 = new Person("My Name Is Another");
	pMe3->PrintName();	// My Name Is Another 출력
	pYou3->PrintName(); // My Name Is Owen 출력

	Person *pTemp3 = pMe3;
	pMe3 = pYou3;
	pYou3 = pTemp3;

	pMe3->PrintName();	// My Name Is Another 출력
	pYou3->PrintName(); // My Name Is Owen 출력
	delete pYou3;
	delete pMe3;
#endif
	//이 예제에서 0번 호출이 가능한데
	//3번 -> 2번 호출에 대해서 설명하는 이유는 Copy 작업이 복잡할 경우.
	//tempSheet = new sheet();
	//tempSheet = copyRange(processSheet, undoRange);
	//processSheet = copyRange(undoSheet, undoRange);
	//delete undoSheet;
	//undoSheet = tempSheet;
	return 0;
}