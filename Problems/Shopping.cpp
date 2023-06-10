/* A local electronics shop has a great deal for notebooks.
You want to buy as many notebooks as you can afford. 
For that, you need to calculate how many notebooks you can buy with the amount in your bank account and how much money will be left over.
The given code includes comments as instructions for two tasks you need to complete.
Follow the instructions to solve this code coach!*/

#include <iostream>
using namespace std;

int main() {
    // your account's balance
    auto balance = 2452.4;
    // price for each notebook
    auto price = 259.99;
    // Task: calculate the number of notebooks you can afford and output it.
    // Hint: use an integer to store the result.
    int total = balance / price;
    cout << total << endl;
    // Task: calculate the amount left over on your account after the purchase and output it on a new line.
    // Hint: calculate the total price of the purchase, then substract it from the balance.
    cout << balance - (total*price);

}