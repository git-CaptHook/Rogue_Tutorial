Roguelikedev Complete Tutorial 2022
===================================

## test ##

```C
const int x = __LINE__;
```

> int main(int argc, char** args) {

<details>
  <summary>THIS IS THE OUTSIDE TEXT</summary>
  this is the inside text
</details>

https://gist.github.com/ChrisTollefson/a3af6d902a74a0afd1c2d79aadc9bb3f




First off lets get a rough idea of the architecture of this game. There are going to be two layers. 

The "bottom" layer is going to be the SDL layer.
> platform.c

The second layer is going to be the game layer.
> game.c

The platform layer is going to implement SDL, set up window, and do any OS specific things that need to be done. The game layer is going to do all the game specific stuff. This type of architecture makes it a lot easier in the future to rewrite the 'underneath' stuff to run on other OS's, or things like that.



<details>
  <summary> Part 1: Drawing the '@' Symbol and moving it around. </summary>
  
  
</details>
