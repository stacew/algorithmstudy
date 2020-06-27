#include<iostream>
using namespace std;

class Brain {
private:
	bool m_bMemory;
public:
	void Copy(Brain& a_rBrain) {
		m_bMemory = a_rBrain.m_bMemory;
		cout << "Copy Brain " << endl;
	}
};
class Person {
private:
	Brain m_oBrain;
	string m_strName;
public:
	Person(string a_strName) {
		m_strName = a_strName;
	}
	void Copy(Person& a_rPerson) {
		m_strName = a_rPerson.m_strName;
		m_oBrain.Copy(a_rPerson.m_oBrain);
	}
	void PrintName() {
		cout << m_strName << endl;
	}
};
void SwapPersonRef3(Person& a_r1, Person& a_r2) {
	Person temp("temp");
	temp.Copy(a_r1);
	a_r1.Copy(a_r2);
	a_r2.Copy(temp);
}
void SwapPersonPointer3(Person* a_p1, Person* a_p2) {
	Person temp("temp");
	temp.Copy(*a_p1);
	a_p1->Copy(*a_p2);
	a_p2->Copy(temp);
}

//Undo Sheet ����
void SwapPersonDoublePointer2(Person** a_p1, Person** a_p2) {
	Person* pTemp = new Person("temp");
	pTemp->Copy(**a_p1);//pTemp�� ���� ��Ʈ
	(*a_p1)->Copy(**a_p2);//���� ��Ʈ�� Undo�� ����� ��Ʈ
	delete(*a_p2);
	*a_p2 = pTemp;//Undo�� ����� ��Ʈ�� ���� ��Ʈ ������
}
void SwapPersonPointerRef2(Person*& a_p1, Person*& a_p2) {
	Person* pTemp = new Person("temp");
	pTemp->Copy(*a_p1);
	a_p1->Copy(*a_p2);
	delete(a_p2);
	a_p2 = pTemp;
}

int main() {
#if 1
	Person oMe("My Name Is Owen");
	Person oYou("My Name Is Another");
	oMe.PrintName(); // My Name Is Owen ���
	oYou.PrintName(); // My Name Is Another ���
	SwapPersonRef3(oMe, oYou); // Copy Brain 3ȸ ���
	oMe.PrintName(); // My Name Is Another ���
	oYou.PrintName(); // My Name Is Owen ���
#endif
	cout << endl;
#if 1
	Person* pMe1 = new Person("My Name Is Owen");
	Person* pYou1 = new Person("My Name Is Another");
	pMe1->PrintName(); // My Name Is Owen ���
	pYou1->PrintName(); // My Name Is Another ���

	//SwapPersonPointer3(pMe1, pYou1);// Copy Brain 3ȸ ���

	//LocalSwapPersonPoint3 // Copy Brain 3ȸ ���
	Person* pTemp1 = new Person("temp");
	pTemp1->Copy(*pMe1);//pTemp�� ���� ��Ʈ
	pMe1->Copy(*pYou1);//���� ��Ʈ�� Undo�� ����� ��Ʈ
	pYou1->Copy(*pTemp1);
	delete pTemp1;

	pMe1->PrintName(); // My Name Is Another ���
	pYou1->PrintName(); // My Name Is Owen ���
	delete pYou1;
	delete pMe1;	
#endif
	cout << endl;
#if 1
	Person* pMe2 = new Person("My Name Is Owen");
	Person* pYou2 = new Person("My Name Is Another");
	pMe2->PrintName(); // My Name Is Another ���
	pYou2->PrintName(); // My Name Is Owen ���

	//SwapPersonDoublePointer2(&pMe2, &pYou2);// Copy Brain 2ȸ ���

	//SwapPersonPointerRef2(pMe2, pYou2);// Copy Brain 2ȸ ���

	//LocalSwapPeronPointer2 // Copy Brain 2ȸ ���
	Person* pTemp2 = new Person("temp");
	pTemp2->Copy(*pMe2);
	pMe2->Copy(*pYou2);
	delete(pYou2);
	pYou2 = pTemp2;

	pMe2->PrintName(); // My Name Is Another ���
	pYou2->PrintName(); // My Name Is Owen ���
	delete pYou2;
	delete pMe2;	
#endif
	return 0;
}