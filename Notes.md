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

The "bottom" layer is going to be the SDL layer.</br>
<code> platform.c </code>

The "top" layer is going to be the game layer.</br>
<code> game.c </code>

The platform layer is going to implement SDL, set up window, and do any OS specific things that need to be done. The game layer is going to do all the game specific stuff. This type of architecture makes it a lot easier in the future to rewrite the 'underneath' stuff to run on other OS's, or things like that.

Platform (SDL) Layer
====================
<ol>
  <li>Will handle all SDL functionality.
  <li>Has hooks into game layer through 3 functions
  <ol>
    <li>game_init() will be run before the main loop is started, and after all the SDL stuff is done.
    <li>game_update() will be called once per frame.
    <li>game_render() will be called once per frame, after game_update()
  </ol>
  <li>There is a defined struct <code>str_Input</code> that is just a bunch of ints for possible inputs, the game layer will read this struct.
  <li>The platform layer will aim for a target frame rate, so it will sleep after every frame of 1. update 2. render 3. get input.
</ol>


Tutorial Notes
==============
<details>
  <summary> Part 1: Drawing the '@' Symbol and moving it around. </summary>
</details>


<details>
  <summary> Part 2: The generic Entity, the render functions, the map. </summary>
</details>


<details>
  <summary> Part 3: Generating a dungeon. </summary>
</details>


<details>
  <summary> Part 4: Field of view. </summary>
</details>
