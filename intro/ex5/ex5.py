'''/******************************************
* Haim Gil
* 203676945
* 8911003
* ex5
******************************************/'''

# I only used sys to print multiple things in one line.
import sys

# "sys.stdout.write" operation means print in the same line.
# Global list that helps me to get value to symbols.
suits = ["diamond", "spade", "club", "heart"]
# Global list that helps me to know if the cards are in the same color.
suitsValid = ["diamond", "spade", "heart", "club"]

# This is a class of card. Each card has number and symbol.
class Card:
    num = 0
    symbol = " "

    def __init__(self, num, symbol):
        self.num = num
        self.symbol = symbol

    '''/***********************************************************************
    * function name: PrintCard.
    * The Input: None.
    * The output: None.
    * The Function operation: The function print the card.
    ***********************************************************************/'''
    def PrintCard(self):
        sys.stdout.write("<" + str(self.num) + "," + self.symbol + ">")

''' This is a class of deck. The deck contains list of cards, number of cards,
index of the front and index of the tail.'''
class Deck:
    counter = 0
    front = 0
    tail = 0
    data = []

    def __init__(self, size):
        self.data = [Card] * size
        self.counter = 0
        self.front = 0
        self.tail = 0
    '''/***********************************************************************
    * function name: NewDeck.
    * The Input: None.
    * The output: None.
    * The Function operation: The function delete the current deck and create
    * new deck from 2 diamond to 14 heart.
    ***********************************************************************/'''
    def NewDeck (self):
        # Delete the older deck.
        for i in range(0, self.counter):
            self.Draw()
        # Create new deck.
        for symbol in suits:
            for num in range(2, 15):
                c = Card(num, symbol)
                self.Add(c)

    '''/***********************************************************************
    * function name: Add.
    * The Input: A card.
    * The output: None.
    * The Function operation: The function gets a card and adding it
    * to the deck.
    ***********************************************************************/'''
    def Add (self, card):
        # Add the card to the last place.
        self.data[self.tail] = card
        # Update the tail.
        self.tail = (self.tail+1)%len(self.data)
        # Update counter.
        self.counter = self.counter + 1

    '''/***********************************************************************
    * function name: AddCards.
    * The Input: List of cards and his length.
    * The output: None.
    * The Function operation: The function gets list of cards and adding it
    * to the deck.
    ***********************************************************************/'''
    def AddCards (self, cards, numOfCards):
        # Adding the list of cards to the deck.
        for i in range(0, numOfCards):
            self.Add(cards[i])

    '''/***********************************************************************
    * function name: Draw.
    * The Input: None.
    * The output: A card.
    * The Function operation: The function draw a crad from the deck and
    * return it.
    ***********************************************************************/'''
    def Draw (self):
        # Draw the card, update the tail and counter.
        card = self.data[self.front]
        self.front = (self.front+1)%len(self.data)
        self.counter = self.counter - 1
        return card

    '''/***********************************************************************
    * function name: Count.
    * The Input: None.
    * The output: The number of cards that in the deck.
    * The Function operation: The function return the number of cards that
    * in the deck .
    ***********************************************************************/'''
    def Count (self):
        return self.counter

    '''/***********************************************************************
    * function name: Print.
    * The Input: None.
    * The output: None.
    * The Function operation: The function prints all the cards in the deck.
    ***********************************************************************/'''
    def Print(self):
        sys.stdout.write('[')
        # Prints all the cards in the deck.
        for i in range(0, self.counter - 1):
            c = self.data[i]
            c.PrintCard()
            sys.stdout.write(',')
        self.data[i+1].PrintCard()
        sys.stdout.write(']')

'''/*************************************************************************
* function name: IsBetter.
* The Input: Two cards.
* The output: 1 or 0.
* The Function operation: The function gets two cards and return 1 if the
* first is better and 0 if the second is better.
* Note: In case its the same card the funtion will return 2.
*************************************************************************/'''
def IsBetter(card1, card2):
    # The first is better.
    if (card1.num > card2.num):
        return 1
    elif (card1.num == card2.num):
        # Gets value for symbol.
        for i in range(0, 4):
            if card1.symbol == suits[i]:
                symbol1 = i
            if card2.symbol == suits[i]:
                symbol2 = i
        # the first is better.
        if symbol1 > symbol2:
            return 1
        else:
            return 0
    else:
        return 0

