#include<iostream>
#include<fstream>
#include<vector>
#include<unistd.h>
#include<iomanip>
#include<algorithm>

using namespace std;

struct Book {
    string title;
    string author;
    string genre;
    int year;
    double price;
};

struct Order {
    string customerName;
    string bookTitle;
    int quantity;
};


// Function prototypes
void login(); //Login page (first)
void registration(); // registration page
void log_menu(); // Logging menu page
void mainguest_menu(); // Logging menu page for guest
void mainlog_menu(); //Login page (second)
void AddBooks(); // Add books
void ViewBooks(); // View books
void SearchBooks(); // Search books
void AddOrder(); // Add orders
void ViewOrders(); // View orders
void PrintQuotation(); // Quotation print
void logout(); // Log out
void exitProgram(); // Exit


int main()
{
    int c;
    cout << "|---------------------------------------------------------|" << endl;
    cout << "|              WELCOME TO NETHRA BOOK SHOP                |" << endl;
    cout << "|---------------------------------------------------------|" << endl;
    cout << "|                                                         |" << endl;
    cout << "|                #####################                    |" << endl;
    cout << "|                #         1         #                    |" << endl;
    cout << "|                #       Login       #                    |" << endl;
    cout << "|                #####################                    |" << endl;
    cout << "|                      *   *   *                          |" << endl;
    cout << "|                   ---------------                       |" << endl;
    cout << "|                      *   *   *                          |" << endl;
    cout << "|                #####################                    |" << endl;
    cout << "|                #         2         #                    |" << endl;
    cout << "|                #      Register     #                    |" << endl;
    cout << "|                #####################                    |" << endl;
    cout << "|                      *   *   *                          |" << endl;
    cout << "|                   ---------------                       |" << endl;
    cout << "|                      *   *   *                          |" << endl;
    cout << "|                #####################                    |" << endl;
    cout << "|                #         3         #                    |" << endl;
    cout << "|                #       Exit        #                    |" << endl;
    cout << "|                #####################                    |" << endl;
    cout << "|                                                         |" << endl;
    cout << "|_________________________________________________________|" << endl;
    cout << "|Enter Access Level:                                      |" << endl;
    cout << endl;
    cin >> c;
    cout << "                                    " << endl;

    switch (c)
    {
    case 1:
        login();
        break;

    case 2:
        registration();
        break;

    case 3:
    cout << "\t\t\t Thank You! \n\n";
    exitProgram();
    break;

    default:
        system("cls");
        cout << "\t\t\t Please Select from the Option Given Above \n"
             << endl;
        main();
    }
}

void login()
{
    int count = 0;
    string userId, password, id, pass;
    system("cls");

    cout << endl;
    cout << "|---------------------------------------------------------|" << endl;
    cout << "|          Welcome to NETHRA BOOK SHOP Login System       |" << endl;
    cout << "|---------------------------------------------------------|" << endl;

    cout << "  |-Input Login name:";
    cin >> userId;
    cout << "  |-Input Login Password:";
    cin >> password;

    ifstream input("records.txt");

    while (input >> id >> pass)
    {
        if (id == userId && pass == password)
        {
            count = 1;
            system("cls");
        }
    }
    input.close();

    if (count == 1)
    {

        cout << "Hello \t" << userId << "\n Your LOGIN is Successful \n Thanks for logging in ! \n";
        log_menu();
    }
    else
    {
        cout << " \n LOGIN ERROR! \n Please check your UserName and Password\n";
        main();
    }
}

void log_menu()
{
    system("cls");
      int c;
    cout << "|---------------------------------------------------------|" << endl;
    cout << "|              WELCOME TO NETHRA BOOK SHOP                |" << endl;
    cout << "|---------------------------------------------------------|" << endl;
    cout << "|                                                         |" << endl;
    cout << "|                #####################                    |" << endl;
    cout << "|                #         1         #                    |" << endl;
    cout << "|                #       Admin       #                    |" << endl;
    cout << "|                #####################                    |" << endl;
    cout << "|                      *   *   *                          |" << endl;
    cout << "|                   ---------------                       |" << endl;
    cout << "|                      *   *   *                          |" << endl;
    cout << "|                #####################                    |" << endl;
    cout << "|                #         2         #                    |" << endl;
    cout << "|                #       Guest       #                    |" << endl;
    cout << "|                #####################                    |" << endl;
    cout << "|                      *   *   *                          |" << endl;
    cout << "|                   ---------------                       |" << endl;
    cout << "|                      *   *   *                          |" << endl;
    cout << "|                #####################                    |" << endl;
    cout << "|                #         3         #                    |" << endl;
    cout << "|                #       Exit        #                    |" << endl;
    cout << "|                #####################                    |" << endl;
    cout << "|                                                         |" << endl;
    cout << "|_________________________________________________________|" << endl;
    cout << "|Enter Access Level:                                      |" << endl;
    cout << endl;
    cin >> c;
    cout << "                                    " << endl;

    switch (c)
    {
    case 1:
        mainlog_menu();
        break;

    case 2:
        mainguest_menu();
        break;

    case 3:
    cout << "\t\t\t Thank You! \n\n";
    exitProgram();
    break;

    default:
        system("cls");
        cout << "\t\t\t Please Select from the Option Given Above \n"
             << endl;
        main();
    }

}


