#include "finding_n.h"

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PRINT_FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void printLine() {
  cout << "------------------------------------------------------\n";
}

void printIntro() {
  cout << "***************************************************************\n";
  cout << "WELCOME TO THE NUMBER GUESSING GAME!\n";
  cout << "- Before playing, please read the game tutorial carefully!\n";
  cout << "- Select the level in the menu and enjoy the game. Here is the game menu.\n";
}

void printMenu() {
  cout << "--------------------------MENU------------------------\n";
  cout << "1.  Game tutorials\n";
  cout << "Here are some levels of the game range from easy to extremely hard.\n";
  printLine();
  cout << "2.  Easy (3 digits)\n";
  cout << "3.  Medium (4 digits)\n";
  cout << "4.  Hard (5 digits)\n";
  cout << "5.  Extreme (6 digits)\n";
  cout << "6.  Customize (1 -> 10 digits)\n";
  cout << "0.  Quit project\n";
}

void printTutorials() {
  cout << "-----------------------GAME TUTORIAL------------------------\n";
  cout << "- The computer will generate a secret number consisting of unique digits.\n";
  cout << "- Each digit is from 0 to 9.\n";
  cout << "- Digits do NOT repeat.\n";
  printLine();
  cout << "Your task:\n";
  cout << "- Guess the correct digits in the correct order.\n";
  cout << endl;
  cout << "After each guess, the game will tell you:\n";
  cout << "- Digits correct: Number of digits that appear in the secret number.\n";
  cout << "- Positions correct: Number of digits that are in the correct position.\n";
  cout << endl;
  printLine();
  cout << "Example:\n";
  int example1[3] = {4, 1, 7};
  cout << "Secret number: ";
  printArr(example1, 3);
  int example2[3] = {1, 4, 7};
  cout << "Your guess: ";
  printArr(example2, 3);
  cout << endl;
  cout << "Digits correct: 3\n";
  cout << "Positions correct: 1\n";
  cout << endl;
  cout << "The game continues until you guess the correct number.\n";
  cout << endl;
  cout << "Good luck and have fun!\n";
}

void printResult(int attempt) {
    string msg1 = "You finished the game after ";
    string msg2 = to_string(attempt) + " attempts";
    cout << "---------------------------------------------\n";
    cout << msg1 + msg2 << endl;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ARRAY_FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
int *generateArr(int size) {
  int *array = new int[size];
  return array;
}

void enterArr(int* arr, int n) {
  for (int i = 0; i < n; i++) {
    int val;
    cout << "Digit " << i + 1 << ": "; cin >> val;

    if (val < 0 || val > 9) {
        for (int i = 0; i < n; i++){
            arr[i] = -1;
        }
        break;
    }
    arr[i] = val;
  }
}

void deleteArr(int *arr) { delete arr; }

void printArr(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int *generate_keyArr(int length) {
  if (length > 10) {
    length = 10;
  }

  int *digits = new int[10];

  for (int i = 0; i < 10; i++) {
    digits[i] = i;
  }

  random_device rd;
  mt19937 gen(rd());
  shuffle(digits, digits + 10, gen);

  int *key = new int[length];

  for (int i = 0; i < length; i++) {
    key[i] = digits[i];
  }

  return key;
}

void keyCheck(int* arr, int* key, int size) {
  int pos = 0, count = 0;
  for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        if (arr[i] == key[j]) {
          count++;
        }
      }
      if (arr[i] == key[i]) {
        pos++;
      }
    }
    printLine();
    cout << "Correct numbers: " << count << endl;
    cout << "Correct positions: " << pos << endl;
}

bool isSameArray(int* arr1, int* arr2, int size){
  for (int i = 0; i < size; i++){
    if(arr1[i] != arr2[i]){
      return false;
    }
  }
  return true;
}

bool hasDuplicate(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) return true;
        }
    }
    return false;
}

