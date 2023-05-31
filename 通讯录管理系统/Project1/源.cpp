#include <iostream>
#include <string>
#define MAX 1000
using namespace std;


//设计联系人的结构体
struct person {
	//姓名
	string name;
	//性别
	int sex;
	//年龄
	int age;
	//电话
	string phone;
	//住址
	string addr;
};

//通讯录结构体
struct addressbooks {
	//联系人数组
	struct person personarray[MAX];

	//通讯录当前人的个数
	int size = 0;
};

//1、添加联系人
void addperson(addressbooks *abs) {
	//判断通讯录是否已满，如果满了则不再添加
	if (abs->size == MAX) {
		cout << "通讯录已满，无法再添加！" << endl;
		return;
	}
	else {
		//添加联系人
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personarray[abs->size].name = name;
		//性别
		cout << "请输入性别：" << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		int sex = 0;
		
		while (true) {
			//如果输入正确退出循环，输入其他值重新输入
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personarray[abs->size].sex = sex;
				break;
			}
			else {
				cout << "输入有误，请重新输入" << endl;
			}
		}
		
		//年龄
		cout << "请输入年龄" << endl;
		int age = 0;
		cin >> age;
		abs->personarray[abs->size].age = age;

		//电话
		cout << "请输入联系人电话：" << endl;
		string phone;
		cin >> phone;
		abs->personarray[abs->size].phone = phone;

		//住址
		cout << "请输入家庭地址" << endl;
		string address;
		cin >> address;
		abs->personarray[abs->size].addr = address;

		//更新通讯录人数
		abs->size++;
		cout << "添加成功" << endl;
		system("pause");
		system("cls");//清屏操作
	}

}

//2、显示所有联系人
void showperson(addressbooks *abs) {
	//判断通讯录中人数是否为0，如果为0提示记录为空
	//如果不为0，显示记录的联系人信息
	if (abs->size == 0) {
		cout << "当前记录为空" << endl;
	}
	else {
		for (int i = 0; i < abs->size; i++) {
			cout << "姓名：" << abs->personarray[i].name << "\t";
			cout << "性别：" << (abs->personarray[i].sex == 1 ? "男" : "女" ) << "\t";
			cout << "年龄：" << abs->personarray[i].age << "\t";
			cout << "电话：" << abs->personarray[i].phone << "\t";
			cout << "住址：" << abs->personarray[i].addr << endl;
		}
	}

	system("pause");
	system("cls");
}

//检测联系人是否存在，如果存在返回联系人位置，不存在返回-1
//参数1 通讯录 参数2 对比姓名
int isexist(addressbooks *abs,string name) {
	for (int i = 0; i < abs->size; i++) {
		if (abs->personarray[i].name == name) {
			return i;//找到了返回下标i
		}
	}
	return -1;//没有找到返回-1
}

//3、删除联系人
void deleteperson(addressbooks *abs) {
	cout << "请输入您要删除的联系人" << endl;
	string name;
	cin >> name;

	//接受结果 -1未查到否则查到
	int ret = isexist(abs, name);
	if (ret != -1) {
		for (int i = ret; i < abs->size; i++) {
			abs->personarray[i] = abs->personarray[i + 1];//数据前移
		}
		abs->size --;
		cout << "删除成功" << endl;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//4、查找联系人
void findperson(addressbooks *abs) {
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;

	//判断联系人是否在通讯录中
	int ret = isexist(abs, name);

	if (ret != -1) {
		cout << "姓名：" << abs->personarray[ret].name << "\t";
		cout << "性别：" << (abs->personarray[ret].sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << abs->personarray[ret].age << "\t";
		cout << "电话：" << abs->personarray[ret].phone << "\t";
		cout << "住址：" << abs->personarray[ret].addr << endl;
	}
	else {
		cout << "未找到联系人" << endl;
	}
	system("pause");
	system("cls");
}

//5、修改指定联系人信息
void modifyperson(addressbooks *abs) {
	cout << "请输入您要修改的联系人" << endl;
	string name;
	cin >> name;
	int ret = isexist(abs, name);

	if (ret != -1) {
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personarray[ret].name = name;

		//性别
		cout << "请输入性别：" << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		int sex = 0;
		while(true){
		cin >> sex;
		if (sex == 1 || sex == 2) {
			abs->personarray[ret].sex = sex;
			break;
		}
		else {
			cout << "输入有误，请重新输入" << endl;
		}
	}

		//年龄
		cout << "请输入年龄" << endl;
		int age = 0;
		cin >> age;
		abs->personarray[ret].age = age;

		//电话
		cout << "请输入联系人电话：" << endl;
		string phone;
		cin >> phone;
		abs->personarray[ret].phone = phone;

		//地址
		cout << "请输入家庭地址" << endl;
		string address;
		cin >> address;
		abs->personarray[ret].addr = address;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

//6、清空联系人
void cleanperson(addressbooks *abs){
	cout << "您是否真的要清空联系人" << endl;
	cout << "1---确认" << endl;
	cout << "2--返回" << endl;
	int ret;
	cin >> ret;
	while(true){
	if (ret == 1) {
		abs->size = 0;
		cout << "通讯录已经清空" << endl;
		system("pause");
		system("cls");
		return ;
	}else if(ret == 2){
		cout << "已返回" << endl;
		system("pause");
		system("cls");
		return ;
	}else {
		cout << "错误指令，请重新输入：" << endl;
		cin >> ret;
	}
	}
	
}
//显示菜单界面
void showmenu() {
	cout << "***********************" << endl;
	cout << "*****1、添加联系人*****" << endl;
	cout << "*****2、显示联系人*****" << endl;
	cout << "*****3、删除联系人*****" << endl;
	cout << "*****4、查找联系人*****" << endl;
	cout << "*****5、修改联系人*****" << endl;
	cout << "*****6、清空联系人*****" << endl;
	cout << "*****0、退出通讯录*****" << endl;
	cout << "***********************" << endl;
}
int main() {

	//创建通讯录的结构体变量
	addressbooks abs;
	//初始化通讯录中当前人员个数
	abs.size = 0;


	int select = 0;//创建用户选择输入的变量
	//菜单的调用
	while (true) {
		showmenu();
		cin >> select;

		switch (select) {
		case 1://添加联系人
			addperson(&abs);//利用地址传递 修饰实参
			break;
		case 2://显示联系人
			showperson(&abs);
			break;
		case 3://删除联系人
			deleteperson(&abs);
			break;
		case 4://查找联系人
			findperson(&abs);
			break;
		case 5://修改联系人
			modifyperson(&abs);
			break;
		case 6://清空联系人
			cleanperson(&abs);
			break;
		case 0://退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	
}