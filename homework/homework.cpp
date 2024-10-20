#include <iostream>
#include <vector>
using namespace std;

class Product {
	string name; 
	string description;
	int price; 
	int discount; 
	static int idCounter; 

public:
	
	Product() {
		this->name = "";
		this->description = "";
		this->price = 0;
		this->discount = 0;
		idCounter++; 
	}


	Product(string name, string description, int price, int discount) {
		this->name = name;
		this->description = description;
		this->price = price;
		this->discount = discount;
		idCounter++; 
	}

	string GetName() const{ 
		return name; 
	}
	string GetDescription() const {
		return description;
	}
	int GetPrice() const { 
		return price; 
	}
	int GetDiscount() const {
		return discount; 
	}

	void setName(string name) {
		if (name.length() > 0) {
			this->name = name;
		}
		else {
			cout << "Adi duzgun qeyd edin" << endl;
		}
	}

	void setDescription(string description) { 
		this->description = description; 
	}

	void setPrice(int price) {
		if (price >= 0) {
			this->price = price;
		}
		else {
			cout << "Qiymet menfi ola bilmez" << endl;
		}
	}

	void setDiscount(int discount) { 
		this->discount = discount; 
	}


	void showProduct() const {
		cout << "Adi: " << name << endl;
		cout << "Haqqinda: " << description << endl;
		cout << "Qiymet: " << price << endl;
		cout << "Endirim: " << discount << endl;
	}
};

int Product::idCounter = 0; 

class Stock {
public:
	static void Manager(Product products[], int& count) {
		int choice;
		do {
			cout << "1 - Stoku Goster\n2 - Product yarat\n3 - Product sil\n4 - Product axtar\n5 - Productu deyis\n6 - Cixis\n";
			cin >> choice;

			switch (choice) {
			case 1: {
				cout << "Movcud product:" << endl;
				for (int i = 0; i < count; ++i) {
					products[i].showProduct();
					cout << "-----------------" << endl;
				}
				break;
			}
			case 2: {
				string name, description;
				float price, discount;
				cout << "Ad girin: ";
				cin >> name;
				cout << "Haqqinda daxil edin: ";
				cin >> description;
				cout << "Qiymet daxi edin: ";
				cin >> price;
				cout << "Endirim daxil edin: ";
				cin >> discount;

				products[count++] = Product(name, description, price, discount);
				break;
			}
			case 3: {
				int index;
				cout << "Silinecek productun indexini daxil edin: ";
				cin >> index;
				if (index >= 0 && index < count) {
					for (int i = index; i < count - 1; ++i) {
						products[i] = products[i + 1]; 
					}
					count--; 
					cout << "Product silindi." << endl;
				}
				else {
					cout << " Error" << endl;
				}
				break;
			}
			case 4: {
				string name;
				cout << "Axtarilacaq Product: ";
				cin >> name;
				bool found = false;
				for (int i = 0; i < count; ++i) {
					if (products[i].GetName() == name) {
						products[i].showProduct();
						found = true;
					}
				}
				if (!found) {
					cout << "Product tapilmadi." << endl;
				}
				break;
			}
			case 5: {
				int index;
				cout << "Deyisdirelecek productun indeksini girin: ";
				cin >> index;
				if (index >= 0 && index < count) {
					string name, description;
					float price, discount;
					cout << "Yeni ad girin: ";
					cin >> name;
					cout << "Yeni haqqinda girin: ";
					cin >> description;
					cout << "Yeni qiymet girin: ";
					cin >> price;
					cout << "Yeni endirim girin: ";
					cin >> discount;

					products[index].setName(name);
					products[index].setDescription(description);
					products[index].setPrice(price);
					products[index].setDiscount(discount);
				}
				else {
					cout << "Error" << endl;
				}
				break;
			}
			case 6:
				cout << "Cixildi" << endl;
				break;
			default:
				cout << "Xais olunur duzgun girin" << endl;
			}
		} while (choice != 6);
	}

};

int main() {
	const int MAX_PRODUCTS = 100; 
	Product products[MAX_PRODUCTS];
	int count = 0;
	Stock::Manager(products, count); 
	return 0;
}
