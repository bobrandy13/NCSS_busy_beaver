class Solution:
    r0 = 0 
    r1 = 0 
    input_array = [] 
    def __init__(self, input_array) -> None:
        self.input_array = input_array
    
    # def to_int(input_token):
    #     if (type(input_token) == int):
    #         return input_token
    
    def execute(self): 
        I_step = 0 
        output = [] 
        steps = 0
        

        while (I_step < len(self.input_array)):
            command = self.input_array[I_step]

            print(command)

            steps += 1
            match command:
                case 0:
                    I_step = len(self.input_array) + 1
                case 1: 
                    self.r0 += 1
                case 2: 
                    self.r0 -= 1
                case 3: 
                    self.r1 += 1
                case 4: 
                    self.r1 -= 1
                case 5: 
                    self.r0 = self.r0 + self.r1
                case 6: 
                    self.r0 = self.r0 - self.r1
                case 7:
                    output.append(self.r0)
                case 8:
                    # look at the next value and then loop if r!= 0
                    address = self.input_array[I_step + 1]

                    if (self.r0 != 0):
                        I_step = address - 1
                    else:
                        I_step += 1 
                
                case 9: 
                    address = self.input_array[I_step + 1]

                    if (self.r0 == 0):
                        I_step = address - 1
                    else:
                        I_step += 1 
                
                case 10:
                    # get the valu
                    load_value = self.input_array[I_step + 1]
                    self.r0 = load_value
                    I_step += 1
                case 11: 
                    load_value = self.input_array[I_step + 1]
                    self.r1 = load_value
                    I_step += 1

                case 12:
                    copy_value = self.input_array[I_step + 1]
                    self.input_array[copy_value] = self.r0
                    I_step += 1
                
                case 13:
                    copy_value = self.input_array[I_step + 1]
                    self.input_array[copy_value] = self.r1
                    I_step += 1

                case 14:
                    swap_value = self.input_array[I_step + 1]

                    tmp = self.r0

                    self.r0 = self.input_array[swap_value]

                    self.input_array[swap_value] = tmp

                    I_step += 1

                case 15:
                    swap_value = self.input_array[I_step + 1]

                    tmp = self.r1

                    self.r1 = self.input_array[swap_value]

                    self.input_array[swap_value] = tmp

                    I_step += 1
            I_step+=1

            return steps

x = Solution([])
steps = x.execute()

print(steps)