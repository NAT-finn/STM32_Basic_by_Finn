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
- Because I use STM32CubeIDE, so it want me use the real STM32 chip (STM32f103ct6). But i can't buy any real STM32 chip (it's very hard to find). When i try to run or debug the clone chip, It allways occur some error like this:
**reason 18 st-link could not verify st device** or **Could not verify ST device! Please verify that the latest version of GDB-server is used for the connection**
=> So I have 2 ways to resolve it
1. You can follow the link :( https://www.makerlab.vn/cach-sua-loi-stm32-blue-pill-stm32f103c8t6-khong-nap-code-duoc-bang-phan-mem-stm32cube-ide/ ). Maybe it will help you. But for me, it's not work =))
2. This way is absolutely work, but you can't debug and run code in the same time. I hacve a J-Link, so I download J-Flash and improt the HEX file i had created in STM32CubeIDE (Right click to the project -> Properties -> C/C++ Build -> Setting -> MCU Post build outputs) (you can search internet with other IDEs). After that I connect the Target (STM32 chip) and Production Programing
  In this way, you must to debug your code by the other ways. You can use RTT in J-Link or use UART by USB UART CP2102 