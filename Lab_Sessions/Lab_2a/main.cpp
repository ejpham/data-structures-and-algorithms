#include "ArrayList.cpp"

int main() {

    //***********  addElements Function is Tested  ***********

    ArrayList<int> arrList(1);
    arrList.addElement(1);
    arrList.addElement(2);
    arrList.addElement(3);
    arrList.addElement(4);
    arrList.addElement(5);
    if (arrList.getArraySize() == 8)
    {
        cout << "Correct Result" << endl;
        cout << "array Size after expansion is : 8" << endl << endl;
    }
    else
    {
        cout << "Your addElement Function is not correct" << endl;
        cout << "Your arraySize after Expansion is : " << arrList.getArraySize() << endl;
        cout << "Expected Output : 8 " << endl << endl;
    }
    //*********** Constructor with invalid input  is Tested  ***********
    ArrayList<int> arrList2(0);
    if (arrList2.getArraySize() == 2)
    {
        cout << "Correct Result" << endl;
        cout << "array Size after given wrong value (less than one) : 1" << endl << endl;
    }
    else
    {
        cout << "Your constrcutor is not Correct" << endl;
        cout << "The arraySize should be at least One" << endl << endl;
    }

    //*********** getElementAt Function  is Tested  ***********
    ArrayList<int> arrList4(1);
    arrList4.addElement(1);
    arrList4.addElement(2);
    arrList4.addElement(3);
    int s = arrList4.getElementAt(2);
    int s1 = 3;

    if (s == s1) {
        cout << "Correct Result" << endl;
        cout << "The element with index 2 is: 3" << endl << endl;
    }
    else {
        cout << "Result is incorrect " << endl;
        cout << "your function prints:";
        cout << s << endl;
        cout << " But, Expected output should be:" << s1 << endl << endl;

    }

    //*********** Copy Constructor  is Tested  ***********
    ArrayList<double> arrList5(1);
    arrList5.addElement(10);
    ArrayList<double> arrList6 = arrList5;
    arrList6.addElement(2.1);
    arrList6.addElement(4.5);
    double d1 = arrList5.getElementAt(0);
    double output1 = 10;
    double d2 = arrList6.getElementAt(1);
    double output2 = 2.1;
    //if(arrList.getnumOfElements() == 3 && arrList.getarraySize() == 4)
    if (d1 == output1 && d2 == output2) {
        cout << "Correct Result" << endl;
        cout << "First element of the first array is " << arrList5.getElementAt(0) << endl;
        cout << "The second element of the copied array after modification is " << arrList6.getElementAt(1) << endl << endl;
    }
    else {
        cout << "Result is incorrect " << endl;
        cout << "First element of the first array is " << arrList5.getElementAt(0) << " and should be: 10" << endl;
        cout << "The second element of the copied array after modification is " << arrList6.getElementAt(1) << " and should be: 2.1" << endl << endl;


    }

    return 0;


}