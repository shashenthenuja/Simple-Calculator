# Simple Calculator In C
This project is a simple command line gui calculator program written in C programming language. It only has addition operation with positive integers. The program have 1 command line argument. The argument is the name of the text file where the output will be written when the program ends. This is the command format when you run the program `./calculator <file_name>`

![simple calculator program](https://gcdnb.pbrd.co/images/KvWpo0PdirBc.png?o=1)

## Number Display
This displays the number user enters through the number keypad. This display can
only hold up to 7 digits. 

![calculator display](https://gcdnb.pbrd.co/images/B6ZIu0hpVNSy.png?o=1)

## Number Keypad
This shows the number keypad where the user moves the arrow to select the number or
the mathematical operations.

![keypad](https://gcdnb.pbrd.co/images/pAOdkU7b2V2A.png?o=1)

The user can move the arrow with `W`, `A`, `S`, `D` to select the number from the interface. The user can press `E` to enter the selected number to the display. 

If the user selects `+` symbol to add the number, then the program will add the displayed number to the current total. After then the display will reset to `0`

If the user selects `=` symbol, the program will end and it prints the added numbers and the current total sum to the output file.

W - *Move cursor up*<br>
A - *Move cursor left*<br>
S - *Move cursor down*<br>
D - *Move cursor right*<br>
E - *Select the number*

## Keypad Randomness
The keypad structure will randomly change with a *50%-50%* probability every time the user starts a new program.

![keypad structure](https://gcdnb.pbrd.co/images/K3UrtX1GuJxs.png?o=1)

## LinkedList Usage
The added number in the program will be written to a generic linkedlist which holds all the values added. At the end of the program, it will output all the content stored in the linkedlist to the textfile named at the beginning of the program. The program will traverse the linkedlist and print the integers one by one in the reverse order in this format:
`<last_number>` **+** `<second_last_number>` **+** ... **+** `<first_number>` **=** `<total_sum>`

![contents in the linkedlist (textfile data)](https://gcdnb.pbrd.co/images/Y9EeXhnIJ4M2.png?o=1)

## Compilation
Run the provided makefile given and all the necessary files should be present in the same directory as the makefile. Run the following in the command line to compile the program : `make` 

### Indexed in Turn-It In Global Referencing Scheme

***This project should not be used for any coursework related activity and all codes have been submitted to `Turn-It In global referencing platform`, where usage of this code may be caught for Plagiarism.***
