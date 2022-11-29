#include <iostream>
#include <fstream>
#include <string>
using std::string;
using namespace std;

class cart {
private:
	int productId;
	string productName;
	double price;
	double discount;
public:
	void customer();
	void administrator();
	void receipt();
	void items();
	void list();
	void add();
	void edit();
	void rem();
};

void cart::customer() {
main:
	int choice;
	cout << "\n\t\t\t\t\t----------------------\n";
	cout << "\n\t\t\t\t\t    Customer menu   \n\n";
	cout << "\t\t\t\t\t----------------------\n";
	cout << "\t\t\t\t\t1- Add Product to cart\n";
	cout << "\t\t\t\t\t					\n";
	cout << "\t\t\t\t\t2- Main Menu   	\n";
	cout << "\t\t\t\t\t					\n";
	cout << "\n\t\t\t\t	Enter your choice : ";
	cin >> choice;

	if (choice == 1) {
		receipt();
	}
	else {
		items();
	}
	goto main;
}

void cart::administrator() {
main:
	int choice;
	cout << "\n\t\t\t\t\t					   \n";
	cout << "\n\t\t\t\t\t----------------------\n";
	cout << "\n\t\t\t\t\t Administrator menu \n";
	cout << "\n\t\t\t\t\t----------------------\n";
	cout << "\n\t\t\t\t\t1- Add Product\n";
	cout << "\n\t\t\t\t\t2- Edit Product\n";
	cout << "\n\t\t\t\t\t3- Delete Product\n";
	cout << "\n\t\t\t\t\t4- Main Menu\n";
	cout << "\n\t\t\t\t\t----------------------\n";
	cout << "\n\t\t\t\t	Enter your choice : ";
	cin >> choice;
	switch (choice) {
	case 1:
		add();
		break;
	case 2:
		edit();
		break;
	case 3:
		rem();
		break;
	case 4:
		items();
		break;
	default:
		cout << "\n\t\t\t\t Sorry,Invalid selection!";
		break;
	}
	goto main;
}
void cart::receipt() {

	fstream data;

	int arrId[100];
	int arrQty[100];
	int c = 0;
	string choice;
	float amount = 0;
	float dis = 0;
	float total = 0;

	cout << "\n\t\t\t\t\t----------------------\n";
	cout << "\n\t\t\t\t\t       Receipt     \n\n";
	cout << "\t\t\t\t\t----------------------\n";
	
	data.open("Pdata.txt", ios::in);
	if (!data) {
		cout << "Sorry, no data found";
	}
	else {
		data.close();
		list();
		cout << "\t\t\t\t\t								    \n";
		cout << "\t\t\t\t\t_________________________________\n";
		cout << "\t\t\t\t\t								    \n";
		cout << "\t\t\t\t\t  Add your order to the cart  	\n";
		cout << "\t\t\t\t\t_________________________________\n";

		cout << "\n\t\t\t\t\t Enter product number: ";
		cin >> arrId[c];
		cout << "\n\t\t\t\t\t Enter the quantity: ";
		cin >> arrQty[c];

		do {
		main:
			for (int i = 0; i < c; i++) {

				if (arrId[c] == arrId[i]) {

					cout << "\n\n\t\t Please try again, has found duplicate products.\n ";
					goto main;
				}
			}
			c++;
			cout << "\n\n\t\t Do you want to add another product to the cart, if yes press 'y' else press 'n': ";

			cin >> choice;
		
		} 
		
		while (choice == "y");

		cout << "\n\n\t\t\t_______________Receipt_____________";
		cout << "\n\t Product No.\t Product Name \t Quantity\tPrice\tAmount\tAmountWithDiscount";

		for (int i = 0; i < c; i++) {
			data.open("Pdata.txt", ios::in);
			data >> productId >> productName >> price >> discount;
			while (!data.eof())
			{
				if (productId == arrId[i]) {
					amount = price * arrQty[i];
					dis = amount - (amount * discount / 100);
					total = total + dis;
				}
				cout << "\n" << productId << "\t\t" << productName << "\t\t" << arrQty[i] << "\t\t" << price << "\t\t" << dis;
			}
			data >> productId >> productName >> price >> discount;
		}
		data.close();

	}

	cout << "\n\n____________________________________";
	cout << "\n\t Total Amount:" << total << endl;


}
void cart::items() {
main:
	int choice;
	
	// Authentication varblies 
	string userName;
	string passWord;

	//Desgin App Interface 

	cout << "\n\n\t\t\t\t\t_______________________________\n";
	cout << "\t\t\t\t\t							      \n";
	cout << "\t\t\t\t\t    Simple Billing System 	  \n";
	cout << "\t\t\t\t\t							      \n";
	cout << "\t\t\t\t\t       Vegetables Shop 		  \n";
	cout << "\t\t\t\t\t							      \n";
	cout << "\t\t\t\t\t         Developed by  		  \n"; 
	cout << "\t\t\t\t\t       Kahlawy@gmail.com   	  \n";
	cout << "\t\t\t\t\t_______________________________\n";
	cout << "\t\t\t\t\t							      \n";
	cout << "\t\t\t\t\t1- Administrator \n";
	cout << "\t\t\t\t\t					\n";
	cout << "\t\t\t\t\t2- Customer		\n";
	cout << "\t\t\t\t\t					\n";
	cout << "\t\t\t\t\t3- Exit   		\n";
	cout << "\t\t\t\t\t					\n";
	cout << "\n\t\t\t\t	Please select : ";
	cin >> choice;
	// Validation for integer input 
	bool intCheck = (std::numeric_limits<std::streamsize>::is_integer, choice );
	if (intCheck == false)
		exit(0);

		
	switch (choice)
	{
	case 1:
		cout << "\n\t\t\t\t\t Login as administrator \n";
		cout << "\n\t\t\t\t\t Enter username : ";
		cin >> userName;
		cout << "\n\t\t\t\t\t Enter password : ";
		cin >> passWord;
				
		if (userName == "admin" && passWord == "admin") {
			cout << "\n\t\t\t\t\t Welcome : administrator!";
			administrator();
		}
		else {
			cout << "\n\n\t\t\t\t\t Sorry,invalid username or password!\n\n";
		}
		break;
	case 2:
		cout << "\n\n\t\t\t\t\t Welcome : Customer ";
		customer();
		break;
	case 3:
			exit(0);
		break;
	default:
		cout << "\n\n\t\t\t\t\t Sorry,Invalid selection!";
		break;
	}
	goto main;
}
void cart::list() {

	fstream data;
	data.open("Pdata.txt", ios::in);
	cout << "\t\t\t\t\t\n____________________________________________";
	cout <<"\t\t\t\t\t\nID |Product Name \t  |price   |Discount ";
	cout << "\t\t\t\t\t\n____________________________________________\n";
	data >> productId >> productName >> price >> discount;

	while (!data.eof()) {

		cout << productId << "  |" << productName << "\t\t  |" << price << "\t   |" << discount << "\n";
		data >> productId >> productName >> price >> discount;
	}
	data.close();

}
void cart::add() {
main:
	fstream data;
	int Pid;
	int token = 0;
	float Pprice;
	float Pdiscount;
	string Pname;

	cout << "\n\t\t\t\t\t Add new product";
	cout << "\n\t\t\t\t\t Add  product ID: ";
	cin >> productId;
	cout << "\n\t\t\t\t\t Add  product Name: ";
	cin >> productName;
	cout << "\n\t\t\t\t\t Add  Pric: ";
	cin >> price;
	cout << "\n\t\t\t\t\t Add  Discount: ";
	cin >> discount;

	data.open("Pdata.txt", ios::in);
	if (!data) {
		data.open("Pdata.txt", ios::app | ios::out);
		data << productId << "\t" << productName << "\t" << price << "\t" << discount << "\n";
		data.close();
	}
	else {
		data >> Pid >> Pprice >> Pdiscount >> Pname;

		while (!data.eof()) {

			if (Pid == productId) {
				token++;
			}
			data >> Pid >> Pprice >> Pdiscount >> Pname;
		}
		data.close();

		if (token == 1) {
			goto main;
		}
		else {
			data.open("Pdata.txt", ios::app | ios::out);
			data << productId << "\t" << productName << "\t" << price << "\t" << discount << "\n";
			data.close();
		}

	}

	cout << " \n\n\t\t\t\t The record was Added successfully!";
}
void cart::edit() {
	fstream data, data1;
	int Pid=0;
	int token = 0;
	float Pprice=0;
	float Pdiscount=0;
	string Pname;

	cout << "\n\n\t\t\t\t\t Edit new product";
	cout << "\n\n\t\t\t\t\t product ID: ";
	cin >> productId;
	data.open("Pdata.txt", ios::in);
	if (!data) {
		cout << " \n\n\t\t\t\t Sorry, the file doesn't exist!";
	}
	else {
		data1.open("Pdata1.txt", ios::app | ios::out);

		//data >> Pid >> Pprice >> Pdiscount >> Pname;
		data >> productId >> productName >> price >> discount;
		while (!data.eof()) {

			if (Pid == productId) {
				cout << "\n\n\t\t\t\t\t New product ID: ";
				cin >> productId;
				cout << "\n\n\t\t\t\t\t New product Name: ";
				cin >> productName;
				cout << "\n\n\t\t\t\t\t New product price: ";
				cin >> price;
				cout << "\n\n\t\t\t\t\t New product discount: ";
				cin >> discount;
				data1 << "\n" << productId << "\t" << productName << "\t\t" << price << "\t" << discount << "\n";
				cout << "\n\n\t\t\t\t The record was updated successfully!";
				token++;
			}
			else {
				data1 << "\n" << productId << "\t" << productName << "\t\t" << price << "\t" << discount << "\n";
			}
			data >> productId >> productName >> price >> discount;
		}
		data.close();
		data1.close();

		remove("Pdata.txt");
		rename("Pdata1.txt","Pdata.txt");

		if (token == 0) {
			cout << "Sorry, the record not found!";
		}
	}

}
void cart::rem() {

	fstream data, data1;
	int Pid=0;
	int token = 0;


	cout << "\n\n\t\t\t\t\t Delete product";
	cout << "\n\n\t\t\t\t\t product ID: ";
	cin >> productId;

	data.open("Pdata.txt", ios::in);
	if (!data) {
		cout << " \n\n\t\t\t\t Sorry, the file doesn't exist!";
	}
	else {
		data1.open("Pdata1.txt", ios::app | ios::out);

		//data >> Pid >> Pprice >> Pdiscount >> Pname;
		data >> productId >> productName >> price >> discount;
		while (!data.eof()) {

			if (Pid == productId) {
				cout << " \n\n\t\t\t\t The record was deleted successfully!";
				token++;
			}
			else {
				data1 << "\t" << productId << "\t" << productName << "\t" << price << "\t" << discount << "\n";
			}
			data >> productId >> productName >> price >> discount;
		}
		data.close();
		data1.close();

		remove("Pdata.txt");
		rename("Pdata1.txt","Pdata.txt");

		if (token == 0) {
			cout << "Sorry, the record not found!";
		}
	}
}

int main()
{
	cart cart;
	cart.items();

	return 0;
}