void registration()
{
    string ruserId, rpassword, rid, rpass;
    system("cls");

    cout << endl;
    cout << "|---------------------------------------------------------|" << endl;
    cout << "|      Welcome to NETHRA BOOK SHOP Registration System    |" << endl;
    cout << "|---------------------------------------------------------|" << endl;
    cout << "  |-Enter User Name:";
    cin >> ruserId;

    cout << "  |-Enter Password:";
    cin >> rpassword;

    ofstream f1("records.txt", ios::app);
    f1 << ruserId << ' ' << rpassword << endl;
    system("cls");

    cout << "\n Your Registration is Successful ! \n";
    main();

}

void mainlog_menu()
{
    system("cls");
   cout<<endl;
	cout << "##############################################################################" << endl;
	cout << "                      WELCOME to the Main Admin Menu                          " << endl;
	cout << "##############################################################################" << endl << endl;
	cout << "                   Please,  Select from the following Options :               " << endl << endl;
	cout << " ____________________________________________________________________________ " << endl;
	cout << "|                                           	                             |" << endl;
	cout << "|                   1   Add Books                                            |" << endl;
	cout << "|                   2   View Books                                           |" << endl;
	cout << "|                   3   Search Books                                         |" << endl;
	cout << "|                   4   View Orders                                          |" << endl;
	cout << "|                   5   Print Quotation                                      |" << endl;
	cout << "|                   6   Log out                                              |" << endl;
	cout << "|                   7   Exit                                                 |" << endl;
	cout << "|____________________________________________________________________________|" << endl;
	cout << endl<<endl;

	int option;
	cout << "Select 1,2,3,4,5,6,7: ";
	cin >> option;

	switch (option) {
		case 1: AddBooks();
			break;
		case 2: ViewBooks();
			break;
		case 3: SearchBooks();
			break;
		case 4: ViewOrders();
			break;
		case 5: PrintQuotation();
			break;
		case 6:system("cls");
				logout();
			break;
		case 7:log_menu();
				break;
		default: cout << "Invalid options Please enter 1,2,3,4,5,6,7!" << endl;
		break;
	}
	system("pause");
}

void mainguest_menu()
{
    system("cls");
 cout<<endl;
	cout << "##############################################################################" << endl;
	cout << "                     WELCOME to the Main Guest Menu                           " << endl;
	cout << "##############################################################################" << endl << endl;
	cout << "                   Please,  Select from the following Options :               " << endl << endl;
	cout << " ____________________________________________________________________________ " << endl;
	cout << "|                                           	                             |" << endl;
	cout << "|                   1   View Books                                           |" << endl;
	cout << "|                   2   Search Books                                         |" << endl;
	cout << "|                   3   Add Order                                            |" << endl;
	cout << "|                   4   Print Quotation                                      |" << endl;
	cout << "|                   5   Log out                                              |" << endl;
	cout << "|                   6   Exit                                                 |" << endl;
	cout << "|____________________________________________________________________________|" << endl;
	cout << endl<<endl;

	int option;
	cout << "Select 1,2,3,4,5,6: ";
	cin >> option;

	switch (option) {
		case 1: ViewBooks();
			break;
		case 2: SearchBooks();
			break;
		case 3: AddOrder();
			break;
		case 4: PrintQuotation();
			break;
		case 5:system("cls");
				logout();
			break;
		case 6:log_menu();
				break;
		default: cout << "Invalid options Please enter 1,2,3,4,5,6!" << endl;
		break;
	}
	system("pause");


}

