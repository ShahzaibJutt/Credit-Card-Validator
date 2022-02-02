#include <bits/stdc++.h>
#define MAX 1

using namespace std;

class creditCard {
	string ccNo;
	long int n;
	public:
	void getNumber() {
		cin >> n;
	}
	bool isValidLength() {
		int i = 0;
		long int temp = n;
		while (temp > 0) {
			temp = temp / 10;
			i++;
		}
		// Check if length is valid
		// Most used cards length (13, 15, 16)
		if (i == 13 || i == 15 || i == 16)
			return 1;
		else return 0;
	}
	bool isValidNo() {
		// Calculate checksum
		int sum1 = 0;
		int sum2 = 0;
		long x = n;
		int total = 0;
		int mod1;
		int mod2;
		int d1;
		int d2;
		do {
			// Remove last digit and add to sum1
			mod1 = x % 10;
			x = x / 10;
			sum1 = sum1 + mod1;
			// Remove second last digit
			mod2 = x % 10;
			x = x / 10;
			// Double second last digit and add digits to sum2
			mod2 = mod2 * 2;
			d1 = mod2 % 10;
			d2 = mod2 / 10;
			sum2 = sum2 + d1 + d2;
		}
		while (x > 0);
		total = sum1 + sum2;
		// Next check Luhn Algorithm
		if (total % 10 == 0)
			return 1;
		else return 0;
	}
	void getCompany() {
		// Get starting digits
		long start = n;
		do
			start = start / 10;
		while (start > 100);
		// Next check starting digits for card type
		// Mastercard (51...56)
		// AMEX (34, 37)
		// VISA (4)
		if ((start / 10 == 5) && (0 < start % 10 && start % 10 < 6))
			cout << "MASTERCARD" << endl;
		else if ((start / 10 == 3) && (start % 10 == 4 || start % 10 == 7))
			cout << "AMEX" << endl;
		else if (start / 10 == 4)
			cout << "VISA" << endl;
		else
			cout << "Sorry! but we couldn't identify the card." << endl;
	}
};

int main(){
	creditCard cards[MAX];
	for (int i = 0; i < MAX; i++)
		cards[i].getNumber();
	for (int i = 0; i < MAX; i++)
		if (cards[i].isValidNo() == 1 && cards[i].isValidLength() == 1)
			cards[i].getCompany();
		else
			cout << "INVALID! Please enter the valid number." << endl;
}