int* copyArr(int* arr, int size){
  int *newArr = new int[size];
  for (int i = 0; i < size; i++){
    newArr[i] = arr[i];
  }
  return newArr;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MAIN_FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
int main() {
  printIntro();
  cout << endl;
  printMenu();
  
  int *guess = nullptr, *keyArr = nullptr, *tmpArr = nullptr;
  int size, opt, attempt_cnt;
  char cont, ready;

  while(1){
    printLine();
    cout << "Enter your selection: "; cin >> opt;
    switch (opt){
      case 1:
        printLine();
        cout << "Here is the game tutorial, please read it carefully!\n";
        printTutorials();
        printLine();
        cout << "Are you ready? (y/n): "; cin >> ready;
        if(ready == 'Y' || ready == 'y'){
          printLine();
          cout << "Ok, let's choose the game level.\n";
          continue;
        }
        else{
          printIntro();
          cout << endl;
          printMenu();
          break;
        }
      case 2:
        printLine();
        cout << "You have chosen easy level (3 digits).\n";
        attempt_cnt = 0;
        size = 3;

        keyArr = generate_keyArr(size);
        tmpArr = generateArr(size);
        guess = generateArr(size);

        do{
          printLine();
          cout << "ATTEMPT " << attempt_cnt + 1 << endl;
          cout << endl;
          enterArr(tmpArr, size);

          if(tmpArr[0] == -1) {
            cout << endl;
            printLine();
            cout << "Invalid input! Please enter digits 0-9 only.\n";
            continue;
          }
          else if(hasDuplicate(tmpArr, size)){
            cout << endl;
            printLine();
            cout << "Digits must be unique!\n";
            continue;
          }

          guess = copyArr(tmpArr, size);

          keyCheck(guess, keyArr, size);
          attempt_cnt++;

        } while (!isSameArray(guess, keyArr, size));
        printResult(attempt_cnt);

        printLine();
        cout << "\nDo you want to continue? (y/n): "; cin >> cont;
        if (cont == 'n' || cont == 'N') {
          printLine();
          cout << "Thanks for your experience, goodbye!\n";
          exit(0);
        } 
        else {
          break;
        }

      case 3:
        printLine();
        cout << "You have chosen medium level (4 digits).\n";
        attempt_cnt = 0;
        size = 4;

        keyArr = generate_keyArr(size);
        tmpArr = generateArr(size);
        guess = generateArr(size);

        do{
          printLine();
          cout << "ATTEMPT " << attempt_cnt + 1 << endl;
          cout << endl;
          enterArr(tmpArr, size);

          if(tmpArr[0] == -1) {
            cout << endl;
            printLine();
            cout << "Invalid input! Please enter digits 0-9 only.\n";
            continue;
          }
          else if(hasDuplicate(tmpArr, size)){
            cout << endl;
            printLine();
            cout << "Digits must be unique!\n";
            continue;
          }

          guess = copyArr(tmpArr, size);

          keyCheck(guess, keyArr, size);
          attempt_cnt++;

        } while (!isSameArray(guess, keyArr, size));
        printResult(attempt_cnt);

        printLine();
        cout << "\nDo you want to continue? (y/n): "; cin >> cont;
        if (cont == 'n' || cont == 'N') {
          printLine();
          cout << "Thanks for your experience, goodbye!\n";
          exit(0);
        } 
        else {
          break;
        }

      case 4:
        printLine();
        cout << "You have chosen hard level (5 digits).\n";
        attempt_cnt = 0;
        size = 5;

        keyArr = generate_keyArr(size);
        tmpArr = generateArr(size);
        guess = generateArr(size);

        do{
          printLine();
          cout << "ATTEMPT " << attempt_cnt + 1 << endl;
          cout << endl;
          enterArr(tmpArr, size);

          if(tmpArr[0] == -1) {
            cout << endl;
            printLine();
            cout << "Invalid input! Please enter digits 0-9 only.\n";
            continue;
          }
          else if(hasDuplicate(tmpArr, size)){
            cout << endl;
            printLine();
            cout << "Digits must be unique!\n";
            continue;
          }

          guess = copyArr(tmpArr, size);

          keyCheck(guess, keyArr, size);
          attempt_cnt++;

        } while (!isSameArray(guess, keyArr, size));
        printResult(attempt_cnt);

        printLine();
        cout << "\nDo you want to continue? (y/n): "; cin >> cont;
        if (cont == 'n' || cont == 'N') {
          printLine();
          cout << "Thanks for your experience, goodbye!\n";
          exit(0);
        } 
        else {
          break;
        }

      case 5:
        printLine();
        cout << "You have chosen extreme level (6 digits).\n";
        attempt_cnt = 0;
        size = 6;

        keyArr = generate_keyArr(size);
        tmpArr = generateArr(size);
        guess = generateArr(size);

        do{
          printLine();
          cout << "ATTEMPT " << attempt_cnt + 1 << endl;
          cout << endl;
          enterArr(tmpArr, size);

          if(tmpArr[0] == -1) {
            cout << endl;
            printLine();
            cout << "Invalid input! Please enter digits 0-9 only.\n";
            continue;
          }
          else if(hasDuplicate(tmpArr, size)){
            cout << endl;
            printLine();
            cout << "Digits must be unique!\n";
            continue;
          }

          guess = copyArr(tmpArr, size);

          keyCheck(guess, keyArr, size);
          attempt_cnt++;

        } while (!isSameArray(guess, keyArr, size));
        printResult(attempt_cnt);

        printLine();
        cout << "\nDo you want to continue? (y/n): "; cin >> cont;
        if (cont == 'n' || cont == 'N') {
          printLine();
          cout << "Thanks for your experience, goodbye!\n";
          exit(0);
        } 
        else {
          break;
        }

      case 6:
        printLine();
        cout << "You have chosen custom mode (1 -> 10 digits).\n";
        int custom_size;
        while(true){
          cout << "Enter your size (1 -> 10): "; cin >> custom_size;
          if(custom_size < 1 || custom_size > 10){
            printLine();
            cerr << "Invalid size, please enter again!\n";
            continue;
          }
          break;
        }
        
        attempt_cnt = 0;
        size = custom_size;

        keyArr = generate_keyArr(size);
        tmpArr = generateArr(size);
        guess = generateArr(size);

        do{
          printLine();
          cout << "ATTEMPT " << attempt_cnt + 1 << endl;
          cout << endl;
          enterArr(tmpArr, size);

          if(tmpArr[0] == -1) {
            cout << endl;
            printLine();
            cout << "Invalid input! Please enter digits 0-9 only.\n";
            continue;
          }
          else if(hasDuplicate(tmpArr, size)){
            cout << endl;
            printLine();
            cout << "Digits must be unique!\n";
            continue;
          }

          guess = copyArr(tmpArr, size);

          keyCheck(guess, keyArr, size);
          attempt_cnt++;

        } while (!isSameArray(guess, keyArr, size));
        printResult(attempt_cnt);

        printLine();
        cout << "\nDo you want to continue? (y/n): "; cin >> cont;
        if (cont == 'n' || cont == 'N') {
          printLine();
          cout << "Thanks for your experience, goodbye!\n";
          exit(0);
        } 
        else {
          break;
        }

      case 0:
        printLine();
        cout << "Thanks for your experience, goodbye!\n";
        exit(0);

      default:
        printLine();
        cout << "Invalid selection! Please try again.\n";
        break;
    }
  }

  // default code
  deleteArr(tmpArr);
  deleteArr(guess);
  deleteArr(keyArr);
  return 0;
}