void AddBooks() {
    system("cls");
    Book newBook;
    cout << endl;
    cout << "|---------------------------------------------------------|" << endl;
    cout << "|             NETHRA BOOK SHOP - Add Books                |" << endl;
    cout << "|---------------------------------------------------------|" << endl;
    cout << "  |-Enter Book Title: ";
    cin.ignore();
    getline(cin, newBook.title);

    cout << "  |-Enter Author: ";
    getline(cin, newBook.author);

    cout << "  |-Enter Genre: ";
    getline(cin, newBook.genre);

    cout << "  |-Enter Publication Year: ";
    cin >> newBook.year;

    cout << "  |-Enter Price (in rupees): ";
    cin >> newBook.price;

    ofstream booksFile("books.txt", ios::app);
    booksFile << newBook.title << ',' << newBook.author << ',' << newBook.genre << ',' << newBook.year << ',' << newBook.price << endl;
    booksFile.close();

    cout << "Book added successfully!\n";

    cout << "\nDo you want to go back or add another book? (1 for go back, 0 for add another book): ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            system("cls");
            mainlog_menu();
        } else {
            AddBooks();
        }


}


void ViewBooks() {
    system("cls");
    ifstream booksFile("books.txt");
    if (booksFile.is_open()) {
        string line;
    cout << "|-------------------------------------------------------------------------------------|" << endl;
    cout << "|                            NETHRA BOOK SHOP - List of Books                         |" << endl;
    cout << "|-------------------------------------------------------------------------------------|" << endl;
        cout << setw(30) << left << "Title" << setw(20) << left << "Author"
             << setw(10) << left << "Year" << setw(10) << left << "Price" << endl;

        while (getline(booksFile, line)) {
            stringstream ss(line);
            string title, author, genre;
            int year;
            double price;

            getline(ss, title, ',');
            getline(ss, author, ',');
            getline(ss, genre, ',');
            ss >> year;
            ss.ignore();
            ss >> price;


            cout << setw(30) << left << title << setw(20) << left << author
                 << setw(10) << left << year << setw(10) << left << "Rs. " << fixed << setprecision(2) << price << endl;
        }

        booksFile.close();


        cout << "\nDo you want to go back? (1 for Yes, 0 for No): ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            system("cls");
            log_menu();
        } else {
            cout << "Exiting...\n";
            exitProgram();
        }
    } else {
        cout << "Unable to open books file.\n";
    }
}



void SearchBooks() {
    system("cls");
    string searchPrefix;
    cout << "|-------------------------------------------------------------------------------------|" << endl;
    cout << "|                            NETHRA BOOK SHOP - Search Books                         |" << endl;
    cout << "|-------------------------------------------------------------------------------------|" << endl;
    cout << "  |-Enter the title to search: ";
    cin.ignore();
    getline(cin, searchPrefix);
    transform(searchPrefix.begin(), searchPrefix.end(), searchPrefix.begin(), ::tolower);

    ifstream booksFile("books.txt");
    if (booksFile.is_open()) {
        string line;
        bool resultsFound = false;

        cout << "\nSearch Results:\n";
        cout << setw(30) << left << "Title" << setw(20) << left << "Author"
             << setw(10) << left << "Year" << setw(10) << left << "Price" << endl;

        while (getline(booksFile, line)) {
            stringstream ss(line);
            string title, author, genre;
            int year;
            double price;

            getline(ss, title, ',');
            getline(ss, author, ',');
            getline(ss, genre, ',');
            ss >> year;
            ss.ignore();
            ss >> price;

            transform(title.begin(), title.end(), title.begin(), ::tolower);

            if (title.find(searchPrefix) != string::npos) {
                cout << setw(30) << left << title << setw(20) << left << author
                     << setw(10) << left << year << setw(10) << left << "Rs. " << fixed << setprecision(2) << price << endl;
                resultsFound = true;
            }
        }

        booksFile.close();

        if (!resultsFound) {
            cout << "No results found for the given search.\n";
        }

        cout << "\nDo you want to go back? (1 for Yes, 0 for No): ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            system("cls");
            log_menu();
        } else {
            SearchBooks();
        }
    } else {
        cout << "Unable to open books file.\n";
    }
}


