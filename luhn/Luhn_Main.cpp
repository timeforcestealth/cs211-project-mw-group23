#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "Credit Card Validator" << endl; // display a header for the program
    string number; // variable to store the 16-digit number entered by the user

    while(true) // loop indefinitely until the user enters "stop"
    {
    cout << "Enter a 16-digit number or type stop to quit: "; // prompt the user to enter a 16-digit number
    if (!getline(cin, number)) // check if input ends unexpectedly
    break; // stop if input ends unexpectedly
    if (number == "stop") // check if the user wants to quit
        break; // exit the while loop
    
        if (number.length() != 16) // check if the number is not 16 digits long
    {
        cout << "Invalid input: number must be 16 digits long." << endl; // display error message if number is not 16 digits long
        continue; // skip the rest of the loop and prompt the user again
    }
    
    bool allDigits = true; // flag to indicate whether all characters in the number are digits

for (char c : number) // iterate over each character in the number to check if it is a digit
{
    if (c < '0' || c > '9') // check if the character is not a digit
    {
        allDigits = false; // set the flag to false if a non-digit character is found
        break; // stop checking this input
    }
}

if (!allDigits) // check if any character in the number is not a digit
{
    cout << "Invalid input: number must contain only digits." << endl; // display error message if number contains non-digit characters
    continue; // ask for another input
}
   
    cout << "Valid 16-digit number entered." << endl; // indicate that the entered number is valid

    int sum = 0; // variable to store the sum of the digits after processing with the Luhn algorithm
    bool doubleNext = false; // flag to indicate whether the next digit should be doubled according to the Luhn algorithm

    for (int i = 15; i >= 0; --i) // iterate over the digits from right to left according to the Luhn algorithm
    {
        int digit = number[i] - '0'; // convert the character to an integer digit
        
        if (doubleNext) // check if the current digit should be doubled according to the Luhn algorithm
        {
            digit *= 2; // double the digit
            if (digit > 9) // if the doubled digit is greater than 9, subtract 9
                digit -= 9; // subtract 9 from the doubled digit if it is greater than 9
        }

        sum += digit; // add the processed digit to the sum according to the Luhn algorithm
        doubleNext = !doubleNext; // toggle the flag for the next digit according to the Luhn algorithm

    } // end of for loop iterating over digits

    if (sum % 10 == 0) // check if the checksum is valid
        cout << "Valid Card." << endl; // indicate that the checksum is valid
    else
        cout << "Invalid Card." << endl; // indicate that the checksum is invalid
    } // end of while loop for input validation and Luhn algorithm processing
    
    cout << "Program terminated." << endl; // indicate that the program has ended
    
    return 0; // exit the program successfully
}