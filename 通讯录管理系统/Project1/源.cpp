#include <iostream>
#include <string>
#define MAX 1000
using namespace std;


//�����ϵ�˵Ľṹ��
struct person {
	//����
	string name;
	//�Ա�
	int sex;
	//����
	int age;
	//�绰
	string phone;
	//סַ
	string addr;
};

//ͨѶ¼�ṹ��
struct addressbooks {
	//��ϵ������
	struct person personarray[MAX];

	//ͨѶ¼��ǰ�˵ĸ���
	int size = 0;
};

//1�������ϵ��
void addperson(addressbooks *abs) {
	//�ж�ͨѶ¼�Ƿ���������������������
	if (abs->size == MAX) {
		cout << "ͨѶ¼�������޷�����ӣ�" << endl;
		return;
	}
	else {
		//�����ϵ��
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personarray[abs->size].name = name;
		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		int sex = 0;
		
		while (true) {
			//���������ȷ�˳�ѭ������������ֵ��������
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personarray[abs->size].sex = sex;
				break;
			}
			else {
				cout << "������������������" << endl;
			}
		}
		
		//����
		cout << "����������" << endl;
		int age = 0;
		cin >> age;
		abs->personarray[abs->size].age = age;

		//�绰
		cout << "��������ϵ�˵绰��" << endl;
		string phone;
		cin >> phone;
		abs->personarray[abs->size].phone = phone;

		//סַ
		cout << "�������ͥ��ַ" << endl;
		string address;
		cin >> address;
		abs->personarray[abs->size].addr = address;

		//����ͨѶ¼����
		abs->size++;
		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls");//��������
	}

}

//2����ʾ������ϵ��
void showperson(addressbooks *abs) {
	//�ж�ͨѶ¼�������Ƿ�Ϊ0�����Ϊ0��ʾ��¼Ϊ��
	//�����Ϊ0����ʾ��¼����ϵ����Ϣ
	if (abs->size == 0) {
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < abs->size; i++) {
			cout << "������" << abs->personarray[i].name << "\t";
			cout << "�Ա�" << (abs->personarray[i].sex == 1 ? "��" : "Ů" ) << "\t";
			cout << "���䣺" << abs->personarray[i].age << "\t";
			cout << "�绰��" << abs->personarray[i].phone << "\t";
			cout << "סַ��" << abs->personarray[i].addr << endl;
		}
	}

	system("pause");
	system("cls");
}

//�����ϵ���Ƿ���ڣ�������ڷ�����ϵ��λ�ã������ڷ���-1
//����1 ͨѶ¼ ����2 �Ա�����
int isexist(addressbooks *abs,string name) {
	for (int i = 0; i < abs->size; i++) {
		if (abs->personarray[i].name == name) {
			return i;//�ҵ��˷����±�i
		}
	}
	return -1;//û���ҵ�����-1
}

//3��ɾ����ϵ��
void deleteperson(addressbooks *abs) {
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;

	//���ܽ�� -1δ�鵽����鵽
	int ret = isexist(abs, name);
	if (ret != -1) {
		for (int i = ret; i < abs->size; i++) {
			abs->personarray[i] = abs->personarray[i + 1];//����ǰ��
		}
		abs->size --;
		cout << "ɾ���ɹ�" << endl;
	}
	else {
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//4��������ϵ��
void findperson(addressbooks *abs) {
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;

	//�ж���ϵ���Ƿ���ͨѶ¼��
	int ret = isexist(abs, name);

	if (ret != -1) {
		cout << "������" << abs->personarray[ret].name << "\t";
		cout << "�Ա�" << (abs->personarray[ret].sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << abs->personarray[ret].age << "\t";
		cout << "�绰��" << abs->personarray[ret].phone << "\t";
		cout << "סַ��" << abs->personarray[ret].addr << endl;
	}
	else {
		cout << "δ�ҵ���ϵ��" << endl;
	}
	system("pause");
	system("cls");
}

//5���޸�ָ����ϵ����Ϣ
void modifyperson(addressbooks *abs) {
	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isexist(abs, name);

	if (ret != -1) {
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personarray[ret].name = name;

		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		int sex = 0;
		while(true){
		cin >> sex;
		if (sex == 1 || sex == 2) {
			abs->personarray[ret].sex = sex;
			break;
		}
		else {
			cout << "������������������" << endl;
		}
	}

		//����
		cout << "����������" << endl;
		int age = 0;
		cin >> age;
		abs->personarray[ret].age = age;

		//�绰
		cout << "��������ϵ�˵绰��" << endl;
		string phone;
		cin >> phone;
		abs->personarray[ret].phone = phone;

		//��ַ
		cout << "�������ͥ��ַ" << endl;
		string address;
		cin >> address;
		abs->personarray[ret].addr = address;
	}
	else {
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

//6�������ϵ��
void cleanperson(addressbooks *abs){
	cout << "���Ƿ����Ҫ�����ϵ��" << endl;
	cout << "1---ȷ��" << endl;
	cout << "2--����" << endl;
	int ret;
	cin >> ret;
	while(true){
	if (ret == 1) {
		abs->size = 0;
		cout << "ͨѶ¼�Ѿ����" << endl;
		system("pause");
		system("cls");
		return ;
	}else if(ret == 2){
		cout << "�ѷ���" << endl;
		system("pause");
		system("cls");
		return ;
	}else {
		cout << "����ָ����������룺" << endl;
		cin >> ret;
	}
	}
	
}
//��ʾ�˵�����
void showmenu() {
	cout << "***********************" << endl;
	cout << "*****1�������ϵ��*****" << endl;
	cout << "*****2����ʾ��ϵ��*****" << endl;
	cout << "*****3��ɾ����ϵ��*****" << endl;
	cout << "*****4��������ϵ��*****" << endl;
	cout << "*****5���޸���ϵ��*****" << endl;
	cout << "*****6�������ϵ��*****" << endl;
	cout << "*****0���˳�ͨѶ¼*****" << endl;
	cout << "***********************" << endl;
}
int main() {

	//����ͨѶ¼�Ľṹ�����
	addressbooks abs;
	//��ʼ��ͨѶ¼�е�ǰ��Ա����
	abs.size = 0;


	int select = 0;//�����û�ѡ������ı���
	//�˵��ĵ���
	while (true) {
		showmenu();
		cin >> select;

		switch (select) {
		case 1://�����ϵ��
			addperson(&abs);//���õ�ַ���� ����ʵ��
			break;
		case 2://��ʾ��ϵ��
			showperson(&abs);
			break;
		case 3://ɾ����ϵ��
			deleteperson(&abs);
			break;
		case 4://������ϵ��
			findperson(&abs);
			break;
		case 5://�޸���ϵ��
			modifyperson(&abs);
			break;
		case 6://�����ϵ��
			cleanperson(&abs);
			break;
		case 0://�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	
}