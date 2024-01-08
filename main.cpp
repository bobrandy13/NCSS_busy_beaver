#include <iostream>
#include <vector>

using namespace std;

class Program {
  vector<char> control;
  int r0, r1;

private:
  // function to convert token into its decimal equivalent
  int convertcharToInt(char token) {
    if (token == 'A')
      return 10;
    if (token == 'B')
      return 11;
    if (token == 'C')
      return 12;
    if (token == 'D')
      return 13;
    if (token == 'E')
      return 14;
    if (token == 'F')
      return 15;

    return atoi(&token);
  }
  char calculateWrap(int reg) {

    while (reg < 0)
      reg += 16;

    return reg;
  }

public:
  Program(vector<char> control) {
    this->control = control;
    r0 = 0;
    r1 = 0;
  }

  void execute() {
    int I_step = 0;
    int steps = 0;
    while (I_step <= this->control.size()) {
      char command = this->control[I_step];
      /* cout << "current step -> " << command << endl; */
      steps++;
      switch (command) {
      case '0':
        // break out of the looop trust me i didnt think of a better way to do
        // this im so tired
        I_step = this->control.size() + 1;
      case '1':
        // Add one to register 0
        this->r0++;
        break;
      case '2':
        // Add one to register 0
        this->r0--;
        break;
      case '3':
        this->r1++;
        break;
      case '4':
        this->r1--;
        break;
      case '5':
        this->r0 = calculateWrap(this->r0 + this->r1);
        break;
      case '6':
        this->r0 = calculateWrap(this->r0 - this->r1);
        break;
      case '7':
        // print command;
        cout << r0;
        break;
      case '8': {

        // look at the next number, and do the loop;
        char address = this->control[I_step + 1];
        if (r0 != 0) {
          // jump to address if this is the case;

          I_step = convertcharToInt(address) - 1;
        } else {
          I_step++;
        }
        break;
      }
      case 'A': {
        // load value into r0
        //<address> is the number in the cell after the cell containing the
        // instruction (!= means "is not equal to")
        char next_val = this->control[I_step + 1];
        this->r0 = convertcharToInt(next_val);
        I_step++;
        break;
      }
      case 'B': {
        // load value into r1
        // <address> is the number in the cell after the cell containing the
        // instruction (== means "is equal to")
        char next_val = this->control[I_step + 1];
        this->r1 = convertcharToInt(next_val);
        I_step++;
        break;
      }
      case 'C': {
        // 	 Copy the contents of R0 into the memory cell at <address>
        char next_val = this->control[I_step + 1];
        this->control[next_val] = this->r0;
        I_step++;
        break;
      }
      case 'D': {
        //  Copy the contents of R1 into the memory cell at <address>
        char next_val = this->control[I_step + 1];
        this->control[next_val] = this->r1;
        I_step++;
        break;
      }
      case 'E': {
        // swap the memory and r0 pointer;
        // Swap the contents of R0 and the memory cell at <address>
        int next_val = convertcharToInt(this->control[I_step + 1]);

        // swap
        int tmp;
        tmp = this->r0;
        this->r0 = convertcharToInt(this->control[next_val]);

        this->control[next_val] = tmp;
        I_step++;
        break;
      }
      case 'F': {
        // Swap the contents of R1 and the memory cell at <address>
        char next_val = this->control[I_step + 1];
        int tmp;
        tmp = this->r0;
        this->r0 = convertcharToInt(next_val);

        this->control[next_val] = tmp;
        I_step++;
        break;
      }
      }

      // check if r0 or r1 need to wrap back
      r0 %= 16;
      r1 %= 16;

      I_step++;
    }
    cout << endl << "Executed in " << steps << " steps" << endl;
  }
};

int main() {
  vector<char> input{'1', '8', '0'};
  cout << hex;
  Program program(input);
  program.execute();
}
