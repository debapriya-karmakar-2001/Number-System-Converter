#include <bits/stdc++.h>
#include <stdlib.h>
#include <string>
#include <cmath>
using namespace std;

void wrong_input_base()
{
	cout << "\n\tThe input base number is not valid as per the Number System.";
	exit(0);
}

void convert_str(string str, int ip_base, int op_base)
{
	int i, j, k=0, ascii, sum=0, m, d;
	string digits;
	
	for(i=0 ; i<str.length() ; i++)						//Scanning through the input base to check whether the input base is valid or not.
	{
		ascii = (int)str[i];
		
		if(ip_base == 11)
		{
			if(ascii < 48 || (ascii > 57 && ascii != 65))
				wrong_input_base();
		}
		else if(ip_base == 12)
		{
			if(ascii < 48 || (ascii > 57 && ascii != 65 && ascii != 66))
				wrong_input_base();
		}
		else if(ip_base == 13)
		{
			if(ascii < 48 || (ascii > 57 && ascii != 65 && ascii != 66 && ascii != 67))
				wrong_input_base();
		}
		else if(ip_base == 14)
		{
			if(ascii < 48 || (ascii > 57 && ascii != 65 && ascii != 66 && ascii != 67 && ascii != 68))
				wrong_input_base();
		}
		else if(ip_base == 15)
		{
			if(ascii < 48 || (ascii > 57 && ascii != 65 && ascii != 66 && ascii != 67 && ascii != 68 && ascii != 69))
				wrong_input_base();
		}
		else if(ip_base == 16)
		{
			if(ascii < 48 || (ascii > 57 && ascii != 65 && ascii != 66 && ascii != 67 && ascii != 68 && ascii != 69 && ascii != 70))
				wrong_input_base();
		}
		else
		{
			if((ascii - 48) > (ip_base - 1))
				wrong_input_base();
		}
	}
	
	for(i=(str.length()-1), j=0; i>=0 ; i--, j++)					//Converting the input number to Decimal.
	{
		ascii = (int)str[i];
		if(ascii >= 65 && ascii <= 70)
		{
			ascii = ascii - 55;
			sum = sum + pow(ip_base, j) * ascii;
		}
		else
		{
			ascii = ascii - 48;
			sum = sum + pow(ip_base, j) * ascii;
		}
	}
	
	cout << "\n\t";
	cout << str << " base " << ip_base << " converted to base " << op_base << " is ";
	m = sum;
	while(m != 0)													//Converting the converted Decimal number to the desired output base.
	{
		d = (m % op_base);
		if(d == 10)
			digits[k++] = 'A';
		else if(d == 11)
			digits[k++] = 'B';
		else if(d == 12)
			digits[k++] = 'C';
		else if(d == 13)
			digits[k++] = 'D';
		else if(d == 14)
			digits[k++] = 'E';
		else if(d == 15)
			digits[k++] = 'F';
		else
			digits[k++] = (char)(d + 48);
			
		m = m / op_base;
	}
	
	for(i=k-1 ; i>=0 ; i--)											//Displaying the desired converted output base.
		cout << digits[i];
	
	return;
}

int main()
{
	int input_base, output_base;
	string str;
	
	printf("\n\tWelcome to the project of NUMBER SYSTEM CONVERTER! Here, we can convert any base number to another base number.");
	printf("\n\tFirstly, we have to enter an input base (from 2 to 16, both included) and an output base (from 2 to 16, both included).");
	printf("\n\tPlease note that the input base and the output base should not be the same. After that, you have to enter a number.");
	printf("\n\tAlso please note that very importantly, please enter the input number in the correct appropriate form as far as the Number System is concerned.");                    
	
	
	cout << "\n\n\n\tEnter the input base: ";
	cin >> input_base;
	
	if(input_base <= 1 || input_base >= 17)
	{
		cout << "\n\tInput base should be any number from 2 to 16, both included. Try again!";
		exit(0);
	}
	
	cout << "\n\tEnter the output base: ";
	cin >> output_base;
	
	if(output_base <= 1 || output_base >= 17)
	{
		cout << "\n\tOutput base should be any number from 2 to 16, both included. Try again!";
		exit(0);
	}
	
	if(input_base == output_base)
	{
		cout << "\n\tInput base and output base are the same! They should be different. Please try again.";
		exit(0);
	}
	
	cout << "\n\tEnter the number (maximum length should be less than or equal to 100): ";
	cin >> str;
	
	if((str.length()) > 100)
	{
		cout << "\n\tThe number of digits of the input number is greater than 100. The number of digits of the input number should be less than or equal to 100. Please try again.";
		exit(0);
	}
	
	convert_str(str, input_base, output_base);
	
	return 0;
}
