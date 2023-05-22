# Bunny, do a flip!

Alice, despite being a powerful mage, is quite shy. One of her more outgoing friends, Cindy, thought that it was that time of the week again to go and visit her—Alice rarely goes out on her own.

To her surprise, there was another bunny! Cindy wants to celebrate this, but before she got out to buy a cake, she noticed something: the bunnies do a flip whenever their name was called a specific amount of times!

Cindy wants to test the bunnies' endurance. Alice says that Bob and Ben could flip a total of $n$ and $m$ times before getting tired, respectively. Cindy will call Bob's and Ben's names in no particular order, and Alice will say any of the following:

- `Cindy, Bob will do a flip!` if Bob still has the energy in him to jump after the $k_\text{th}$ time he's called
- `Cindy, Ben will do a flip!` if Ben still has the energy in him to jump after the $l_\text{th}$ time he's called
- `Cindy, Bob's tired!` if Bob has already flipped $n$ times
- `Cindy, Ben's tired!` if Ben has already flipped $m$ times

Cindy is going to call the bunnies' names _a lot_, and Alice is getting tired of talking—could you help her out?

Below is a picture of Cindy's perspective once she got to Alice's house.

<p align="center">
  <img src="image.png" />
</p>

Note: Since there will be a **huge** amount of input and (expected) output, you'll need the following:

- In C++:

```cpp
  #include <iostream>

  int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
  }
```

- In Python 3.X:

```py
  import sys

  def input():
    return sys.stdin.readline().rstrip()

  def print(*args, sep=' '):
    sys.stdout.write(sep.join([*args, '\n']))
```

## Input

The first line of input contains space separated integers $k$ and $l$.

The second line of input constains pace separated integers $n$ and $m$.

The third line of input contains $t$, the number of times Cindy will call the bunnies.

The following $t$ lines of input will be one of the following:

- `Bob, do a flip!`
- `Ben, do a flip!`

### Constraints

${10\leq n, m\leq 2*10^{6}}$

${1\leq k, l\leq 10}$

## Output

Output $t$ lines, with each one corresponding to what Alice will say.