void AddOrder()
{
    system("cls");
    cout << "|-------------------------------------------------------------------------------|" << endl;
    cout << "|                           NETHRA BOOK SHOP - Add Order                        |" << endl;
    cout << "|-------------------------------------------------------------------------------|" << endl;


    cout << "Available Books:\n";
    ifstream booksFile("books.txt");

    if (booksFile.is_open())
    {
        string line;

        cout << setw(30) << left << "Title" << setw(20) << left << "Author"
             << setw(10) << left << "Year" << setw(10) << left << "Price" << endl;

        int bookCount = 1;

        while (getline(booksFile, line))
        {
            stringstream ss(line);
            string title, author, genre;
            int year;
            double price;

            getline(ss, title, ',');
            getline(ss, author, ',');
            getline(ss, genre, ',');
            ss >> year;
            ss.ignore();
            ss >> price;


            cout << bookCount << ". " << setw(30) << left << title << setw(20) << left << author
                 << setw(10) << left << year << setw(10) << left << "Rs. " << fixed << setprecision(2) << price << endl;

            bookCount++;
        }

        booksFile.close();
    }
    else
    {
        cout << "Unable to open books file.\n";
        return;
    }


    string customerName, bookTitle;
    int quantity;

    cout << "\nEnter customer name: ";
    cin >> customerName;

    cout << "Enter book title: ";
    cin.ignore();
    getline(cin, bookTitle);

    cout << "Enter quantity: ";
    cin >> quantity;


    ifstream checkBookFile("books.txt");
    bool bookExists = false;

    if (checkBookFile.is_open())
    {
        string checkLine;

        while (getline(checkBookFile, checkLine))
        {
            stringstream checkSS(checkLine);
            string checkTitle, checkAuthor, checkGenre;
            int checkYear;
            double checkPrice;

            getline(checkSS, checkTitle, ',');
            getline(checkSS, checkAuthor, ',');
            getline(checkSS, checkGenre, ',');
            checkSS >> checkYear;
            checkSS.ignore();
            checkSS >> checkPrice;

            if (checkTitle == bookTitle)
            {
                bookExists = true;
                break;
            }
        }

        checkBookFile.close();
    }
    else
    {
        cout << "Unable to open books file.\n";
        return;
    }

    if (!bookExists)
    {
        cout << "Book not found. Please make sure to enter a valid book title.\n";
        return;
    }


    ofstream ordersFile("orders.txt", ios::app);

    if (ordersFile.is_open())
    {
        ordersFile << customerName << ',' << bookTitle << ',' << quantity << endl;
        ordersFile.close();

        cout << "Order added successfully!\n";
    }
    else
    {
        cout << "Unable to open orders file.\n";
        return;
    }


    char addMore;
    cout << "Do you want to add more orders? (y/n): ";
    cin >> addMore;

    if (addMore == 'y' || addMore == 'Y')
    {
        AddOrder();
    }
    else
    {

        cout << "\nDo you want to go back? (1 for Yes, 0 for No): ";
        int choice;
        cin >> choice;

        if (choice == 1)
        {
            system("cls");
            mainguest_menu();
        }
        else
        {
            cout << "Exiting...\n";
            exitProgram();
        }
    }
}



void ViewOrders()
{
    system("cls");
    cout << "|----------------------------------------------------------------------------------|" << endl;
    cout << "|                            NETHRA BOOK SHOP - View Orders                        |" << endl;
    cout << "|----------------------------------------------------------------------------------|" << endl;

    ifstream ordersFile("orders.txt");
    ifstream booksFile("books.txt");

    if (!ordersFile.is_open() || !booksFile.is_open())
    {
        cout << "Unable to open orders or books file.\n";
        ordersFile.close();
        booksFile.close();


        cout << "\nDo you want to go back? (1 for Yes, 0 for No): ";
        int choice;
        cin >> choice;

        if (choice == 1)
        {
            system("cls");
            mainlog_menu();
        }
        else
        {
            cout << "Exiting...\n";
            exitProgram();
        }

        return;
    }

    string orderLine;
    string bookLine;

    cout << setw(20) << left << "Customer Name" << setw(30) << left << "Book Title" << setw(10) << left << "Quantity" << setw(10) << left << "Price" << endl;

    while (getline(ordersFile, orderLine))
    {
        stringstream orderSS(orderLine);
        string customerName, bookTitle;
        int quantity;

        getline(orderSS, customerName, ',');
        getline(orderSS, bookTitle, ',');
        orderSS >> quantity;

        bool bookFound = false;

        while (getline(booksFile, bookLine))
        {
            stringstream bookSS(bookLine);
            string title, author, genre;
            int year;
            double price;

            getline(bookSS, title, ',');
            getline(bookSS, author, ',');
            getline(bookSS, genre, ',');
            bookSS >> year;
            bookSS.ignore();
            bookSS >> price;


            if (bookTitle == title)
            {
                cout << setw(20) << left << customerName << setw(30) << left << title << setw(10) << left << quantity << setw(10) << left << "Rs. " << fixed << setprecision(2) << price * quantity << endl;
                bookFound = true;
                break;
            }
        }


        if (!bookFound)
        {
            cout << "Book not found: " << bookTitle << " (Customer: " << customerName << ")\n";
        }


        booksFile.clear();
        booksFile.seekg(0, ios::beg);
    }

    ordersFile.close();
    booksFile.close();


    cout << "\nDo you want to go back? (1 for Yes, 0 for No): ";
    int choice;
    cin >> choice;

    if (choice == 1)
    {
        system("cls");
        mainlog_menu();
    }
    else
    {
        cout << "Exiting...\n";
        exitProgram();
    }
}


