#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class MyFunctions {
public:
    // 1. Determine if a number is prime
    bool isPrime(int num) {
        if (num <= 1) return false;
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) return false;
        }
        return true;
    }

    // 2. Find the sum of elements in an array
    int sumOfArray(const vector<int>& arr) {
        int sum = 0;
        for (int num : arr) {
            sum += num;
        }
        return sum;
    }

    // 3. Sort a list of elements using bubble sort
    void bubbleSort(vector<int>& arr) {
        bool swapped;
        for (size_t i = 0; i < arr.size() - 1; ++i) {
            swapped = false;
            for (size_t j = 0; j < arr.size() - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) break; // Exit if no swaps occurred
        }
    }

    // 4. Read 10 numbers and find their sum and average
    void sumAndAverage() {
        int sum = 0, num;
        for (int i = 0; i < 10; ++i) {
            cout << "Enter number " << i + 1 << ": ";
            cin >> num;
            sum += num;
        }
        cout << "Sum: " << sum << "\nAverage: " << (sum / 10.0) << endl;
    }

    // 5. Compute the length of a string
    size_t stringLength(const string& str) {
        return str.length();
    }

    // 6. Find the position of a target value in an array using linear search
    int linearSearch(const vector<int>& arr, int target) {
        for (size_t i = 0; i < arr.size(); ++i) {
            if (arr[i] == target) return i;
        }
        return -1;
    }

    // 7. Add two numbers using pointers
    int* addNumbersUsingPointers() {
        static int result; // Use static so the variable persists after the function exits
        int a, b;
        cout << "Enter two numbers: ";
        cin >> a >> b;
        result = a + b;
        return &result;
    }

    // 8. Check if a number is a palindrome
    bool isPalindrome(int num) {
        int reversed = 0, original = num;
        while (num != 0) {
            int digit = num % 10;
            reversed = reversed * 10 + digit;
            num /= 10;
        }
        return original == reversed;
    }

    // 9. Create and manipulate a "student" structure
    struct Student {
        string name;
        int age;
        int totalMarks;
    };

    void studentData() {
        Student students[2];
        cin.ignore(); // Clear any leftover newline character
        for (int i = 0; i < 2; ++i) {
            cout << "Enter name of student " << i + 1 << ": ";
            getline(cin, students[i].name);
            cout << "Enter age of student " << i + 1 << ": ";
            cin >> students[i].age;
            cout << "Enter total marks of student " << i + 1 << ": ";
            cin >> students[i].totalMarks;
            cin.ignore(); // Clear newline character for the next input
        }
        int totalMarksSum = 0;
        for (const Student& s : students) {
            totalMarksSum += s.totalMarks;
            cout << "Name: " << s.name << ", Age: " << s.age << ", Total Marks: " << s.totalMarks << endl;
        }
        cout << "Average Marks: " << (totalMarksSum / 2.0) << endl;
    }

    // 10. Analyze a given number (odd/even, positive/negative)
    void analyzeNumber() {
        int num;
        cout << "Enter a number: ";
        cin >> num;
        if (num == 0) {
            cout << "Zero" << endl;
        } else {
            cout << (num > 0 ? "Positive " : "Negative ")
                 << (num % 2 == 0 ? "Even" : "Odd") << endl;
        }
    }

    // 11. Calculate factorial using a recursive function
    int factorial(int n) {
        return (n <= 1) ? 1 : n * factorial(n - 1);
    }

    // 12. Print name, date of birth, and mobile number
    void printDetails() {
        cout << "Name: John Doe\nDate of Birth: 01/01/2000\nMobile Number: +1234567890" << endl;
    }
};

int main() {
    MyFunctions obj;

    // Example usage of each function
    cout << "Is 7 prime? " << (obj.isPrime(7) ? "Yes" : "No") << endl;

    vector<int> arr = {3, 1, 4, 1, 5};
    cout << "Sum of array: " << obj.sumOfArray(arr) << endl;

    obj.bubbleSort(arr);
    cout << "Sorted array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    obj.sumAndAverage();

    string testStr = "Hello";
    cout << "Length of '" << testStr << "': " << obj.stringLength(testStr) << endl;

    cout << "Position of 4 in array: " << obj.linearSearch(arr, 4) << endl;

    int* sumPtr = obj.addNumbersUsingPointers();
    cout << "Sum using pointers: " << *sumPtr << endl;

    int testNum = 121;
    cout << "Is " << testNum << " a palindrome? " << (obj.isPalindrome(testNum) ? "Yes" : "No") << endl;

    obj.studentData();

    obj.analyzeNumber();

    cout << "Factorial of 5: " << obj.factorial(5) << endl;

    obj.printDetails();

    return 0;
}
