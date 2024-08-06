#include <iostream>
#include<iomanip>
#include<string>
#include<string.h>
#include<windows.h>
#include<fstream>
using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
double cost_goods(), total_cost, revenue, cost_of_goods, gross_profit, software_maintenance, total_expenses, earnings_bf_tax, tax, net_earnings, salaries, earn_being_taxed, cost = 0 /*global variable*/;
int getIntegerInput(), no_worker;
const int MAX_ITEMS = 100; /*Maximum number of items in inventory*/
const char fruitFile[] = "fruit_inventory.txt" /* Name of file to store inventory*/; const char inGoods[] = "CostGoods.txt"/* Name of file to store the cost of goods and num of stock*/;
const int MAX_ORDER = 100; // Maximum number of order item
struct fruitItem {
	char name[100];
	double price;
	double quantity;
};
struct costItem {
	char name[100];
	double cost;
	double stock;
};

void mainHeader() { //AURORA FRUIT STALL
	SetConsoleTextAttribute(h, 14);
	cout << "        .d8b.  db    db d8888b.  .d88b.  d8888b.  .d8b.  d88888b d8888b. db    db d888888b d888888b .d8888. d888888b  .d8b.  db      db  " << endl;SetConsoleTextAttribute(h, 6);
	cout << "       d8' `8b 88    88 88  `8D .8P  Y8. 88  `8D d8' `8b 88'     88  `8D 88    88   `88'   `~~88~~' 88'  YP `~~88~~' d8' `8b 88      88  " << endl;SetConsoleTextAttribute(h, 12);
	cout << "       88ooo88 88    88 88oobY' 88    88 88oobY' 88ooo88 88ooo   88oobY' 88    88    88       88    `8bo.      88    88ooo88 88      88   " << endl;SetConsoleTextAttribute(h, 10);
	cout << "       88~~~88 88    88 88`8b   88    88 88`8b   88~~~88 88~~~   88`8b   88    88    88       88      `Y8b.    88    88~~~88 88      88    " << endl;SetConsoleTextAttribute(h, 11);
	cout << "       88   88 88b  d88 88 `88. `8b  d8' 88 `88. 88   88 88      88 `88. 88b  d88   .88.      88    db   8D    88    88   88 88booo. 88booo." << endl;
	cout << "       YP   YP ~Y8888P' 88   YD  `Y88P'  88   YD YP   YP YP      88   YD ~Y8888P' Y888888P    YP    `8888Y'    YP    YP   YP Y88888P Y88888P " << endl;
	SetConsoleTextAttribute(h, 7);
}
void saleHeader() {
	SetConsoleTextAttribute(h, 6);
	cout << string(2, ' ') << string(6, char(178)) << string(2, ' ') << string(6, char(178)) << string(2, ' ') << string(2, char(178)) << string(6, ' ') << string(6, char(178));
	cout << string(2, ' ') << string(10, char(178)) << string(2, ' ') << string(6, char(178)) << string(2, ' ') << string(6, char(178)) << string(2, char(220)) << string(2, ' ') << string(2, char(178)) << string(4, ' ') << string(2, char(178)) << string(2, ' ') << string(2, char(178)) << string(6, ' ') << string(6, char(178)) << string(1, ' ') << endl;
	cout << string(2, ' ') << string(2, char(178)) << string(6, ' ') << string(2, char(178)) << string(2, ' ') << string(2, char(178)) << string(2, ' ') << string(2, char(178)) << string(6, ' ') << string(2, char(178)) << string(4, ' ');
	cout << string(2, ' ') << string(2, char(178)) << string(2, ' ') << string(2, char(178)) << string(2, ' ') << string(2, char(178)) << string(2, ' ') << string(2, char(178)) << string(2, ' ') << string(2, char(178)) << string(2, ' ') << string(2, char(178)) << string(2, ' ') << string(1, char(176)) << string(3, char(178)) << string(2, ' ') << string(2, char(178)) << string(4, ' ') << string(2, char(178)) << string(2, ' ') << string(2, char(178)) << string(6, ' ') << string(2, char(178)) << string(5, ' ') << endl;
	cout << string(2, ' ') << string(6, char(178)) << string(2, ' ') << string(6, char(178)) << string(2, ' ') << string(2, char(178)) << string(6, ' ') << string(6, char(178));
	cout << string(2, ' ') << string(2, char(178)) << string(2, ' ') << string(2, char(178)) << string(2, ' ') << string(2, char(178)) << string(2, ' ') << string(2, char(178)) << string(2, ' ') << string(2, char(178)) << string(2, ' ') << string(2, char(178)) << string(2, ' ') << string(1, char(176)) << string(3, char(178)) << string(2, ' ') << string(2, char(178)) << string(4, ' ') << string(2, char(178)) << string(2, ' ') << string(2, char(178)) << string(6, ' ') << string(6, char(178)) << string(1, ' ') << endl;
	cout << string(6, ' ') << string(2, char(178)) << string(2, ' ') << string(2, char(178)) << string(2, ' ') << string(2, char(178)) << string(2, ' ') << string(2, char(178)) << string(6, ' ') << string(2, char(178)) << string(4, ' ');
	cout << string(2, ' ') << string(2, char(178)) << string(6, ' ') << string(2, char(178)) << string(2, ' ') << string(2, char(178)) << string(2, ' ') << string(2, char(178)) << string(2, ' ') << string(2, char(178)) << string(2, ' ') << string(1, char(176)) << string(3, char(178)) << string(2, ' ') << string(2, char(178)) << string(4, ' ') << string(2, char(178)) << string(2, ' ') << string(2, char(178)) << string(6, ' ') << string(2, char(178)) << string(5, ' ') << endl;
	cout << string(2, ' ') << string(6, char(178)) << string(2, ' ') << string(2, char(178)) << string(2, ' ') << string(2, char(178)) << string(2, ' ') << string(6, char(178)) << string(2, ' ') << string(6, char(178));
	cout << string(2, ' ') << string(2, char(178)) << string(6, ' ') << string(2, char(178)) << string(2, ' ') << string(6, char(178)) << string(2, ' ') << string(6, char(178)) << string(2, char(223)) << string(2, ' ') << string(8, char(178)) << string(2, ' ') << string(6, char(178)) << string(2, ' ') << string(6, char(178)) << string(1, ' ') << endl;
	SetConsoleTextAttribute(h, 7);
	cout << string(120, char(196)) << endl << endl << endl;
}
void transactionHeader() {
	SetConsoleTextAttribute(h, 14);
	cout << "$$$$$$$$$$  $$$$$$      $$$$    $$      $$    $$$$$$    $$$$      $$$$$$  $$$$$$$$$$  $$$$$$    $$$$    $$      $$ " << endl;
	cout << "    $$      $$    $$  $$    $$  $$$$    $$  $$        $$    $$  $$            $$        $$    $$    $$  $$$$    $$ " << endl;
	cout << "    $$      $$$$$$    $$$$$$$$  $$  $$  $$    $$$$    $$$$$$$$  $$            $$        $$    $$    $$  $$  $$  $$ " << endl;
	SetConsoleTextAttribute(h, 6);
	cout << "    $$      $$    $$  $$    $$  $$    $$$$        $$  $$    $$  $$            $$        $$    $$    $$  $$    $$$$" << endl;
	cout << "    $$      $$    $$  $$    $$  $$      $$  $$$$$$    $$    $$    $$$$$$      $$      $$$$$$    $$$$    $$      $$  " << endl;
	SetConsoleTextAttribute(h, 7);
	cout << string(120, char(175)) << endl;
}
int getIntegerInput() {// Function to validate integer input
	int input;
	while (true) {
		cin >> input;
		if (cin.fail()) { // Check if input failed
			cin.clear(); // Clear error flags
			cin.ignore(10000, '\n'); // Ignore invalid input
			cout << "Invalid input. Please enter an integer:";
		}
		else {
			cin.ignore(10000, '\n'); // Ignore any extra characters
			return input;
		}
	}
}
double getDoubleInput() {// Function to validate double input
	double input;
	while (true) {
		cin >> input;
		if (cin.fail()) { // Check if input failed
			cin.clear(); // Clear error flags
			cin.ignore(10000, '\n'); // Ignore invalid input
			cout << "Invalid input. Please enter a number:";
		}
		else {
			cin.ignore(10000, '\n'); // Ignore any extra characters
			return input;
		}
	}
}
int getOrderNo() {//This function gets the last order number in the transaction file.The order number is the same as the transaction ID.
	int orderno = 0;
	double totalpay;
	string paymentmethod;
	ifstream itransactionfile;
	itransactionfile.open("transaction.txt");
	if (itransactionfile.fail()) {
		cout << "Unable to get Order ID.\n";
	}
	else {
		while (!itransactionfile.eof()) {//loop until the latest order number
			itransactionfile >> orderno;
			itransactionfile.ignore();
			itransactionfile >> totalpay;
			itransactionfile.ignore();
			getline(itransactionfile, paymentmethod);
		}
	}
	itransactionfile.close();
	return orderno;
}
void updateSale(fruitItem inventory[], int no_fruit) {//This function is to update the sold item in the inventory file.
	ofstream outstockfile(fruitFile);
	if (outstockfile.is_open()) {
		for (int i = 0; i < no_fruit; i++) {
			outstockfile << inventory[i].name << endl;
			outstockfile << fixed << setprecision(2) << inventory[i].price << " " << inventory[i].quantity << endl;
		}
		cout << "You can process to payment.Thank you!\n";
	}
	else {
		cout << "Sorry, we are unable to process the payment because we were unable to update the order in the file.\n";//If you are unable to open the inventory file and update it, the sale cannot be processed for payment.
	}
	outstockfile.close();
}
void currentInventoryHeader() {
	SetConsoleTextAttribute(h, 13);
	cout << "..%%%%...%%..%%..%%%%%...%%%%%...%%%%%%..%%..%%..%%%%%%..%%%%%%..%%..%%..%%..%%..%%%%%%..%%..%%..%%%%%%...%%%%...%%%%%...%%..%%." << endl;
	cout << ".%%..%%..%%..%%..%%..%%..%%..%%..%%......%%%.%%....%%......%%....%%%.%%..%%..%%..%%......%%%.%%....%%....%%..%%..%%..%%...%%%%.." << endl;
	cout << ".%%......%%..%%..%%%%%...%%%%%...%%%%....%%.%%%....%%......%%....%%.%%%..%%..%%..%%%%....%%.%%%....%%....%%..%%..%%%%%.....%%..." << endl;
	SetConsoleTextAttribute(h, 5);
	cout << ".%%..%%..%%..%%..%%..%%..%%..%%..%%......%%..%%....%%......%%....%%..%%...%%%%...%%......%%..%%....%%....%%..%%..%%..%%....%%..." << endl;
	cout << "..%%%%....%%%%...%%..%%..%%..%%..%%%%%%..%%..%%....%%....%%%%%%..%%..%%....%%....%%%%%%..%%..%%....%%.....%%%%...%%..%%....%%..." << endl;
	cout << "................................................................................................................................" << endl;
	SetConsoleTextAttribute(h, 7);
	cout << "\n\n\n";
}
void currentInventory(fruitItem inventory[], int numItems) {//Function to show users current inventory
	cout << "No. " << "Type of fruit\t\t\t\t\t\t" << "  Price\t\t\t\t" << "   Number of stocks per kg" << endl;
	cout << string(130, char(196));
	cout << "\n\n";
	for (int i = 0; i < numItems; i++) {
		cout << left << setw(5) << i + 1 << left << setw(50) << inventory[i].name;
		cout << "\t";
		cout << right << setw(12) << "RM  " << fixed << setprecision(2) << inventory[i].price;
		cout << "\t\t\t";
		if (inventory[i].quantity == 0) {
			cout << "\t\tSold Out\n";
		}
		else {
			cout << right << setw(10) << inventory[i].quantity << " stocks per kg\n";
		}
	}
	cout << string(130, char(196)) << endl << endl;
}
void purchaseItem(fruitItem inventory[], int optionIndex, double& fruitamount, double& totalpayment) {//calculate the price of the order item
	double itemprice;
	bool validamount = false;//check for the valid input amount	and initialize the loop
	while (validamount == false) {// Set the validamount to false to allow the user to re-enter the amount
		cout << "Please enter the amount of the fruit in kg that you wish to purchase:";
		fruitamount = getDoubleInput();
		if (fruitamount <= 0) {
			cout << "Invalid quantity! Please key in a positive integer value.\n";
			validamount = false;
		}
		else if (fruitamount > inventory[optionIndex].quantity) {
			if (inventory[optionIndex].quantity == 0) {
				cout << "Sorry," << inventory[optionIndex].name << " are sold out.\n";
				fruitamount = 0;
				validamount = true;
			}
			else {
				cout << "Sorry, we only have " << inventory[optionIndex].quantity << "kg of " << inventory[optionIndex].name << " available.\n";
				validamount = false;
			}
		}
		else {
			itemprice = fruitamount * inventory[optionIndex].price;
			cout << "You have ordered " << fixed << setprecision(2) << fruitamount << "kg of ";
			cout << inventory[optionIndex].name << " with total price is RM " << itemprice << "." << endl;
			totalpayment += itemprice;
			validamount = true;
		}
	}
}
void discount(double& total_cost) {//Function to check whether is the customer eligible for a discount //Once total cost is more than RM200, customer will be awarded a 10% discount and the total cost will be calculated
	if (total_cost >= 200)
	{
		cout << "Your total cost is RM " << total_cost << ". You are eligible for a 10% discount" << endl;
		total_cost *= (90.0 / 100);
		cout << "After 10% discount, your total cost is RM " << fixed << setprecision(2) << total_cost << endl;
	}
	else {
		cout << "Your total cost is RM " << total_cost << endl;
	}
}
void updateTransactionRecord(double& totalpayment, int& orderno, string paymethod) {
	ofstream otransactionfile;
	otransactionfile.open("transaction.txt", ios::app);
	if (otransactionfile.is_open()) {
		otransactionfile << orderno << endl;
		otransactionfile << fixed << setprecision(2) << totalpayment << endl;
		otransactionfile << paymethod << endl;
		cout << "Transaction saved to file!\n";
	}
	else {//if the transaction file unable to open, the user unable to save their transaction to file
		cout << "Failed to save transaction to file.\n";
	}
	otransactionfile.close();
}
double total_revenue() {//function to calculate the total revenue of the sales which will be used in income statement
	ifstream itransactionfile;
	itransactionfile.open("transaction.txt");
	double totalpayment = 0.0, revenue = 0.0;
	int orderno = 0;
	string paymethod;
	char space = ' ';
	if (itransactionfile.is_open()) {
		while (!itransactionfile.eof()) {
			itransactionfile >> orderno;
			itransactionfile >> totalpayment;
			// Read the rest of the line as the payment method
			getline(itransactionfile >> space, paymethod);
			revenue += totalpayment;
		}
	}
	else {
		cout << "Failed to open file.\n";
	}
	itransactionfile.close();
	return revenue;
}
void payment_options() {//function that stores the payment options which will be used in the sales module function
	cout << "1. Online Banking" << endl;
	cout << "2. Credit Card" << endl;
	cout << "3. Debit Card" << endl;
}
void getPaymentOpt(string& payMethod) {
	int paymethodOpt;
	do {
		cout << "Your options: ";
		paymethodOpt = getIntegerInput();
		if (paymethodOpt == 1)
			payMethod = "Online Banking";
		else if (paymethodOpt == 2)
			payMethod = "Credit Card";
		else if (paymethodOpt == 3)
			payMethod = "Debit Card";
		else
			cout << "Invalid option!\n";
	} while (paymethodOpt != 1 && paymethodOpt != 2 && paymethodOpt != 3);
}
bool salesmodule(int& orderno, string purchaseitem[], double purchaseamount[]) {
	fruitItem inventory[MAX_ITEMS];
	int no_fruit = 0;//number of types of fruit in inventory
	double fruitamount = 0.0, totalpayment = 0.0;
	string paymethod;
	int option, optionIndex;
	char p_decision = 'Y', gopay, viewreceipt;
	int noitem = 0;//record the total number of item purchased
	for (int i = 0; i < MAX_ITEMS; i++) {
		inventory[i].name[0] = '\0'; // set name to empty string
		inventory[i].price = 0.0; // set price to zero
		inventory[i].quantity = 0; // set quantity to zero
	}
	//load the name of the fruit, price of fruit, and quantity of fruit to display on the menu for the user
	ifstream instockfile(fruitFile);
	if (instockfile.is_open()) {
		while (no_fruit < MAX_ITEMS && instockfile.peek() != EOF) {
			instockfile.getline(inventory[no_fruit].name, 100);
			instockfile >> inventory[no_fruit].price >> inventory[no_fruit].quantity;
			no_fruit++;
			instockfile.ignore();
		}
	}
	else {
		cout << "Unable to open inventory file.\n";
	}
	instockfile.close();
	saleHeader();
	currentInventory(inventory, no_fruit);
	do {
		cout << "Please select an option from the list(1-" << no_fruit << "): ";
		option = getIntegerInput();
		if (option < 1 || option > no_fruit) {
			cout << "Invalid Input.Please pick a number from the list.\n";
			p_decision = 'Y';
		}
		else {
			optionIndex = option - 1;//because the index start from 0 so need to minus 1
			purchaseItem(inventory, optionIndex, fruitamount, totalpayment);
			if (fruitamount > 0) {
				inventory[option - 1].quantity -= fruitamount;
				purchaseitem[noitem] = inventory[option - 1].name;
				purchaseamount[noitem] = fruitamount;
				++noitem;
			}
			do {
				cout << "Do you want to order other fruits? (Enter Y-Yes/N-No): ";
				cin >> p_decision;
				if (toupper(p_decision) != 'Y' && toupper(p_decision) != 'N') {
					cout << "Invalid Input!" << endl;
				}
			} while (toupper(p_decision) != 'Y' && toupper(p_decision) != 'N');
		}
		cout << endl;
	} while (toupper(p_decision) != 'N');
	do {
		cout << endl;
		cout << "Do you confirm your order?(Y to process to payment or N to process to exit): ";
		cin >> gopay;
		if (gopay != 'Y' && gopay != 'N' && gopay != 'y' && gopay != 'n') {
			cout << "Invalid Input!\n ";
		}
	} while (toupper(gopay) != 'Y' && toupper(gopay) != 'N');
	if (toupper(gopay) == 'Y') {
		discount(totalpayment);
		cout << "Payment Options: " << endl;
		payment_options();
		getPaymentOpt(paymethod);
		updateSale(inventory, no_fruit);
		updateTransactionRecord(totalpayment, orderno, paymethod);//save transaction record to customer transaction history
		orderno++;
		do {
			cout << "Do you want to view receipt? (Enter Y-Yes or N-No):";
			cin >> viewreceipt;
			cout << endl;
			if (toupper(viewreceipt) == 'Y') {
				system("cls");
				cout << string(100, char(240)) << endl;
				cout << "\t\t\tReceipt" << endl;
				cout << string(100, char(240)) << endl;
				for (int i = 0; i < noitem; i++) {
					cout << i + 1 << ". " << left << setw(40) << purchaseitem[i] << "\t\t" << setw(6) << purchaseamount[i] << "Kg" << endl;
				}
				cout << string(100, char(240)) << endl;
				cout << "Payment Method: " << paymethod << endl;
				cout << "Total payment:RM " << fixed << setprecision(2) << totalpayment << endl;
			}
		} while (toupper(viewreceipt) != 'Y' && toupper(viewreceipt) != 'N');
		return true;
	}
	else {
		return false;
	}
}
void displayTransaction(string orderNo, string paymentmethod, double totalpayment) {
	string transactionid;
	if (orderNo.length() < 6) {//Check the length of the order number in order to add  zero in front of it.Set at least 6 digits for transaction ID
		transactionid = string(6 - orderNo.length(), char(48)) + orderNo;
	}
	else {//if the transaction id more than six digits 
		transactionid = orderNo;
	}
	cout << "Transaction ID: " << transactionid << endl;
	cout << string(70, char(196)) << endl;
	cout << "Payment Method: " << paymentmethod << endl;
	cout << "Total Payment:RM " << fixed << setprecision(2) << totalpayment << endl << endl;
}
void loadTransactionHistory(int& orderno) {
	int i = 0;
	string transactionid, orderNo, paymentmethod;//The order number stored as a string because we need to convert it to a transaction ID.
	double totalpayment;
	ifstream itransactionfile;
	itransactionfile.open("transaction.txt");
	if (itransactionfile.fail()) {
		cout << "Unable to open transaction record file.\n";
	}
	else {// Read the order number, total payment, and payment method from the transaction file
		while (i < orderno && itransactionfile.peek() != EOF) {//loop continues until i reaches the total number of orders
			getline(itransactionfile, orderNo);
			itransactionfile >> totalpayment;
			itransactionfile.ignore();
			getline(itransactionfile, paymentmethod);
			if (totalpayment >= 0) {
				displayTransaction(orderNo, paymentmethod, totalpayment);
				i++;
			}
		}
		if (i == 0) {
			cout << "No transaction record !\n";
		}
	}
	itransactionfile.close();
}
void searchResult(int orderno, string payMethod, string transactionID) {//Function check the search from the transaction file
	int i = 0;
	int searchNo = 0;//Record the number of matched search results.
	string paymentmethod, transactionid, orderNo;//declare orderNo as string to create transaction id
	double totalpayment;
	ifstream itransactionfile;
	itransactionfile.open("transaction.txt");
	if (itransactionfile.fail()) {
		cout << "Unable to open transaction record file.\n";
	}
	else {
		while (i < orderno && itransactionfile.peek() != EOF) {
			itransactionfile >> orderNo;
			itransactionfile.ignore();
			itransactionfile >> totalpayment;
			itransactionfile.ignore();
			getline(itransactionfile, paymentmethod);
			if (orderNo == transactionID || paymentmethod == payMethod) {//check any matched search result
				displayTransaction(orderNo, paymentmethod, totalpayment);
				++searchNo;
			}
			i++;
		}
		if (searchNo == 0) {
			cout << "Sorry, we cannot find any matched transaction record.\n";
		}
	}
	itransactionfile.close();
}
void search(int& orderno) {// Get what the user want to search
	int searchdecision;
	int  paymethodOpt = 0;
	string transactionID, payMethod;
	cout << "Search for \n";
	cout << "1.Transaction ID " << endl;
	cout << "2.Payment Method " << endl;
	cout << "Your choice: ";
	searchdecision = getIntegerInput();
	while (searchdecision < 1 || searchdecision>2) {
		cout << "Invalid Input! Please key in 1 or 2: ";
		searchdecision = getIntegerInput();
	}
	cout << endl;
	if (searchdecision == 1) {
		cout << "Please key in the Transaction ID that you wish to search.\n";
		cout << "For example, just key in 1 for Transaction ID 000001.\n";
		cout << "Transaction ID: ";
		cin >> transactionID;
	}
	else {//search for payment method
		cout << "Payment Method:\n";
		payment_options();
		cout << "Please key in the type of payment method you wish to seach.\n";
		getPaymentOpt(payMethod);
	}
	cout << endl;
	searchResult(orderno, payMethod, transactionID);
}
void transactionHistory(int& orderno) {//display the transaction history
	char searchOpt;
	transactionHeader();
	loadTransactionHistory(orderno);
	cout << endl;
	cout << "Do you want to search transaction history? (Enter Y-Yes or N-No): ";
	cin >> searchOpt;
	while (toupper(searchOpt) != 'Y' && toupper(searchOpt) != 'N') {
		cout << "Invalid Input!\n";
		cout << "Please key in Y if you want to search transaction history or N if you do not want to search transaction history: ";
		cin >> searchOpt;
	}
	if (toupper(searchOpt) == 'Y') {
		system("cls");
		transactionHeader();
		search(orderno);
	}
	system("pause");
}
bool itemExists(const fruitItem& newItem, const fruitItem inventory[], int numItems) {// Function to check if a fruit item already exists in the inventory
	for (int i = 0; i < numItems; i++) {
		if (strcmp(newItem.name, inventory[i].name) == 0) {
			return true;
		}
	}
	return false;
}
bool itemCostExists(const costItem& newItem, const costItem cost_inventory[], int numItems) {// Function to check if a fruit item already exists in the inventory
	for (int i = 0; i < numItems; i++) {
		if (strcmp(newItem.name, cost_inventory[i].name) == 0) {
			return true;
		}
	}
	return false;
}
void updateCostFile(costItem cost_inventory[], int& numItems) {// Function to update file with new inventory after deleting or changing an fruit item
	ofstream outFile(inGoods);
	if (outFile.is_open()) {
		for (int i = 0; i < numItems; i++) {
			outFile << cost_inventory[i].name << endl;
			outFile << fixed << setprecision(2) << cost_inventory[i].cost << " " << cost_inventory[i].stock << endl;
		}
		outFile.close();
		SetConsoleTextAttribute(h, 113);
		cout << "Inventory updated.\n";
		SetConsoleTextAttribute(h, 7);
	}
	else {
		SetConsoleTextAttribute(h, 113);
		cout << "Error! Could not open inventory file for writing.\n";
		SetConsoleTextAttribute(h, 7);
	}
	SetConsoleTextAttribute(h, 7);
}
void currentCostInventory(costItem cost_inventory[], int& numItems) {//Function to show users current inventory
	cout << "\n" << "\x1b[94m";
	cout << "   #######                                     ###                                                       " << endl;
	cout << "   #     # #    # #    # ###### #####           #  #    # #    # ###### #    # #####  ####  #####  #   # " << endl;
	cout << "   #     # #    # ##   # #      #    #          #  ##   # #    # #      ##   #   #   #    # #    #  # #  " << endl;
	cout << "   #     # #    # # #  # #####  #    #          #  # #  # #    # #####  # #  #   #   #    # #    #   #   " << endl;
	cout << "   #     # # ## # #  # # #      #    #          #  #  # # #    # #      #  # #   #   #    # #####    #   " << endl;
	cout << "   #     # ##  ## #   ## #      #    #          #  #   ##  #  #  #      #   ##   #   #    # #   #    #   " << endl;
	cout << "   ####### #    # #    # ###### #####          ### #    #   ##   ###### #    #   #    ####  #    #   #" << endl;
	cout << "\x1b[37m" << "\n\n";
	cout << "No. " << "Type of fruit\t\t\t\t\t\t" << "Price\t\t\t" << "Number of stocks per kg" << endl;
	cout << string(120, char(61)) << "\n\n";
	for (int i = 0; i < numItems; i++) {
		cout << left << setw(4) << i + 1 << left << setw(50) << cost_inventory[i].name << "\t";
		cout << right << setw(10) << "RM  " << fixed << setprecision(2) << cost_inventory[i].cost << "\t\t\t";
		cout << right << setw(6) << cost_inventory[i].stock << " stocks per kg\n";
	}
	cout << string(120, char(61)) << endl;
}
void addNewCostItem(costItem cost_inventory[], int& numItems) {//Function to add a fruit item into the inventory
	currentCostInventory(cost_inventory, numItems);
	SetConsoleTextAttribute(h, 14);
	cout << "\n" << "  _   _   _   _   _   _   _   _   _   _ " << endl;
	cout << " / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ " << endl;
	cout << "( A | D | D | I | N | G | I | T | E | M )" << endl;
	cout << " \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ " << "\n\n" << endl;
	costItem newItem;
	SetConsoleTextAttribute(h, 7);
	cout << "If nothing is shown below, press any key to continue" << endl;
	cin.ignore(); //ignore the newline character from previous input;
	cout << "Enter name of new fruit item: ";
	cin.getline(newItem.name, 100);
	for (int i = 0; i < strlen(newItem.name); i++) {// Convert name to uppercase
		newItem.name[i] = toupper(newItem.name[i]);
	}
	while (itemCostExists(newItem, cost_inventory, numItems)) {// Check if new fruit item already exists in inventory
		cout << "Error! Name of fruit item already exists in inventory. Please enter new information.\n";
		cout << "Enter name of new fruit item: ";
		cin.getline(newItem.name, 100);
		for (int i = 0; i < strlen(newItem.name); i++) {// Convert name to uppercase
			newItem.name[i] = toupper(newItem.name[i]);
		}
	}
	do {
		cout << "Enter cost of new goods (fruit item) [must be greater than 0]: ";
		newItem.cost = getDoubleInput();
		if (newItem.cost <= 0) {
			cout << "Invalid input. Please enter a value greater than 0." << endl;
		}
	} while (newItem.cost <= 0);
	do {
		cout << "Enter stock of new goods (fruit item) [must be greater than 10]: ";
		newItem.stock = getDoubleInput();
		if (newItem.stock <= 10) {
			cout << "Invalid input. Please enter a value greater than 10." << endl;
		}
	} while (newItem.stock <= 10);
	cout << endl;
	SetConsoleTextAttribute(h, 7);
	int itemIndex = -1;
	costItem tempItem = cost_inventory[itemIndex]; // create a copy of the item before modifying it
	char confirmation;
	do {// Confirm the addition with the user
		cout << "Are you sure you want to add this fruit item? (Enter Y-Yes/N-No): ";
		cin >> confirmation;
		if (toupper(confirmation) == 'N') {
			cout << "Fruit item added canceled.\n";
			cost_inventory[itemIndex] = tempItem; // restore the original values from the copy
		}
		else if (toupper(confirmation) == 'Y') {
			if (numItems < MAX_ITEMS) {// Add new fruit item to inventory
				cost_inventory[numItems] = newItem;
				numItems++;
				SetConsoleTextAttribute(h, 113);
				cout << "New fruit item added successfully to inventory.\n";
			}
			else {
				SetConsoleTextAttribute(h, 113);
				cout << "Error! Maximum inventory capacity reached. Cannot add new item.\n";
				return; //exit the function if maximum inventory capacity has been reached 
			}
			ofstream outFile(inGoods);// Save updated inventory to file
			if (outFile.is_open()) {
				for (int i = 0; i < numItems; i++) {
					outFile << cost_inventory[i].name << endl;
					outFile << fixed << setprecision(2) << cost_inventory[i].cost << " " << cost_inventory[i].stock << endl;
				}
				outFile.close();
				SetConsoleTextAttribute(h, 113);
				cout << "Inventory saved to file.\n";
			}
			else {
				SetConsoleTextAttribute(h, 113);
				cout << "Error! Could not open inventory file for writing.\n";
			}
		}
		else {
			cout << "Invalid input! Please try again.." << endl;
		}
	} while (toupper(confirmation) != 'Y' && toupper(confirmation) != 'N');
	SetConsoleTextAttribute(h, 7);
}
void deleteCostItem(costItem cost_inventory[], int& numItems) {// Function to delete a fruit item from the inventory
	currentCostInventory(cost_inventory, numItems);
	SetConsoleTextAttribute(h, 14);
	cout << "\n" << "  _   _   _   _   _   _   _   _   _   _   _   _  " << endl;
	cout << " / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ " << endl;
	cout << "( D | E | L | E | T | I | N | G | I | T | E | M )" << endl;
	cout << " \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ " << "\n\n" << endl;
	SetConsoleTextAttribute(h, 7);
	int itemIndex = -1;
	while (itemIndex == -1) {
		cout << "Enter the number of the fruit item you want to delete: ";
		itemIndex = getIntegerInput() - 1;
		if (itemIndex < 0 || itemIndex >= numItems) {
			cout << "Invalid input! Please enter a number between 1 and " << numItems << ".\n";
			itemIndex = -1;
		}
	}
	char confirm;
	do {
		cout << "Are you sure you want to delete " << cost_inventory[itemIndex].name << "? (Enter Y-Yes/N-No): ";
		cin >> confirm;
		if (toupper(confirm) == 'Y') {
			for (int i = itemIndex; i < numItems - 1; i++) {// Shift all items after the deleted item back by one index
				cost_inventory[i] = cost_inventory[i + 1];
			}
			numItems--;
			cout << "--Fruit item deleted.--\n";
			updateCostFile(cost_inventory, numItems);// Update file with new inventory
		}
		else if (toupper(confirm) == 'N') {
			cout << "--Fruit item deleted cancel--" << endl;
			updateCostFile(cost_inventory, numItems);
		}
		else {
			cout << "Invalid input! Please enter again.." << endl;
		}
	} while (toupper(confirm) != 'Y' && toupper(confirm) != 'N');
}
void changeCostItem(costItem cost_inventory[], int& numItems) {// Function to change a fruit item in the inventory
	currentCostInventory(cost_inventory, numItems); //display current inventory
	SetConsoleTextAttribute(h, 14);
	cout << "\n" << "  _   _   _   _   _   _   _   _   _   _   _   _ " << endl;
	cout << " / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\" << endl;
	cout << "( C | H | A | N | G | I | N | G | I | T | E | M )" << endl;
	cout << " \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/" << "\n\n" << endl;
	SetConsoleTextAttribute(h, 7);
	int itemIndex = -1;
	while (itemIndex == -1) {
		cout << "Enter the number of the fruit item you want to change: ";
		itemIndex = getIntegerInput() - 1;
		if (itemIndex < 0 || itemIndex >= numItems) {
			cout << "Invalid input. Please enter a number from 1 to " << numItems << ".\n";
			itemIndex = -1;
		}
	}
	costItem tempItem = cost_inventory[itemIndex]; // create a copy of the item before modifying it
	cout << "Enter new name of fruit item: ";
	cin.getline(cost_inventory[itemIndex].name, 100);
	for (int i = 0; i < strlen(cost_inventory[itemIndex].name); i++) {// Convert name to uppercase
		cost_inventory[itemIndex].name[i] = toupper(cost_inventory[itemIndex].name[i]);
	}
	do {
		cout << "Enter new cost of goods (fruit item) [must be greater than 0]: ";
		cost_inventory[itemIndex].cost = getDoubleInput();
		if (cost_inventory[itemIndex].cost <= 0) {
			cout << "Invalid input. Please enter a value greater than 0." << endl;
		}
	} while (cost_inventory[itemIndex].cost <= 0);
	do {
		cout << "Enter new stock of goods (fruit item) [must be greater than 10]: ";
		cost_inventory[itemIndex].stock = getDoubleInput();
		if (cost_inventory[itemIndex].stock <= 10) {
			cout << "Invalid input. Please enter a value greater than 10." << endl;
		}
	} while (cost_inventory[itemIndex].stock <= 10);
	char confirmation;
	do {// Confirm the change with the user
		cout << "Are you sure you want to change this item? (Enter Y-Yes/N-No): ";
		cin >> confirmation;
		if (toupper(confirmation) == 'Y') {
			cout << "Item updated successfully!\n";
			updateCostFile(cost_inventory, numItems);// Update file with new inventory information
		}
		else if (toupper(confirmation) == 'N') {
			cout << "Item change canceled.\n";
			cost_inventory[itemIndex] = tempItem; // restore the original values from the copy
		}
		else {
			cout << "Invalid input! Please try again.." << endl;
		}
	} while (toupper(confirmation) != 'Y' && toupper(confirmation) != 'N');
}
void loadingbar() {//Create a loading bar for user
	int i = 1; //This is for loop
	int x = 219; //This is for loading bar animation
	int y = 177; //This is for initial bar
	cout << "\n\n\n\n\n\n\n\n\n\n" << "\t\t\t\t\t\t";
	cout << "##        #######     ###    ########  #### ##    ##  ######" << "\n\t\t\t\t\t\t";
	cout << "##       ##     ##   ## ##   ##     ##  ##  ###   ## ##    ##" << "\n\t\t\t\t\t\t";
	cout << "##       ##     ##  ##   ##  ##     ##  ##  ####  ## ##" << "\n\t\t\t\t\t\t";
	cout << "##       ##     ## ##     ## ##     ##  ##  ## ## ## ##   ####" << "\n\t\t\t\t\t\t";
	cout << "##       ##     ## ######### ##     ##  ##  ##  #### ##    ##" << "\n\t\t\t\t\t\t";
	cout << "##       ##     ## ##     ## ##     ##  ##  ##   ### ##    ##" << "\n\t\t\t\t\t\t";
	cout << "########  #######  ##     ## ########  #### ##    ##  ###### " << endl;
	cout << "\n\n" << "\t\t\t\t\t";
	for (i = 1; i < 80; i++) {
		cout << (char)y;
	}
	cout << "\r" << "\t\t\t\t\t";
	for (i = 1; i < 80; i++) {//this loop for increase the Loading
		SetConsoleTextAttribute(h, 13);
		cout << (char)x;
		Sleep(30);
	}
	system("cls");
}
void warning_bar() {//Warning Bar for user
	int i = 1; //This is for loop
	int x = 219; //This is for warning bar animation
	int y = 177; //This is for initial bar
	cout << "\n\n\n\n\n\n\n\n\n\n" << "\t\t\t" << endl;
	cout << "\x1b[31m";
	cout << string(15, ' ') << "\t\t\t     '##:::::::'##::::'####::::'########:::'##:::: ##::'#####:'##:::  ##:: '######:: :" << endl;
	cout << string(15, ' ') << "\t\t\t      ## :'## : ##:::'##：##::: :##.... ##:::###:: :## : .##::  ###::  ## : '##... ##::" << endl;
	cout << string(15, ' ') << "\t\t\t      ## : ## : ##:::'##:.##:: ：##:::: ##:::####: :##::  ##::  ####:  ##:  ##:::..:::" << endl;
	cout << string(15, ' ') << "\t\t\t      ## : ## : ## :'##:::.##: ：########::::## ## :##::  ##::  ## ##  ##:  ##::'#### :" << endl;
	cout << string(15, ' ') << "\t\t\t      ## : ## : ## : ######### :##.. ##:::::##. ####::   ##::  ##.  #### : ##:: : ##::" << endl;
	cout << string(15, ' ') << "\t\t\t      ## : ## : ## : ##.... ## :##::. ##::::## : .###::  ##::  ## : .### : ##:: : ##::" << endl;
	cout << string(15, ' ') << "\t\t\t      . ###. ###:::::##:::: ## :##:: : .##::##::.  ## :'#####: ##::.  ##:. ######:::" << endl;
	cout << string(15, ' ') << "\t\t\t      : ...::...:: : ..:::: : ..::..:::: : ..::..::::..::....::..::::..:: : ......::::" << endl;
	cout << string(60, ' ') << "Detected inventory change !!!!!" << endl;
	cout << string(55, ' ') << "Please update bought inventory accordingly !!!!!" << endl;
	cout << "\n\n" << string(2, ' ') << "\t\t\t\t\t";
	for (i = 1; i < 80; i++) {
		cout << (char)y;
	}
	cout << "\r" << "\t\t\t\t\t";
	for (i = 1; i < 80; i++) { //this loop for increase the Loading
		SetConsoleTextAttribute(h, 13);
		cout << (char)x;
		Sleep(30);
	}
	system("cls");
}
void Bought_ItemStock() {//Function to allow shop admin add, delete or change items in inventory
	ifstream inFile(inGoods);
	costItem cost_inventory[MAX_ITEMS];//Load existing inventory from file
	int numItems = 0; // Current number of items in inventory
	for (int i = 0; i < MAX_ITEMS; i++) {
		cost_inventory[i].name[0] = '\0'; // set name to empty string
		cost_inventory[i].cost = 0.0; // set cost to zero
		cost_inventory[i].stock = 0; // set stock to zero
	}
	if (inFile.is_open()) {
		while (numItems < MAX_ITEMS && inFile.peek() != EOF) {
			inFile.getline(cost_inventory[numItems].name, 100);
			inFile >> cost_inventory[numItems].cost >> cost_inventory[numItems].stock;
			inFile.ignore(); // Ignore newline character
			numItems++;
		}
		inFile.close();
		loadingbar();
		SetConsoleTextAttribute(h, 113);
		cout << "Inventory Loaded From File." << endl;
	}
	else {
		SetConsoleTextAttribute(h, 113);
		cout << "Error: Could not open inventory file!" << endl;
	}
	SetConsoleTextAttribute(h, 7);
	//Prompt user to add or change or delete an item
	int choice = -1;
	cout << "\x1b[94m";
	cout << " 	.oPYo.                             8   .oPYo.o                  8      " << endl;
	cout << " 	8    8                             8   8        8               8      " << endl;
	cout << " 	8    8 o   o   o odYo. .oPYo. .oPYo8   `Yooo. o8P8.oPYo. .oPYo. 8  .o  " << endl;
	cout << " 	8    8 Y. .P. .P 8' `8 8oooo8 8    8      `8   8  8    8 8    ' 8oP'   " << endl;
	cout << " 	8    8 `b.d'b.d' 8   8 8.     8    8       8   8  8    8 8    . 8 `b.  " << endl;
	cout << " 	`YooP'  `Y' `Y'  8   8 `Yooo' `YooP'   `YooP'  8  `YooP' `YooP' 8  `o. " << endl;
	cout << "\x1b[37m";
	while (choice != 0) {
		cout << "\n\n" << string(30, char(61)) << endl;
		cout << "Please choose an option:\n";
		cout << string(30, char(61)) << endl;
		cout << "1. Add a new item\n";
		cout << "2. Delete an existing item\n";
		cout << "3. Change an existing item\n";
		cout << "4. Current Inventory\n";
		cout << "0. Exit program\n";
		cout << string(30, char(61)) << endl;
		cout << "Option:";
		choice = getIntegerInput();
		cout << "\n\n";
		switch (choice) {
		case 1: // Add a new item
			system("cls");
			addNewCostItem(cost_inventory, numItems);
			break;
		case 2: // Delete an existing item
			system("cls");
			deleteCostItem(cost_inventory, numItems);
			break;
		case 3: // Change an existing item
			system("cls");
			changeCostItem(cost_inventory, numItems);
			break;
		case 4: // Change an existing item
			system("cls");
			currentCostInventory(cost_inventory, numItems);
			break;
		case 0: // Exit program
			break;
		default:
			cout << "Invalid choice. Please enter 1, 2, 3, 4 or 0.\n";
			continue;
		}
	}
	ofstream outFile(inGoods);//Save inventory to file
	if (outFile.is_open()) {
		for (int i = 0; i < numItems; i++) {
			outFile << cost_inventory[i].name << endl;
			outFile << fixed << setprecision(2) << cost_inventory[i].cost << " " << cost_inventory[i].stock << endl;
		}
		outFile.close();
		SetConsoleTextAttribute(h, 113);
		cout << "Inventory saved to file.\n";
	}
	else {
		SetConsoleTextAttribute(h, 79);
		cout << "Error: Could not open inventory file for writing.\n";
	}
	SetConsoleTextAttribute(h, 7);
}
void updateFile(fruitItem inventory[], int& numItems) {// Function to update file with new inventory after deleting or changing an fruit item
	ofstream outputFile(fruitFile);
	if (outputFile.is_open()) {
		for (int i = 0; i < numItems; i++) {
			outputFile << inventory[i].name << endl;
			outputFile << fixed << setprecision(2) << inventory[i].price << " " << inventory[i].quantity << endl;
		}
		outputFile.close();
		SetConsoleTextAttribute(h, 113);
		cout << "Inventory updated.\n";
		SetConsoleTextAttribute(h, 7);
	}
	else {
		SetConsoleTextAttribute(h, 79);
		cout << "Error! Could not open inventory file for writing.\n";
		SetConsoleTextAttribute(h, 7);
	}
	SetConsoleTextAttribute(h, 7);
}

