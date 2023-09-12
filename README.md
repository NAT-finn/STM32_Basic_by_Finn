# STM32_Basic_by_Finn
Well, I'm learning with STM32 CubeIDE so in my project, I think I only code in Driver, Inc, Src folder =))



## Some precautions with STM32CubeIDE (and it can be applied for other IDEs)
- In my Driver folder (with everything I learned, Driver folder is Driver Layer). It have Header file (.h) and Source file (.c) to code details 
of the peripheral (code registers and place the values).Header file contains:
  + The microcontroller specific details such as the base addresses of various memories present in a microcontroller such as
    flasj, SRAM, ROM,...
  + The base addresses of various bus domains such as (AHBx, APBx,..)
  + Base addresses of various peripherals present in different bus domains
  + Clock management macros, IRQ definitions
  + Peripheral register definiton structures and bit definition
  + ...
To sum up, i will code in Driver folder to define every thing before i code in main, and I will code functions (APIs) in here

## Something with Build Config and Debuger

