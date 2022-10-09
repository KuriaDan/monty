## Table of contents
* [General info](#general-info)
* [Technologies](#technologies)
* [Setup](#setup)

## General info
A Brainfuck program has an implicit byte pointer,called 'the pointer',
which is free to move around within an array of 30000 bytes,
initially all set to zero. The pointer itself is initialized
to point to the beginning of this array.

The Brainfuck programming language consists of eight commands
* > Increment the pointer.
* < Decrement the pointer.
* + Increment the byte at the pointer.
* - Decrement the byte at the pointer.
* . Output the byte at the pointer
* , Input a byte and store in byte at pointer
* [ Jump forward past the matching
* ] Jump backward


## Technologies
Project is created with:
* Brainfvck

## Setup
* BF is done by the BF Interpretter