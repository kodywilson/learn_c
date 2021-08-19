// classifies a poker hand
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

// external variables
//int num_in_rank[NUM_RANKS];
//int num_in_suit[NUM_SUITS];
int hand[5][2];
bool straight, flush, four, three;
int pairs; // can be 0, 1, or 2

// prototypes
void read_cards(void);
void analyze_hand(void);
void print_result(void);

// call read_cards, analyze_hand, and print_result
int main(void)
{
  for (;;) {
    read_cards();
    analyze_hand();
    print_result();
  }

  return 0;
}

// read_cards: reads cards into external variables num_in_rank and num_in_suit
void read_cards(void)
{
  char ch, rank_ch, suit_ch;
  int rank, suit;
  bool bad_card, duplicate_card;
  int cards_read = 0;

  while (cards_read < NUM_CARDS)
  {
    bad_card = false;
    duplicate_card = false;

    printf("Enter a card: ");

    rank_ch = getchar();
    switch (rank_ch)
    {
      case '0':             exit(EXIT_SUCCESS);
      case '2':             rank = 0; break;
      case '3':             rank = 1; break;
      case '4':             rank = 2; break;
      case '5':             rank = 3; break;
      case '6':             rank = 4; break;
      case '7':             rank = 5; break;
      case '8':             rank = 6; break;
      case '9':             rank = 7; break;
      case 't': case 'T':   rank = 8; break;
      case 'j': case 'J':   rank = 9; break;
      case 'q': case 'Q':   rank = 10; break;
      case 'k': case 'K':   rank = 11; break;
      case 'a': case 'A':   rank = 12; break;
      default:              bad_card = true;
    }

    suit_ch = getchar();
    switch (suit_ch)
    {
      case 'c': case 'C': suit = 0; break;
      case 'd': case 'D': suit = 1; break;
      case 'h': case 'H': suit = 2; break;
      case 's': case 'S': suit = 3; break;
      default:            bad_card = true;
    }

    while ((ch = getchar()) != '\n')
      if (ch != ' ') bad_card = true;

    for (int i = 0; i < 5; i++)
      if (hand[i][0] == rank && hand[i][1] == suit)
        duplicate_card = true;

    if (bad_card)
      printf("Bad card, ignored.\n");
    else if (duplicate_card)
      printf("Duplicate card, ignored.\n");
    else
    {
      hand[cards_read][0] = rank;
      hand[cards_read][1] = suit;
      cards_read++;
    }
  }
}

// analyze the hand, looking for flushes, straights, pairs, etc.
void analyze_hand(void)
{
  int card, rank, run, suit;
  straight = false;
  flush = false;
  four = false;
  three = false;
  pairs = 0;

  // check for flush
  suit = hand[0][1];
  for (int card = 0; card < NUM_CARDS; card++)
    if (card == 4 && hand[card][1] == suit)
      flush = true;

  // check for straight
  rank = hand[0][0];
  for (int card = 1; card < NUM_CARDS; card++)
    if (hand[card][0] != rank + 1)
      break;
    else if (hand[card][0] == rank + 1 && card < NUM_CARDS - 1)
      rank++;
    else if (card == 4 && hand[card][0] == rank + 1)
      straight = true;

  // check for 4 of a kind, 3 of a kind, and pairs
  card = 0;
  while (card < NUM_CARDS)
  {
    rank = hand[card][0];
    run = 0;
    do
    {
      run++;
      card++;
    }
    while (card < NUM_CARDS && hand[card][0] == rank);
    switch (run)
    {
      case 2: pairs++;      break;
      case 3: three = true; break;
      case 4: four = true;  break;
    }
  }
}

// print results of hand analysis
void print_result(void)
{
  if (straight && flush)        printf("Straight flush");
  else if (four)                printf("Four of a kind");
  else if (three && pairs == 1) printf("Full house");
  else if (flush)               printf("Flush");
  else if (straight)            printf("Straight");
  else if (three)               printf("Three of a kind");
  else if (pairs == 2)          printf("Two pairs");
  else if (pairs == 1)          printf("Pair");
  else                          printf("High card");

  printf("\n\n");
}

