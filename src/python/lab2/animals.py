from animal_base import Animal
from random import randint


class Dog(Animal):
    _shape = \
'''  /^ ^\\
 / 0 0 \\
 V\\ Y /V    -- bark
  / - \\
 /    |
V__) ||'''


class Cat(Animal):
    _shape = \
'''    /\\_____/\\
   /  o   o  \\
  ( ==  ^  == )
   )         (
  (           )
 ( (  )   (  ) )
(__(__)___(__)__)'''

    def makeSound(self):
        print(self._shape)
        if randint(0, 1):
            print(f'"Meow" says {self._name}')
        else:
            print(f'Silently, {self._name} stares you down')