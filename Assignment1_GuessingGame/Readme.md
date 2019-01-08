### TODO Please edit the following information in your assignment

- Name(s):
- How many hours did it take you to complete this Assignment?
- Did you collaborate with any other students/TAs/Professors?
- Did you use any external resources? (Cite them below)
  - tbd
  - tbd
- (Optional) What was your favorite part of the assignment?
- (Optional) How would you improve the assignment?

# Prompt

I was always impressed by those folks at the amusement parks and country fairs who could perform magic tricks. I even remember once getting a booklet where if you asked someone enough questions in a row, you could guess their date of birth. It was a sort of neat magic trick, but back then (when I was about five years old) I did not realize I was being tricked by a programmer! 

Let’s figure out how to write a similar program to guess a randomly generated number by the computer.

# Logistics

For this assignment (and every assignment/lab), you must login into the servers through `your_khoury_usernamename@login.khoury.neu.edu` to complete and test your work. The reason is the examples I will provide below are compiled strictly for our machines architecture, and this is a consistent architecture where your submission will be graded.

# Part 1 - Establishing your work environment

## VIM and TMUX

<img align="right" width="300px" src="https://joshldavis.com/img/vim/tabs.gif">

(Note this part is ungraded--but you are required to do it!)

Figuring out a good workflow on Unix, Mac, (and even windows) is an important part of becoming a good programmer. My work environment (and the suggested one so I can help you during class), is to use the combination of the VIM text editor and tmux window manager to program your assignments in.

### Student and Teacher Dialouge

*"But I love visual studio, sublime, XCode, Atom, etc."*

*That's great, but you cannot use those in a remote environment easily--so I suggest learning another skill. By all means, use both or multiple tools to write the highest quality code.*

*"Hehe, the professor will never know if I just use notepad. I'll just take a shortcut on this assignment"*

*While that's true you can take a shortcut now, it will eventually catch up to you. I promise this is a good skill to learn! This first assignment is much more lightweight, take the time now to do things properly.*

Here are some suggested resources to get started.
* (VIM+TMUX Example) https://www.youtube.com/watch?v=YD9aFIvlQYs (16:31)
* Type *man tmux* in a terminal.
* Tmux tutorial - https://www.youtube.com/watch?v=BHhA_ZKjyxo (11:23)

> A hint I got a long time ago from a colleague when working, is to ask a colleague if you can shadow them working for 30 minutes.
> It was interesting to see what different tools other computer scientists would use. Whether it was different text editors, short-cuts, plugin-ins, etc.
> Establishing a good workflow can even be part of the fun!

## Compiling and running this assignment

For this assignemnt, you may use the [clang](https://clang.llvm.org/) or [gcc](https://www.gnu.org/software/gcc/) compiler. Both are industry standard compilers for compiling C programs (in addition to many other programming languages). Sometimes trying different compilers will given you more informative or helpful error messages--either one is perfectly fine for this course!

Here is how you will compile your code on the terminal.

`clang main.c -o main`

or

`gcc main.c -o main`

Both achieve the same thing. 

* First the compiler is specified.
* Then a 'space' follows, and then the '.c' file we want to compile.
* `-o` is a flag abbreviated for output. Items that begin with *dash marks* in general are compiler flags.
  * In this case the 'output' file we will generate(if there are no errors) will be called 'main'
  * Note: This 'main' file is a binary file that we can execute. This is different than 'main.c' which has the .c extension, and is a text file.
  
Finally, to execute your program, you will type in: `./main`

# Part 2 - Guessing Game in C

- Randomly generate a number from 1 to 10.
- Take user input from user to guess the randomly generated number.
- When the user guesses the correct answer, output that they have finished.


Implement in the main.c file. Do not forget to 'push' your changes.

TBD


### Sample Correct output 

```
-bash-4.2$ clang main.c -o main
-bash-4.2$ ./main
==========================
CPU Says: Pick a number 1-10
==========================
Make a guess:1
No guess higher!
Make a guess:2
No guess higher!
Make a guess:3
No guess higher!
Make a guess:4
No guess higher!
Make a guess:5
No guess higher!
Make a guess:6
No guess higher!
Make a guess:7
No guess higher!
Make a guess:8
You got it!
==========================
CPU Says: Pick a number 1-10
==========================
Make a guess:5
No guess higher!
Make a guess:7
No guess lower!
Make a guess:6
You got it!
==========================
CPU Says: Pick a number 1-10
==========================
Make a guess:5
No guess higher!
Make a guess:8
You got it!
==========================
CPU Says: Pick a number 1-10
==========================
Make a guess:5
No guess higher!
Make a guess:8
No guess higher!
Make a guess:9
You got it!
==========================
CPU Says: Pick a number 1-10
==========================
Make a guess:5
No guess lower!
Make a guess:3
No guess lower!
Make a guess:1
No guess higher!
Make a guess:2
You got it!
=================================================
|Here are the results of your guessing abilities|
=================================================
Game 0 took you 8 guesses
Game 1 took you 3 guesses
Game 2 took you 2 guesses
Game 3 took you 3 guesses
Game 4 took you 4 guesses
```


# Resources to help



# Rubric

* 100% Guessing Game
    * %50 Program Style
	* %50 Program Correctnesss

* Note: Your code **must** run on the Khoury machines. That is where you should test it, and this is where we grade it!
* Note: You must also commit any additional files into your repository so we can test your code.
  * Points will be lost if you forget!

# Feedback Loop

(An optional task that will reinforce your learning throughout the semester)

tbd

