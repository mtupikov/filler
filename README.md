# filler
42 Unit Factory Project

Filler is an algorithmic game which consists in filling a grid of a known size in advance
with pieces of random size and shapes, without the pieces being stacked more than one
square above each other and without them exceeding the grid. If one of these conditions
is not met, the game stops.
Each successfully placed piece yields a number of points, and has only one player, the
goal of the game could be to get the best score possible. However, it is with two players
that the filler takes all his interest. Each player has for the purpose of placing as many
pieces as possible while attempting to prevent his opponent from doing the same. At the
end of the game, the one with the most points wins the match...

## Goals

Writing a Filler player is a very interesting algorithmic challenge. Each turn, the active
player receives the grid status and must maximize his points while trying to minimize
those of the opponent by eliminating it as quickly as possible.

## How to play

```./filler_vm -p1 [player 1] -p2 [player 2] -f [map] | ./visualisation/visualiser```

## Bonus:  graphic visualizer

![1](https://raw.githubusercontent.com/mtupikov/filler/master/1.png)
![2](https://raw.githubusercontent.com/mtupikov/filler/master/2.png)
