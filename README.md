# Megaman X password decrypter

## _What is this about?_

This is a simple program which receives a Megaman X password and returns the player progress in the game (robot masters defeated, heart tanks, sub tanks and armor parts collects).

## _How do I build it?_

Just clone this repository and run `make` inside root repository.

The project was developed using GNU Make 4.2.1 and gcc version 9.3.0. Be sure to have these (or any version similar) before trying to build it.

## _How do I execute it?_

Once the project is built, the executable will be available on `bin/mmxpd`.

To execute it, simply run `./bin/mmxpd dddd-dddd-dddd` where `dddd-dddd-dddd` is the password to be decoded (e.g. 8344-4347-6751).

## _Nice, but how does it work?_

Ok, so let's go back in time. 

It is early 90s, you just got Megaman X for your Super Nintendo. You wanted to try it before going to school, so you decided to give it a try. You have made some progress but now you need to leave. You turn your console off, but before that you annotate the last password presented by the game.

_Pretty nostalgic, but how is this connected to the program?_

It gives ambience!

So, you come back home and turn your console on again. Awesome soundtrack starts blasting, "Mega Man" flashes on a black background, golden stripes starts to cuts through and a characteristic _shi-ing_ introduces a big "X" on your screen. You take a worned piece of paper containing some aparently random numbers and select the "Password" options.

_Can we move to the part where you explain the program?_

\*ahem\* Right, sorry! Got a little bit carried away here.

So, when the password screen is presented, the user has to fill a 4 x 3 grid with numbers going from 1 through 8.

Depending of the values the player presents on all twelve slots, the game continues with certains achievements already done.

_Achievements? Which achievements?_

The game has 24 achievements in total:
- Defeated eight robot masters;
- Found eight heart tanks;
- Found four sub tanks;
- Found for armor pieces.

_So, the game has 24 achievements but passwords only have 12 numbers. How is that possible?_

That's because each slot is responsible to identify if the player has done not one, but *two* achievements in the game.

Let's take slot [1x0] as example...

_Wait! Slot what!?_

To traverse through the password, we will use a pair of (x,y) coordinates. "x" is as left-right coordinate and "y" is a top-down coordinate. Both coordinates starts as "0" since it facilitates the programming calculation.

| x,y | 0 | 1 | 2 | 3 |
|:---:|:-:|:-:|:-:|:-:|
|  0  | 8 | 3 | 4 | 4 |
|  1  | 4 | 3 | 4 | 7 |
|  2  | 6 | 7 | 5 | 1 |

So, slot [1x0] means "second position from the left, first position from the top", which contains the value "3".

| x,y | 0 |  1  | 2 | 3 |
|:---:|:-:|:---:|:-:|:-:|
|  0  | 8 | (3) | 4 | 4 |
|  1  | 4 |  3  | 4 | 7 |
|  2  | 6 |  7  | 5 | 1 |

Slot [1x0] is responsible to check if the player has already defeated Launch Octopus and acquired the body armor.

_How do you know that? Which slot is responsible to check which achievements?_

