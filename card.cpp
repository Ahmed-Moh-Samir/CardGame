#include <iostream>

using namespace std;

#define DECK_SIZE 52
#define MAX_NAME 30
#define PLAYER_NUM 2

struct Player{
    int score;
    string name;
};

struct Card{
    int face;
    int suit; 
    int color;
};
    
    const string colors[]{"Red", "Black"};
    const string suits[]{"Diamonds","Clubs","Hearts","Spades"};
    const string faces[]{"Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};

struct Deck{
  Card cards[DECK_SIZE];  
};

string getCard(Card card)
{
    return faces[card.face] + " of " + suits[card.suit] + " - " + colors[card.color];
}

void fillDeck(Deck& deck)
{
    for (int i {0}; i < DECK_SIZE; i++)
    {
        deck.cards[i].face = i % 13;
        deck.cards[i].suit = i % 4;
        deck.cards[i].color = i % 2;
    }
}

void shuffleDeck(Deck* deck)

{
    int j;

    Card temp;

    for(int i{0}; i < DECK_SIZE; i++)
    {
        j = rand() % DECK_SIZE;
        temp = deck->cards[i];
        deck->cards[i] = deck->cards[j];
        deck->cards[j] = temp;
    }
}

void dealDeck(const Deck* deck, Player* players)
{

    int remainingCards = DECK_SIZE % PLAYER_NUM;
    for (int i {0}; i < PLAYER_NUM; i++)
    {
        cout << players[i].name << '\t' << '\t';
    }
    cout << '\n';

    for (int i {0}; i < (DECK_SIZE - remainingCards); i++)
    {
        cout << getCard(deck->cards[i]) << ((i + 1) % PLAYER_NUM ? '\t' : '\n');
    }

}

void printDeck(Deck& deck)
{
    for(int i {0}; i < DECK_SIZE; i++)
    {
        cout << getCard(deck.cards[i]) << '\n';
    }
}

void playGame(Deck* deck, Player* players) {
int i, j, c = 0; /* counters */
int rounds = DECK_SIZE / PLAYER_NUM;
int roundWinner;
Card* currentCard;
cout<<"Start of the game!\n";
for (i = 0; i < rounds; i++) {
roundWinner = 0;
currentCard = &(deck->cards[c]);
cout << "Round " << i << "\n";
for (j = 0; j < PLAYER_NUM; j++) {
cout<<players[j].name<<" plays "<<getCard(deck->cards[c])<<"\n";
if ((currentCard->face < deck->cards[c].face) ||
(currentCard->face == deck->cards[c].face
&& currentCard->suit < deck->cards[c].suit))
roundWinner = j;
c++;
}
players[roundWinner].score++;
cout << "Round Winner ["<< players[roundWinner].name<<"]\tTotal:["<<
players[roundWinner].score<<"]\n\n";
}

int gameWinner = 0;
int winnerscore = players[0].score;
for (i = 1; i < PLAYER_NUM; i++) {
if (players[i].score > winnerscore) {
winnerscore = players[i].score;
gameWinner = i;
}
}
cout << "!!!...and the winner is " << players[gameWinner].name << " with " <<
players[gameWinner].score << " points!!!\n";
cout << "End of the game!\n\n";
}


int main()
{
    
    Player players[PLAYER_NUM];
    for (int i{0}; i < PLAYER_NUM; i++)
    {
        players[i].name = "player " + to_string(i + 1);
        players[i].score = 0;
    }
    Deck deck;
    

    fillDeck(deck);
    shuffleDeck(&deck);
    dealDeck(&deck, players);
    // printDeck(deck);
    playGame(&deck, players);


    
}