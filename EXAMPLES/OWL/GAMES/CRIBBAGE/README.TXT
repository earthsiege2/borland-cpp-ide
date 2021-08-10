Copyright Borland International
ObjectWindows (C) 1995

Title: CRIBBAGE Example

Keywords: Game;Turbo Cribbage

Some terminology:


[Dealer]

The player who dealt the hand


[Pone]

The nondealer


[Starter]

The upturned card on the deck


[Heels]

2 points for the dealer, if the starter is a jack


[Nobs]

When counting points in the hand, a jack which matches
the suit of the starter is worth 1 point

[Crib]

A third hand made up of cards discarded from the players hands.
The crib belongs to the dealer.


[Show points]

After the cards have been played, each player in turn
shows their hand and counts the points.  The hands are
counted in strict order: pone, dealer, then dealers crib.


[Muggins]

If a player fails to count all the points in their hand,
the opponent may call "Muggins!" and claim the overlooked
points for themself


[How to play]

Turbo Cribbage implements a 2 handed cribbage game.  The game is played
to 121 points, and because points are accumulated in small amounts, a
pegboard is used to keep track of the scores.  Each round consists of
several phases: the deal, discard, cut for starter, card play, show points.


The Deal: The deal alternates between players each round.  Dealer deals
six cards to each player.


Discard:  Each player discards 2 cards into the crib.


Cut for starter:  Pone cuts the deck, and dealer turns over the top card.
If the starter is a jack, dealer takes 2 points (heels).


Card play:  Pone plays the first card, and announces its face value (face
cards have a value of 10).  Dealer then plays a card, announcing the total
of the two cards.  Play continues alternately, each player announcing the
running total of the cards, continuing until a player is unable to play
without the sum exceeding 31.  At this point, the player says 'go'.  The
other player must continue to play cards if they can without exceeding
31.  Then they take 1 or 2 points for the go (1 point if the sum is less
than 31, 2 points if it equals 31).  The count then begins again at zero,
and play continues with the player who called 'go'.  Play continues until
both players are out of cards.  The player who plays the last card takes
1 point if the sum is less than 31, or 2 if it equals 31.


Scoring during play:  In addition to points for 'go', the following points
may also be scored:


Fifteen: If the sum of the cards reaches fifteen, peg 2.


Pairs: If the card played matches the previous card, peg 2.  If the last 3
cards match, peg 6 (for 3 pair).  If the last 4 cards match, peg 12 (6 pair).


Runs: If the card played forms a sequence with 2 or more of the previous
cards, peg 1 point for each card in the run.  The run cannot be broken:

3,5,6,2  =  run of 4 cards; 4 points.

3,9,1,2  =  no run; the 9 breaks the run of 1,2, and 3.


Showing points:

After cards have been played, each player shows their hand, and counts
the points.  The starter can be used when counting points in the hand.
Points are scored as follows:

   2 points - each pair

   2 points - each combination of cards which adds to 15

   3 points - each 3 card run

   4 points - each 4 card run

   5 points - each 5 card run

   1 point  - nobs (a jack which matches the suit of the starter)

   4 points - a 4 card flush (not using the starter)

   5 points - a 5-card flush (using the starter).  A 5-card flush cannot be
counted in the crib.


It is possible to have multiple runs, for example:

   1,2,3,3   :  double 3-card run ( 2*3 + 2 for pair = 8 points )

   1,2,2,3,3 :  quadruple 3-card run ( 4*3 + 4 for 2 pairs = 16 points )

   1,2,2,2,3 :  triple 3-card run ( 3*3 + 6 for 3 pairs = 15 points )


If a player overlooks some points, and the opponent notices, they may
call "Muggins!" and claim the missed points.  Be carefull, the computer
is _very_ observant.


After the hands have been counted, the cards are placed back into the deck,
the deck is shuffled, and the next hand is dealt.


The game is over when one player reaches 121.  The game ends immediately,
and no other points are counted.  This is why the order of the showing of
hands is important!


Notes:

Turbo Cribbage does not implement a smart computer player.  The computer
simply discards the first 2 cards in its hand, and plays its cards in
order.