'''/**************************************************************************
* function name: PrintBetter.
* The Input: Two cards.
* The output: None.
* The Function operation: The function gets two cards and checks if the first
* card is better than the second.
**************************************************************************/'''
def PrintBetter(c1, c2):
    better = IsBetter(c1, c2)
    if better == 1:
        c1.PrintCard()
        sys.stdout.write(" is better than ")
        c2.PrintCard()
    else:
        c1.PrintCard()
        sys.stdout.write(" is not better than ")
        c2.PrintCard()

'''/*************************************************************************
* function name: IsValidSequence.
* The Input: List of Card and his length.
* The output: None.
* The Function operation: The function gets a list of card and checks if
* they are a valid sequence.
* Note: 13,14,2,1 is a valid sequence.
*************************************************************************/'''
def IsValidSequence(cards, numOfcards):
        # Flag that turns to 1 if its not valid sequence.
        valid = 0
        sys.stdout.write('[')
        # Finding if its valid sequence.
        for i in range(0, numOfcards - 1):
            cFirst = cards[i]
            cNext = cards [i + 1]
            # Gets value for symbols.
            for i in range(0, 4):
                if cFirst.symbol == suitsValid[i]:
                    symbol1 = i
                if cNext.symbol == suitsValid[i]:
                    symbol2 = i
            # The second card number is not sequence.
            if ((cFirst.num + 1) % 13) != (cNext.num % 13):
                valid = 1
                cFirst.PrintCard()
                sys.stdout.write(',')
            # The cards has different colors.
            elif (symbol1 % 2 == 0) and (symbol2 % 2 != 0):
                valid = 1
                cFirst.PrintCard()
                sys.stdout.write(',')
            # The cards has different colors.
            elif (symbol1 % 2 != 0) and (symbol2 % 2 == 0):
                valid = 1
                cFirst.PrintCard()
                sys.stdout.write(',')
            # Its a valid sequence.
            else:
                cFirst.PrintCard()
                sys.stdout.write(',')
        cNext.PrintCard()
        sys.stdout.write(']')

        # Its a valid sequence.
        if valid == 0:
            print " is a valid sequence"
        else:
            print " is not a valid sequence"

'''/*************************************************************************
* function name: ScanCard.
* The Input: None.
* The output: A card.
* The Function operation: The function scaning from the user number and symbol
* and return it as a card.
* Note: The program will sacn until there will be legal card.
**************************************************************************/'''
def ScanCard():
    # Flag that turns to true if legal input has entered.
    legalInput = False

    while legalInput == False:
        string = raw_input()
        # Split the string by space.
        (num, symbol) = string.split(' ')
        # Convert the num from string to float.
        num = float(num)
        # Turns the number to positive.
        num = abs(num)
        # Convert to int.
        num = int(num)

        # If its valid card.
        if (2 <= num <= 14) and (symbol in suits):
            c = Card(num, symbol)
            legalInput = True
    return c

sta = Deck(52)
mission = -1
while mission != 0:
    mission = raw_input()
    if mission == '1':
       sta.NewDeck()
    elif mission == '2':

        # If the deck is empty.
        if sta.Count() < 1:
            continue
        card = sta.Draw()
        card.PrintCard()
        print ""
    elif mission == '3':
        c = ScanCard()
        sta.Add(c)
    elif mission == '4':
        amount = raw_input()
        amount = int(amount)

        if amount < 1:
            continue
        cardsAdd = [Card] * amount

        # Sacnning cards.
        for i in range(0, amount):
            cardsAdd[i] = ScanCard()
        sta.AddCards(cardsAdd,amount)
    elif mission == '5':

        # Deck is empty or has only one card.
        if sta.Count() < 2:
            continue
        else:
            c1 = sta.Draw()
            c2 = sta.Draw()
            PrintBetter(c1, c2)
            print ""
    elif mission == '6':

        # Draw All the cards in the deck and print it.
        for i in range(0, sta.Count()):
            card = sta.Draw()
            card.PrintCard()
            print ""
    elif mission == '7':
        amount = raw_input()
        amount = int(amount)

        '''There isn't enough cards in the deck and
            sequence need to be more than one.'''
        if sta.Count() < amount or amount < 2:
            continue
        cardsDraw = [Card] * amount
        # Draw amount of cards and cheks valid sequence.
        for i in range(0, amount):
            cardsDraw[i] = sta.Draw()
        IsValidSequence(cardsDraw, amount)
    elif mission == '0':
       exit()