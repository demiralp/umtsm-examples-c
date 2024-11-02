/*==============================================================================
 * Created by Fehmi Demiralp (Fedem) on 2024-07-28 GMT.
 * Copyright (C) 2023-2024 FEDEM (Fehmi Demiralp) <f.demiralp@gmail.com>.
 * 
 * Released under the MIT License:
 *============================================================================*/

/*
Copyright (c) 2023-2024 Fedem (Fehmi Demiralp)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <Calculator.h>
#include <Keypad.h>
#include <Display.h>

#include <unistd.h>
#include <stdlib.h>

#include <ncurses.h>

S_SM_Calculator_t calculator;


int main()
{
    initscr();

    erase();
    clear();
    noecho();
    cbreak();
    keypad(stdscr, true);
    nodelay(stdscr, true);
    notimeout(stdscr, true);
    set_escdelay(0);
    clrtobot();
    refresh();

    Calculator_Initialize(&calculator);
    
    calculator.subsm.CalculatorKeypad.instanceData.pCalculator= &calculator;

    Calculator_Start( &calculator );

    while(Calculator_IsIn_Main_Region(&calculator))
    {
        sleep(1);
    }

    printw("Exited!\n");

    Calculator_Deinitialize(&calculator);
    
    endwin();

    return EXIT_SUCCESS;
}