You can check the list [here](#slot-achievements).

_Each slot accepts eight different values only to check two achievements. Isn't that a bit too much?_

Well yes, but actually no!

There are four possible combinations for these achievements:

1. Player has realized both achievements.
2. Player has only realized the first achievement.
3. Player has only realized the second achievement.
4. Player did not realized any achievement

So, the math here is:

```
 8 possible values
------------------ = 2 values per combination
  4 combinations
```
This means that, in all eight values:
- Two of them means that both achievements were realized.
- Two of them means that only the first achievement was realized.
- Two of them means that only the second achievement was realized.
- Two of them means that none of the achievements were realized.

_But why use a pair of values? Wouldn't be simpler to use only a single value?_

There is a reason for that, but not on the decryption side. If you are curious to know about it I recommend to read [UltraBongo's Mega Man X Password Encryption System article][1].

_Ok, a pair for each achievement then. Seems pretty simple. Which one are they then?_

It's not *that* simple.

Let's take slot [1x0] again. The four pair for this slot are:

- [2,3]
- [7,8]
- [1,4]
- [5,6]

But *which* pair means *which* achievement combination depends on how we traverse these pairs.

_Wait, what?_

Don't worry. I'll explain.

Let's take all four pairs and identify then as "A", "B", "C" and "D".

- [2,3] is A 
- [7,8] is B
- [1,4] is C
- [5,6] is D

Also, let's create a table describing all achievement combinations for a slot.

| None | First | Second | Both |
|---|---|---|---|


Now, let's fill this table by traversing the pairs in four different ways.

The first and most straightforward is to traverse them forwards: A, B, C and D.

| None | First | Second | Both |
|:-:|:-:|:-:|:-:|
| A | B | C | D |

This means that:
- A value from pair "A" ([2,3]) on slot [1x0] means that player did not realize any achievement.
- A value from pair "B" ([7,8]) on slot [1x0] means that player realized only the first achievement.
- A value from pair "C" ([1,4]) on slot [1x0] means that player realized only the second achievement.
- A value from pair "D" ([5,6]) on slot [1x0] means that player realized both achievements.

The second way is just the opposite. We traverse the pairs backwards.

| None | First | Second | Both |
|:-:|:-:|:-:|:-:|
| D | C | B | A |

For the third way we travese forwards and then left rotate twice.

| None | First | Second | Both |
|:-:|:-:|:-:|:-:|
| C | D | A | B |

And for the fourth we traverse backwards and left rotate twice.

| None | First | Second | Both |
|:-:|:-:|:-:|:-:|
| B | A | D | C |

_Ok, so what dictates the traversion we need to do?_

Ah! For that we need to analyse slots [1x2], [2x0] and [3x0].


| yx | 0 |  1  |  2  |  3  |
|:--:|:-:|:---:|:---:|:---:|
|  0 | 8 |  3  | (4) | (4) |
|  1 | 4 |  3  |  4  |  7  |
|  2 | 6 | (7) |  5  |  1  |


These positions behaves slightly different from the others. _They do not have four pairs_. Instead, _they have two quartets_.

To better understand it, let's take a look at slot [1x2].

| yx | 0 |  1  | 2 | 3 |
|:--:|:-:|:---:|:-:|:-:|
|  0 | 8 |  3  | 4 | 4 |
|  1 | 4 |  3  | 4 | 7 |
|  2 | 6 | (7) | 5 | 1 |

It's possible values are divided into two groups.

- Group 0: [8, 3, 2, 1]
- Group 1: [6, 7, 4, 2]

If slot [1x0] value maches group 0 we need to traverse the pairs in one way, but if the value matches group 1, traversion will be done in a different way.

These rules also applies to slots [2x0] and [3x0]. Each one of them also has two groups:

Slot [2x0]:
- Group 0: [2, 4, 6, 7]
- Group 1: [1, 5, 8, 3]

Slot [3x0]:
- Group 0: [5, 3, 2, 6]
- Group 1: [4, 7, 8, 1]

And this gives us a total of eight different ways to traverse all password slots:

| [3x0] group  | [2x0] group | [1x2] group | Traversion set |
|:-:|:-:|:-:|:-:|
| 0 | 0 | 0 | 0 |
| 0 | 0 | 1 | 1 |
| 0 | 1 | 0 | 2 |
| 0 | 1 | 1 | 3 |
| 1 | 0 | 0 | 4 |
| 1 | 0 | 1 | 5 |
| 1 | 1 | 0 | 6 |
| 1 | 1 | 1 | 7 |

And, for each set, we need to traverse pairs slots as presented [here](#traversion-sets).

Let's go back to our example then.

| x,y | 0 |  1  |  2  |  3  |
|:---:|:-:|:---:|:---:|:---:|
|  0  | 8 |  3  | (4) | (4) |
|  1  | 4 |  3  |  4  |  7  |
|  2  | 6 | (7) |  5  |  1  |

Slots [1x2], [2x0] and [3x0] are, respectively, 7, 4 and 4, so:

- Slot [1x2] is in group 1 ([6, 7, 4, 2]).
- Slot [2x0] is in group 0 ([2, 4, 6, 7]).
- Slot [3x0] is in group 1 ([4, 7, 8, 1]).

This means that our traversion set is 5.

Traversion set 5:

| x,y |  0    |  1    |  2    |  3    |
|:---:|:-----:|:-----:|:-----:|:-----:|
|  0  |    F  |  BR2  |  FR2  |    F  |
|  1  |  FR2  |  BR2  |  BR2  |  FR2  |
|  2  |  FR2  |  BR2  |    B  |    B  |

This means that, if we want to check achievements marked for slot [1x0], we need to get its pair groups.

| [2, 3] | [7, 8] | [1, 4] | [5, 6] |
|--------|--------|--------|--------|

Traverse backwards and rotate left twice to have our achievement pairs.

|  None  | First  | Second  | Both  |
|:------:|:------:|:-------:|:-----:|
| [7, 8] | [2, 3] | [5, 6]  | [1, 4]|

And check which achievement pair contains slot [1x0] value (3), which will be the "first achievement realized" pair.

Now, we check which achievements are validated on slot [1x0]:

| Slot  |    First achievement   | Second achievement |
|:-----:|:-----------------------|:-------------------|
|  1x0  | Defeated Flame Mammoth | Acquired helmet    |

So, this means that player has already defeated Flame Mammoth, but has not acquired armor helmet yet.

_What about slots [1x2], [2x0] and [3x0]? They do not have pairs._

In these cases the steps are quite the same, but instead of working with pair groups you need to work with the quartet which contains the selected value.

So, for slot [2x0] the quartets are:

- [2, 4, 6, 7]
- [1, 5, 8, 3]

Continuing with our example, slot [2x0] contains value "4", which is in the first quartet.

| 2 | 4 | 6 | 7 |
|---|---|---|---|


We already know that our traverse set is 5, so let's take its table and check slot [2x0]

| x,y  |  0    |  1    |  2    |  3    |
|:----:|:-----:|:-----:|:-----:|:-----:|
|  0   |    F  |  BR2  | (FR2) |    F  |
|  1   |  FR2  |  BR2  |  BR2  |  FR2  |
|  2   |  FR2  |  BR2  |    B  |    B  |

So, we have to traverse forwards and then rotate left twice to have our achievement values.

| None  | First | Second | Both |
|:-----:|:-----:|:------:|:----:|
|   6   |   7   |   2    |   4  |

Slot [2x0] contains value "4", so this means that player has done both achievements.

If we check which achievements are validated on slot [2x0]:

|  Slot | First achievement | Second achievement |
|:-----:|:------------------|:-------------------|
|  2x0  | Acquired heart tank on Flame Mammoth stage | Acquired sub tank on Flame Mammoth stage |

We know that player has already acquired both the heart tank and the sub tank located on Flame Mammoth stage.

_Ok, this seems to cover pretty much everything. It there something else we need to know?_

Well, actually there is. It seems that slot [3x1] and [3x2] were also destinated to select something for the game since its only valid values are, respectively, [2,6,8,7] and [1,4,6,8], but it seems the programmers never used that...  

... except for the hadouken password:

| x,y | 0 |  1  |  2  |  3  |
|:---:|:-:|:---:|:---:|:---:|
|  0  | 2 |  6  | (5) | (3) |
|  1  | 3 |  8  |  4  |  8  |
|  2  | 7 | (5) |  4  |  7  |

The hadouken password is the only password which contains a 7 on slot [3x2].

# Tables

## Slot pair groups

| Slot | Pair 1 | Pair 2 | Pair 3 | Pair 4 |
|:-:|:-:|:-:|:-:|:-:|
| 0x0 | 1, 4 | 2, 7 | 5, 6 | 3, 8 |
| 1x0 | 2, 3 | 7, 8 | 1, 4 | 5, 6 |
| 0x1 | 5, 7 | 2, 3 | 1, 8 | 4, 6 |
| 1x1 | 2, 8 | 4, 7 | 1, 3 | 5, 6 |
| 2x1 | 4, 5 | 1, 8 | 3, 7 | 2, 6 |
| 0x2 | 1, 8 | 4, 6 | 3, 7 | 2, 5 |
| 2x2 | 2, 6 | 7, 8 | 3, 5 | 1, 4 |

## Slot quartets

| Slot | Quartet 1 | Quartet 2 |
|---|---|---|
| 2x0 | 2, 4, 6, 7 | 1, 5, 8, 3 |
| 3x0 | 5, 3, 2, 6 | 4, 7, 8, 1 |
| 3x1 | 2, 6, 8, 7 | |
| 1x2 | 8, 3, 2, 1 | 6, 7, 4, 5 |
| 3x2 | 1, 4, 6, 8 | 7 (hadouken) |

## Traversions

| | None | First | Second | Both |
|---|---|---|---|---|
| Forwards  | Pair 1 | Pair 2 | Pair 3 | Pair 4 |
| Backwards | Pair 4 | Pair 3 | Pair 2 | Pair 1 |
| Forwards left rotate twice | Pair 3 | Pair 4 | Pair 1 | Pair 2 |
| Backwards left rotate twice | Pair 2 | Pair 1 | Pair 4 | Pair 3 |

## Traverson set selection

| [3x0] group  | [2x0] group | [1x2] group | Traversion set |
|:-:|:-:|:-:|:-:|
| 0 | 0 | 0 | 0 |
| 0 | 0 | 1 | 1 |
| 0 | 1 | 0 | 2 |
| 0 | 1 | 1 | 3 |
| 1 | 0 | 0 | 4 |
| 1 | 0 | 1 | 5 |
| 1 | 1 | 0 | 6 |
| 1 | 1 | 1 | 7 |

## Traversion sets

Legend:
 - F: Forwards traversion.
 - B: Backwards traversion.
 - BR2: Traverse forwards and then rotate left twice.
 - FR2: Traverse backwards and then rotate left twice.

### Traversion set 0

| x,y  |  0    |  1    |  2    |  3    |
|------|:-----:|:-----:|:-----:|:-----:|
|  0   |    F  |    F  |    F  |    F  |
|  1   |    F  |    F  |    F  |    F  |
|  2   |    F  |    F  |    F  |    F  |

### Traversion set 1

| x,y  |  0    |  1    |  2    |  3    |
|------|:-----:|:-----:|:-----:|:-----:|
|  0   |    B  |    F  |    B  |    B  |
|  1   |  FR2  |    B  |    B  |    B  |
|  2   |  FR2  |  BR2  |    F  |    F  |

### Traversion set 2

| x,y  |  0    |  1    |  2    |  3    |
|------|:-----:|:-----:|:-----:|:-----:|
|  0   |  FR2  |    F  |  FR2  |    F  |
|  1   |    F  |  FR2  |  FR2  |  BR2  |
|  2   |  BR2  |  BR2  |    F  |    F  |

### Traversion set 3

| x,y  |  0    |  1    |  2    |  3    |
|------|:-----:|:-----:|:-----:|:-----:|
|  0   |  FR2  |  BR2  |    F  |  FR2  |
|  1   |    F  |  FR2  |  FR2  |    B  |
|  2   |    B  |  BR2  |  BR2  |  BR2  |

### Traversion set 4

| x,y  |  0    |  1    |  2    |  3    |
|------|:-----:|:-----:|:-----:|:-----:|
|  0   |    F  |    F  |    F  |  FR2  |
|  1   |  FR2  |  BR2  |  BR2  |    F  |
|  2   |    F  |  BR2  |  FR2  |  FR2  |

### Traversion set 5

| x,y  |  0    |  1    |  2    |  3    |
|------|:-----:|:-----:|:-----:|:-----:|
|  0   |    F  |  BR2  |  FR2  |    F  |
|  1   |  FR2  |  BR2  |  BR2  |  FR2  |
|  2   |  FR2  |  BR2  |    B  |    B  |

### Traversion set 6

| x,y  |  0    |  1    |  2    |  3    |
|------|:-----:|:-----:|:-----:|:-----:|
|  0   |  FR2  |    F  |  FR2  |  FR2  |
|  1   |  FR2  |    B  |    B  |  BR2  |
|  2   |  BR2  |    F  |  FR2  |  FR2  |
  
### Traversion set 7

| x,y  |  0    |  1    |  2    |  3    |
|------|:-----:|:-----:|:-----:|:-----:|
|  0   |  FR2  |  BR2  |    F  |    F  |
|  1   |  FR2  |    B  |    B  |    B  |
|  2   |    B  |    F  |    B  |    B  |

## Slot achievements

| Slot | First achievement | Second achievement |
|---|---|---|
| 0x0 | Acquired heart tank on Chill Penguin stage | Acquired sub tank on Armored Armadillo stage |
| 1x0 | Defeated Flame Mammoth | Acquired helmet |
| 2x0 | Acquired heart tank on Flame Mammoth stage | Acquired sub tank on Flame Mammoth stage |
| 3x0 | Defeated Storm Eagle | Acquired heart tank on Storm Eagle stage  |
| 0x1 | Defeated Launch Octopus | Acquired body armor |
| 1x1 | Defeated Boomer Kwanger | Acquired heart tank on Boomer Kwanger stage |
| 2x1 | Defeated Armored Armadillo | Acquired Mega Buster |
| 3x1 | Defeated Spark Mandrill | Acquired heart tank on Sting Chameleon stage |
| 0x2 | Acquired heart tank on Armored Armadillo stage | Acquired boots |
| 1x2 | Defeated Sting Chameleon | Acquired sub tank on Storm Eagle stage |
| 2x2 | Acquired heart tank on Launch Octopus stage | Acquired sub tank on Spark Mandrill stage |
| 3x2 | Defeated Chill Penguin | Acquired heart tank on Spark Mandrill stage |

# References

While developing this program I could not find many materials related to it. The only thing I found was this awesome [UltraBongo's Mega Man X Password Encryption System article][1]. Thanks UltraBongo for sharing this material. Without it this program would definitelly not exist.

[1]:https://gamefaqs.gamespot.com/pc/562670-mega-man-x/faqs/52749