void PrintQuotation() {
    system("cls");
    cout << "|------------------------------------------------------------------------------|" << endl;
    cout << "|                     NETHRA BOOK SHOP - Print Quotation                       |" << endl;
    cout << "|------------------------------------------------------------------------------|" << endl;

    ifstream ordersFile("orders.txt");
    ifstream booksFile("books.txt");

    if (!ordersFile.is_open() || !booksFile.is_open()) {
        cout << "Unable to open orders or books file.\n";
        ordersFile.close();
        booksFile.close();
        return;
    }

    string orderLine;
    string bookLine;


    vector<string> customerNames;

    while (getline(ordersFile, orderLine)) {
        stringstream orderSS(orderLine);
        string customerName, bookTitle;
        int quantity;

        getline(orderSS, customerName, ',');
        getline(orderSS, bookTitle, ',');
        orderSS >> quantity;


        if (find(customerNames.begin(), customerNames.end(), customerName) == customerNames.end()) {
            customerNames.push_back(customerName);
        }
    }


    cout << "Available Customers:\n";
    for (size_t i = 0; i < customerNames.size(); ++i) {
        cout << i + 1 << ". " << customerNames[i] << endl;
    }


    int customerIndex;
    cout << "Select a customer (enter the customer number): ";
    cin >> customerIndex;


    if (customerIndex < 1 || customerIndex > static_cast<int>(customerNames.size())) {
        cout << "Invalid selection!";
        cout << "\nDo you want to try again? (1 for Yes, 0 for No): ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        system("cls");
        PrintQuotation();
    } else {
        log_menu();
    }
        return;
    }


    string selectedCustomer = customerNames[customerIndex - 1];

    cout << setw(20) << left << "Customer Name" << setw(30) << left << "Book Title" << setw(10) << left << "Quantity"
         << setw(10) << left << "Price" << endl;

    double totalPrice = 0.0;


    ordersFile.clear();
    ordersFile.seekg(0, ios::beg);

    while (getline(ordersFile, orderLine)) {
        stringstream orderSS(orderLine);
        string customerName, bookTitle;
        int quantity;

        getline(orderSS, customerName, ',');
        getline(orderSS, bookTitle, ',');
        orderSS >> quantity;


        if (customerName == selectedCustomer) {
            bool bookFound = false;

            while (getline(booksFile, bookLine)) {
                stringstream bookSS(bookLine);
                string title, author, genre;
                int year;
                double price;

                getline(bookSS, title, ',');
                getline(bookSS, author, ',');
                getline(bookSS, genre, ',');
                bookSS >> year;
                bookSS.ignore();
                bookSS >> price;


                if (bookTitle == title) {
                    cout << setw(20) << left << customerName << setw(30) << left << title << setw(10) << left << quantity
                         << setw(10) << left << "Rs. " << fixed << setprecision(2) << price * quantity << endl;
                    totalPrice += price * quantity;
                    bookFound = true;
                    break;
                }
            }

            if (!bookFound) {
                cout << "Book not found: " << bookTitle << " (Customer: " << customerName << ")\n";
            }


            booksFile.clear();
            booksFile.seekg(0, ios::beg);
        }
    }


    ordersFile.close();
    booksFile.close();


    double discount = 0.0;
    if (totalPrice > 2000) {
        discount = 0.05 * totalPrice;
    }


    cout << "\nTotal Price: Rs. " << fixed << setprecision(2) << totalPrice << endl;
    cout << "Discount: Rs. " << fixed << setprecision(2) << discount << endl;
    cout << "--------------------------------------\n";
    cout << "Final Price: Rs. " << fixed << setprecision(2) << totalPrice - discount << endl;


    cout << "\nDo you want to go back? (1 for Yes, 0 for No): ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        system("cls");
        log_menu();
    } else {
        cout << "Exiting...\n";
        exitProgram();
    }
}

void logout() {
    main();
}

void exitProgram() {
    exit(0);
}

