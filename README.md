# Stopwatch
This is a simple stopwatch program with an ncurses UI.

## Usage

## Features
* The resolution is 0.1s.
* No limit set to the maximum duration timed.
* Display is hours:minute:seconds.milliseconds.
* The time reference is the local computer clock.

## Installation

### Instructions

### Dependencies
* ncurses

## User interface
### User actions
The possible user actions, in combination with the program states are
summarized in the following diagram.

![ui_state](doc/ui_state.svg)

The program states are:
* Program start: the start of the program.
* Zeroed count: the stopwatch is set to duration zero.
* Stopped: The stopwatch is inactive, and waiting for user action.
* Counting: The stopwatch is counting and displaying the current duration.

The user actions are:
* Resume: Start counting duration. In case a previous count was stopped (but not
  reset), then the duration counting continues from the last count.
  Also display the current duration while counting.
* Stop: Stop counting the duration. Also display the current duration (frozen).
* Reset: Set the duration count to zero and stop the clock.
* Quit: Terminate the program.

### Bindings
The default bindings are:
* Stop/Resume: `Space`
* Reset: `r`
* Quit: `q`

## Tested on
We build and use this program on Gentoo Linux, amd64, with musl libc.