void addNewItem(fruitItem inventory[], int& numItems) {//Function to add a fruit item into the inventory
	currentInventoryHeader();
	currentInventory(inventory, numItems);
	SetConsoleTextAttribute(h, 14);
	cout << "\n" << "  _   _   _   _   _   _   _   _   _   _ " << endl;
	cout << " / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ " << endl;
	cout << "( A | D | D | I | N | G | I | T | E | M )" << endl;
	cout << " \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ " << "\n\n" << endl;
	fruitItem newItem;
	SetConsoleTextAttribute(h, 7);
	do {
		cout << "Please enter name of new fruit item: ";
		cin.getline(newItem.name, 100);
		for (int i = 0; i < strlen(newItem.name); i++) {// Convert name to uppercase
			newItem.name[i] = toupper(newItem.name[i]);
		}
		if (itemExists(newItem, inventory, numItems)) {
			cout << "Error! Name of fruit item already exists in inventory. Please enter new information.\n";
		}
	} while (itemExists(newItem, inventory, numItems));
	do {
		cout << "Please enter price of new fruit item (must be greater than 0): ";
		newItem.price = getDoubleInput();
		if (newItem.price <= 0) {
			cout << "Invalid input. Please enter a value greater than 0." << endl;
		}
	} while (newItem.price <= 0);
	do {
		cout << "Please enter quantity of new fruit item (must be greater than 10): ";
		newItem.quantity = getDoubleInput();
		if (newItem.quantity <= 10) {
			cout << "Invalid input. Please enter a value greater than 10." << endl;
		}
	} while (newItem.quantity <= 10);
	cout << endl;
	SetConsoleTextAttribute(h, 7);
	int itemIndex = -1;
	fruitItem tempItem = inventory[itemIndex]; // create a copy of the item before modifying it
	char confirmation;
	do {// Confirm the addition with the user
		cout << "Are you sure you want to add this fruit item? (Enter Y-Yes/N-No): ";
		cin >> confirmation;
		if (toupper(confirmation) == 'N') {
			cout << "Fruit item added canceled.\n";
			inventory[itemIndex] = tempItem; // restore the original values from the copy
		}
		else if (toupper(confirmation) == 'Y') {
			if (numItems < MAX_ITEMS) {// Add new fruit item to inventory
				inventory[numItems] = newItem;
				numItems++;
				SetConsoleTextAttribute(h, 113);
				cout << "New fruit item added successfully to inventory.\n";
				ofstream logFile("inventory_log.txt", ios::app);
				if (logFile.is_open()) {//Update the history of actions
					logFile << "\n";
					logFile << left << setw(15) << "Added new item:   " << left << setw(30) << inventory[numItems - 1].name;
					logFile << "\t";
					logFile << "RM " << fixed << setprecision(2) << left << setw(6) << inventory[numItems - 1].price;
					logFile << "\t";
					logFile << right << setw(6) << inventory[numItems - 1].quantity << " stocks per kg\n";
					logFile.close();
				}
				else {
					cout << "Error: Could not open log file for writing!\n";
				}
			}
			else {
				SetConsoleTextAttribute(h, 113);
				cout << "Error! Maximum inventory capacity reached. Cannot add new item.\n";
			}
			ofstream outputFile(fruitFile);// Save updated inventory to file
			if (outputFile.is_open()) {
				for (int i = 0; i < numItems; i++) {
					outputFile << inventory[i].name << endl;
					outputFile << fixed << setprecision(2) << inventory[i].price << " " << inventory[i].quantity << endl;
				}
				outputFile.close();
				SetConsoleTextAttribute(h, 113);
				cout << "Inventory saved to file.\n";
			}
			else {
				SetConsoleTextAttribute(h, 79);
				cout << "Error! Could not open inventory file for writing.\n";
			}
		}
		else {
			cout << "Invalid input! Please try again.." << endl;
		}
	} while (toupper(confirmation) != 'Y' && toupper(confirmation) != 'N');
	SetConsoleTextAttribute(h, 7);
}
void deleteItem(fruitItem inventory[], int& numItems) {// Function to delete a fruit item from the inventory
	currentInventoryHeader();
	currentInventory(inventory, numItems);
	SetConsoleTextAttribute(h, 14);
	cout << "\n" << "  _   _   _   _   _   _   _   _   _   _   _   _  " << endl;
	cout << " / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ " << endl;
	cout << "( D | E | L | E | T | I | N | G | I | T | E | M )" << endl;
	cout << " \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ " << "\n\n" << endl;
	SetConsoleTextAttribute(h, 7);
	int itemIndex = -1;
	while (itemIndex == -1) {
		cout << "Please enter the number of the fruit item you want to delete: ";
		itemIndex = getIntegerInput() - 1;
		if (itemIndex < 0 || itemIndex >= numItems) {
			cout << "Invalid input! Please enter a number from 1 to " << numItems << ".\n";
			itemIndex = -1;
		}
	}
	char confirm;
	do {
		cout << "Are you sure you want to delete " << inventory[itemIndex].name << "? (Enter Y-Yes/N-No): ";
		cin >> confirm;
		if (toupper(confirm) == 'Y') {
			for (int i = itemIndex; i < numItems - 1; i++) {// Shift all items after the deleted item back by one index
				inventory[i] = inventory[i + 1];
			}
			numItems--;
			cout << "--Fruit item deleted.--\n";
			updateFile(inventory, numItems);// Update file with new inventory
			ofstream logFile("inventory_log.txt", ios::app);
			if (logFile.is_open()) { //Update the history of actions
				logFile << "\n";
				logFile << left << setw(15) << "Deleted item:     " << left << setw(30) << inventory[itemIndex].name;
				logFile << "\t";
				logFile << "RM " << fixed << setprecision(2) << left << setw(6) << inventory[itemIndex].price;
				logFile << "\t";
				logFile << right << setw(6) << inventory[itemIndex].quantity << " stocks per kg\n";
				logFile.close();
			}
			else {
				cout << "Error: Could not open log file for writing!\n";
			}
		}
		else if (toupper(confirm) == 'N') {
			cout << "--Fruit item deleted cancel--" << endl;
			updateFile(inventory, numItems);
		}
		else {
			cout << "Invalid input! Please enter again.." << endl;
		}
	} while (toupper(confirm) != 'Y' && toupper(confirm) != 'N');
}
void changeItem(fruitItem inventory[], int& numItems) {// Function to change a fruit item in the inventory
	currentInventoryHeader();
	currentInventory(inventory, numItems);
	SetConsoleTextAttribute(h, 14);
	cout << "\n" << "  _   _   _   _   _   _   _   _   _   _   _   _ " << endl;
	cout << " / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\" << endl;
	cout << "( C | H | A | N | G | I | N | G | I | T | E | M )" << endl;
	cout << " \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/" << "\n\n" << endl;
	SetConsoleTextAttribute(h, 7);
	int itemIndex = -1;
	while (itemIndex == -1) {
		cout << "Please enter the number of the fruit item you want to change: ";
		itemIndex = getIntegerInput() - 1;
		if (itemIndex < 0 || itemIndex >= numItems) {
			cout << "Invalid input. Please enter a number from 1 to " << numItems << ".\n";
			itemIndex = -1;
		}
	}
	char newName[50];
	bool nameExists;
	do {
		cout << "Please enter new name of fruit item: ";
		cin.getline(newName, 50);
		// Convert name to uppercase
		for (int i = 0; i < strlen(newName); i++) {
			newName[i] = toupper(newName[i]);
		}
		nameExists = false;
		for (int i = 0; i < numItems; i++) {
			if (i != itemIndex && strcmp(inventory[i].name, newName) == 0) {
				nameExists = true;
				break;
			}
		}
		if (nameExists) {
			cout << "Error! An item with that name already exists in the inventory. Please choose a different name.\n";
		}
	} while (nameExists);
	strcpy_s(inventory[itemIndex].name, newName);
	do {
		cout << "Enter new price of fruit item (must be greater than 0): ";
		inventory[itemIndex].price = getDoubleInput();
		if (inventory[itemIndex].price <= 0) {
			cout << "Invalid input. Please enter a value greater than 0." << endl;
		}
	} while (inventory[itemIndex].price <= 0);
	do {
		cout << "Enter new quantity of fruit item (must be greater than 10): ";
		inventory[itemIndex].quantity = getDoubleInput();
		if (inventory[itemIndex].quantity <= 10) {
			cout << "Invalid input. Please enter a value greater than 10." << endl;
		}
	} while (inventory[itemIndex].quantity <= 10);
	char confirmation;
	do {// Confirm the change with the user
		cout << "Are you sure you want to change this item? (Enter Y-Yes/N-No): ";
		cin >> confirmation;
		if (toupper(confirmation) == 'Y') {
			cout << "Item updated successfully!\n";
			updateFile(inventory, numItems);// Update file with new inventory information
			ofstream logFile("inventory_log.txt", ios::app);
			if (logFile.is_open()) { //Update the history of actions
				logFile << "\n";
				logFile << left << setw(15) << "Changed item:     " << left << setw(30) << inventory[itemIndex].name;
				logFile << "\t";
				logFile << "RM " << fixed << setprecision(2) << left << setw(6) << inventory[itemIndex].price;
				logFile << "\t";
				logFile << right << setw(6) << inventory[itemIndex].quantity << " stocks per kg\n";
				logFile.close();
			}
			else {
				cout << "Error: Could not open log file for writing!\n";
			}
		}
		else if (toupper(confirmation) == 'N') {
			cout << "Item change canceled.\n";
			//inventory[itemIndex] = tempItem; // restore the original values from the copy
		}
		else {
			cout << "Invalid input! Please try again.." << endl;
		}
	} while (toupper(confirmation) != 'Y' && toupper(confirmation) != 'N');
}
void viewLog() {
	ifstream logFile("inventory_log.txt");
	if (logFile.is_open()) {
		string line;
		while (getline(logFile, line)) {
			cout << line << endl;
		}
		logFile.close();
	}
	else {
		cout << "Error: Could not open log file for reading!\n";
	}
}
void historyheader() {
	SetConsoleTextAttribute(h, 10);
	cout << "        _     _                          __   _        _   _                 " << endl;
	cout << "  /\\  /(_)___| |_ ___  _ __ _   _  ___  / _| /_\\   ___| |_(_) ___  _ __  ___ " << endl;
	cout << " / /_/ / / __| __/ _ \\| '__| | | |/ _ \\| |_ //_\\\\ / __| __| |/ _ \\| '_ \\/ __|" << endl;
	cout << "/ __  /| \\__ \\ || (_) | |  | |_| | (_) |  _/  _  \\ (__| |_| | (_) | | | \\__ \\" << endl;
	cout << "\\/ /_/ |_|___/\\__\\___/|_|   \\__, |\\___/|_| \\_/ \\_/\\___|\\__|_|\\___/|_| |_|___/" << endl;
	cout << "                            |___/                                            " << endl;
}
void viewModule() {
	ifstream inputFile(fruitFile);
	fruitItem inventory[MAX_ITEMS];
	int numItems = 0; // Current number of items in inventory
	for (int i = 0; i < MAX_ITEMS; i++) {
		inventory[i].name[0] = '\0'; // set name to empty string
		inventory[i].price = 0; // set price to zero
		inventory[i].quantity = 0; // set quantity to zero
	}
	if (inputFile.is_open()) {
		while (numItems < MAX_ITEMS && inputFile.peek() != EOF) {
			inputFile.getline(inventory[numItems].name, 100);
			inputFile >> inventory[numItems].price >> inventory[numItems].quantity;
			inputFile.ignore(); // Ignore newline character
			numItems++;
		}
		inputFile.close();
		loadingbar();
		SetConsoleTextAttribute(h, 113);
	}
	else {
		SetConsoleTextAttribute(h, 79);
		cout << "Error: Could not open inventory file!" << endl;
	}
	SetConsoleTextAttribute(h, 11);
	cout << "dP     dP oo                     8888ba.88ba                 dP          dP          " << endl;
	cout << "88     88                        88  `8b  `8b                88          88          " << endl;
	SetConsoleTextAttribute(h, 3);
	cout << "88    .8P dP .d8888b. dP  dP  dP 88   88   88 .d8888b. .d888b88 dP    dP 88 .d8888b. " << endl;
	cout << "88    d8' 88 88ooood8 88  88  88 88   88   88 88'  `88 88'  `88 88    88 88 88ooood8 " << endl;
	SetConsoleTextAttribute(h, 9);
	cout << "88  .d8P  88 88.  ... 88.88b.88' 88   88   88 88.  .88 88.  .88 88.  .88 88 88.  ... " << endl;
	cout << "888888'   dP `88888P' 8888P Y8P  dP   dP   dP `88888P' `88888P8 `88888P' dP `88888P' " << endl;
	cout << "ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo" << "\n\n\n" << endl;
	SetConsoleTextAttribute(h, 7);
	int choice = -1;
	while (choice != 0) {
		cout << "\n\n" << string(30, char(61)) << endl;
		cout << "Please choose an option:\n";
		cout << string(30, char(61)) << endl;
		cout << "1. Current Inventory\n";
		cout << "2. History of Actions\n";
		cout << "0. Exit program\n";
		cout << string(30, char(61)) << endl;
		cout << "Option:";
		choice = getIntegerInput();
		cout << "\n\n";
		switch (choice) {
		case 1: //List out the current inventory
			system("cls");
			currentInventoryHeader();
			currentInventory(inventory, numItems);
			break;
		case 2: //List out the history of actions
			system("cls");
			historyheader();
			SetConsoleTextAttribute(h, 7);
			viewLog();
			break;
		case 0: // Exit program
			system("cls");
			break;
		default:
			cout << "Invalid choice. Please enter 1, 2, or 0.\n";
			break;
		}
	}
}
void stockHeader() {
	SetConsoleTextAttribute(h, 11);
	cout << string(8, char(219)) << string(4, ' ') << string(8, char(219)) << string(4, ' ') << string(8, char(219)) << string(4, ' ') << string(8, char(219)) << string(4, ' ') << string(2, char(219)) << string(4, ' ') << string(2, char(219)) << endl;
	cout << string(2, char(219)) << string(13, ' ') << string(2, char(219)) << string(7, ' ') << string(2, char(219)) << string(4, ' ') << string(2, char(219)) << string(4, ' ') << string(2, char(219)) << string(10, ' ') << string(2, char(219)) << string(2, ' ') << string(2, char(219)) << endl;
	cout << string(8, char(219)) << string(7, ' ') << string(2, char(219)) << string(7, ' ') << string(2, char(219)) << string(4, ' ') << string(2, char(219)) << string(4, ' ') << string(2, char(219)) << string(10, ' ') << string(4, char(219)) << endl;
	SetConsoleTextAttribute(h, 3);
	cout << string(6, ' ') << string(2, char(219)) << string(7, ' ') << string(2, char(219)) << string(7, ' ') << string(2, char(219)) << string(4, ' ') << string(2, char(219)) << string(4, ' ') << string(2, char(219)) << string(10, ' ') << string(2, char(219)) << string(2, ' ') << string(2, char(219)) << endl;
	cout << string(8, char(219)) << string(7, ' ') << string(2, char(219)) << string(7, ' ') << string(8, char(219)) << string(4, ' ') << string(8, char(219)) << string(4, ' ') << string(2, char(219)) << string(4, ' ') << string(2, char(219)) << "\n" << endl;
	SetConsoleTextAttribute(h, 9);
	cout << string(58, char(219)) << "\n\n" << endl;
}
int stock(int x) {// Function to allow shop admin add, delete or change items in inventory
	ifstream inputFile(fruitFile);
	fruitItem inventory[MAX_ITEMS];//Load existing inventory from file
	int numItems = 0; // Current number of items in inventory
	for (int i = 0; i < MAX_ITEMS; i++) {
		inventory[i].name[0] = '\0'; // set name to empty string
		inventory[i].price = 0.0; // set price to zero
		inventory[i].quantity = 0; // set quantity to zero
	}
	if (inputFile.is_open()) {
		while (numItems < MAX_ITEMS && inputFile.peek() != EOF) {
			inputFile.getline(inventory[numItems].name, 100);
			inputFile >> inventory[numItems].price >> inventory[numItems].quantity;
			inputFile.ignore(); // Ignore newline character
			numItems++;
		}
		inputFile.close();
		loadingbar();
		SetConsoleTextAttribute(h, 113);
		cout << "Inventory Loaded From File." << endl;
	}
	else {
		SetConsoleTextAttribute(h, 79);
		cout << "Error: Could not open inventory file!" << endl;
	}
	SetConsoleTextAttribute(h, 7);
	//Prompt user to add or change or delete an item
	int choice = -1;
	char choice2 = 'y';
	while (choice != 0) {
		cout << "\n";
		stockHeader();
		SetConsoleTextAttribute(h, 7);
		cout << "\n\n" << string(30, char(61)) << endl;
		cout << "Please choose an option:\n";
		cout << string(30, char(61)) << endl;
		cout << "1. Add a new item\n";
		cout << "2. Delete an existing item\n";
		cout << "3. Change an existing item\n";
		cout << "4. View Module\n";
		cout << "0. Exit program\n";
		cout << string(30, char(61)) << endl;
		cout << "Option:";
		choice = getIntegerInput();
		x = choice;
		cout << "\n\n";
		switch (choice) {
		case 1: // Add a new item
			system("cls");
			addNewItem(inventory, numItems);
			break;
		case 2: // Delete an existing item
			system("cls");
			deleteItem(inventory, numItems);
			break;
		case 3: // Change an existing item
			system("cls");
			changeItem(inventory, numItems);
			break;
		case 4: //  View Module
			system("cls");
			viewModule();
			break;
		case 0: // Exit program
			break;
		default:
			cout << "Invalid choice. Please enter 1, 2, 3, 4 or 0.\n";
			continue;
		}
		return x;
	}
	ofstream outputFile(fruitFile);//Save inventory to file
	if (outputFile.is_open()) {
		for (int i = 0; i < numItems; i++) {
			outputFile << inventory[i].name << endl;
			outputFile << fixed << setprecision(2) << inventory[i].price << " " << inventory[i].quantity << endl;
		}
		outputFile.close();
		SetConsoleTextAttribute(h, 113);
		cout << "Inventory saved to file.\n";
	}
	else {
		SetConsoleTextAttribute(h, 79);
		cout << "Error: Could not open inventory file for writing.\n";
	}
	SetConsoleTextAttribute(h, 7);
}
void income_statement() {//income statement used in financial report
	cout << string(7, ' ') << " " << char(46) << string(101, char(95)) << char(46) << endl;
	cout << string(7, ' ') << " " << char(124) << string(42, ' ') << "Income Statement" << string(43, ' ') << char(124) << endl;
	cout << string(7, ' ') << " " << char(124) << string(101, char(95)) << char(124) << endl;
	cout << string(7, ' ') << " " << char(124) << " " << left << setw(70) << "Revenue" << right << setw(20) << revenue << setw(11) << right << char(124) << endl;
	cout << string(7, ' ') << " " << char(124) << " " << left << setw(70) << "Cost of Goods Sold (COGS)" << right << setw(20) << cost_of_goods << setw(11) << right << char(124) << endl;
	cout << string(7, ' ') << " " << char(124) << string(101, char(95)) << char(124) << endl;
	cout << string(7, ' ') << " " << char(124) << " " << left << setw(70) << "Gross Profit" << right << setw(20) << gross_profit << setw(11) << right << char(124) << endl;
	cout << string(7, ' ') << " " << char(124) << string(101, ' ') << char(124) << endl;
	cout << string(7, ' ') << " " << char(124) << " " << left << setw(70) << "Expenses" << right << setw(31) << char(124) << endl;
	cout << string(7, ' ') << " " << char(124) << string(3, ' ') << left << setw(70) << "Software maintenance" << right << setw(18) << software_maintenance << setw(11) << right << char(124) << endl;
	cout << string(7, ' ') << " " << char(124) << string(3, ' ') << left << setw(70) << "Salaries" << right << setw(18) << salaries << setw(11) << right << char(124) << endl;
	cout << string(7, ' ') << " " << char(124) << string(101, char(95)) << char(124) << endl;
	cout << string(7, ' ') << " " << char(124) << " " << left << setw(70) << "Total Expenses" << right << setw(20) << total_expenses << setw(11) << right << char(124) << endl;
	cout << string(7, ' ') << " " << char(124) << string(101, char(95)) << char(124) << endl;
	cout << string(7, ' ') << " " << char(124) << " " << left << setw(70) << "Earnings before tax" << right << setw(20) << earnings_bf_tax << setw(11) << right << char(124) << endl;
	cout << string(7, ' ') << " " << char(124) << string(101, ' ') << char(124) << endl;
	cout << string(7, ' ') << " " << char(124) << " " << left << setw(70) << "Tax" << right << setw(20) << tax << setw(11) << right << char(124) << endl;
	cout << string(7, ' ') << " " << char(124) << string(101, char(95)) << char(124) << endl;
	cout << string(7, ' ') << " " << char(124) << " " << left << setw(70) << "Net Earnings" << right << setw(20) << net_earnings << setw(11) << right << char(124) << endl;
	cout << string(7, ' ') << " " << char(124) << string(101, char(95)) << char(124) << endl;
}
void financial_report() {//financial report to show current business status
	ofstream report;
	report.open("Financial Report.txt");  // save data inside the file named "Financial Report"
	cout << "88888888b  @@                                         @@            dP    888888ba                                             dP     " << endl;
	cout << "88                                                                  88    88    `8b                                            88     " << endl;
	cout << "a88aaaa    dP  88d888b.  .d8888b.  88d888b.  .d8888b. dP  .d8888b.  88    a88aaaa8P' .d8888b.  88d888b.  .d8888b.  88d888b.  d8888P   " << endl;
	cout << "88         88  88'  `88  88'  `88  88'  `88  88'  `   88  88'  `88  88    88   `8b.  88ooood8  88'  `88  88'  `88  88'  `88    88     " << endl;
	cout << "88         88  88    88  88.  .88  88    88  88.  ... 88  88.  .88  88    88     88  88.  ...  88.  .88  88.  .88  88          88     " << endl;
	cout << "dP         dP  dP    dP  `88888P8  dP    dP  `88888P' dP  `88888P8  dP    dP     dP  `88888P'  88Y888P'  `88888P'  dP          dP     " << endl;
	cout << "	                                                                                       88                                          " << endl;
	cout << "                                                                                               dP                                     " << endl;
	revenue = total_revenue();  // Call the total revenue function and assign the value of total revenue to revenue
	cost_of_goods = cost_goods();
	gross_profit = revenue - cost_of_goods;
	software_maintenance = 200.00;
	no_worker = 1;  //number of workers
	salaries = 1500.00 * no_worker;
	total_expenses = software_maintenance + salaries;
	earnings_bf_tax = gross_profit - total_expenses;
	net_earnings = earnings_bf_tax - tax;
	//Tax rate provided by LDHN Malaysia is used as reference //Tax rate below only illustrates the tax rate for category A and B
	if (earnings_bf_tax <= 5000)
		tax = 0;
	else if (earnings_bf_tax > 5000 && earnings_bf_tax <= 20000)
	{
		earn_being_taxed = earnings_bf_tax - 5000;
		tax = (1.0 / 100) * earn_being_taxed;
	}
	//record data into financial report
	report << fixed << setprecision(2);
	report << left << string(60, char(95)) << endl;
	report << right << string(23, ' ') << "Income Statement " << endl;
	report << left << string(60, char(95)) << endl;
	report << left << setw(30) << "Revenue " << setw(30) << right << revenue << endl;
	report << left << setw(30) << "Cost of Goods Sold (COGS) " << setw(30) << right << cost_of_goods << endl;
	report << left << string(60, char(95)) << endl;
	report << left << setw(30) << "Gross Profit " << setw(30) << right << gross_profit << endl;
	report << string(100, ' ') << endl;
	report << left << setw(30) << "Expenses " << endl;
	report << left << setw(30) << " Software maintenance " << setw(30) << right << software_maintenance << endl;
	report << left << setw(30) << " Salaries" << setw(30) << right << salaries << endl;
	report << left << string(60, char(95)) << endl;
	report << left << setw(30) << "Total Expenses " << setw(30) << right << total_expenses << endl;
	report << left << string(60, char(95)) << endl;
	report << left << setw(30) << "Earnings before tax " << setw(30) << right << earnings_bf_tax << endl;
	report << string(100, ' ') << endl;
	report << left << setw(30) << "Tax " << setw(30) << right << tax << endl;
	report << left << string(60, char(95)) << endl;
	report << left << setw(30) << "Net Earnings: " << setw(30) << right << net_earnings << endl;
	cout << fixed << setprecision(2);
	cout << endl << endl << endl;
	income_statement();
	cout << "\n" << "\tThe business in currently experiencing profit or loss: ";
	if (net_earnings > 0)
		cout << string(33, ' ') << "profit " << endl;
	else
		cout << string(33, ' ') << "loss" << endl;
	report.close();  // close the file
}
void GoodsItems(costItem inventory[], int& numItems) {//Function to show items inside CostGoods file
	cout << "\n\n" << string(120, char(61)) << "\n" << endl;
	cout << "No. " << "Type of fruit\t\t\t\t\t    " << "Cost of Goods\t\t    " << "Number of stocks per kg" << endl;
	cout << string(120, char(61)) << "\n" << endl;
	for (int i = 0; i < numItems; i++) {
		cout << left << setw(4) << i + 1 << left << setw(50) << inventory[i].name;
		cout << "\t" << right << setw(10) << "RM  " << fixed << setprecision(2) << inventory[i].cost;
		cout << "\t\t\t" << right << setw(10) << inventory[i].stock << " stocks per kg\n";
	}
	cout << string(120, char(61)) << endl;
}
double cost_goods() {//calculate cost of goods (COGS) to be used in income statement
	cout << fixed << setprecision(2);
	ifstream inputFile(inGoods);
	costItem cost_inventory[MAX_ITEMS];
	int numItems = 0;
	double cost_of_goods = 0, stock = 0, cost = 0, total_cost = 0;
	for (int i = 0; i < MAX_ITEMS; i++) {
		cost_inventory[i].name[0] = '\0'; // set name to empty string
		cost_inventory[i].cost = 0.0; // set price to zero
		cost_inventory[i].stock = 0; // set quantity to zero
	}
	if (inputFile.is_open()) {
		while (numItems < MAX_ITEMS && inputFile.peek() != EOF) {
			inputFile.getline(cost_inventory[numItems].name, 100);
			inputFile >> cost_inventory[numItems].cost >> cost_inventory[numItems].stock;
			inputFile.ignore(); // Ignore newline character
			numItems++;
		}
		inputFile.close();
	}
	else {
		cout << "Error" << endl;
	}
	GoodsItems(cost_inventory, numItems);
	for (int i = 0; i < numItems; i++) {// Calculate cost of goods and total cost
		double cost_of_goods = cost_inventory[i].cost * cost_inventory[i].stock;
		total_cost += cost_of_goods;
	}
	cout << "\n" << "Total cost of goods : RM " << total_cost << endl;
	return total_cost;
}
void menu() {//menu page for admin to choose the operation wanted to be done 
	cout << "         ____  " << endl;
	cout << "        |-   |" << endl;
	cout << "        |-   | _________________________________________" << endl;
	cout << "       /                                                 \\" << endl;
	cout << "      /    . %%.....%%.. %%%%%%.. %%.. %%.. %%.. %%.      \\" << endl;
	cout << "     /     . %%%...%%%.. %%...... %%%. %%.. %%.. %%.       \\" << endl;
	cout << "    /      . %%..%..%%.. %%%%.... %%. %%%.. %%.. %%.        \\" << endl;
	cout << "   /       . %%.....%%.. %%...... %%.. %%.. %%.. %%.         \\" << endl;
	cout << "  /        . %%.....%%.. %%%%%%.. %%.. %%.... %%%%..          \\" << endl;
	cout << " / 	    .........................................          \\" << endl;
	cout << "/______________________________________________________________ \\" << endl;
	cout << "|                                                               |" << endl;
	cout << "|  1. Stock                    ,--./,-.          _              |" << endl;
	cout << "|  2. Transaction History     / #      \\       _ \\'-_,#         |" << endl;
	cout << "|  3. Owned Inventory        |          |     _\\'--','`|        |" << endl;
	cout << "|  4. Financial Report        \\        /     \\`---`  /          |" << endl;
	cout << "|  5. Exit                     `._,._,'       `----'`           |" << endl;
	cout << "|                                                               |" << endl;
	cout << "|_______________________________________________________________|" << endl;
}
void ch1() {
	ifstream input(inGoods);
	costItem cost_inventory[MAX_ITEMS];
	int numItems = 0;// Current number of items in inventory
	for (int i = 0; i < MAX_ITEMS; i++) {
		cost_inventory[i].name[0] = '\0'; // set name to empty string
		cost_inventory[i].cost = 0.0; // set price to zero
		cost_inventory[i].stock = 0; // set quantity to zero
	}
	if (input.is_open()) {
		while (numItems < MAX_ITEMS && input.peek() != EOF) {
			input.getline(cost_inventory[numItems].name, 100);
			input >> cost_inventory[numItems].cost >> cost_inventory[numItems].stock;
			input.ignore(); // Ignore newline character
			numItems++;
		}
		input.close();
		system("CLS");
		warning_bar();
		SetConsoleTextAttribute(h, 113);
		cout << "Inventory Loaded From File." << endl;
	}
	else {
		SetConsoleTextAttribute(h, 113);
		cout << "Error: Could not open inventory file!" << endl;
	}
	SetConsoleTextAttribute(h, 7);
	cout << "Detect inventory change!" << endl;
	cout << "Please update bought inventory accordingly!" << endl;
	addNewCostItem(cost_inventory, numItems);
	cout << "Please enter any key to exit " << endl;
}
void ch2() {
	ifstream input(inGoods);
	costItem cost_inventory[MAX_ITEMS];
	int numItems = 0;// Current number of items in inventory
	for (int i = 0; i < MAX_ITEMS; i++) {
		cost_inventory[i].name[0] = '\0'; // set name to empty string
		cost_inventory[i].cost = 0.0; // set price to zero
		cost_inventory[i].stock = 0; // set quantity to zero
	}
	if (input.is_open()) {
		while (numItems < MAX_ITEMS && input.peek() != EOF) {
			input.getline(cost_inventory[numItems].name, 100);
			input >> cost_inventory[numItems].cost >> cost_inventory[numItems].stock;
			input.ignore(); // Ignore newline character
			numItems++;
		}
		input.close();
		system("CLS");
		warning_bar();
		SetConsoleTextAttribute(h, 113);
		cout << "Inventory Loaded From File." << endl;
	}
	else {
		SetConsoleTextAttribute(h, 113);
		cout << "Error: Could not open inventory file!" << endl;
	}
	SetConsoleTextAttribute(h, 7);
	cout << "Detect inventory change!" << endl;
	cout << "Please update bought inventory accordingly!" << endl;
	deleteCostItem(cost_inventory, numItems);
	cout << "Please enter any key to exit " << endl;
}
void ch3() {
	ifstream input(inGoods);
	costItem cost_inventory[MAX_ITEMS];
	int numItems = 0;// Current number of items in inventory
	for (int i = 0; i < MAX_ITEMS; i++) {
		cost_inventory[i].name[0] = '\0'; // set name to empty string
		cost_inventory[i].cost = 0.0; // set price to zero
		cost_inventory[i].stock = 0; // set quantity to zero
	}
	if (input.is_open()) {
		while (numItems < MAX_ITEMS && input.peek() != EOF) {
			input.getline(cost_inventory[numItems].name, 100);
			input >> cost_inventory[numItems].cost >> cost_inventory[numItems].stock;
			input.ignore(); // Ignore newline character
			numItems++;
		}
		input.close();
		system("CLS");
		warning_bar();
		SetConsoleTextAttribute(h, 113);
		cout << "Inventory Loaded From File." << endl;
	}
	else {
		SetConsoleTextAttribute(h, 113);
		cout << "Error: Could not open inventory file!" << endl;
	}
	SetConsoleTextAttribute(h, 7);
	cout << "Detect inventory change!" << endl;
	cout << "Please update bought inventory accordingly!" << endl;
	changeCostItem(cost_inventory, numItems);
	cout << "Please enter any key to exit " << endl;
}
void main_menu() {
	int selection = 0, selection1 = 0, selection2 = 0, x = 0, choice1 = 0;
	char choice2 = 'n';
	int orderno = getOrderNo(); //get the order number
	++orderno;
	bool exit_menu = false;
	do {
		do {
			system("CLS");
			mainHeader();
			cout << "Please select your role: " << endl;
			cout << "1. User" << endl;
			cout << "2. Shop Admin" << endl;
			cout << "Your selection: ";
			selection1 = getIntegerInput();
			switch (selection1)
			{
			case 1:
				do {
					system("CLS");
					loadingbar();
					SetConsoleTextAttribute(h, 7);
					string purchaseitem[MAX_ORDER] = { " " };
					double purchaseamount[MAX_ORDER] = { 0 };
					salesmodule(orderno, purchaseitem, purchaseamount);
					cout << endl;
					cout << "0- Exit or 1 - Reorder \n";
					cout << "Your selection: ";
					selection2 = getIntegerInput();

				} while (selection2 == 1);
				break;
			case 2:
				do {
					system("CLS");
					menu();
					cout << "Please select what you want to view : " << endl;
					cout << "Your selection: ";
					selection = getIntegerInput();
					switch (selection)
					{
					case 1:
						system("CLS");
						choice1 = stock(x);

						if (choice1 == 1) {
							ch1();
							break;
						}
						else if (choice1 == 2) {
							ch2();
							break;
						}
						else if (choice1 == 3) {
							ch3();
							break;
						}
						else if (choice1 == 4) {
							bool exit_view = false;
							do
							{
								cout << "Do you want to view bought inventory? [Y/N]: ";
								cin >> choice2;
								if (choice2 == 'y' || choice2 == 'Y')
								{
									system("pause");
									Bought_ItemStock();
									exit_view = true;
								}
								else if (choice2 == 'n' || choice2 == 'N')
								{
									cout << "Please enter any key to exit " << endl;
									exit_view = true;
								}
								else
								{
									cout << "Invalid selection! " << endl;
									cout << "Please re-enter! " << endl;
								}
							} while (!exit_view);
							break;
						}
					case 2:
						system("CLS");
						loadingbar();
						SetConsoleTextAttribute(h, 7);
						transactionHistory(orderno);
						cout << "Please enter any key to exit " << endl;
						break;
					case 3:
						system("CLS");
						Bought_ItemStock();
						cout << "Please enter any key to exit " << endl;
						break;
					case 4:
						system("CLS");
						financial_report();
						system("pause");
						cout << "Please enter any key to exit " << endl;
						break;
					}
				} while (selection != 5);
			}exit_menu = false;
		} while (!exit_menu);
	} while (selection1 != 1 && selection1 != 2);
}

int main() {
	main_menu();
	system("pause");
	return 0;
}
