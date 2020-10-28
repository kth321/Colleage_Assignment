from collections import Counter
import random

number = ['A', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K']
shape = ['H', 'D', 'S', 'C']
deck = []

def init_deck():
    global deck
    deck = [x for x in range(1, 53)]

def num(x):
    return number[x]

def Shape(x):
    return shape[x]
  
def input_player():
    return int(input('Input number of players [1-5]: '))

def pick_card():
    cards = []
    for _ in range(5):
        while True:
            idx = random.randint(0, 51)
            if deck[idx] != 0:
                break
        cards.append(idx)
        deck[idx] = 0
    return cards

def print_card(cards):
    for card in cards:
        quota, rest = divmod(card, 4)
        c = num(quota) + Shape(rest)
        print(c, end=' ')

def check_pair(cards):
    straight = True
    cards = list(map(lambda x: x // 4, cards))
    cards.sort()
    for i in range(4):
        if cards[i] + 1 != cards[i+1]:
            straight = False
    if straight:
        return "Straight!"
    check = Counter(cards)
    pair = 0
    for i in check.values():
        if i == 4:
            return 'Four card'
        if i == 3:
            return 'Triple'
        elif i == 2:
            pair += 1
    if pair == 2:
        return 'Two pair'
    elif pair == 1:
        return 'One pair'
    else:
        return ""

player = input_player()
while True:
    init_deck()
    for _ in range(player):
        cards = pick_card()
        print_card(cards)
        print(check_pair(cards))
    coin = input('Continue game? ')
    if coin == 'z':
        break
    else:
        print()