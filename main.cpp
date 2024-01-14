#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

class Program {
  vector<int> control;
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
  long long steps;
  Program(vector<int> control) {
    this->control = control;
    r0 = 0;
    r1 = 0;
  }

  int getSteps() { return (int)steps; }

  long long execute() {
    int I_step = 0;
    long long steps = 0;
    this->control.push_back(0);
    this->control.push_back(0);
    this->control.push_back(0);
    this->control.push_back(0);
    while (I_step <= this->control.size()) {
      int command = this->control[I_step];
      /* cout << "current step -> " << command << endl; */
      steps++;
      switch (command) {
      case 0:
        // break out of the looop trust me i didnt think of a better way to do
        // this im so tired
        I_step = this->control.size() + 1;
      case 1:
        // Add one to register 0
        this->r0++;
        break;
      case 2:
        // Add one to register 0
        this->r0--;
        break;
      case 3:
        this->r1++;
        break;
      case 4:
        this->r1--;
        break;
      case 5:
        this->r0 = (this->r0 + this->r1);
        break;
      case 6:
        this->r0 = (this->r0 - this->r1);
        break;
      case 7:
        // print command;
        /* cout << r0; */
        break;
      case 8: {

        // look at the next number, and do the loop;
        int address = this->control[I_step + 1];
        if (r0 != 0) {
          // jump to address if this is the case;

          I_step = (address)-1;
        } else {
          I_step++;
        }
        break;
      }
      case 9: {
        int address = this->control[I_step + 1];
        if (r0 == 0) {
          // jump to address if this is the case;

          I_step = (address)-1;
        } else {
          I_step++;
        }
        break;
      }
      case 10: {
        // load value into r0
        //<address> is the number in the cell after the cell containing the
        // instruction (!= means "is not equal to")
        int next_val = this->control[I_step + 1];
        this->r0 = (next_val);
        I_step++;
        break;
      }
      case 11: {
        // load value into r1
        // <address> is the number in the cell after the cell containing the
        // instruction (== means "is equal to")
        int next_val = this->control[I_step + 1];
        this->r1 = convertcharToInt(next_val);
        I_step++;
        break;
      }
      case 12: {
        // 	 Copy the contents of R0 into the memory cell at <address>
        int next_val = this->control[I_step + 1];
        this->control[next_val] = this->r0;
        I_step++;
        break;
      }
      case 13: {
        //  Copy the contents of R1 into the memory cell at <address>
        int next_val = this->control[I_step + 1];
        this->control[next_val] = this->r1;
        I_step++;
        break;
      }
      case 14: {
        // swap the memory and r0 pointer;
        // Swap the contents of R0 and the memory cell at <address>
        int next_val = (this->control[I_step + 1]);

        // swap
        int tmp;
        tmp = this->r0;
        this->r0 = (this->control[next_val]);

        this->control[next_val] = tmp;
        I_step++;
        break;
      }
      case 15: {
        // Swap the contents of R1 and the memory cell at <address>
        char next_val = this->control[I_step + 1];
        int tmp;
        tmp = this->r1;
        this->r1 = (next_val);

        this->control[next_val] = tmp;
        I_step++;
        break;
      }
      }

      // check if r0 or r1 need to wrap back
      r0 %= 16;
      r1 %= 16;

      I_step++;

      if (steps >= 10000) {

        return 0;
        break;
      }
    }
    /* cout << endl << "Executed in " << steps << " steps" << endl; */
    return steps;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<char> y;
  /* program.execute(); */
  int max_steps = INT_MIN;
  tuple<int, vector<int>> gmax;

  // vector<int> input_array {1, 1, 1, 8, 7, 3, 5, 8};
  vector<int> input_array{14, 14, 7, 12, 14, 14, 15, 2,
                          12, 15, 8, 0,  0,  0,  4,  5};

  // Program x(input_array);
  // int steps = x.execute();
  // cout << steps;

  for (int i = 1; i <= 15; i++) {
    for (int j = 0; j <= 15; j++) {

      for (int k = 0; k <= 15; k++) {

        for (int s = 0; s <= 15; s++) {
          for (int q = 0; q <= 15; q++) {
            for (int t = 0; t <= 15; t++) {
              for (int d = 0; d <= 15; d++) {
                for (int y = 0; y <= 15; y++) {
                  for (int o = 0; o <= 15; o++) {
                    /* for (int u = 0; u <= 15; u++) { */

                    vector<int> a;
                    a.push_back(i);
                    a.push_back(j);
                    a.push_back(k);
                    a.push_back(s);
                    a.push_back(q);
                    a.push_back(t);
                    a.push_back(d);
                    a.push_back(y);
                    a.push_back(o);
                    a.push_back(0);
                    /* a.push_back(d); */
                    //                   a.push_back('0' + t);
                    //                   a.push_back('0' + d);
                    //                   a.push_back('0' + y);
                    //                   a.push_back('8');
                    //                   a.push_back('0');
                    //

                    /* for (int b : a) */
                    /*   cout << b << ""; */
                    Program x(a);
                    int steps = (int)x.execute();
                    // cout << a.size() << endl;
                    if (steps > get<0>(gmax)) {
                      // cout << steps << endl;
                      for (int b : a)
                        cout << b << "";
                      cout << endl;
                      cout << steps << endl;
                      //                     vector<char> b;
                      //                     b.push_back('e');
                      //                     b.push_back('0' + i);
                      //                     b.push_back('0' + j);
                      //                     b.push_back('8');
                      //                     b.push_back('0');
                      //                     b.push_back('0' + k);
                      //                     b.push_back('0' + s);
                      //                     b.push_back('0' + q);
                      //                     b.push_back('0' + t);
                      //                     b.push_back('0' + d);
                      //                     b.push_back('0' + y);
                      //                     b.push_back('8');
                      //                     b.push_back('0');

                      gmax = make_tuple(steps, a);
                      //                     cout << get<0>(gmax) << endl;
                      cout << endl;
                    }
                    // }
                    /* } */
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  //   }
  // }

  // for (char a : get<1>(gmax))
  //   cout << a << endl;

  // cout << get<1>(gmax).size() << endl;
  // cout << max_steps << endl;
}
