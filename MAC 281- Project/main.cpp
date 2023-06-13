//
//  main.cpp
//  MAC 281- Project
//
//  Created by Kamal gurung on 11/28/20.
//  Copyright © 2020 Kamal gurung. All rights reserved.
//

#include <iostream>
#include <chrono>
#include <sstream>
using namespace std;

// Function for finding sum of large numbers represented as strings
string findSum(string str1, string str2) {
    if (str1.length() > str2.length())
        swap(str1, str2);
    // Take an empty string for storing result
    string str = "";
    // Calculate length of both string
    int n1 = str1.length(), n2 = str2.length();
    // Reverse both of strings
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    int carry = 0;
    for (int i=0; i<n1; i++){
        // compute sum of
        // current digits and carry
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        // Calculate carry for next step
        carry = sum/10;}
    // Add remaining digits of larger number
    for (int i=n1; i<n2; i++){
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;}
    // Add remaining carry
    if (carry)
        str.push_back(carry+'0');
    
    // reverse resultant string
    reverse(str.begin(), str.end());
    
    return str;
}

// function for finding n-th Fibonacci number
// using strings (can find very large numbers)
string fibonacci(int n) {
    
    if(n<=0){
        cout << "Wrong input!";
        return 0;
    }
    
    if(n==1) {
        return "1";
    }
    
    string current = "1";
    string previous = "1";
    string temp;
    for(int i=2; i<n; i++) {
        temp = current;
        current = findSum(current,previous);
        previous = temp;
        
    }
    return current;
}

int intFibonacci(int n) {
    if(n<=0){
        cout << "Wrong input!";
        return 0;
    }
    
    if(n==1) {
        return 1;
    }
    
    int current = 1;
    int previous = 1;
    int temp;
    for(int i=2; i<n; i++) {
        temp = current;
        current = current+previous;
        previous = temp;
        
    }
    return current;
}

// prints all prime Fbonacci numbers up to n
void primeFibonacci(int n){
    if(n<1) {return;}
    int fib;
    bool isPrime;
    int count = 0;
    int i=3;
    while(count<=n-1) {
        isPrime =  true;
        fib = intFibonacci(i);
        for (int j=2; j<fib/2; j++) {
            if(fib%j==0) {
                isPrime = false;
            }
        }
        if(isPrime) {
            cout << fib << " ";
            count++;
        }i++;
    }
}



int main() {
    
    
    // calculate numbers and find execution times
    auto t1 = std::chrono::high_resolution_clock::now();
    string f100 = fibonacci(100);
    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration100 = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    
    auto t12 = std::chrono::high_resolution_clock::now();
    string f500 = fibonacci(500);
    auto t22 = std::chrono::high_resolution_clock::now();
    auto duration500 = std::chrono::duration_cast<std::chrono::microseconds>( t22 - t12 ).count();
    
    auto t13 = std::chrono::high_resolution_clock::now();
    string f1000 = fibonacci(1000);
    auto t23 = std::chrono::high_resolution_clock::now();
    auto duration1000 = std::chrono::duration_cast<std::chrono::microseconds>( t23 - t13 ).count();
    
    
    
    cout << "f100 = " << f100 << endl << "Execution time: " << duration100 << " microseconds" <<endl << endl;
    cout << "f500 = " << f500 << endl << "Execution time: " << duration500 << " microseconds" <<endl<<endl;
    cout << "f1000 = " << f1000 << endl << "Execution time: " << duration1000 << " microseconds" <<endl<<endl;
    
    int num = 1;
    while(intFibonacci(num) < 1000000) {
        num+=1;
        
    }
    cout << "The smallest fibonacci number greater than 1,000,000: " << intFibonacci(num) <<endl;
    
    int num2 = 1;
    
    while(intFibonacci(num2) < 1000000000) {
        num2+=1;
        
    }
    cout << "The smallest fibonacci number greater than 1,000,000,000: " << intFibonacci(num2)<<endl<<endl;
    
    int nn = 10;
    cout << "First "<<nn << " Fibonacci primes are: "<<endl<<endl;
    primeFibonacci(nn);
    
    for(int i=1; i<=10; i++) {
        auto t1 = std::chrono::high_resolution_clock::now();
        cout<<endl;
        primeFibonacci(i);
        auto t2 = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        cout << endl << "Execution time: "<<duration << endl;
    }
    
    
    
    
    return 0;
}
